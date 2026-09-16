# Find Pivot Index — explained solution

## Input and result

```cpp
int pivotIndex(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The GFG handbook returns one-based positions; LC and the current GFG prompt use zero-based indices. 

## How to think about it

Compute the total sum. At each index subtract the current value from the remaining total, compare that right sum with the left sum, then add the current value to the left.

## Worked trace

[1,7,3,6,5,6]: at index 3 both sides sum to 11. LC returns 3; the handbook GFG implementation returns position 4.

## Why this works

Before comparison, left excludes the current value and the remaining total is precisely the right side. The first equality is the leftmost equilibrium.

## Approaches to compare

- **Brute Force:** Recalculate both sides. Time O(n^2); space O(1).
- **Better:** Prefix sum array. Time O(n); space O(n).
- **Optimal:** Total sum and left sum. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[1, 7, 3, 6, 5, 6]]` | `3` |
| `[[1, 2, 3]]` | `-1` |
| `[[0, 0]]` | `0` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_724_Find_Pivot_Index --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
