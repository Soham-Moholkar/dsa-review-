# LeetCode: Find Peak Element

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return any peak index where the value is greater than its neighbours.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 162 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Binary Search |

## Recognition cue

A rising slope guarantees a peak to the right; a falling slope guarantees one at or left of mid.

## Invariant

A peak remains in the closed interval [left,right].

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Neighbour checks | O(n) | O(1) |
| Better | First falling edge | O(n) | O(1) |
| Optimal | Binary search on adjacent slope | O(log n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
