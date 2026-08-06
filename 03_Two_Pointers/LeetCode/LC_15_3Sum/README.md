# LeetCode: 3Sum

## Problem summary

Return all unique triplets whose values sum to zero.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 15 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Two Pointers |

## Recognition cue

After sorting, fixing one value reduces the remaining search to a two-pointer pair sum.

## Invariant

For each fixed i, left and right search the only remaining range and duplicates are skipped.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Check every triplet and deduplicate with a set | O(n^3 log n) | O(number of answers) |
| Better | Fix two values and use a hash set | O(n^2) average | O(n) |
| Optimal | Sort, fix one value, and use two pointers | O(n^2) | O(1) excluding answer |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
