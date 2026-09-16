# LeetCode: Next Permutation

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Transform nums into the lexicographically next permutation, or the smallest permutation if none exists.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 31 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Sorting, Greedy Decisions, and Intervals |

## Recognition cue

Find the rightmost ascent, swap with the smallest greater suffix value, then reverse the suffix.

## Invariant

The suffix after the pivot is non-increasing and can be reversed into its smallest order.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Generate and sort every permutation | O(n! × n) | O(n! × n) |
| Better | Use the standard library operation | O(n) | O(1) |
| Optimal | Manual pivot, successor, and suffix reversal | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
