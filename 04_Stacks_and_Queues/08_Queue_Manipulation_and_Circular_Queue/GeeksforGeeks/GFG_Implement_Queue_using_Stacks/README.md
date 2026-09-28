# GeeksforGeeks: Implement Queue using Stacks

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://www.geeksforgeeks.org/problems/queue-using-stack/1)

## Problem summary

Preserve FIFO behavior using only stack operations and discuss the tradeoff.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Easy |
| Main topic | Stacks and Queues |
| Pattern | Queue Manipulation and Circular Queue |
| Starter signature | `class MyQueue { public: MyQueue(); void push(int x); int pop(); int peek(); bool empty(); };` |

## Recognition cue

Preserve FIFO behavior using only stack operations and discuss the tradeoff.

## Invariant

Outgoing stack items precede all incoming items in FIFO order.

## Prerequisites

two stacks; basic queue contract.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Same efficient method (no distinct baseline) | O(1) amortized per operation | O(n) |
| Better | Same efficient method (no distinct intermediate) | O(1) amortized per operation | O(n) |
| Optimal | Fifo from lifo reference | O(1) amortized per operation | O(n) |

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
