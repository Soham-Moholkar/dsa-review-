# GeeksforGeeks: Second Largest

## Problem summary

Return the second-largest distinct value, or -1 when it does not exist.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Easy |
| Main topic | Arrays / Vectors |
| Pattern | Linear Traversal and In-Place Manipulation |

## Recognition cue

Two best distinct values must be maintained while scanning.

## Invariant

largest and secondLargest are the greatest and second-greatest distinct values seen so far.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Sort and locate the first distinct value | O(n log n) | O(log n) |
| Better | Two complete scans | O(n) | O(1) |
| Optimal | One scan with two states | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
