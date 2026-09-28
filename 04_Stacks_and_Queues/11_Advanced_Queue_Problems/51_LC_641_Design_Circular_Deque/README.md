# 51. Design Circular Deque

| Field | Value |
|---|---|
| Platform | LeetCode |
| Difficulty | Medium |
| Problem link | [Open the live problem](https://leetcode.com/problems/design-circular-deque/) |
| Starter signature | `class MyCircularDeque { public: MyCircularDeque(int k); bool insertFront(int value); bool insertLast(int value); bool deleteFront(); bool deleteLast(); int getFront(); int getRear(); bool isEmpty(); bool isFull(); };` |
| Reference solution available | No — intentionally locked |

## What you are meant to learn

Extend wraparound reasoning to insertions and removals at both ends.

## Concepts required

- circular deque
- two-ended capacity

## Prerequisites

- circular queue
- deque operations

## Attempt protocol

1. Read the live platform statement and constraints (or the exercise contract above).
2. Add two of your own edge cases to `test_cases.txt`.
3. Write only your first honest solution in `01_original_attempt.cpp`.
4. Record compiler errors, wrong assumptions, and failed cases in `mistakes.md`.
5. Mark the progress tracker truthfully before requesting a hint or reference layer.

The README explains the learning target, not the algorithm.
