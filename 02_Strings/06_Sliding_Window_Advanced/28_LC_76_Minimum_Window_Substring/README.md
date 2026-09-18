# 28. Minimum Window Substring

| Field | Value |
|---|---|
| Platform | LeetCode |
| Difficulty | Hard |
| Problem link | [Open the live problem](https://leetcode.com/problems/minimum-window-substring/) |
| Starter signature | `string minWindow(string s, string t)` |
| Reference solution available | No — intentionally locked |

## What you are meant to learn

Track when all required counts are satisfied, then remove unnecessary characters from the left.

## Concepts required

- Variable window
- required multiplicities
- minimum valid range

## Prerequisites

- frequency maps
- grow/shrink windows

## Attempt protocol

1. Read the live platform statement and constraints.
2. Add two of your own edge cases to `test_cases.txt`.
3. Write only your first honest solution in `01_original_attempt.cpp`.
4. Record compiler errors, wrong assumptions, and failed cases in `mistakes.md`.
5. Mark the progress tracker truthfully before requesting a hint or reference layer.

The README intentionally explains the learning target, not the algorithm.
