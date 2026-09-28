# Repository exercise: Practise Deque Operations

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://github.com/Soham-Moholkar/dsa-review-/blob/main/04_Stacks_and_Queues/09_Deque_and_Monotonic_Queue/Exercises/EX_Practise_Deque_Operations/README.md)

## Problem summary

Each command is 'push_front x', 'push_back x', 'pop_front', or 'pop_back'. Ignore removals on empty; return contents from front to back.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | Repository exercise |
| Problem number | — |
| Study difficulty | Easy |
| Main topic | Stacks and Queues |
| Pattern | Deque and Monotonic Queue |
| Starter signature | `vector<int> applyDequeOperations(vector<string>& commands)` |

## Recognition cue

Become fluent with both-end insertion and removal before optimizing windows.

## Invariant

The deque contents follow each requested front or back operation.

## Prerequisites

std::queue operations; vector<string>.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Same efficient method (no distinct baseline) | O(commands + output) | O(n) |
| Better | Same efficient method (no distinct intermediate) | O(commands + output) | O(n) |
| Optimal | Std::deque reference | O(commands + output) | O(n) |

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
