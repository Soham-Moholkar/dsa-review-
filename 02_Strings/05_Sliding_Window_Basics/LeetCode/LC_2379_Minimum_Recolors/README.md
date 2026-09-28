# LeetCode: Minimum Recolors to Get K Consecutive Black Blocks

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/)

## Problem summary

Interpret the cost of a candidate substring as the count of characters that must change.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 2379 |
| Study difficulty | Easy |
| Main topic | Strings |
| Pattern | Sliding Window Basics |
| Starter signature | `int minimumRecolors(string blocks, int k)` |

## Recognition cue

Interpret the cost of a candidate substring as the count of characters that must change.

## Invariant

The count of white blocks equals the recolors needed for the current window.

## Prerequisites

running counts; min.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Recount recolors in each window | O(nk) | O(1) |
| Better | Query recolors with prefix counts | O(n) | O(n) |
| Optimal | Fixed window reference | O(n) | O(1) |

The levels compare actual code. Some basic exercises reuse the efficient approach when a separate intermediate algorithm would only be artificial. Time/space use the assumptions in the live prompt; `n` is input length unless the problem says otherwise. Output memory is listed separately where relevant.

## Files

- `01_original_attempt.cpp` — your exact learner starter; do not replace it with reference code.
- `02_brute_force.cpp` — baseline or explicitly identified identical efficient method.
- `03_better_approach.cpp` — intermediate tradeoff where meaningful.
- `04_optimal_solution.cpp` — preferred reference under the local contract.
- `mistakes.md` — your own error log, kept separate from generated notes.
- `testcases.md` — starter cases and space for your personal cases.
- `revision_notes.md` — pattern reminder and blank spaced-review log.
- `metadata.json` — machine-readable classification and approach costs.

## Attempt protocol

Read the live prompt, add two of your own tests, and attempt it in `01_original_attempt.cpp` before reading the [explained reference](solution.md). Record only mistakes you actually made.
