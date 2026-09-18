# Boolean Matrix — explained solution

## Input and result

```cpp
void booleanMatrix(vector<vector<int>>& matrix)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). The matrix is nonempty and rectangular; rotation additionally requires a square.

## How to think about it

Save whether the first row and first column originally contained 1. Use their cells to mark other rows and columns that should become 1. Apply interior marks first, then the saved first-row and first-column flags.

## Worked trace

[[0,0,0],[0,1,0]] becomes [[0,1,0],[1,1,1]]. The new ones must not trigger further rows or columns.

## Why this works

Markers record only original ones. Applying them after the scan prevents newly written ones from spreading the operation incorrectly.

## Approaches to compare

- **Brute Force:** Use an unchanged copy for every marker. Time O(r × c × (r+c)); space O(r × c).
- **Better:** Row and column marker arrays. Time O(r × c); space O(r+c).
- **Optimal:** Use first row and column as markers. Time O(r × c); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[[0]]]` | `Input becomes [[0]]` |
| `[[[0]]]` | `Input becomes [[0]]` |
| `[[[0]]]` | `Input becomes [[0]]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Boolean_Matrix --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
