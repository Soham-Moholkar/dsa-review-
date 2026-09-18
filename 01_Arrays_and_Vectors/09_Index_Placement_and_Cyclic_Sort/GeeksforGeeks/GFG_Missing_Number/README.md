# GeeksforGeeks: Missing Number

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

The array contains n-1 distinct values from 1 through n; return the missing value.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Easy |
| Main topic | Arrays / Vectors |
| Pattern | Index Placement and Cyclic Sort |

## Recognition cue

The value range is complete except for one number.

## Invariant

XOR cancellation leaves exactly the missing value.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Test every candidate | O(n^2) | O(1) |
| Better | Sort and find first mismatch | O(n log n) | O(log n) |
| Optimal | XOR full range and values | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
