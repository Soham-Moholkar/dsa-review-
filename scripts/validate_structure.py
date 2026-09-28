#!/usr/bin/env python3
"""Validate coverage, metadata consistency and local Markdown destinations."""
import json
from pathlib import Path
import re
import sys
from urllib.parse import unquote

ROOT = Path(__file__).resolve().parents[1]
ARRAYS_ROOT = ROOT / '01_Arrays_and_Vectors'
STRINGS_ROOT = ROOT / '02_Strings'
STACKS_QUEUES_ROOT = ROOT / '04_Stacks_and_Queues'
REQUIRED = {
    'README.md', '01_original_attempt.cpp', '02_brute_force.cpp',
    '03_better_approach.cpp', '04_optimal_solution.cpp', 'mistakes.md',
    'testcases.md', 'revision_notes.md', 'metadata.json', 'solution.md',
}
REFERENCE_FILES = (
    '02_brute_force.cpp', '03_better_approach.cpp', '04_optimal_solution.cpp'
)
STRING_REQUIRED = {
    'README.md', '01_original_attempt.cpp', '02_brute_force.cpp',
    '03_better.cpp', '04_optimal.cpp', 'mistakes.md', 'test_cases.txt',
}
STACKS_QUEUES_STAGES = (
    '01_Stack_Fundamentals', '02_Stack_Manipulation_and_Recursion',
    '03_Parentheses_and_Expressions', '04_Monotonic_Stack',
    '05_Stack_Range_and_Histogram', '06_Advanced_Stack_Problems',
    '07_Queue_Fundamentals', '08_Queue_Manipulation_and_Circular_Queue',
    '09_Deque_and_Monotonic_Queue', '10_Queue_Simulation_and_Streams',
    '11_Advanced_Queue_Problems',
)
EXPLANATION_MARKER = 'DETAILED BEGINNER EXPLANATION'
EXPLANATION_SECTIONS = (
    '1. WHAT THIS FILE SOLVES',
    '2. FUNCTION SIGNATURE, PART BY PART',
    '3. ALGORITHM IN SIMPLE STEPS',
    '4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED',
    '5. DRY RUN',
    '6. WHY THE ALGORITHM IS CORRECT',
    '7. COMPLEXITY',
    '8. EDGE CASES TO CHECK',
    '9. COMMON MISTAKES',
    '10. HOW TO STUDY THIS SOLUTION',
)


def main():
    errors = []
    manifest = json.loads((ROOT/'repository_manifest.json').read_text())
    folders = sorted(p.parent for p in ARRAYS_ROOT.glob('*/*/*/metadata.json'))
    by_path = {entry['folder']: entry for entry in manifest}
    actual = {p.relative_to(ROOT).as_posix() for p in folders}
    if len(by_path) != len(manifest):
        errors.append('Duplicate manifest paths')
    if set(by_path) != actual:
        errors.append(f'Manifest/folder mismatch: {set(by_path) ^ actual}')
    if len(folders) != 80:
        errors.append(f'Expected the 80 handbook entries, found {len(folders)}')
    if sorted(entry['index'] for entry in manifest) != list(range(1,81)):
        errors.append('Manifest indices must be exactly 1..80')
    for folder in folders:
        rel = folder.relative_to(ROOT).as_posix()
        missing = REQUIRED - {p.name for p in folder.iterdir()}
        if missing:
            errors.append(f'{rel}: missing {sorted(missing)}')
        data = json.loads((folder/'metadata.json').read_text())
        if any(by_path.get(rel, {}).get(k) != v for k,v in data.items()):
            errors.append(f'{rel}: metadata differs from manifest')
        if [a['level'] for a in data['approaches']] != ['brute_force','better','optimal']:
            errors.append(f'{rel}: unexpected approach levels')
        if not data['signature'] or int(folder.relative_to(ARRAYS_ROOT).parts[0][:2]) != data['pattern_number']:
            errors.append(f'{rel}: invalid signature or pattern number')
        for filename in REFERENCE_FILES:
            reference = folder/filename
            if not reference.exists():
                continue
            text = reference.read_text()
            if text.count(EXPLANATION_MARKER) != 1:
                errors.append(
                    f'{rel}/{filename}: expected exactly one detailed explanation appendix'
                )
            for heading in EXPLANATION_SECTIONS:
                if heading not in text:
                    errors.append(f'{rel}/{filename}: missing explanation section {heading!r}')
        original = folder/'01_original_attempt.cpp'
        if original.exists() and EXPLANATION_MARKER in original.read_text():
            errors.append(
                f'{rel}/01_original_attempt.cpp: generated reference notes must not alter the learner attempt'
            )
    # A new problem without an oracle must fail validation, not silently be skipped.
    sys.path.insert(0, str(ROOT/'tests'))
    from scenarios import cases
    for folder in folders:
        try:
            if not cases(folder.name, trials=0):
                errors.append(f'{folder.name}: no executable cases')
        except (ValueError, AssertionError) as exc:
            errors.append(str(exc))

    string_manifest_path = STRINGS_ROOT/'problem_manifest.json'
    if not string_manifest_path.exists():
        errors.append('02_Strings/problem_manifest.json is missing')
        string_manifest = []
    else:
        string_manifest = json.loads(string_manifest_path.read_text())
    string_folders = sorted(p.parent for p in STRINGS_ROOT.glob('*/*/README.md'))
    manifest_paths = {entry['folder'] for entry in string_manifest}
    actual_string_paths = {p.relative_to(ROOT).as_posix() for p in string_folders}
    if len(string_folders) != 45 or len(string_manifest) != 45:
        errors.append(
            f'Expected 45 String starters, found {len(string_folders)} folders and '
            f'{len(string_manifest)} manifest entries'
        )
    if manifest_paths != actual_string_paths:
        errors.append(f'String manifest/folder mismatch: {manifest_paths ^ actual_string_paths}')
    forbidden_titles = {
        'Longest Common Subsequence', 'Edit Distance', 'Longest Palindromic Subsequence',
        'Distinct Subsequences', 'Shortest Common Supersequence',
    }
    string_by_path = {entry['folder']: entry for entry in string_manifest}
    if [entry.get('index') for entry in string_manifest] != list(range(1,46)):
        errors.append('String module indices must be sequential 1..45')
    for folder in string_folders:
        rel = folder.relative_to(ROOT).as_posix()
        if string_by_path.get(rel,{}).get('platform') == 'GeeksforGeeks' and ('_GFG_' not in rel or 'geeksforgeeks.org/problems/' not in string_by_path[rel].get('url','')):
            errors.append(f'{rel}: GFG must be a first-class folder with a live GFG problem link')
        missing = STRING_REQUIRED - {p.name for p in folder.iterdir()}
        if missing:
            errors.append(f'{rel}: missing {sorted(missing)}')
        original = (folder/'01_original_attempt.cpp').read_text()
        if 'LEARNER STARTER' not in original:
            errors.append(f'{rel}: original attempt must remain a learner starter')
        compact = re.sub(r'//.*', '', original)
        if re.search(r'\b(return|for|while|if|switch)\b', compact):
            errors.append(f'{rel}: original attempt contains solution logic')
        for filename in ('02_brute_force.cpp', '03_better.cpp', '04_optimal.cpp'):
            text = (folder/filename).read_text()
            if 'REFERENCE SLOT INTENTIONALLY EMPTY' in text or 'class Solution' not in text:
                errors.append(f'{rel}/{filename}: missing implemented reference')
        if not (folder/'solution.md').exists():
            errors.append(f'{rel}: missing solution explanation')
        if not (folder/'revision_notes.md').exists() or not (folder/'metadata.json').exists():
            errors.append(f'{rel}: missing study metadata or revision notes')
        else:
            metadata = json.loads((folder/'metadata.json').read_text())
            if any(metadata.get(key) != string_by_path.get(rel,{}).get(key) for key in ('title','platform','url','signature','category','difficulty')):
                errors.append(f'{rel}: study metadata differs from the String manifest')
        if (folder/'README.md').read_text().count('Reference solution available | Yes') != 1:
            errors.append(f'{rel}: problem README misstates reference availability')
        title = next((entry['title'] for entry in string_manifest if entry['folder'] == rel), '')
        if title in forbidden_titles:
            errors.append(f'{rel}: dynamic-programming String problem belongs in module 10')

    new_manifest_file = STACKS_QUEUES_ROOT/'problem_manifest.json'
    new_manifest = json.loads(new_manifest_file.read_text()) if new_manifest_file.exists() else []
    new_folders = sorted(
        folder for stage in STACKS_QUEUES_ROOT.iterdir() if stage.is_dir()
        for folder in stage.iterdir() if folder.is_dir()
    ) if STACKS_QUEUES_ROOT.exists() else []
    expected_paths = [p.relative_to(ROOT).as_posix() for p in new_folders]
    declared_paths = [entry.get('folder') for entry in new_manifest]
    if len(new_folders) != 55 or len(new_manifest) != 55:
        errors.append(f'Expected 55 Stack/Queue starters, found {len(new_folders)} folders and {len(new_manifest)} manifest entries')
    if len(declared_paths) != len(set(declared_paths)) or set(declared_paths) != set(expected_paths):
        errors.append('Stack/Queue manifest/folder paths differ or contain duplicates')
    if [entry.get('index') for entry in new_manifest] != list(range(1, 56)):
        errors.append('Stack/Queue module indices must be sequential 1..55')
    if [entry.get('global_index') for entry in new_manifest] != list(range(126, 181)):
        errors.append('Stack/Queue global indices must be sequential 126..180')
    if len(list(STACKS_QUEUES_ROOT.glob('*/README.md'))) != 11:
        errors.append('Expected exactly 11 stage READMEs')
    for item in new_manifest:
        index = item.get('index')
        category = item.get('category')
        rel = item.get('folder', '')
        parts = Path(rel).parts
        if not isinstance(index, int) or not 1 <= index <= 55:
            errors.append(f'{rel}: invalid module index')
            continue
        expected_stage = STACKS_QUEUES_STAGES[next((i for i, max_index in enumerate((5,9,14,21,26,30,34,40,45,50,55)) if index <= max_index), 10)]
        if len(parts) != 3 or parts[0] != STACKS_QUEUES_ROOT.name or parts[1] != category or category != expected_stage or not parts[2].startswith(f'{index:02d}_'):
            errors.append(f'{rel}: wrong stage or problem order')
        if item.get('track') != ('Stack' if index <= 30 else 'Queue/Deque'):
            errors.append(f'{rel}: wrong track')
        for key in ('title','url','platform','difficulty','signature','concepts','prerequisites','goal','tests'):
            if not item.get(key):
                errors.append(f'{rel}: missing {key} metadata')
        if not isinstance(item.get('tests'), list) or len(item['tests']) < 3:
            errors.append(f'{rel}: fewer than three starter tests')
        if item.get('platform') == 'GeeksforGeeks' and ('_GFG_' not in rel or 'geeksforgeeks.org/problems/' not in item.get('url','')):
            errors.append(f'{rel}: GFG must be a first-class folder with a live GFG problem link')
    if sum(item.get('track') == 'Stack' for item in new_manifest) != 30 or sum(item.get('track') == 'Queue/Deque' for item in new_manifest) != 25:
        errors.append('Expected exactly 30 Stack and 25 Queue/Deque manifest entries')
    if len(set(p.parent.name for p in (STACKS_QUEUES_ROOT).glob('*/README.md'))) != 11 or set(p.parent.name for p in STACKS_QUEUES_ROOT.glob('*/README.md')) != set(STACKS_QUEUES_STAGES):
        errors.append('Stack/Queue stage folder names differ from the roadmap')
    for module_root, expected_companions in ((STRINGS_ROOT, 11), (STACKS_QUEUES_ROOT, 24)):
        guide = module_root/'GFG_PRACTICE.md'
        if not guide.exists():
            errors.append(f'{guide.relative_to(ROOT)}: GFG companion guide is missing')
            continue
        urls = re.findall(r'https://www\.geeksforgeeks\.org/problems/[^)\s]+', guide.read_text())
        if len(urls) != expected_companions or len(set(urls)) != len(urls):
            errors.append(f'{guide.relative_to(ROOT)}: expected {expected_companions} distinct GFG problem links, found {len(urls)}')
    for folder in new_folders:
        rel = folder.relative_to(ROOT).as_posix()
        missing = STRING_REQUIRED - {p.name for p in folder.iterdir()}
        if missing:
            errors.append(f'{rel}: missing {sorted(missing)}')
            continue
        original = (folder/'01_original_attempt.cpp').read_text()
        if original.count('LEARNER STARTER') != 1:
            errors.append(f'{rel}: expected exactly one LEARNER STARTER marker')
        compact = re.sub(r'/\*.*?\*/|//[^\n]*', '', original, flags=re.S)
        compact = re.sub(r'^\s*#.*$', '', compact, flags=re.M)
        # Class declarations legitimately contain method signatures. Strip declarations
        # before checking for executable statements, loops and assignments.
        if re.search(r'\b(return|for|while|if|switch|do|try|catch)\b', compact) or re.search(r'(?<![=!<>])=(?!=)|\+\+|--', compact):
            errors.append(f'{rel}: original attempt contains implemented solution logic')
        for body in re.findall(r'\)\s*\{([^{}]*)\}', compact):
            if body.strip():
                errors.append(f'{rel}: original attempt has a populated method body')
        for filename in ('02_brute_force.cpp', '03_better.cpp', '04_optimal.cpp'):
            reference_text = (folder/filename).read_text()
            if 'REFERENCE SLOT INTENTIONALLY EMPTY' in reference_text or 'class ' not in reference_text:
                errors.append(f'{rel}/{filename}: missing implemented reference')
        if not (folder/'solution.md').exists():
            errors.append(f'{rel}: missing solution explanation')
        if not (folder/'revision_notes.md').exists() or not (folder/'metadata.json').exists():
            errors.append(f'{rel}: missing study metadata or revision notes')
        else:
            metadata = json.loads((folder/'metadata.json').read_text())
            entry = next((item for item in new_manifest if item.get('folder') == rel), {})
            if any(metadata.get(key) != entry.get(key) for key in ('title','platform','url','signature','category','difficulty')):
                errors.append(f'{rel}: study metadata differs from Stack/Queue manifest')
        if (folder/'README.md').read_text().count('Reference solution available | Yes') != 1:
            errors.append(f'{rel}: problem README misstates reference availability')
        if '[add your own case]' not in (folder/'test_cases.txt').read_text():
            errors.append(f'{rel}: missing personal test case slots')
    tracker = (ROOT/'PROGRESS_TRACKER.md').read_text()
    tracker_rows = [line for line in tracker.splitlines() if line.startswith('| ') and re.match(r'\| \d+ \|', line)]
    if [int(row.split('|')[1].strip()) for row in tracker_rows] != list(range(1, 181)):
        errors.append('Progress tracker must have exactly sequential rows 1..180')
    for item, row in zip(new_manifest, tracker_rows[125:]):
        if item['title'] not in row or row.count('[ ]') != 7 or row.count('[x]') != 1:
            errors.append(f'{item["folder"]}: tracker availability or learner status is incorrect')
    for row in tracker_rows[80:125]:
        if row.count('[ ]') != 7 or row.count('[x]') != 1:
            errors.append('Strings tracker availability or learner status is incorrect')
    index_text = (ROOT/'INDEX.md').read_text()
    module_text = (STACKS_QUEUES_ROOT/'README.md').read_text() if (STACKS_QUEUES_ROOT/'README.md').exists() else ''
    for item in new_manifest:
        if item['folder'] not in index_text:
            errors.append(f'{item["folder"]}: missing from INDEX.md')
        if Path(item['folder']).name not in module_text:
            errors.append(f'{item["folder"]}: missing from module README')
    links = 0
    for path in ROOT.rglob('*.md'):
        for dest in re.findall(r'\[[^\]]*\]\(([^)]+)\)', path.read_text()):
            if re.match(r'^[a-zA-Z][a-zA-Z0-9+.-]*:', dest) or dest.startswith('#'):
                continue
            dest = unquote(dest.split('#')[0])
            if dest and not (path.parent/dest).exists():
                errors.append(f'{path.relative_to(ROOT)}: broken local link {dest}')
            links += 1
    for message in errors:
        print('ERROR:', message)
    references = len(folders) * len(REFERENCE_FILES)
    print(
        f'{len(folders)} Array/Vector problems; {references} explained references; '
        f'{len(string_folders)} String starters with {len(string_folders)*3} references; '
        f'{len(new_folders)} Stack/Queue starters with {len(new_folders)*3} references; {links} local links checked; '
        f'{len(errors)} errors'
    )
    return bool(errors)


if __name__ == '__main__':
    try:
        sys.exit(main())
    except (OSError, ValueError, KeyError, TypeError) as exc:
        print(f'Structure validation failed: {exc}', file=sys.stderr)
        sys.exit(1)
