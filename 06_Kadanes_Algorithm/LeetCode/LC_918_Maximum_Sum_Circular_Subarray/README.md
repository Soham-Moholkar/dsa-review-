# LeetCode: Maximum Sum Circular Subarray

## Problem summary

Return the maximum non-empty subarray sum when the array wraps circularly.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 918 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Kadane's Algorithm |

## Recognition cue

Compare a normal maximum with total sum minus the minimum subarray.

## Invariant

Both maximum and minimum Kadane states are updated over the same prefix.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Enumerate circular starts and lengths | O(n^2) | O(1) |
| Better | Duplicate and enumerate bounded ranges | O(n^2) | O(n) |
| Optimal | Maximum and minimum Kadane | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
