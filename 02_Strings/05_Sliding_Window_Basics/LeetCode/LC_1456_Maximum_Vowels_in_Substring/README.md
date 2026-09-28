# LeetCode: Maximum Number of Vowels in a Substring of Given Length

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)

## Problem summary

Update one window statistic in constant time as the window slides.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 1456 |
| Study difficulty | Medium |
| Main topic | Strings |
| Pattern | Sliding Window Basics |
| Starter signature | `int maxVowels(string s, int k)` |

## Recognition cue

Update one window statistic in constant time as the window slides.

## Invariant

The running count covers exactly the current k-character window.

## Prerequisites

vowel membership; running counts.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Recount every fixed window | O(nk) | O(1) |
| Better | Query fixed windows with prefix counts | O(n) | O(n) |
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
