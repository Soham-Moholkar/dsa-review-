# LeetCode: Best Time to Buy and Sell Stock

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the best profit from one buy and one later sell.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 121 |
| Study difficulty | Easy |
| Main topic | Arrays / Vectors |
| Pattern | Kadane's Algorithm |

## Recognition cue

The best purchase for today is the minimum price seen earlier.

## Invariant

minimumPrice and maximumProfit summarize all days processed so far.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Try all transactions | O(n^2) | O(1) |
| Better | Suffix maximum | O(n) | O(n) |
| Optimal | Minimum-so-far scan | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
