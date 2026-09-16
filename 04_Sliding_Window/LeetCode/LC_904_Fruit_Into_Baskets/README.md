# LeetCode: Fruit Into Baskets

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the longest contiguous subarray containing at most two distinct values.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 904 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Sliding Window |

## Recognition cue

The two baskets translate directly to a window with at most two distinct types.

## Invariant

The current window contains no more than two keys in the frequency map.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Check every starting index | O(n^2) | O(1) distinct keys |
| Better | Sliding frequency map | O(n) average | O(1) distinct keys |
| Optimal | Two-type sliding window | O(n) average | O(1) distinct keys |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
