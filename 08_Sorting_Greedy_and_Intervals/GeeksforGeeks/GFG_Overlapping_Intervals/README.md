# GeeksforGeeks: Overlapping Intervals

## Problem summary

Merge all overlapping intervals.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Sorting, Greedy Decisions, and Intervals |

## Recognition cue

Sorting by start places possible overlaps next to each other.

## Invariant

answer contains fully merged intervals, and only its last interval can overlap the current one.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Repeatedly merge any overlapping pair | O(n^3) | O(n) |
| Better | Sort and merge into answer | O(n log n) | O(n) |
| Optimal | Sorted one-pass interval merge | O(n log n) | O(n) answer |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
