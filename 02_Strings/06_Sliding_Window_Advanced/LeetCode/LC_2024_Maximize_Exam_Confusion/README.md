# LeetCode: Maximize the Confusion of an Exam

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/)

## Problem summary

Model a binary alphabet and decide whether one generic invariant or two passes is clearer.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 2024 |
| Study difficulty | Medium |
| Main topic | Strings |
| Pattern | Sliding Window Advanced |
| Starter signature | `int maxConsecutiveAnswers(string answerKey, int k)` |

## Recognition cue

Model a binary alphabet and decide whether one generic invariant or two passes is clearer.

## Invariant

The current window needs at most k changes to become all one chosen character.

## Prerequisites

replacement-window reasoning.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Enumerate candidate intervals | O(n²) | O(1) |
| Better | Same efficient method (no distinct intermediate) | O(n) | O(1) |
| Optimal | Variable window reference | O(n) | O(1) |

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
