#!/usr/bin/env python3
"""Validate coverage, metadata consistency and local Markdown destinations."""
import json
from pathlib import Path
import re
import sys
from urllib.parse import unquote

ROOT = Path(__file__).resolve().parents[1]
ARRAYS_ROOT = ROOT / '01_Arrays_and_Vectors'
REQUIRED = {
    'README.md', '01_original_attempt.cpp', '02_brute_force.cpp',
    '03_better_approach.cpp', '04_optimal_solution.cpp', 'mistakes.md',
    'testcases.md', 'revision_notes.md', 'metadata.json', 'solution.md',
}
REFERENCE_FILES = (
    '02_brute_force.cpp', '03_better_approach.cpp', '04_optimal_solution.cpp'
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
    print(f'{len(folders)} problems; {references} explained references; {len(manifest)} manifest entries; {links} local links checked; {len(errors)} errors')
    return bool(errors)


if __name__ == '__main__':
    try:
        sys.exit(main())
    except (OSError, ValueError, KeyError, TypeError) as exc:
        print(f'Structure validation failed: {exc}', file=sys.stderr)
        sys.exit(1)
