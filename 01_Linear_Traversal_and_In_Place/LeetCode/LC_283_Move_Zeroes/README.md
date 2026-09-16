# LeetCode: Move Zeroes

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Move all zero values to the end while preserving the relative order of non-zero values.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 283 |
| Study difficulty | Easy |
| Main topic | Arrays / Vectors |
| Pattern | Linear Traversal and In-Place Manipulation |

## Recognition cue

One pointer reads all values while another marks the next write position.

## Invariant

Indexes before j contain the processed non-zero values in their original order.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Use an additional result vector | O(n) | O(n) |
| Better | Overwrite non-zero values then fill zeroes | O(n) | O(1) |
| Optimal | Stable swap with read and write pointers | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
