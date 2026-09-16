# GeeksforGeeks: Insert and Merge Interval

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Insert a new interval into sorted non-overlapping intervals and merge overlaps.

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

Intervals fall into before, overlapping, and after groups.

## Invariant

All intervals already added are finalized and lie before the current merged new interval.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Append, sort, then merge all | O(n log n) | O(n) |
| Better | Three-phase linear insertion | O(n) | O(n) |
| Optimal | Single linear merge around new interval | O(n) | O(n) answer |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
