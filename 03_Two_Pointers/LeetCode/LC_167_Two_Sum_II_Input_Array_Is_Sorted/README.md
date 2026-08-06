# LeetCode: Two Sum II - Input Array Is Sorted

## Problem summary

Return one-indexed positions of two values in a sorted array that sum to the target.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 167 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Two Pointers |

## Recognition cue

Sorted order makes endpoint movement monotonic.

## Invariant

The answer, if not found, remains between left and right.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Compare all pairs | O(n^2) | O(1) |
| Better | Binary search the complement | O(n log n) | O(1) |
| Optimal | Opposite-end two pointers | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
