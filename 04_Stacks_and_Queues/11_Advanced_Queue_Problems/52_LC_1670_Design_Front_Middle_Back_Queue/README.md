# 52. Design Front Middle Back Queue

| Field | Value |
|---|---|
| Platform | LeetCode |
| Difficulty | Medium |
| Problem link | [Open the live problem](https://leetcode.com/problems/design-front-middle-back-queue/) |
| Starter signature | `class FrontMiddleBackQueue { public: FrontMiddleBackQueue(); void pushFront(int val); void pushMiddle(int val); void pushBack(int val); int popFront(); int popMiddle(); int popBack(); };` |
| Reference solution available | No — intentionally locked |

## What you are meant to learn

Maintain an explicit middle choice when both ends and the center can change.

## Concepts required

- two deques
- balancing
- middle contract

## Prerequisites

- deque operations
- invariants

## Attempt protocol

1. Read the live platform statement and constraints (or the exercise contract above).
2. Add two of your own edge cases to `test_cases.txt`.
3. Write only your first honest solution in `01_original_attempt.cpp`.
4. Record compiler errors, wrong assumptions, and failed cases in `mistakes.md`.
5. Mark the progress tracker truthfully before requesting a hint or reference layer.

The README explains the learning target, not the algorithm.
