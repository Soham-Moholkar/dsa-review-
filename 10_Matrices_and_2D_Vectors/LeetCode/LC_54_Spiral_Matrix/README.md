# LeetCode: Spiral Matrix

## Problem summary

Return all matrix values in clockwise spiral order.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 54 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Matrices and Two-Dimensional Vectors |

## Recognition cue

Shrink four boundaries after traversing each side.

## Invariant

The unvisited region is exactly the rectangle bounded by top,bottom,left,right.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Visited simulation | O(r × c) | O(r × c) |
| Better | Boundary traversal | O(r × c) | O(1) excluding answer |
| Optimal | Four-boundary spiral | O(r × c) | O(1) excluding answer |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
