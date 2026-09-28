# LeetCode: Trapping Rain Water

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://leetcode.com/problems/trapping-rain-water/)

## Problem summary

Compare the stack boundary view with the two-pointer lesson in Arrays/Vectors.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 42 |
| Study difficulty | Hard |
| Main topic | Stacks and Queues |
| Pattern | Stack Range and Histogram |
| Starter signature | `int trap(vector<int>& height)` |

## Recognition cue

Compare the stack boundary view with the two-pointer lesson in Arrays/Vectors.

## Invariant

Popped valleys can hold water only after a left and right wall exist.

## Prerequisites

previous/next greater; two-pointer basics.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Recompute both height boundaries | O(n²) | O(1) |
| Better | Precompute left and right wall maxima | O(n) | O(n) |
| Optimal | Bounded ranges reference | O(n) | O(n) |

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
