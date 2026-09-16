# Rotate Image — explained solution

## Input and result

```cpp
void rotate(vector<vector<int>>& matrix)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The matrix is nonempty and rectangular; rotation additionally requires a square. 

## How to think about it

Transpose across the main diagonal. For clockwise rotation reverse each row. For anticlockwise rotation reverse the order of rows.

## Worked trace

[[1,2],[3,4]] transposes to [[1,3],[2,4]]. Reversing each row gives clockwise [[3,1],[4,2]]. Reversing row order gives anticlockwise [[2,4],[1,3]].

## Why this works

A transpose maps (r,c) to (c,r). The following reversal yields (c,n-1-r) clockwise or (n-1-c,r) anticlockwise. The matrix must be square.

## Approaches to compare

- **Brute Force:** Use an extra matrix. Time O(n^2); space O(n^2).
- **Better:** Transpose and reverse rows. Time O(n^2); space O(1).
- **Optimal:** In-place transpose plus row reversal. Time O(n^2); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[[2]]]` | `Input becomes [[2]]` |
| `[[[0]]]` | `Input becomes [[0]]` |
| `[[[2]]]` | `Input becomes [[2]]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_48_Rotate_Image --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
