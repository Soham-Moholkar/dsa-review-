# Minimum Size Subarray Sum — explained solution

## Input and result

```cpp
int minSubArrayLen(int target, vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). LC uses positive values and sum >= target; GFG uses nonnegative values and sum > x, with a nonnegative threshold. 

## How to think about it

Grow a window by moving right. Whenever its sum satisfies the threshold, save its length and remove values from the left while it remains valid.

## Worked trace

[2,3,1,2,4,3], threshold 7 with >=: shrinking eventually finds [4,3], length 2. For a strict >7 condition that same window is not valid.

## Why this works

With nonnegative values, growing cannot reduce the sum and shrinking cannot increase it. Every shortest valid window ending at each right index is considered. Negative values break this reasoning.

## Approaches to compare

- **Brute Force:** Try every start. Time O(n^2); space O(1).
- **Better:** Prefix sums with lower_bound. Time O(n log n); space O(n).
- **Optimal:** Variable sliding window. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[1, [2, 3, 1, 2, 4, 3]]` | `1` |
| `[1, [1]]` | `1` |
| `[1, [1]]` | `1` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_209_Minimum_Size_Subarray_Sum --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
