# GeeksforGeeks: Count Distinct Elements in Every Window

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the number of distinct values in every contiguous window of size k.

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

A sliding frequency map can update distinct count as values enter and leave.

## Invariant

frequency stores counts only for the current window.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Build a set for each window | O(n × k) | O(k) |
| Better | Sliding ordered map | O(n log k) | O(k) |
| Optimal | Sliding hashmap with zero-count erasure | O(n) average | O(k) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
