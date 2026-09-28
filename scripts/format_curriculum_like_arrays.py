#!/usr/bin/env python3
"""Give Strings and Stacks/Queues the Arrays/Vectors textbook file format.

This script never opens 01_original_attempt.cpp or mistakes.md for writing. It
keeps the numbered module manifests as the source of truth and rewrites only
generated study material. It can be rerun after reviewing reference changes.
"""
from __future__ import annotations

import importlib.util
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
APPENDIX_MARKER = 'DETAILED BEGINNER EXPLANATION'


def load_builder(filename):
    spec = importlib.util.spec_from_file_location('reference_builder', ROOT / 'scripts' / filename)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


STRING_INVARIANTS = [
    'Positions outside the two pointers are already reversed.',
    'Every character before the current position has its required case.',
    'The right boundary marks the last non-space character not yet counted.',
    'The output contains the alternating characters already consumed from each input.',
    'The output contains complete words in reverse order with single separators.',
    'A frequency count represents every input character; the first count of one wins.',
    'The remaining counts cover precisely the magazine letters not yet consumed.',
    'Every nonzero recorded frequency equals the first nonzero frequency.',
    'A complete balloon consumes one b, a, n and two l and o characters.',
    'The output is assembled from characters in nonincreasing frequency order.',
    'All characters outside the two pointers have already matched after normalization.',
    'After the first mismatch, only one of the two skipped ranges may be a palindrome.',
    'Every earlier word was tested before the current word is considered.',
    'Only vowel positions change; processed ends already contain the reversed vowels.',
    'Only letter positions change; punctuation stays at its original index.',
    'Equal-length anagrams have the same multiplicity for every character.',
    'Both forward and reverse mappings remain consistent for processed positions.',
    'The character-to-word and word-to-character maps agree on processed tokens.',
    'Words in the same group share the same canonical sorted-character key.',
    'The two strings use the same characters and the same multiset of frequencies.',
    'The three characters in the current fixed-size window are checked together.',
    'The running count covers exactly the current k-character window.',
    'The count of white blocks equals the recolors needed for the current window.',
    'The frequency table describes exactly one window of s1.size() characters.',
    'Every reported starting index has the same character multiplicities as p.',
    'The range from left through right contains no repeated character.',
    'The current window can be made uniform with at most k replacements.',
    'The missing count is zero exactly when the current window covers t.',
    'Each valid suffix extension is counted once when the window contains a, b and c.',
    'The current window needs at most k changes to become all one chosen character.',
    'Each processed Roman symbol contributes according to the following symbol.',
    'Only an optional sign and the leading consecutive digits affect the value.',
    'After each symbol is chosen, num is the unrepresented remainder.',
    'Every produced digit equals the column sum modulo ten; carry moves left.',
    'Digit positions accumulate the products of their matching place values.',
    'All candidate match positions before the current offset have been checked.',
    'The candidate period must divide the full string length.',
    'The prefix table stores the longest proper border of each processed prefix.',
    'The last prefix-table value is the longest proper prefix that is also a suffix.',
    'The seen set records previously visited windows of length ten.',
    'The built string contains exactly the current number of copies of a.',
    'The map counts word multiplicities inside one aligned, word-sized window.',
    'Processed word characters obey a consistent mapping in both directions.',
    'A partition ends only after the last occurrence of every character inside it.',
    'The output rows contain the characters already assigned by zigzag position.',
]

QUEUE_INVARIANTS = [
    'The top of the array is the most recently pushed live value.',
    'The head node is the most recently pushed live value.',
    'The stored history contains exactly the uncancelled scores.',
    'Adjacent equal characters at the output end cancel as new input arrives.',
    'The auxiliary stack contains pushed items not yet matched by popped.',
    'All saved values return above the newly inserted bottom value.',
    'Reinsertion under the remaining stack reverses the removed suffix.',
    'After deleting the target depth, the removed elements return in order.',
    'The recursively sorted remainder stays sorted as each item is inserted.',
    'The stack contains unmatched opening delimiters in nesting order.',
    'A closed group is redundant when no operator lies inside its matching pair.',
    'Unmatched closing brackets and remaining openings require additions.',
    'Each stack value represents one fully evaluated postfix subexpression.',
    'The saved last term preserves multiplication and division precedence.',
    'The stack keeps candidate values strictly greater than the current value.',
    'The stack keeps candidate values strictly smaller than the current value.',
    'Candidates to the left are popped until the nearest greater value remains.',
    'Candidates to the left are popped until the nearest smaller value remains.',
    'The repeated traversal leaves only valid circular greater candidates.',
    'Each stored price carries the number of earlier days it already spans.',
    'Unresolved indices wait for their first warmer day.',
    'A popped height extends to the first smaller boundary on either side.',
    'Each row turns vertical runs of ones into histogram heights.',
    'A subarray minimum is charged to one index using a consistent duplicate tie.',
    'Each subarray contributes its maximum minus its minimum exactly once.',
    'Popped valleys can hold water only after a left and right wall exist.',
    'The saved minimum equals the smallest value in the current stack.',
    'Only opposing directions can collide; survivors keep their original order.',
    'Removing a larger preceding digit improves the earliest available place.',
    'Each closed bracket restores its previous prefix and repeats its inner block.',
    'The head index identifies the oldest active item in the array.',
    'The head and tail nodes identify the oldest and newest active values.',
    'One FIFO turn serves one ticket and preserves everybody else’s order.',
    'If nobody waiting wants the current sandwich, no further match is possible.',
    'The remaining queue is reversed as earlier front items return later.',
    'Only the first k elements change order; the suffix remains in order.',
    'Each output pair draws one item from each original half.',
    'The count distinguishes an empty circular buffer from a full one.',
    'Outgoing stack items precede all incoming items in FIFO order.',
    'Rotating after a push makes the newest element the next queue front.',
    'The deque contents follow each requested front or back operation.',
    'The deque holds unexpired positions of negative values.',
    'Deque values decrease from front to back and indices stay inside the window.',
    'Two deques track the current minimum and maximum of the live window.',
    'Prefix sums in the deque are increasing candidates for shortest valid ranges.',
    'The queue contains arrivals that may still be the first unique character.',
    'Every queued timestamp is inside the inclusive recent-call interval.',
    'The queue contains positions not yet assigned a reveal value.',
    'Each queue holds the next active turn for that party.',
    'The buffer contains the last capacity arrivals in their original order.',
    'The head and count define the live circular deque positions.',
    'The two halves remain balanced so the middle is available at an end.',
    'Each cell enters the queue when it first becomes rotten.',
    'The first exit removed by BFS has the fewest steps from the entrance.',
    'Each land-origin BFS layer gives the shortest distance of its newly reached sea cells.',
]

# Time and auxiliary storage for the preferred implementation. Output space is
# noted in the study pages separately when it dominates the result size.
STRING_OPTIMAL = [
    ('O(n)','O(1)'),('O(n)','O(1)'),('O(n)','O(1)'),('O(n + m)','O(n + m)'),
    ('O(n)','O(n)'),('O(n)','O(1)'),('O(n + m)','O(1)'),('O(n)','O(1)'),
    ('O(n)','O(1)'),('O(n + A log A)','O(A + n)'),('O(n)','O(1)'),('O(n)','O(1)'),
    ('O(total characters)','O(1)'),('O(n)','O(n)'),('O(n)','O(n)'),
    ('O(n log n)','O(n)'),('O(n)','O(1)'),('O(n)','O(n)'),
    ('O(w L log L + w log w)','O(w L)'),('O(n)','O(1)'),('O(n)','O(1)'),
    ('O(n)','O(1)'),('O(n)','O(1)'),('O(n + m)','O(1)'),('O(n + m)','O(1) plus result'),
    ('O(n)','O(1)'),('O(n)','O(1)'),('O(n + m)','O(1)'),('O(n)','O(1)'),
    ('O(n)','O(1)'),('O(n)','O(1)'),('O(n)','O(1)'),('O(output length)','O(output length)'),
    ('O(max(n,m))','O(max(n,m))'),('O(nm)','O(n + m)'),('O(nm) worst case','O(1)'),
    ('O(n)','O(n)'),('O(n + m)','O(m) plus result'),('O(n)','O(n)'),
    ('O(n)','O(n)'),('O((n + m)m) worst case','O(n + m)'),
    ('O(nw) expected','O(w + result)'),('O(total characters)','O(1) plus result'),
    ('O(n)','O(1) plus result'),('O(n)','O(n)'),
]

QUEUE_OPTIMAL = [
    ('O(1) amortized per operation','O(n)'),('O(1) per operation','O(n)'),
    ('O(n)','O(n)'),('O(n)','O(n)'),('O(n)','O(n)'),('O(n)','O(n)'),
    ('O(n²)','O(n) recursion'),('O(n²)','O(n) recursion'),('O(n²)','O(n) recursion'),
    ('O(n)','O(n)'),('O(n)','O(n)'),('O(n)','O(1)'),('O(n)','O(n)'),('O(n)','O(1)'),
    *[('O(n)','O(n)')]*7,
    ('O(n)','O(n)'),('O(rows × columns)','O(columns)'),
    ('O(n)','O(n)'),('O(n)','O(n)'),('O(n)','O(n)'),
    ('O(1) per operation','O(n)'),('O(n)','O(n)'),('O(n)','O(n)'),('O(decoded length)','O(decoded length + nesting)'),
    ('O(1) amortized per operation','O(total arrivals)'),('O(1) per operation','O(n)'),
    ('O(n)','O(1)'),('O(n)','O(1)'),('O(n)','O(n)'),('O(n)','O(n)'),('O(n)','O(n)'),
    ('O(1) per operation','O(capacity)'),('O(1) amortized per operation','O(n)'),
    ('O(n) push, O(1) pop/top','O(n)'),('O(commands + output)','O(n)'),
    ('O(n)','O(k) plus result'),('O(n)','O(k) plus result'),
    ('O(n)','O(n)'),('O(n)','O(n)'),('O(n)','O(n)'),
    ('O(1) amortized per ping','O(window)'),('O(n log n)','O(n)'),
    ('O(n)','O(n)'),('O(n)','O(capacity)'),
    ('O(1) per operation','O(capacity)'),('O(1) amortized per operation','O(n)'),
    ('O(rows × columns)','O(rows × columns)'),
    ('O(rows × columns)','O(rows × columns)'),('O(rows × columns)','O(rows × columns)'),
]

STRING_BRUTE_COST = {
    3:('O(n)','O(n)'),5:('O(n)','O(n)'),6:('O(n²)','O(1)'),
    7:('O(nm)','O(m)'),10:('O(n + A log A)','O(A + n)'),
    11:('O(n)','O(n)'),12:('O(n²)','O(n)'),14:('O(n)','O(n)'),15:('O(n)','O(n)'),
    16:('O(n log n)','O(log n)'),
    19:('O(w² L log L)','O(w L)'),22:('O(nk)','O(1)'),23:('O(nk)','O(1)'),
    24:('O(nm log m)','O(m)'),25:('O(nm log m)','O(m)'),26:('O(n²)','O(n)'),
    27:('O(n²)','O(1)'),28:('O(n³)','O(n)'),29:('O(n²)','O(1)'),
    30:('O(n²)','O(1)'),36:('O(nm)','O(1)'),37:('O(n²)','O(1)'),
    38:('O(nm)','O(1) plus result'),39:('O(n²)','O(n)'),
    40:('O(n²)','O(n)'),42:('O(nw) expected','O(w) plus result'),
}
QUEUE_BRUTE_COST = {
    **{index:('O(n²)','O(1) plus result') for index in (15,16,17,18,19,21)},
    22:('O(n²)','O(1)'),24:('O(n²)','O(1)'),25:('O(n²)','O(1)'),
    26:('O(n²)','O(1)'),33:('O(total ticket turns)','O(n)'),34:('O(n²)','O(n)'),
    42:('O(nk)','O(1) plus result'),43:('O(nk)','O(1) plus result'),
    44:('O(n²)','O(1)'),45:('O(n²)','O(1)'),
    50:('O(capacity)','O(capacity) plus result'),55:('O((rows × columns)²)','O(1)'),
}
STRING_BETTER_COST = {
    10:('O(n + A log A)','O(A + n)'),16:('O(n)','O(A)'),
    19:('O(w L log L) expected','O(w L)'),
    22:('O(n)','O(n)'),23:('O(n)','O(n)'),24:('O(nm)','O(1)'),
    25:('O(nm)','O(1) plus result'),26:('O(n)','O(n)'),
    40:('O(n)','O(n)'),
}
QUEUE_BETTER_COST = {
    22:('O(n)','O(n)'),26:('O(n)','O(n)'),
    35:('O(n)','O(n) recursion'),36:('O(n)','O(n)'),37:('O(n)','O(n)'),
    43:('O(n log k)','O(k) plus result'),44:('O(n log n)','O(n)'),
    46:('O(n²)','O(1) plus result'),50:('O(n × capacity)','O(capacity) plus result'),
}

assert len(STRING_INVARIANTS)==len(STRING_OPTIMAL)==45
assert len(QUEUE_INVARIANTS)==len(QUEUE_OPTIMAL)==55
QUEUE_OPTIMAL[7] = ('O(n)', 'O(n) recursion')
QUEUE_OPTIMAL[19] = ('O(1) amortized per price', 'O(n)')

STRING_BASELINES = {
    1:'Use std::reverse',3:'Read every word with a stream',5:'Collect words and reverse their order',
    6:'Count each character by scanning again',7:'Erase each consumed character',
    10:'Count, sort, and emit characters',11:'Normalize and compare a reversed copy',
    12:'Try every possible deletion',14:'Collect and reverse the vowels',
    15:'Collect and reverse the letters',16:'Sort both strings',
    19:'Scan the existing groups for each word',22:'Recount every fixed window',
    23:'Recount recolors in each window',24:'Sort every candidate substring',
    25:'Sort every candidate substring',26:'Scan each distinct substring',
    27:'Try all candidate intervals',28:'Check all candidate substrings',
    29:'Enumerate all substrings',30:'Enumerate candidate intervals',
    36:'Check each possible alignment',37:'Try each candidate period',
    38:'Compare the pattern at each text position',39:'Compare each proper prefix and suffix',
    40:'Compare repeated length-ten windows',42:'Check every word-aligned starting position',
    45:'Place each character by its zigzag period',
}
QUEUE_BASELINES = {
    **{n:'Scan the requested direction for each element' for n in (15,16,17,18,19,21)},
    22:'Enumerate every histogram interval',24:'Enumerate subarray minimums',
    25:'Enumerate subarray ranges',26:'Recompute both height boundaries',
    33:'Simulate every ticket turn in a queue',34:'Simulate sandwich turns in a queue',
    42:'Scan each window for its first negative',43:'Scan each window for its maximum',
    44:'Enumerate valid contiguous ranges',45:'Enumerate every subarray sum',
    50:'Keep the last capacity events',55:'Check each sea cell against every land cell',
}
STRING_INTERMEDIATES = {
    6:'Count characters in a hash map',10:'Order frequency groups with a heap',
    16:'Count characters in a hash map',19:'Group sorted keys in a hash map',
    22:'Query fixed windows with prefix counts',23:'Query recolors with prefix counts',
    24:'Recompute frequency counts for each window',
    25:'Recompute frequency counts for each window',
    26:'Keep a set of distinct window characters',
    27:'Recompute the most frequent window character',
    37:'Test periodicity using the doubled string',
    40:'Count repeated windows in a hash map',
}
QUEUE_INTERMEDIATES = {
    22:'Find left and right boundaries separately',26:'Precompute left and right wall maxima',
    35:'Reverse by recursive queue removal',36:'Copy the queue to an indexable deque',
    37:'Interleave from a copied vector',43:'Maintain a multiset of window values',
    44:'Maintain a multiset of window extremes',
    46:'Rescan the stream prefix after each arrival',
    47:'Store recent requests in a deque',48:'Track unfilled slots in a deque',
    50:'Erase the oldest vector element on overflow',
    53:'Store arrival time with every queue cell',
}


def format_cpp(code: str) -> str:
    """Insert line breaks around C++ delimiters without changing any tokens."""
    if APPENDIX_MARKER in code:
        code = code[:code.index('/*\n' + APPENDIX_MARKER)].rstrip() + '\n'
    code = code.replace('\r\n', '\n')
    lines, segment = [], []
    indent = parens = 0
    quote = None
    escape = False

    def flush():
        chunk = ''.join(segment).strip()
        segment.clear()
        if chunk:
            if chunk.startswith(('public:', 'private:', 'protected:')) and chunk.count(':', 0, 11):
                label, _, tail = chunk.partition(':')
                lines.append('    ' * max(0, indent - 1) + label + ':')
                if tail.strip():
                    lines.append('    ' * indent + tail.strip())
            else:
                lines.append('    ' * indent + chunk)

    for char in code:
        if quote:
            segment.append(char)
            if escape:
                escape = False
            elif char == '\\':
                escape = True
            elif char == quote:
                quote = None
            continue
        if char in ('"', "'"):
            quote = char
            segment.append(char)
        elif char == '(':
            parens += 1
            segment.append(char)
        elif char == ')':
            parens -= 1
            segment.append(char)
        elif char == '{':
            segment.append(char)
            flush()
            indent += 1
        elif char == '}':
            flush()
            indent = max(0, indent - 1)
            segment.append(char)
            flush()
        elif char == ';' and parens == 0:
            segment.append(char)
            flush()
        elif char == '\n':
            flush()
        else:
            segment.append(char)
    flush()
    formatted = '\n'.join(lines) + '\n'
    # A brace followed by a semicolon belongs to a class/initializer closure.
    return formatted.replace('\n;\n', ';\n')


def approach_data(item, builder, is_string):
    index = item['index']
    optimal = (STRING_OPTIMAL if is_string else QUEUE_OPTIMAL)[index-1]
    brute = (STRING_BRUTE_COST if is_string else QUEUE_BRUTE_COST).get(index,optimal)
    better = (STRING_BETTER_COST if is_string else QUEUE_BETTER_COST).get(index,optimal)
    if index not in builder.B:
        brute = optimal
    if index not in builder.BETTER:
        better = optimal
    core = item['concepts'].split(';')[0].strip().lower()
    baselines=STRING_BASELINES if is_string else QUEUE_BASELINES
    intermediates=STRING_INTERMEDIATES if is_string else QUEUE_INTERMEDIATES
    return [
        {'level':'brute_force','name':baselines.get(index,'Direct alternative: '+core) if index in builder.B else 'Same efficient method (no distinct baseline)',
         'time':brute[0],'space':brute[1]},
        {'level':'better','name':intermediates.get(index,'Intermediate: '+core) if index in builder.BETTER else 'Same efficient method (no distinct intermediate)',
         'time':better[0],'space':better[1]},
        {'level':'optimal','name':core[:1].upper()+core[1:]+' reference','time':optimal[0],'space':optimal[1]},
    ]


def problem_number(item):
    match = re.match(r'LC_(\d+)_',Path(item['folder']).name)
    return int(match.group(1)) if match else None


def metadata_for(item,builder,is_string):
    return {
        'platform':item['platform'], 'problem_number':problem_number(item),
        'title':item['title'], 'study_difficulty':item['difficulty'],
        'main_topic':'Strings' if is_string else 'Stacks and Queues',
        'pattern_number':int(item['category'][:2]),
        'pattern':item['category'][3:].replace('_',' '),
        'signature':item['signature'],
        'recognition_cue':item['goal'],
        'invariant':(STRING_INVARIANTS if is_string else QUEUE_INVARIANTS)[item['index']-1],
        'approaches':approach_data(item,builder,is_string),
        'original_attempt_captured':False,
        'source_handbook':'Strings curriculum' if is_string else 'Stacks and Queues curriculum',
        'url':item['url'],'module_index':item['index'],
        'concepts':item['concepts'],'prerequisites':item['prerequisites'],
    }


def readme_for(item,data):
    number=data['problem_number'] if data['problem_number'] is not None else '—'
    table='\n'.join(
        f"| {label} | {row['name']} | {row['time']} | {row['space']} |"
        for label,row in zip(('Brute force','Better','Optimal'),data['approaches'])
    )
    contract=item.get('contract','')
    if item['folder'].startswith('04_Stacks_and_Queues/'):
        source=load_builder('create_stacks_queues_curriculum.py')
        contract=source.PROBLEMS[item['index']-1]['contract'] or contract
    if not contract:
        existing=(ROOT/item['folder']/'README.md').read_text()
        if '\n## Exercise contract\n\n' in existing:
            contract=existing.split('\n## Exercise contract\n\n',1)[1].split('\n## ',1)[0].strip()
    return f'''# {item['platform']}: {item['title']}

[Explained solution, worked trace, and local test command](solution.md) · [Live problem]({item['url']})

## Problem summary

{contract or item['goal']}

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | {item['platform']} |
| Problem number | {number} |
| Study difficulty | {item['difficulty']} |
| Main topic | {data['main_topic']} |
| Pattern | {data['pattern']} |
| Starter signature | `{item['signature']}` |

## Recognition cue

{data['recognition_cue']}

## Invariant

{data['invariant']}

## Prerequisites

{item['prerequisites']}.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
{table}

The levels compare actual code. Some basic exercises reuse the efficient approach when a separate intermediate algorithm would only be artificial. Time/space use the assumptions in the live prompt; `n` is input length unless the problem says otherwise. Output memory is listed separately where relevant.

## Files

- `01_original_attempt.cpp` — your exact learner starter; do not replace it with reference code.
- `02_brute_force.cpp` — baseline or explicitly identified identical efficient method.
- `03_better_approach.cpp` — intermediate tradeoff where meaningful.
- `04_optimal_solution.cpp` — preferred reference under the local contract.
- `mistakes.md` — your own error log, kept separate from generated notes.
- `testcases.md` — starter cases and space for your personal cases.
- `revision_notes.md` — pattern reminder and blank spaced-review log.
- `metadata.json` — machine-readable classification and approach costs.

## Attempt protocol

Read the live prompt, add two of your own tests, and attempt it in `01_original_attempt.cpp` before reading the [explained reference](solution.md). Record only mistakes you actually made.
'''


SPECIAL_TRACES = {
    ('02_Strings',24):'In `eidbaooo`, the two-character window `ba` has the same counts as `ab`, so the result becomes true.',
    ('02_Strings',28):'In `ADOBECODEBANC`, `BANC` covers A, B, and C and is shorter than earlier covering windows.',
    ('02_Strings',38):'In `abcab`, the pattern `ab` starts at positions 0 and 3; the prefix table avoids forgetting a possible overlapping start.',
    ('04_Stacks_and_Queues',15):'For [2,1,4,3], the nearest larger value to the right of 2 and 1 is 4; neither 4 nor 3 has one.',
    ('04_Stacks_and_Queues',22):'For heights [2,1,5,6,2,3], the bars 5 and 6 cover width two at height five, giving area ten.',
    ('04_Stacks_and_Queues',43):'For the first size-three window [1,3,-1], the maximum is 3; expired indices leave before each next output.',
    ('04_Stacks_and_Queues',53):'With one initially rotten cell, all adjacent fresh cells enter the first time layer; cells reached from them enter later layers.',
}


def solution_for(item,data,module):
    refs=data['approaches']
    case=item['tests'][0]
    extra=SPECIAL_TRACES.get((module,item['index']),
        f'Start from the first example `{case}`. After each input step, check: {data["invariant"]} '
        'The next loop step updates that state before the final result is reported.')
    examples='\n'.join(f'| `{case.split(" -> ")[0]}` | `{case.split(" -> ")[-1]}` |' for case in item['tests'])
    approaches='\n'.join(f"- **{label}:** {row['name']}. Time {row['time']}; extra space {row['space']}."
                         for label,row in zip(('Brute force','Better','Optimal'),refs))
    runner='strings' if module=='02_Strings' else 'queues'
    return f'''# {item['title']} — explained solution

## Input and result

```cpp
{item['signature']}
```

Follow the [live problem]({item['url']}) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

{item['goal']} The useful state is: {data['invariant']}

## Worked trace

{extra}

The first local case is `{case}`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

{data['invariant']} The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

{approaches}

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
{examples}

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module {runner} --problem {Path(item['folder']).name} --sanitize`.
'''


def revision_for(item,data):
    approach=data['approaches'][-1]
    return f'''# Revision Notes

## One-line trigger

{data['recognition_cue']}

## State or invariant to remember

{data['invariant']}

## Optimal approach

**{approach['name']}**

- Time: `{approach['time']}`
- Extra space: `{approach['space']}`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: {data['pattern']}
Maintain: {data['invariant']}
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
'''


def testcases_for(item):
    examples='\n\n'.join(
        f'## {i}. Starter case\n\n```text\n{case}\n```'
        for i,case in enumerate(item['tests'],1)
    )
    return f'''# Test Cases

{examples}

## Your own cases

{len(item['tests'])+1}. [add your own case]
{len(item['tests'])+2}. [add your own case]

## Edge-case checklist

- Smallest valid input, including empty/single-element only when the platform permits it
- Duplicate values or repeated characters
- Missing valid result when allowed
- First and last positions, all equal values, or window boundaries
- Maximum permitted size and integer limits

The examples are starter checks. Confirm the live problem's input/output convention before submitting.
'''


def appendix_for(item,data,code,filename):
    # Reuse the executable-line explanations and glossary conventions of Arrays.
    arrays=load_builder('add_detailed_cpp_comments.py')
    position=('02_brute_force.cpp','03_better_approach.cpp','04_optimal_solution.cpp').index(filename)
    approach=data['approaches'][position]
    pattern_fact=(f'The preferred pattern uses this invariant: {data["invariant"]}'
                  if position != 2 and not approach['name'].startswith('Same efficient')
                  else f'The maintained fact is: {data["invariant"]}')
    lines=arrays.clean_code_for_walkthrough(code)
    walkthrough='\n'.join(f'{n}. `{line}`\n   {arrays.explain_line(line)}' for n,line in enumerate(lines,1))
    terms=arrays.glossary_keys(code)
    glossary='\n'.join(f'- {term}: {arrays.GLOSSARY[term]}' for term in terms)
    is_class=item['signature'].startswith('class ')
    signature=('- This is a design class. Its declared public methods form the local exercise interface.\n'
               '- The judge calls each operation separately; use the problem README for empty/capacity behavior.'
               if is_class else
               f'- `{item["signature"].split(" ",1)[0]}` is the return type.\n'
               '- References (`&`) name the caller’s object; copying by value uses separate storage.')
    return f'''/*
{APPENDIX_MARKER}
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: {item['title']}
Platform: {item['platform']}
Pattern: {data['pattern']}

Learning goal: {item['goal']}
This file implements: {approach['name']}.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`{item['signature']}`
{signature}
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
{pattern_fact}

Read these executable lines in their actual order. Nested indentation shows when
an action belongs to a class, method, branch, loop, or lambda:

{walkthrough}

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
{glossary or '- The class and function signatures define the exercise interface.'}

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: {item['tests'][0]}
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. {pattern_fact}
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: {approach['time']}.
- Extra space: {approach['space']}.
- `n` means input length, `k` a window/capacity where used, `w` a word count,
  `L` word length, and `A` alphabet size. Design problems state per-operation
  costs. Recursive frames count; returned output storage may be additional.

8. EDGE CASES TO CHECK
----------------------
- Smallest valid input; empty access only when explicitly permitted.
- Repeated or equal values and strict versus nonstrict comparisons.
- The first and final valid indexes or a result that does not exist.
- Signed values and arithmetic near the declared input limits.

9. COMMON MISTAKES
------------------
- Failing to restore popped items or losing their relative order.
- Assuming an STL pop operation returns the removed value.
- Forgetting an element's index when the question asks for distance or range.
- Omitting recursion or auxiliary containers from space analysis.
- Claiming a live-platform signature without checking its current contract.

10. HOW TO STUDY THIS SOLUTION
------------------------------
1. Hide the code and describe the saved state in a sentence.
2. Explain each line and trace at least one counterexample without executing.
3. Compare all three files and their actual time/space tradeoffs.
4. Recode from memory and record your own failure in mistakes.md.

This explanatory comment does not change the C++ program's behavior.
*/
'''


def expected_reference(item,builder,filename):
    index=item['index']
    body=({'02_brute_force.cpp':builder.B.get(index,builder.O[index]),
           '03_better_approach.cpp':builder.BETTER.get(index,builder.O[index]),
           '04_optimal_solution.cpp':builder.O[index]})[filename]
    header='#include <bits/stdc++.h>\nusing namespace std;\n\n'
    if item['signature'].startswith('class '):
        return header+body+'\n'
    return header+f'class Solution {{\npublic:\n    {item["signature"]} {{\n        {body}\n    }}\n}};\n'


def build():
    for module,script,is_string in (
        ('02_Strings','build_string_references.py',True),
        ('04_Stacks_and_Queues','build_stacks_queues_references.py',False),
    ):
        builder=load_builder(script)
        manifest_path=ROOT/module/'problem_manifest.json'
        manifest=json.loads(manifest_path.read_text())
        for item in manifest:
            folder=ROOT/item['folder']
            if item['platform']=='Repository exercise':
                item['url']='https://github.com/Soham-Moholkar/dsa-review-/blob/main/'+item['folder']+'/README.md'
            data=metadata_for(item,builder,is_string)
            (folder/'metadata.json').write_text(json.dumps(data,indent=2)+'\n')
            (folder/'README.md').write_text(readme_for(item,data))
            (folder/'solution.md').write_text(solution_for(item,data,module))
            notes=folder/'revision_notes.md'
            old=notes.read_text()
            if re.search(r'\| (?:First solve|2-day revision|1-week revision|1-month revision) \|\s*[^ |\n]',old):
                raise RuntimeError(f'Preserving user-authored revision date: {notes}')
            notes.write_text(revision_for(item,data))
            tests=folder/'testcases.md'
            old=tests.read_text()
            for case in item['tests']:
                if case not in old:
                    raise RuntimeError(f'Existing test case would be lost in {tests}: {case}')
            if old.count('[add your own case]') != 2:
                raise RuntimeError(f'Existing personal tests require manual migration: {tests}')
            tests.write_text(testcases_for(item))
            for filename in ('02_brute_force.cpp','03_better_approach.cpp','04_optimal_solution.cpp'):
                path=folder/filename
                code=format_cpp(path.read_text())
                expected=format_cpp(expected_reference(item,builder,filename))
                if code!=expected:
                    raise RuntimeError(f'Refusing to overwrite edited reference: {path}')
                path.write_text(code.rstrip()+'\n\n'+appendix_for(item,data,code,filename))
        manifest_path.write_text(json.dumps(manifest,indent=2)+'\n')
        print(f'Formatted {len(manifest)} {module} problems like Arrays/Vectors.')


if __name__=='__main__':
    build()
