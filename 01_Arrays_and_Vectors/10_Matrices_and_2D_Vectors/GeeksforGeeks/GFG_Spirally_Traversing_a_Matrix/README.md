# GeeksforGeeks: Spirally Traversing a Matrix

[Explained solution, worked trace, and local test command](solution.md)

## Problem summary

Return matrix elements in clockwise spiral order.

This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Medium |
| Main topic | Arrays / Vectors |
| Pattern | Matrices and Two-Dimensional Vectors |

## Recognition cue

Four boundaries shrink after completing each direction.

## Invariant

All cells outside top,bottom,left,right have already been emitted exactly once.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Simulation with visited cells and directions | O(rows × columns) | O(rows × columns) |
| Better | Boundary traversal | O(rows × columns) | O(1) excluding answer |
| Optimal | Four shrinking boundaries | O(rows × columns) | O(1) excluding answer |

## Files

- `01_original_attempt.cpp` — your exact first attempt; placeholder until you solve it.
- `02_brute_force.cpp` — simplest baseline/reference approach.
- `03_better_approach.cpp` — intermediate improvement when meaningful.
- `04_optimal_solution.cpp` — preferred reference solution in your consistent C++ style.
- `mistakes.md` — common failure points and a slot for your exact mistake.
- `testcases.md` — normal, edge, and revision tests.
- `revision_notes.md` — compact pattern reminder and progress log.
- `metadata.json` — machine-readable classification.
