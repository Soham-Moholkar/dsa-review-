# LeetCode: Find the Duplicate Number

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the repeated value in n+1 values drawn from 1 through n without modifying nums.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 287 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Index Placement and Cyclic Sort |

## Recognition cue

Treat each value as a next pointer; the duplicate creates a cycle entry.

## Invariant

Floyd’s first phase finds a meeting inside the cycle; the second finds its entry.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Compare every pair | O(n^2) | O(1) |
| Better | Hash set | O(n) average | O(n) |
| Optimal | Floyd cycle detection | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
