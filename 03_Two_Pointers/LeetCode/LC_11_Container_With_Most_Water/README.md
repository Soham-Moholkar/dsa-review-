# LeetCode: Container With Most Water

## Problem summary

Choose two vertical lines that form the container with maximum area.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 11 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Two Pointers |

## Recognition cue

Width shrinks each step, so only moving the shorter boundary can possibly improve height.

## Invariant

Every discarded pair using the shorter boundary cannot beat a future pair with that same boundary.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Check every pair | O(n^2) | O(1) |
| Better | Two pointers | O(n) | O(1) |
| Optimal | Two pointers with equal-height skip | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
