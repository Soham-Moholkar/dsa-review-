# GeeksforGeeks: Frequencies in a Limited Array

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Replace the first N positions with frequencies of values 1 through N; values may be limited by P.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Hashing and Frequency Counting |

## Recognition cue

Values lie in a known range, so array indexes can encode counts.

## Invariant

Positive cells hold unprocessed values; nonpositive cells hold consumed slots or negative occurrence counts.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Count every value separately | O(n^2) | O(n) |
| Better | Use a separate frequency array | O(n) | O(n) |
| Optimal | Consume values into negative counters | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
