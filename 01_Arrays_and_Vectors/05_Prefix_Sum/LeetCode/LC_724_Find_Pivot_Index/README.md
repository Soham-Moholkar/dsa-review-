# LeetCode: Find Pivot Index

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the first zero-based index whose left sum equals its right sum.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 724 |
| Study difficulty | Easy |
| Main topic | Arrays / Vectors |
| Pattern | Prefix Sum and Prefix Sum with Hashmap |

## Recognition cue

The index value itself belongs to neither side.

## Invariant

leftSum covers elements before i; totalSum after subtraction covers elements after i.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Recalculate both sides | O(n^2) | O(1) |
| Better | Prefix sum array | O(n) | O(n) |
| Optimal | Total sum and left sum | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
