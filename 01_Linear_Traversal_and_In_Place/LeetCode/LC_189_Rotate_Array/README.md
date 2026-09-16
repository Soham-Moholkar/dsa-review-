# LeetCode: Rotate Array

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Rotate the array to the right by k positions.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | LeetCode |
| Problem number | 189 |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Linear Traversal and In-Place Manipulation |

## Recognition cue

A cyclic rearrangement can be decomposed into complete and partial reversals.

## Invariant

After the three reversals, each segment has the order required by a right rotation.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Rotate one step k times | O(n × k) | O(1) |
| Better | Place values in an extra vector | O(n) | O(n) |
| Optimal | Three reversals | O(n) | O(1) |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
