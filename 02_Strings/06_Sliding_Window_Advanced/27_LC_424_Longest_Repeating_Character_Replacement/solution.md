# Longest Repeating Character Replacement — reference discussion

## Contract

`int characterReplacement(string s, int k)` — [LeetCode problem](https://leetcode.com/problems/longest-repeating-character-replacement/). Verify the current live editor's signature before submission.

## Recognition cue

Express validity as window length minus its most frequent character count.

## Approach progression

| File | Role |
|---|---|
| [Brute force](02_brute_force.cpp) | direct baseline |
| [Better](03_better.cpp) | intermediate alternative |
| [Optimal](04_optimal.cpp) | efficient reference |

The levels are comparison slots; a separate intermediate algorithm is not invented when it would only duplicate another method. Work through the first case in `test_cases.txt` by hand, tracking the state named in the code. The input contract and edge cases in the live statement take precedence over example formatting here.

Reference availability is separate from your own original attempt and revision history.

## Examples in the starter

These are learning cases from `test_cases.txt`, not platform acceptance records.

- `"ABAB", 2 -> 4`
- `"AABABBA", 1 -> 4`
- `"AAAA", 0 -> 4`

## Check yourself

1. Explain the cue: Express validity as window length minus its most frequent character count.
2. Trace one case above through each actual C++ implementation. Note when an approach uses the same algorithm as another; that is an honest absence of a distinct intermediate method.
3. State the invariant and derive time and auxiliary-space costs from the loops and containers in each file. Recursion also consumes stack space.
4. Add a counterexample in [mistakes.md](mistakes.md), then recode without looking at the reference.
5. Record your own dates in [revision notes](revision_notes.md).

Run `python3 scripts/test_curriculum_references.py --module strings --sanitize` from the repository root to check the supplied reference implementations.
