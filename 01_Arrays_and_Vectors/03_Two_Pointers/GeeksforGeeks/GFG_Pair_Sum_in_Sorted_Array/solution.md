# Pair Sum in Sorted Array — explained solution

## Input and result

```cpp
bool twoSum(vector<int>& arr, int target)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). The array is sorted in nondecreasing order.

## How to think about it

Start at the left and right ends of the SORTED array. If the sum is too small, move left forward. If it is too large, move right backward.

## Worked trace

[1,2,4,7], target=6: 1+7 is too large, so discard 7. Then 1+4 is too small, so discard 1. Finally 2+4=6.

## Why this works

If the sum is too small, the left value cannot work with any smaller right value. The symmetric argument applies to a sum that is too large. LC 167 returns one-based indices.

## Approaches to compare

- **Brute Force:** Compare every pair. Time O(n^2); space O(1).
- **Better:** Hash set lookup. Time O(n) average; space O(n).
- **Optimal:** Opposite-end two pointers. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[2, 7, 11, 15], 13]` | `True` |
| `[[2, 7, 11, 15], 9]` | `True` |
| `[[2, 7, 11, 15], 0]` | `False` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Pair_Sum_in_Sorted_Array --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
