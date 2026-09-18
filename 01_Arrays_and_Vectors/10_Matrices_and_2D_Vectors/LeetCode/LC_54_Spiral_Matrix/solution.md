# Spiral Matrix — explained solution

## Input and result

```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). The matrix is nonempty and rectangular; rotation additionally requires a square.

## How to think about it

Maintain top, bottom, left, and right boundaries. Traverse the top edge, right edge, bottom edge, and left edge, shrinking the appropriate boundary after each. Recheck bounds before the last two edges.

## Worked trace

[[1,2,3],[4,5,6]]: top gives 1,2,3; right gives 6; bottom gives 5,4. No left edge remains. Result [1,2,3,6,5,4].

## Why this works

Each traversal removes one unvisited boundary. The bound checks prevent revisiting a final single row or single column.

## Approaches to compare

- **Brute Force:** Visited simulation. Time O(r × c); space O(r × c).
- **Better:** Boundary traversal. Time O(r × c); space O(1) excluding answer.
- **Optimal:** Four-boundary spiral. Time O(r × c); space O(1) excluding answer.

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[[2]]]` | `[2]` |
| `[[[0]]]` | `[0]` |
| `[[[2]]]` | `[2]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_54_Spiral_Matrix --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
