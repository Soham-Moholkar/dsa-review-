# 50. Bounded Event Buffer

| Field | Value |
|---|---|
| Platform | Repository exercise |
| Difficulty | Medium |
| Problem link | [Open the live problem](https://github.com/Soham-Moholkar/dsa-review-/blob/topic/stacks-queues/04_Stacks_and_Queues/10_Queue_Simulation_and_Streams/50_EX_Bounded_Event_Buffer/README.md) |
| Starter signature | `vector<int> lastEvents(vector<int>& events, int capacity)` |
| Reference solution available | Yes — three C++ approaches |

## What you are meant to learn

Decide which oldest event to evict once fixed capacity is reached.

## Exercise contract

Return the last capacity arrivals in original order. capacity >= 0; empty input is allowed.

## Concepts required

- bounded FIFO
- eviction
- stream

## Prerequisites

- circular queue
- enqueue/dequeue

## Attempt protocol

1. Read the live platform statement and constraints (or the exercise contract above).
2. Add two of your own edge cases to `test_cases.txt`.
3. Write only your first honest solution in `01_original_attempt.cpp`.
4. Record compiler errors, wrong assumptions, and failed cases in `mistakes.md`.
5. Mark the progress tracker truthfully before requesting a hint or reference layer.

The README explains the learning target, not the algorithm.

## After your own attempt

[Compare the reference approaches](solution.md), then record your own mistake and revision dates. Reference availability does not record personal completion.
