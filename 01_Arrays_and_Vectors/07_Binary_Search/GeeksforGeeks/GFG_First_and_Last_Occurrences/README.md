# GeeksforGeeks: First and Last Occurrences

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the first and last index of x in a sorted array, or {-1,-1}.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Binary Search |

## Recognition cue

A found value is not enough; continue searching toward one boundary.

## Invariant

Each binary search records a candidate and then narrows toward the required side.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Linear scan | O(n) | O(1) |
| Better | lower_bound and upper_bound | O(log n) | O(1) |
| Optimal | Two boundary binary searches | O(log n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
