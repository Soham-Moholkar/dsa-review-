# Repository exercise: Implement a Queue with Linked Nodes

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://github.com/Soham-Moholkar/dsa-review-/blob/main/04_Stacks_and_Queues/07_Queue_Fundamentals/Exercises/EX_Implement_a_Queue_with_Linked_Nodes/README.md)

## Problem summary

Use singly linked nodes. pop() on empty does nothing; front()/back() on empty return -1. Release owned nodes on destruction.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | Repository exercise |
| Problem number | — |
| Study difficulty | Easy |
| Main topic | Stacks and Queues |
| Pattern | Queue Fundamentals |
| Starter signature | `class LinkedQueue { public: void push(int x); void pop(); int front(); int back(); bool empty(); int size(); };` |

## Recognition cue

Compare head and tail updates when an initially empty queue gains or loses its last item.

## Invariant

The head and tail nodes identify the oldest and newest active values.

## Prerequisites

pointers; basic class design.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Same efficient method (no distinct baseline) | O(1) per operation | O(n) |
| Better | Same efficient method (no distinct intermediate) | O(1) per operation | O(n) |
| Optimal | Fifo reference | O(1) per operation | O(n) |

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
