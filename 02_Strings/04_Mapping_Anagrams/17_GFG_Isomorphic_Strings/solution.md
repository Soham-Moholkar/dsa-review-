# Isomorphic Strings — reference discussion

## Contract

`bool isIsomorphic(string s, string t)` — [GeeksforGeeks problem](https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1). Verify the current live editor's signature before submission.

## Recognition cue

Enforce a one-to-one mapping in both directions rather than checking only one direction.

## Approach progression

| File | Role |
|---|---|
| [Brute force](02_brute_force.cpp) | same efficient approach (no distinct baseline recorded) |
| [Better](03_better.cpp) | same efficient approach (no distinct intermediate recorded) |
| [Optimal](04_optimal.cpp) | efficient reference |

The levels are comparison slots; a separate intermediate algorithm is not invented when it would only duplicate another method. Work through the first case in `test_cases.txt` by hand, tracking the state named in the code. The input contract and edge cases in the live statement take precedence over example formatting here.

Reference availability is separate from your own original attempt and revision history.

## Examples in the starter

These are learning cases from `test_cases.txt`, not platform acceptance records.

- `"egg", "add" -> true`
- `"foo", "bar" -> false`
- `"badc", "baba" -> false`

## Check yourself

1. Explain the cue: Enforce a one-to-one mapping in both directions rather than checking only one direction.
2. Trace one case above through each actual C++ implementation. Note when an approach uses the same algorithm as another; that is an honest absence of a distinct intermediate method.
3. State the invariant and derive time and auxiliary-space costs from the loops and containers in each file. Recursion also consumes stack space.
4. Add a counterexample in [mistakes.md](mistakes.md), then recode without looking at the reference.
5. Record your own dates in [revision notes](revision_notes.md).

Run `python3 scripts/test_curriculum_references.py --module strings --sanitize` from the repository root to check the supplied reference implementations.
