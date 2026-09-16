# LeetCode: Remove Duplicates from Sorted Array

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Place unique values in the first k positions of a sorted array and return k.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 26 |
| Study difficulty | Easy |
| Main topic | Arrays / Vectors |
| Pattern | Two Pointers |

## Recognition cue

A write pointer advances only when a new distinct value is read.

## Invariant

nums[0..j] contains the unique prefix.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Use a set | O(n log n) | O(n) |
| Better | Use an extra vector | O(n) | O(n) |
| Optimal | Two pointers | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
