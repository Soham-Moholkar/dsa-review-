# Repository exercise: Implement a Queue with an Array

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://github.com/Soham-Moholkar/dsa-review-/blob/main/04_Stacks_and_Queues/07_Queue_Fundamentals/Exercises/EX_Implement_a_Queue_with_an_Array/README.md)

## Problem summary

Use an array-like storage choice. pop() on empty does nothing; front()/back() on empty return -1.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | Repository exercise |
| Problem number | — |
| Study difficulty | Easy |
| Main topic | Stacks and Queues |
| Pattern | Queue Fundamentals |
| Starter signature | `class ArrayQueue { public: void push(int x); void pop(); int front(); int back(); bool empty(); int size(); };` |

## Recognition cue

Define the FIFO contract and consider how removed positions affect storage.

## Invariant

The head index identifies the oldest active item in the array.

## Prerequisites

vector; class methods.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Same efficient method (no distinct baseline) | O(1) amortized per operation | O(total arrivals) |
| Better | Same efficient method (no distinct intermediate) | O(1) amortized per operation | O(total arrivals) |
| Optimal | Fifo reference | O(1) amortized per operation | O(total arrivals) |

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
