# GeeksforGeeks: Search in a Row-Column Sorted Matrix

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return whether x exists in a matrix sorted across every row and column.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Matrices and Two-Dimensional Vectors |

## Recognition cue

From the top-right corner, one comparison eliminates a full row or column.

## Invariant

The remaining candidate rectangle lies below and left of the current position.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Check every cell | O(r × c) | O(1) |
| Better | Binary search every row | O(r log c) | O(1) |
| Optimal | Top-right staircase search | O(r+c) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
