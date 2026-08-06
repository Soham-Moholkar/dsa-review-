# GeeksforGeeks: First Negative Integer in Every Window of Size K

## Problem summary

For every K-sized window, return its first negative value or 0 when none exists.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Sliding Window |

## Recognition cue

The answer depends on the earliest still-valid negative index.

## Invariant

The deque stores negative indexes in increasing order and only from the current window.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Scan each window | O(n × k) | O(1) |
| Better | Store all negative indexes and advance a pointer | O(n) | O(n) |
| Optimal | Deque of negative indexes | O(n) | O(k) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
