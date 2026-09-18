# Binary Search — explained solution

## Input and result

```cpp
int search(vector<int>& nums, int target)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). The array is sorted in nondecreasing order.

## How to think about it

Search a sorted array by checking its middle. Discard the half that cannot contain the target. For GFG, save a matching index and continue left to find the first occurrence.

## Worked trace

[1,2,2,2,5], target 2: a middle match does not prove it is the first. Searching farther left finds index 1. LC 704 has distinct elements and can return immediately.

## Why this works

The target, if still unseen, remains in the active interval. Comparisons eliminate only impossible positions; saving matches preserves a valid answer while searching earlier positions.

## Approaches to compare

- **Brute Force:** Linear scan. Time O(n); space O(1).
- **Better:** lower_bound. Time O(log n); space O(1).
- **Optimal:** Manual binary search. Time O(log n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[1, 2, 3, 4, 5], 1]` | `0` |
| `[[1, 2, 3, 4, 5], 5]` | `4` |
| `[[1], 17]` | `-1` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_704_Binary_Search --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
