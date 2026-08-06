# GeeksforGeeks: Maximum Circular Subarray Sum

## Problem summary

Return the maximum sum of a non-empty contiguous subarray in a circular array.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Hard |
| Main topic | Arrays / Vectors |
| Pattern | Kadane's Algorithm |

## Recognition cue

The best circular range equals total sum minus the minimum middle subarray.

## Invariant

Normal Kadane covers non-wrapping ranges; total-minimum covers wrapping ranges.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Enumerate circular starts and lengths | O(n^2) | O(1) |
| Better | Duplicate array and bound subarray length | O(n^2) | O(n) |
| Optimal | Maximum Kadane plus total minus minimum Kadane | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
