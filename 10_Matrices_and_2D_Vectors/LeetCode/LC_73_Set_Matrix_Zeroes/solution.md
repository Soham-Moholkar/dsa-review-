# Set Matrix Zeroes — explained solution

## Input and result

```cpp
void setZeroes(vector<vector<int>>& matrix)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The matrix is nonempty and rectangular; rotation additionally requires a square. 

## How to think about it

Save whether the first row and column originally had zeros. Mark other affected rows and columns in those first cells, update the interior, then handle the saved first row and column.

## Worked trace

[[1,1,1],[1,0,1],[1,1,1]] becomes [[1,0,1],[0,0,0],[1,0,1]]. Only the original zero determines the affected row and column.

## Why this works

The first row and column store original-zero information without allocating marker arrays. Delayed writes stop generated zeros from causing extra clearing.

## Approaches to compare

- **Brute Force:** Use a copy to preserve original zeroes. Time O(r × c × (r+c)); space O(r × c).
- **Better:** Row and column marker arrays. Time O(r × c); space O(r+c).
- **Optimal:** First row and column as markers. Time O(r × c); space O(1).

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
python3 scripts/test_solutions.py --problem LC_73_Set_Matrix_Zeroes --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
