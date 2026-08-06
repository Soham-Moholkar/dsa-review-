# LeetCode: Maximum Product Subarray

## Problem summary

Return the maximum product of a non-empty contiguous subarray.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 152 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Kadane's Algorithm |

## Recognition cue

A negative factor swaps the roles of maximum and minimum products.

## Invariant

maximumEnding and minimumEnding capture both sign possibilities ending at i.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Enumerate every product | O(n^2) | O(1) |
| Better | Bidirectional product scans | O(n) | O(1) |
| Optimal | Maximum/minimum ending states | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
