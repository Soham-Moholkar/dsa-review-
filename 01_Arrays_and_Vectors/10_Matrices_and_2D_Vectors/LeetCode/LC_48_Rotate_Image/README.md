# LeetCode: Rotate Image

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Rotate a square matrix 90 degrees clockwise in place.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 48 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Matrices and Two-Dimensional Vectors |

## Recognition cue

Clockwise rotation equals transpose followed by reversing every row.

## Invariant

After transpose, each row contains a column of the original; reversing gives clockwise order.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Use an extra matrix | O(n^2) | O(n^2) |
| Better | Transpose and reverse rows | O(n^2) | O(1) |
| Optimal | In-place transpose plus row reversal | O(n^2) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
