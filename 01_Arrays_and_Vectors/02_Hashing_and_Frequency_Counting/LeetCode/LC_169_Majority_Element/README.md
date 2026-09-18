# LeetCode: Majority Element

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the majority element, which is guaranteed to exist.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 169 |
| Study difficulty | Easy |
| Main topic | Arrays / Vectors |
| Pattern | Hashing and Frequency Counting |

## Recognition cue

Pairwise cancellation leaves the value that occurs more than half the time.

## Invariant

candidate is the surviving value after cancelling different values in the processed prefix.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Count each value | O(n^2) | O(1) |
| Better | Frequency hashmap | O(n) average | O(n) |
| Optimal | Boyer-Moore voting | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
