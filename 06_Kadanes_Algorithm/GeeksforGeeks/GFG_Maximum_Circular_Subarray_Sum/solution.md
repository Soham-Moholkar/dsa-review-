# Maximum Circular Subarray Sum — explained solution

## Input and result

```cpp
int circularSubarraySum(vector<int>& arr)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The input is nonempty. 

## How to think about it

Compute ordinary maximum-subarray sum, minimum-subarray sum, and total sum. A wrapping answer is total minus a middle block of minimum sum. If all values are negative, return the ordinary maximum.

## Worked trace

[5,-3,5]: ordinary maximum is 7, minimum is -3, total is 7; wrapping gives 7-(-3)=10. For [-3,-2,-5], return -2, not zero.

## Why this works

Every wrapping subarray excludes one contiguous middle block. Minimizing that block maximizes what remains. The all-negative guard prevents choosing an empty complement.

## Approaches to compare

- **Brute Force:** Enumerate circular starts and lengths. Time O(n^2); space O(1).
- **Better:** Duplicate array and bound subarray length. Time O(n^2); space O(n).
- **Optimal:** Maximum Kadane plus total minus minimum Kadane. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[2, 3, -2, 4]]` | `9` |
| `[[-3, -2, -5]]` | `-2` |
| `[[-2, 0, -1]]` | `0` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Maximum_Circular_Subarray_Sum --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
