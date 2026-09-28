# LeetCode: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

## Problem summary

Maintain both extremes as a variable window changes.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 1438 |
| Study difficulty | Medium |
| Main topic | Stacks and Queues |
| Pattern | Deque and Monotonic Queue |
| Starter signature | `int longestSubarray(vector<int>& nums, int limit)` |

## Recognition cue

Maintain both extremes as a variable window changes.

## Invariant

Two deques track the current minimum and maximum of the live window.

## Prerequisites

sliding-window maximum; minimum tracking.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Enumerate valid contiguous ranges | O(n²) | O(1) |
| Better | Maintain a multiset of window extremes | O(n log n) | O(n) |
| Optimal | Two monotonic deques reference | O(n) | O(n) |

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
