# 32. Implement a Queue with Linked Nodes

| Field | Value |
|---|---|
| Platform | Repository exercise |
| Difficulty | Easy |
| Problem link | [Open the live problem](https://github.com/Soham-Moholkar/dsa-review-/blob/topic/stacks-queues/04_Stacks_and_Queues/07_Queue_Fundamentals/32_EX_Implement_a_Queue_with_Linked_Nodes/README.md) |
| Starter signature | `class LinkedQueue { public: void push(int x); void pop(); int front(); int back(); bool empty(); int size(); };` |
| Reference solution available | No — intentionally locked |

## What you are meant to learn

Compare head and tail updates when an initially empty queue gains or loses its last item.

## Exercise contract

Use singly linked nodes. pop() on empty does nothing; front()/back() on empty return -1. Release owned nodes on destruction.

## Concepts required

- FIFO
- head/tail nodes
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
