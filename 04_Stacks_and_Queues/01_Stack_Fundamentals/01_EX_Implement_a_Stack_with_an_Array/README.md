# 01. Implement a Stack with an Array

| Field | Value |
|---|---|
| Platform | Repository exercise |
| Difficulty | Easy |
| Problem link | [Open the live problem](https://github.com/Soham-Moholkar/dsa-review-/blob/topic/stacks-queues/04_Stacks_and_Queues/01_Stack_Fundamentals/01_EX_Implement_a_Stack_with_an_Array/README.md) |
| Starter signature | `class ArrayStack { public: void push(int x); void pop(); int top(); bool empty(); int size(); };` |
| Reference solution available | No — intentionally locked |

## What you are meant to learn

Define how the five basic operations behave, including an empty stack.

## Exercise contract

Use a growable array. pop() on empty does nothing; top() on empty returns -1. size() counts current items.

## Concepts required

- LIFO
- std::stack API
- contiguous storage

## Prerequisites

- vector
- class methods

## Attempt protocol

1. Read the live platform statement and constraints (or the exercise contract above).
2. Add two of your own edge cases to `test_cases.txt`.
3. Write only your first honest solution in `01_original_attempt.cpp`.
4. Record compiler errors, wrong assumptions, and failed cases in `mistakes.md`.
5. Mark the progress tracker truthfully before requesting a hint or reference layer.

The README explains the learning target, not the algorithm.
