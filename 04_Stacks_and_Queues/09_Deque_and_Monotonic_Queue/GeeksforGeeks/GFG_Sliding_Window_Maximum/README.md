# GeeksforGeeks: Sliding Window Maximum

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k-using-dequeue--161044/1)

## Problem summary

Track the strongest candidate while positions leave the window.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Hard |
| Main topic | Stacks and Queues |
| Pattern | Deque and Monotonic Queue |
| Starter signature | `vector<int> maxSlidingWindow(vector<int>& nums, int k)` |

## Recognition cue

Track the strongest candidate while positions leave the window.

## Invariant

Deque values decrease from front to back and indices stay inside the window.

## Prerequisites

fixed sliding window; first negative windows.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Scan each window for its maximum | O(nk) | O(1) plus result |
| Better | Maintain a multiset of window values | O(n log k) | O(k) plus result |
| Optimal | Monotonic deque reference | O(n) | O(k) plus result |

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
