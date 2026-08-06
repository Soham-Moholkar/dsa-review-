# GeeksforGeeks: Majority Element

## Problem summary

Return the element occurring more than n/2 times, or -1 if none exists.

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

One value may dominate all others, but the candidate must be verified when existence is not guaranteed.

## Invariant

Boyer-Moore count represents the candidate’s net votes against different values.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Count each candidate | O(n^2) | O(1) |
| Better | Frequency hashmap | O(n) average | O(n) |
| Optimal | Boyer-Moore plus verification | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
