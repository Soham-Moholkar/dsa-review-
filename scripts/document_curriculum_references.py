#!/usr/bin/env python3
"""Add study pages and synchronize reference status without editing attempts.

Existing personal notes and metadata are preserved on reruns. This script does
not write to learner attempts, mistakes, or C++ solution files.
"""
import json
from pathlib import Path
import importlib.util

ROOT = Path(__file__).resolve().parents[1]


def write_new(path, text):
    if not path.exists():
        path.write_text(text)


def main():
    for module in ('02_Strings', '04_Stacks_and_Queues'):
        items = json.loads((ROOT / module / 'problem_manifest.json').read_text())
        script = ROOT / 'scripts' / ('build_string_references.py' if module == '02_Strings' else 'build_stacks_queues_references.py')
        spec = importlib.util.spec_from_file_location('curriculum_references', script)
        refs = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(refs)
        for item in items:
            folder = ROOT / item['folder']
            readme = folder / 'README.md'
            text = readme.read_text()
            text = text.replace('Reference solution available | No — intentionally locked', 'Reference solution available | Yes — three C++ approaches')
            if '[Compare the reference approaches](solution.md)' not in text:
                text += '\n## After your own attempt\n\n[Compare the reference approaches](solution.md), then record your own mistake and revision dates. Reference availability does not record personal completion.\n'
            readme.write_text(text)
            stage = item['category'].replace('_', ' ', 1).replace('_', ' ')
            concepts = item.get('concepts', '')
            goal = item.get('goal', '')
            tests = item.get('tests', [])
            write_new(folder / 'metadata.json', json.dumps({
                'platform': item['platform'], 'title': item['title'],
                'difficulty': item['difficulty'], 'category': item['category'],
                'module_index': item['index'], 'signature': item['signature'],
                'url': item['url'], 'recognition_cue': goal,
                'concepts': concepts, 'prerequisites': item.get('prerequisites', ''),
                'reference_files': ['02_brute_force.cpp', '03_better.cpp', '04_optimal.cpp'],
            }, indent=2) + '\n')
            metadata = folder / 'metadata.json'
            current = json.loads(metadata.read_text())
            if current.get('original_attempt_captured') is False:
                del current['original_attempt_captured']
                metadata.write_text(json.dumps(current, indent=2) + '\n')
            write_new(folder / 'revision_notes.md', f'''# Revision notes — {item['title']}

## Recognition cue

{goal}

## Stage and concepts

{stage}: {concepts}.

## State or invariant to remember

_Write this in your own words after solving the exercise._

## Complexity tradeoffs

_Compare the three references and record the cost of each approach._

## Mistake to remember

_Record your own concrete counterexample in [mistakes.md](mistakes.md)._

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
''')
            solution = folder / 'solution.md'
            existing = solution.read_text()
            if item['index'] in refs.BETTER:
                existing = existing.replace('same efficient approach (no distinct intermediate recorded)', 'intermediate alternative')
                existing = existing.replace('Same efficient method; no distinct intermediate recorded', 'Intermediate alternative')
            if '## Examples in the starter' not in existing:
                existing += '\n## Examples in the starter\n\nThese are learning cases from `test_cases.txt`, not platform acceptance records.\n\n'
                existing += '\n'.join(f'- `{case}`' for case in tests) + '\n'
            if '## Check yourself' not in existing:
                existing += f'''\n## Check yourself

1. Explain the cue: {goal}
2. Trace one case above through each actual C++ implementation. Note when an approach uses the same algorithm as another; that is an honest absence of a distinct intermediate method.
3. State the invariant and derive time and auxiliary-space costs from the loops and containers in each file. Recursion also consumes stack space.
4. Add a counterexample in [mistakes.md](mistakes.md), then recode without looking at the reference.
5. Record your own dates in [revision notes](revision_notes.md).

Run `python3 scripts/test_curriculum_references.py --module {'strings' if module == '02_Strings' else 'queues'} --sanitize` from the repository root to check the supplied reference implementations.
'''
            solution.write_text(existing)
        for stage in sorted({item['category'] for item in items}):
            readme = ROOT / module / stage / 'README.md'
            text = readme.read_text()
            if '\n## Platform and references\n' in text:
                continue
            rows = ['| # | Platform | Problem | References |', '|---:|---|---|---|']
            for item in items:
                if item['category'] != stage:
                    continue
                name = Path(item['folder']).name
                rows.append(f'| {item["index"]} | {item["platform"]} | [{item["title"]}]({name}/) | [Brute]({name}/02_brute_force.cpp) · [Better]({name}/03_better.cpp) · [Optimal]({name}/04_optimal.cpp) |')
            readme.write_text(text.rstrip() + '\n\n## Platform and references\n\n' + '\n'.join(rows) + '\n')
    print('Synchronized 100 problem study pages and reference availability.')


if __name__ == '__main__':
    main()
