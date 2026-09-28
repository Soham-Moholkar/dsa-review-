# 02. Implement a Stack with Linked Nodes

| Field | Value |
|---|---|
| Platform | Repository exercise |
| Difficulty | Easy |
| Problem link | [Open the live problem](https://github.com/Soham-Moholkar/dsa-review-/blob/topic/stacks-queues/04_Stacks_and_Queues/01_Stack_Fundamentals/02_EX_Implement_a_Stack_with_Linked_Nodes/README.md) |
| Starter signature | `class LinkedStack { public: void push(int x); void pop(); int top(); bool empty(); int size(); };` |
| Reference solution available | No — intentionally locked |

## What you are meant to learn

Compare constant-time stack operations with linked storage and clean up owned nodes.

## Exercise contract

Use singly linked nodes. pop() on empty does nothing; top() on empty returns -1. Release owned nodes on destruction.

## Concepts required

- LIFO
- nodes
- ownership

## Prerequisites

- pointers
- basic class design

## Attempt protocol

1. Read the live platform statement and constraints (or the exercise contract above).
2. Add two of your own edge cases to `test_cases.txt`.
3. Write only your first honest solution in `01_original_attempt.cpp`.
4. Record compiler errors, wrong assumptions, and failed cases in `mistakes.md`.
5. Mark the progress tracker truthfully before requesting a hint or reference layer.

The README explains the learning target, not the algorithm.
