# GeeksforGeeks: Find Duplicates in an Array

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return values that occur more than once when values lie in the range 0 through n-1.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Index Placement and Cyclic Sort |

## Recognition cue

The bounded range lets each index encode the frequency of its corresponding value.

## Invariant

After shifting values by one, positive cells hold unprocessed values and nonpositive cells hold negative counts of original values.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Count every value separately | O(n^2) | O(1) |
| Better | Frequency vector | O(n) | O(n) |
| Optimal | In-place negative frequency counting | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
