# LeetCode: Time Needed to Buy Tickets

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://leetcode.com/problems/time-needed-to-buy-tickets/)

## Problem summary

Model repeated fair turns without changing the identity of the target person.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 2073 |
| Study difficulty | Easy |
| Main topic | Stacks and Queues |
| Pattern | Queue Fundamentals |
| Starter signature | `int timeRequiredToBuy(vector<int>& tickets, int k)` |

## Recognition cue

Model repeated fair turns without changing the identity of the target person.

## Invariant

One FIFO turn serves one ticket and preserves everybody else’s order.

## Prerequisites

queue push/pop; indexes.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Simulate every ticket turn in a queue | O(total ticket turns) | O(n) |
| Better | Same efficient method (no distinct intermediate) | O(n) | O(1) |
| Optimal | Fifo turns reference | O(n) | O(1) |

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
