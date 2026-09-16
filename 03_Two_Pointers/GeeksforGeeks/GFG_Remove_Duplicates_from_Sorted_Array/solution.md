# Remove Duplicates from Sorted Array — explained solution

## Input and result

```cpp
int removeDuplicates(vector<int>& arr)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The array is sorted in nondecreasing order. 

## How to think about it

Keep a write pointer at the last distinct value. Move the read pointer through the sorted array. Copy a value forward only when it differs from the last distinct value.

## Worked trace

[1,1,2,2,3] yields the prefix [1,2,3] and returns k=3. Ignore all positions at or after index k.

## Why this works

Sorted order groups equal values together. One value from each group is written, in order, into the first k positions.

## Approaches to compare

- **Brute Force:** Use an ordered set and copy back. Time O(n log n); space O(n).
- **Better:** Use a separate unique vector. Time O(n); space O(n).
- **Optimal:** Read/write two pointers. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[-4, -3, -2, 0, 3, 4, 5]]` | `k=7; prefix=[-4, -3, -2, 0, 3, 4, 5]` |
| `[[1, 1, 2]]` | `k=2; prefix=[1, 2]` |
| `[[1]]` | `k=1; prefix=[1]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Remove_Duplicates_from_Sorted_Array --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
