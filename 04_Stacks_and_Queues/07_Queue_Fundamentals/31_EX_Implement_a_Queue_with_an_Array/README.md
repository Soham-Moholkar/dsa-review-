# 31. Implement a Queue with an Array

| Field | Value |
|---|---|
| Platform | Repository exercise |
| Difficulty | Easy |
| Problem link | [Open the live problem](https://github.com/Soham-Moholkar/dsa-review-/blob/topic/stacks-queues/04_Stacks_and_Queues/07_Queue_Fundamentals/31_EX_Implement_a_Queue_with_an_Array/README.md) |
| Starter signature | `class ArrayQueue { public: void push(int x); void pop(); int front(); int back(); bool empty(); int size(); };` |
| Reference solution available | Yes — three C++ approaches |

## What you are meant to learn

Define the FIFO contract and consider how removed positions affect storage.

## Exercise contract

Use an array-like storage choice. pop() on empty does nothing; front()/back() on empty return -1.

## Concepts required

- FIFO
- std::queue API
- storage

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

## After your own attempt

[Compare the reference approaches](solution.md), then record your own mistake and revision dates. Reference availability does not record personal completion.
