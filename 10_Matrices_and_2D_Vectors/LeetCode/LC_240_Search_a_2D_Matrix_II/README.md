# LeetCode: Search a 2D Matrix II

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Search a matrix sorted left-to-right in rows and top-to-bottom in columns.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 240 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Matrices and Two-Dimensional Vectors |

## Recognition cue

Top-right comparison eliminates one complete row or column.

## Invariant

All remaining candidates lie in the rectangle below and left of the current cell.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Scan every cell | O(r × c) | O(1) |
| Better | Binary search each row | O(r log c) | O(1) |
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
