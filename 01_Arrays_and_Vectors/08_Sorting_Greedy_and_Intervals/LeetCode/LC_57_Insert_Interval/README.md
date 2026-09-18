# LeetCode: Insert Interval

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Insert and merge a new interval into sorted non-overlapping intervals.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 57 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Sorting, Greedy Decisions, and Intervals |

## Recognition cue

Scan intervals before, overlapping with, and after the new interval.

## Invariant

The new interval grows to cover every overlap before it is appended.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Append, sort, merge | O(n log n) | O(n) |
| Better | Three-phase scan | O(n) | O(n) |
| Optimal | Linear insertion and merge | O(n) | O(n) answer |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
