#!/usr/bin/env python3
"""One-time, repeat-safe layout migration to the Arrays/Vectors platform layout.

Move whole problem directories without reading or changing learner attempts. Stop
if a destination already exists, so existing learner work cannot be replaced.
"""
from __future__ import annotations

import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
MODULES = ('02_Strings', '04_Stacks_and_Queues')
FILE_NAMES = {
    '03_better.cpp': '03_better_approach.cpp',
    '04_optimal.cpp': '04_optimal_solution.cpp',
}


def platform_folder(name: str) -> str:
    return {'GeeksforGeeks': 'GeeksforGeeks', 'LeetCode': 'LeetCode',
            'Repository exercise': 'Exercises'}[name]


def migrate() -> None:
    changes: dict[str, str] = {}
    manifests = {}
    for module in MODULES:
        manifest_file = ROOT / module / 'problem_manifest.json'
        items = json.loads(manifest_file.read_text())
        for item in items:
            old = item['folder']
            name = Path(old).name
            # Arrays/Vectors uses LC_..., GFG_... and a platform directory.
            new_name = re.sub(r'^\d+_', '', name)
            new = str(Path(module) / item['category'] / platform_folder(item['platform']) / new_name)
            if old == new:
                continue
            if (ROOT / old).exists() and (ROOT / new).exists():
                raise RuntimeError(f'Destination exists; refusing to replace learner work: {new}')
            changes[old] = new
            item['folder'] = new
        manifests[module] = (manifest_file, items)

    for old, new in changes.items():
        source, target = ROOT / old, ROOT / new
        if source.exists():
            target.parent.mkdir(parents=True, exist_ok=True)
            source.rename(target)
        elif not target.exists():
            raise RuntimeError(f'Neither old nor new curriculum folder exists: {old}')
        for old_name, new_name in FILE_NAMES.items():
            src, dst = target / old_name, target / new_name
            if src.exists():
                if dst.exists():
                    raise RuntimeError(f'File collision: {dst}')
                src.rename(dst)
        testcase = target / 'test_cases.txt'
        if testcase.exists():
            if (target / 'testcases.md').exists():
                raise RuntimeError(f'Test case collision in {target}')
            lines = testcase.read_text().splitlines()
            examples = [line for line in lines if re.match(r'^\d+\.', line)]
            starter = '\n'.join(examples)
            (target / 'testcases.md').write_text(
                '# Test Cases\n\n## Starter cases\n\n```text\n' + starter +
                '\n```\n\n## Edge-case checklist\n\n'
                '- Smallest allowed input\n- Repeated values or characters\n'
                '- Empty or single element, when allowed\n- A missing result, when allowed\n'
                '- Boundary values and larger inputs\n\n'
                'Add at least two personal cases in the blank lines above before coding.\n'
            )
            testcase.unlink()

    for manifest_file, items in manifests.values():
        if manifest_file.read_text() != json.dumps(items, indent=2) + '\n':
            manifest_file.write_text(json.dumps(items, indent=2) + '\n')

    # Keep all navigation links working after moving directories and files.
    # Match longest path first: short folder names also occur inside full paths.
    replacements = []
    for old, new in sorted(changes.items(), key=lambda pair: -len(pair[0])):
        stage_old = '/'.join(Path(old).parts[-2:])
        stage_new = '/'.join(Path(new).parts[-3:])
        replacements += [(old, new), (stage_old, stage_new),
                         (Path(old).name + '/', '/'.join(Path(new).parts[-2:]) + '/')]
    replacements += [(old, new) for old, new in FILE_NAMES.items()]
    replacements.append(('test_cases.txt', 'testcases.md'))
    for path in ROOT.rglob('*.md'):
        if '.git' in path.parts:
            continue
        text = path.read_text()
        before = text
        for old, new in replacements:
            text = text.replace(old, new)
        if before != text:
            path.write_text(text)
    print(f'Aligned {len(changes)} platform problem directories with Arrays/Vectors.')


if __name__ == '__main__':
    migrate()
