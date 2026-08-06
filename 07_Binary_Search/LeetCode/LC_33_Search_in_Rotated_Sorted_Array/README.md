# LeetCode: Search in Rotated Sorted Array

## Problem summary

Return target index in a rotated sorted array of distinct values.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 33 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Binary Search |

## Recognition cue

One side of mid is always sorted.

## Invariant

The retained side is the only side that can still contain target.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Linear search | O(n) | O(1) |
| Better | Pivot plus binary search | O(log n) | O(1) |
| Optimal | One modified binary search | O(log n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
