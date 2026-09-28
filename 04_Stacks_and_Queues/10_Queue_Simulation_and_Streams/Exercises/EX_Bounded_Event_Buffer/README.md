# Repository exercise: Bounded Event Buffer

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://github.com/Soham-Moholkar/dsa-review-/blob/main/04_Stacks_and_Queues/10_Queue_Simulation_and_Streams/Exercises/EX_Bounded_Event_Buffer/README.md)

## Problem summary

Return the last capacity arrivals in original order. capacity >= 0; empty input is allowed.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | Repository exercise |
| Problem number | — |
| Study difficulty | Medium |
| Main topic | Stacks and Queues |
| Pattern | Queue Simulation and Streams |
| Starter signature | `vector<int> lastEvents(vector<int>& events, int capacity)` |

## Recognition cue

Decide which oldest event to evict once fixed capacity is reached.

## Invariant

The buffer contains the last capacity arrivals in their original order.

## Prerequisites

circular queue; enqueue/dequeue.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Keep the last capacity events | O(capacity) | O(capacity) plus result |
| Better | Erase the oldest vector element on overflow | O(n × capacity) | O(capacity) plus result |
| Optimal | Bounded fifo reference | O(n) | O(capacity) |

The levels compare actual code. Some basic exercises reuse the efficient approach when a separate intermediate algorithm would only be artificial. Time/space use the assumptions in the live prompt; `n` is input length unless the problem says otherwise. Output memory is listed separately where relevant.

## Files

- `01_original_attempt.cpp` — your exact learner starter; do not replace it with reference code.
- `02_brute_force.cpp` — baseline or explicitly identified identical efficient method.
- `03_better_approach.cpp` — intermediate tradeoff where meaningful.
- `04_optimal_solution.cpp` — preferred reference under the local contract.
- `mistakes.md` — your own error log, kept separate from generated notes.
- `testcases.md` — starter cases and space for your personal cases.
- `revision_notes.md` — pattern reminder and blank spaced-review log.
- `metadata.json` — machine-readable classification and approach costs.

## Attempt protocol

Read the live prompt, add two of your own tests, and attempt it in `01_original_attempt.cpp` before reading the [explained reference](solution.md). Record only mistakes you actually made.
