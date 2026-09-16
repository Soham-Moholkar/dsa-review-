# GeeksforGeeks: Chocolate Distribution Problem

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Choose m packet sizes so the difference between maximum and minimum is minimized.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Easy |
| Main topic | Arrays / Vectors |
| Pattern | Sorting, Greedy Decisions, and Intervals |

## Recognition cue

After sorting, an optimal chosen group appears as a contiguous window of size m.

## Invariant

Each scanned sorted window represents a candidate group with smallest and largest at its ends.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Enumerate subsets recursively | Exponential | O(n) recursion stack |
| Better | Sort and test all m-sized windows | O(n log n) | O(log n) |
| Optimal | Sorted fixed-size greedy window | O(n log n) | O(log n) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
