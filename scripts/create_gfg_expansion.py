#!/usr/bin/env python3
"""Add 30 GFG practice environments without replacing any existing file.

Reruns recreate missing generated files only. Existing attempts, notes, tests,
references, and metadata are never opened for writing. Navigation is maintained
separately by sync_curriculum_indexes.py and sync_repository_manifest.py.
"""
import json
from pathlib import Path
import textwrap
from gfg_expansion_data import ITEMS, S, Q
from format_curriculum_like_arrays import format_cpp
import add_detailed_cpp_comments as cpp_notes

ROOT = Path(__file__).resolve().parents[1]
FILES = ('02_brute_force.cpp', '03_better_approach.cpp', '04_optimal_solution.cpp')
LEVELS = ('brute_force', 'better', 'optimal')


def create(path, content):
    path.parent.mkdir(parents=True, exist_ok=True)
    if not path.exists():
        path.write_text(content)


def render(item, entry):
    category = entry['category']
    pattern = category.split('_', 1)[1].replace('_', ' ')
    approach_data = [{key: part[key] for key in ('name','time','space')} | {'level':level}
                     for level,part in zip(LEVELS,item['approaches'])]
    metadata = dict(platform='GeeksforGeeks',problem_number=None,title=item['title'],
                    study_difficulty=item['difficulty'],main_topic='Strings' if item['module']==S else 'Stacks & Queues',
                    pattern_number=item['stage'],pattern=pattern,signature=item['signature'],
                    recognition_cue=item['goal'],invariant=item['invariant'],approaches=approach_data,
                    original_attempt_captured=False,source_handbook='GFG curriculum expansion',url=item['url'],
                    module_index=item['index'],concepts=entry['concepts'],prerequisites=item['prerequisites'])
    table = '\n'.join(f'| [{level.replace("_"," ").title()}]({filename}) | {a["name"]} | {a["time"]} | {a["space"]} |'
                      for level,filename,a in zip(LEVELS,FILES,item['approaches']))
    examples = '\n'.join(f'| `{json.dumps(args)}` | `{json.dumps(answer)}` |' for args,answer in item['cases'])
    signature = item['signature'] if item['starter'] is None else item['starter']
    starter = '#include <bits/stdc++.h>\nusing namespace std;\n\n// LEARNER STARTER — record your own first attempt here.\n'
    starter += (item['starter']+'\n') if item['starter'] else f'class Solution {{\npublic:\n    {signature} {{\n        // Write your attempt here.\n    }}\n}};\n'
    files = {'01_original_attempt.cpp':starter, 'metadata.json':json.dumps(metadata,indent=2)+'\n'}
    files['README.md'] = f'''# {item['title']}

- **Platform:** GeeksforGeeks
- **Study difficulty:** {item['difficulty']}
- **Live problem:** [{item['title']}]({item['url']})
- **Stage:** {pattern}
- **Module ID:** {item['index']} · **Global ID:** {item['global_index']}
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

{item['goal']}

## Concepts and prerequisites

{item['prerequisites']}. Review [{pattern}](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

{item['contract']}

```cpp
{signature}
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
{table}

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
'''
    explanations = '\n\n'.join(f'### {level.replace("_"," ").title()}: {a["name"]}\n\n{a["explanation"]}\n\nTime: `{a["time"]}`. Space: `{a["space"]}`.' for level,a in zip(LEVELS,item['approaches']))
    runner = 'strings' if item['module']==S else 'queues'
    files['solution.md'] = f'''# {item['title']} — explained solution

## Input and result

```cpp
{signature}
```

{item['contract']}

## How to think about it

{item['goal']}

{explanations}

## Worked trace

{item['trace']}

## Why this works

{item['invariant']}

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
{table}

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
{examples}

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module {runner} --problem {item['slug']} --sanitize
```
'''
    files['testcases.md'] = f'# Test cases — {item["title"]}\n\n{item["contract"]}\n\n| Arguments / operations | Expected |\n|---|---|\n{examples}\n\n## My cases before coding\n\n1. [add your own case]\n2. [add your own case]\n'
    files['mistakes.md'] = '# Mistake log\n\nNo learner attempt has been recorded. Fill this only with your actual mistakes.\n\n| Date | My mistake | Why it happened | Correction | Test that catches it |\n|---|---|---|---|---|\n| | | | | |\n'
    files['revision_notes.md'] = f'''# Revision Notes

## One-line trigger

{item['goal']}

## Invariant to remember

{item['invariant']}

## My recall notes

Write your own explanation after attempting the exercise.

| Review | Date | Could I recode independently? | What I forgot |
|---|---|---|---|
| First solve | | | |
| 2-day revision | | | |
| 1-week revision | | | |
| 1-month revision | | | |
'''
    for filename, a in zip(FILES,item['approaches']):
        code = '#include <bits/stdc++.h>\nusing namespace std;\n\n'
        if item['starter']:
            code += a['code']+'\n'
        else:
            code += 'class Solution {\npublic:\n    '+item['signature']+' {\n'+textwrap.indent(a['code'],'        ')+'\n    }\n};\n'
        code = format_cpp(code)
        walkthrough = '\n'.join(f'{i}. `{line}`\n   {cpp_notes.explain_line(line)}' for i,line in enumerate(cpp_notes.clean_code_for_walkthrough(code),1))
        glossary = '\n'.join(f'- {term}: {cpp_notes.GLOSSARY[term]}' for term in cpp_notes.glossary_keys(code))
        code += f'''
/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
{item['title']}: {item['contract']}

2. FUNCTION SIGNATURE, PART BY PART
{item['signature']}
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: {a['name']}.
{a['explanation']}
Read the initialization first, then trace each loop or operation, and finally
check the return expression against the required type and sentinel.

Executable-line walkthrough:
{walkthrough}

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
{glossary}

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: {item['trace']}
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
{item['invariant']}
{a['explanation']}

7. COMPLEXITY
Time: {a['time']}. Space: {a['space']}.
Input-by-value copying is additional to the stated auxiliary storage. n/m are
input lengths; C is capacity; T is total generated text; output space is named
separately where relevant. Small teaching baselines can exceed judge limits.

8. EDGE CASES TO CHECK
Use the normal, boundary, repeated-value, and missing-answer cases in
testcases.md. Follow the documented allowed input domain before adding cases.

9. COMMON MISTAKES
Changing argument order, using the wrong index base, dropping overlaps,
ignoring equal-value ties, and treating a missing answer as a valid empty value
can all violate the contract. State your invariant before changing a comparison.

10. HOW TO STUDY THIS SOLUTION
Try the starter first. Trace one example by hand, explain why each update is
safe, compare time and memory across references, then recode from memory.
Record only actual learner mistakes and revision dates.
*/
'''
        files[filename]=code
    return files


def main():
    manifests = {m:json.loads((ROOT/m/'problem_manifest.json').read_text()) for m in (S,Q)}
    for item in ITEMS:
        manifest = manifests[item['module']]
        category = next(x['category'] for x in manifest if int(x['category'][:2]) == item['stage'])
        folder = f'{item["module"]}/{category}/GeeksforGeeks/{item["slug"]}'
        entry = dict(category=category,folder=folder,title=item['title'],url=item['url'],platform='GeeksforGeeks',
                     difficulty=item['difficulty'],signature=item['signature'],concepts=category.split('_',1)[1].replace('_',' '),
                     prerequisites=item['prerequisites'],goal=item['goal'],tests=[json.dumps(args)+' -> '+json.dumps(out) for args,out in item['cases']],
                     index=item['index'],global_index=item['global_index'],curriculum_batch='gfg_expansion_2026_09')
        if item['module']==Q: entry['track']='Stack' if item['stage']<=6 else 'Queue/Deque'
        existing = next((x for x in manifest if x['index']==item['index']),None)
        if existing is not None and existing != entry:
            raise RuntimeError(f'Existing manifest entry differs; preserve it for review: {folder}')
        if existing is None:
            if any(x['folder']==folder for x in manifest): raise RuntimeError(f'Duplicate folder: {folder}')
            manifest.append(entry)
        for filename,content in render(item,entry).items(): create(ROOT/folder/filename,content)
    for module,manifest in manifests.items():
        path = ROOT/module/'problem_manifest.json'
        content=json.dumps(manifest,indent=2)+'\n'
        if path.read_text()!=content: path.write_text(content)
    print('30 GFG additions ready: 18 Strings, 7 Stack, 5 Queue/Deque; existing files preserved.')


if __name__=='__main__':main()
