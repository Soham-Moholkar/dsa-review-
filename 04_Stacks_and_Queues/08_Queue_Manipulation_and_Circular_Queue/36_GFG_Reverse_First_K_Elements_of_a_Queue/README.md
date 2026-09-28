# 36. Reverse First K Elements of a Queue

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Difficulty | Easy |
| Problem link | [Open the live problem](https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1) |
| Starter signature | `void reverseFirstK(queue<int>& q, int k)` |
| Reference solution available | Yes — three C++ approaches |

## What you are meant to learn

Keep the suffix in its original order while reversing only a prefix.

## Exercise contract

0 <= k <= q.size(). Mutate the queue; leftmost is front.

## Concepts required

- partial reversal
- order preservation

## Prerequisites

- reverse queue
- queue rotation

The local starter signature is preserved. Check the live GFG editor for any differing method name, parameters, or output convention before submitting a copy.

## Attempt protocol

1. Read the live platform statement and constraints (or the exercise contract above).
2. Add two of your own edge cases to `test_cases.txt`.
3. Write only your first honest solution in `01_original_attempt.cpp`.
4. Record compiler errors, wrong assumptions, and failed cases in `mistakes.md`.
5. Mark the progress tracker truthfully before requesting a hint or reference layer.

The README explains the learning target, not the algorithm.

## After your own attempt

[Compare the reference approaches](solution.md), then record your own mistake and revision dates. Reference availability does not record personal completion.
