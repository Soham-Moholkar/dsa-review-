# GeeksforGeeks: Smallest Positive Missing Number

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the smallest positive integer absent from an unsorted array.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Hard |
| Main topic | Arrays / Vectors |
| Pattern | Index Placement and Cyclic Sort |

## Recognition cue

Only values 1 through n can affect the first missing positive answer.

## Invariant

After cyclic placement, value x should be at index x-1 whenever it is present and valid.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Store values in a set and scan positives | O(n) | O(n) |
| Better | Sort and scan | O(n log n) | O(log n) |
| Optimal | Cyclic placement | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
