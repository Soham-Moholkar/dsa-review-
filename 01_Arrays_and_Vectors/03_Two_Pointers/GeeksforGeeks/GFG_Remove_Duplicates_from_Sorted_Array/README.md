# GeeksforGeeks: Remove Duplicates from Sorted Array

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Compress a sorted array so its first returned-length elements are unique.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Easy |
| Main topic | Arrays / Vectors |
| Pattern | Two Pointers |

## Recognition cue

Equal values are adjacent, so one read pointer and one unique-write pointer are enough.

## Invariant

Indexes 0 through j contain all unique values found so far.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Use an ordered set and copy back | O(n log n) | O(n) |
| Better | Use a separate unique vector | O(n) | O(n) |
| Optimal | Read/write two pointers | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
