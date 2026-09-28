# 08. Delete Middle Element of a Stack

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Difficulty | Medium |
| Problem link | [Open the live problem](https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1) |
| Starter signature | `void deleteMiddle(stack<int>& st)` |
| Reference solution available | Yes — three C++ approaches |

## What you are meant to learn

Keep the original order when removing the middle entry from LIFO storage.

## Exercise contract

For even n, remove the lower middle (index (n-1)/2 from the bottom). Mutate the stack; rightmost is top.

## Concepts required

- recursion
- position
- restoration

## Prerequisites

- call stack
- stack size

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
