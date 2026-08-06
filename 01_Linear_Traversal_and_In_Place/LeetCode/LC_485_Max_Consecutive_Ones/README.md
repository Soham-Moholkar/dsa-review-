# LeetCode: Max Consecutive Ones

## Problem summary

Return the maximum number of consecutive 1 values in a binary array.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 485 |
| Study difficulty | Easy |
| Main topic | Arrays / Vectors |
| Pattern | Linear Traversal and In-Place Manipulation |

## Recognition cue

A running streak resets whenever the required value is broken.

## Invariant

currentCount is the streak ending at i; maximumCount is the best streak seen anywhere.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Start a streak from every index | O(n^2) | O(1) |
| Better | Single scan with explicit reset | O(n) | O(1) |
| Optimal | Single scan streak state | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
