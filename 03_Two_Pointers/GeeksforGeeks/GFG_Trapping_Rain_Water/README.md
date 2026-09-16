# GeeksforGeeks: Trapping Rain Water

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return the total water trapped between elevation bars.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Hard |
| Main topic | Arrays / Vectors |
| Pattern | Two Pointers |

## Recognition cue

Water at an index depends on the best boundary on both sides.

## Invariant

The side with the smaller current boundary can be finalized safely.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Find left and right maxima for every index | O(n^2) | O(1) |
| Better | Prefix and suffix maximum arrays | O(n) | O(n) |
| Optimal | Two pointers with running boundaries | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
