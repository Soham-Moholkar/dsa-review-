# 38. Search Pattern (KMP Algorithm)

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Difficulty | Medium |
| Problem link | [Open the live problem](https://www.geeksforgeeks.org/problems/search-pattern0205/1) |
| Starter signature | `vector<int> search(string &pat, string &txt)` |
| Reference solution available | No — intentionally locked |

## What you are meant to learn

Build the prefix table and reuse matched information instead of restarting after a mismatch.

## Concepts required

- LPS/prefix table
- KMP fallback

## Prerequisites

- naive matching
- prefix/suffix definitions

## Attempt protocol

1. Read the live platform statement and constraints.
2. Add two of your own edge cases to `test_cases.txt`.
3. Write only your first honest solution in `01_original_attempt.cpp`.
4. Record compiler errors, wrong assumptions, and failed cases in `mistakes.md`.
5. Mark the progress tracker truthfully before requesting a hint or reference layer.

The README intentionally explains the learning target, not the algorithm.
