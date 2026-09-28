# Basic Calculator II — reference discussion

## Contract

`int calculate(string s)` — [LeetCode problem](https://leetcode.com/problems/basic-calculator-ii/). The live judge may use a different C++ method name or parameters; adapt a copy of your code, not the first attempt.

## Recognition cue

Contrast operator precedence in infix with the immediate operand order of postfix.

## Approach progression

| File | Role |
|---|---|
| [Brute force](02_brute_force.cpp) | Same efficient method; no distinct baseline recorded |
| [Better](03_better.cpp) | Same efficient method; no distinct intermediate recorded |
| [Optimal](04_optimal.cpp) | Efficient reference |

For a concrete dry run, trace the first case in `test_cases.txt` and identify what state each container stores. Approach labels are not a promise that all three slots have different complexity; avoid inventing an algorithm to fill a slot.

Reference availability never represents personal completion or mastery.

## Examples in the starter

These are learning cases from `test_cases.txt`, not platform acceptance records.

- `"3+2*2" -> 7`
- `" 3/2 " -> 1`
- `" 3+5 / 2 " -> 5`

## Check yourself

1. Explain the cue: Contrast operator precedence in infix with the immediate operand order of postfix.
2. Trace one case above through each actual C++ implementation. Note when an approach uses the same algorithm as another; that is an honest absence of a distinct intermediate method.
3. State the invariant and derive time and auxiliary-space costs from the loops and containers in each file. Recursion also consumes stack space.
4. Add a counterexample in [mistakes.md](mistakes.md), then recode without looking at the reference.
5. Record your own dates in [revision notes](revision_notes.md).

Run `python3 scripts/test_curriculum_references.py --module queues --sanitize` from the repository root to check the supplied reference implementations.
