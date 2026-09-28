# 41. Practise Deque Operations

| Field | Value |
|---|---|
| Platform | Repository exercise |
| Difficulty | Easy |
| Problem link | [Open the live problem](https://github.com/Soham-Moholkar/dsa-review-/blob/topic/stacks-queues/04_Stacks_and_Queues/09_Deque_and_Monotonic_Queue/41_EX_Practise_Deque_Operations/README.md) |
| Starter signature | `vector<int> applyDequeOperations(vector<string>& commands)` |
| Reference solution available | No — intentionally locked |

## What you are meant to learn

Become fluent with both-end insertion and removal before optimizing windows.

## Exercise contract

Each command is 'push_front x', 'push_back x', 'pop_front', or 'pop_back'. Ignore removals on empty; return contents from front to back.

## Concepts required

- std::deque
- both ends
- front/back

## Prerequisites

- std::queue operations
- vector<string>

## Attempt protocol

1. Read the live platform statement and constraints (or the exercise contract above).
2. Add two of your own edge cases to `test_cases.txt`.
3. Write only your first honest solution in `01_original_attempt.cpp`.
4. Record compiler errors, wrong assumptions, and failed cases in `mistakes.md`.
5. Mark the progress tracker truthfully before requesting a hint or reference layer.

The README explains the learning target, not the algorithm.
