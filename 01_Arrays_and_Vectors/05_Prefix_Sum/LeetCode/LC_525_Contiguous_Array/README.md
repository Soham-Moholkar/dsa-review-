# LeetCode: Contiguous Array

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the longest contiguous subarray containing equal numbers of zeroes and ones.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 525 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Prefix Sum and Prefix Sum with Hashmap |

## Recognition cue

Treat 0 as -1; then equal counts correspond to a zero-sum subarray.

## Invariant

firstIndex stores the earliest position for each transformed prefix sum.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Count zeroes and ones for every subarray | O(n^2) | O(1) |
| Better | Ordered map of transformed prefixes | O(n log n) | O(n) |
| Optimal | Hashmap of earliest transformed prefixes | O(n) average | O(n) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
