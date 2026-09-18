# LeetCode: Subarray Sum Equals K

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Count contiguous subarrays whose sum equals k.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 560 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Prefix Sum and Prefix Sum with Hashmap |

## Recognition cue

Each current prefix needs the frequency of prefixSum-k from earlier positions.

## Invariant

frequency contains all prior prefix sums and their occurrence counts.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Enumerate all subarrays | O(n^2) | O(1) |
| Better | Ordered map of prefix frequencies | O(n log n) | O(n) |
| Optimal | Unordered-map prefix frequencies | O(n) average | O(n) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
