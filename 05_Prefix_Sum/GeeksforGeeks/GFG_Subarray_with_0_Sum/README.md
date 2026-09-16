# GeeksforGeeks: Subarray with 0 Sum

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return whether any non-empty contiguous subarray has sum zero.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Prefix Sum and Prefix Sum with Hashmap |

## Recognition cue

Equal prefix sums imply that the values between them sum to zero.

## Invariant

seen contains every prefix sum before the current position, including 0 before the array starts.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Enumerate all subarrays | O(n^2) | O(1) |
| Better | Store, sort, and compare prefix sums | O(n log n) | O(n) |
| Optimal | Prefix sum hash set | O(n) average | O(n) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
