# LeetCode: Longest Consecutive Sequence

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the longest length of consecutive integer values in an unsorted array.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 128 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Hashing and Frequency Counting |

## Recognition cue

Use existence rather than original order, and start only at sequence beginnings.

## Invariant

Every sequence is counted exactly once from its smallest value.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Repeated linear existence search | O(n^3) | O(1) |
| Better | Sort and scan | O(n log n) | O(log n) |
| Optimal | Hash set sequence starts | O(n) average | O(n) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
