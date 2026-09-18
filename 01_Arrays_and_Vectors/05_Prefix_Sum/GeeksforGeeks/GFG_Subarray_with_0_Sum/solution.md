# Subarray with 0 Sum — explained solution

## Input and result

```cpp
bool subArrayExists(vector<int>& arr)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md).

## How to think about it

Store prefix sums, starting with zero. If a prefix repeats, return true. Otherwise save it and continue.

## Worked trace

[4,2,-3,1,6] has prefixes 4,6,3,4,10. Prefix 4 repeats, so the elements between those occurrences, [2,-3,1], sum to zero.

## Why this works

Equal prefixes differ by zero. Including the initial empty prefix detects zero-sum subarrays starting at index 0.

## Approaches to compare

- **Brute Force:** Enumerate all subarrays. Time O(n^2); space O(1).
- **Better:** Store, sort, and compare prefix sums. Time O(n log n); space O(n).
- **Optimal:** Prefix sum hash set. Time O(n) average; space O(n).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[-3, 5, -4, 0, 3, -2, 4]]` | `True` |
| `[[1, 2, 3]]` | `False` |
| `[[1, -1]]` | `True` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Subarray_with_0_Sum --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
