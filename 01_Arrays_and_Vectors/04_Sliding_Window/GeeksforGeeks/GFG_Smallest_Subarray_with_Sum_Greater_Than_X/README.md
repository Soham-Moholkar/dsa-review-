# GeeksforGeeks: Smallest Subarray with Sum Greater Than X

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the minimum length of a contiguous subarray whose sum is strictly greater than x.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Sliding Window |

## Recognition cue

With positive values, expanding increases sum and shrinking decreases it monotonically.

## Invariant

The current window is the candidate range ending at right; all shorter valid prefixes are tested by shrinking.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Try every start and end | O(n^2) | O(1) |
| Better | Prefix sums with binary search | O(n log n) | O(n) |
| Optimal | Variable sliding window | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
