# Search in a Row-Column Sorted Matrix — explained solution

## Input and result

```cpp
bool searchMatrix(vector<vector<int>>& mat, int x)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The matrix is nonempty and rectangular; rotation additionally requires a square. 

## How to think about it

Begin in the top-right corner. Move left when the value is too large and down when it is too small. Stop on a match or after leaving the matrix.

## Worked trace

[[1,4,7],[2,5,8],[3,6,9]], target 6: 7 is too large -> 4 is too small -> 5 is too small -> 6 is a match.

## Why this works

Rows and columns are sorted. A value too large eliminates its remaining column; a value too small eliminates its remaining row. At most rows+columns moves occur.

## Approaches to compare

- **Brute Force:** Check every cell. Time O(r × c); space O(1).
- **Better:** Binary search every row. Time O(r log c); space O(1).
- **Optimal:** Top-right staircase search. Time O(r+c); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[[-7]], -99]` | `False` |
| `[[[-7]], -7]` | `True` |
| `[[[-7]], -7]` | `True` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Search_in_a_Row_Column_Sorted_Matrix --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
