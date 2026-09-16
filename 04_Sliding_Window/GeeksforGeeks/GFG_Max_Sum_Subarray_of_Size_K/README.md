# GeeksforGeeks: Max Sum Subarray of Size K

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the maximum sum among all contiguous subarrays containing exactly K elements.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Easy |
| Main topic | Arrays / Vectors |
| Pattern | Sliding Window |

## Recognition cue

The subarray size is fixed, so each new window differs by one incoming and one outgoing value.

## Invariant

windowSum is the sum of the current K-element window.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Recalculate every window | O(n × k) | O(1) |
| Better | Prefix sums | O(n) | O(n) |
| Optimal | Fixed sliding window | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
