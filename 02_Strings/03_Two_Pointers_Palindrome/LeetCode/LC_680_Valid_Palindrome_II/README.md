# LeetCode: Valid Palindrome II

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://leetcode.com/problems/valid-palindrome-ii/)

## Problem summary

Branch only at the first mismatch and test the two meaningful remaining ranges.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 680 |
| Study difficulty | Easy |
| Main topic | Strings |
| Pattern | Two Pointers Palindrome |
| Starter signature | `bool validPalindrome(string s)` |

## Recognition cue

Branch only at the first mismatch and test the two meaningful remaining ranges.

## Invariant

After the first mismatch, only one of the two skipped ranges may be a palindrome.

## Prerequisites

palindrome range checking.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Try every possible deletion | O(n²) | O(n) |
| Better | Same efficient method (no distinct intermediate) | O(n) | O(1) |
| Optimal | Two pointers reference | O(n) | O(1) |

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
