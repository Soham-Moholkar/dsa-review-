# Maximum Product Subarray — explained solution

## Input and result

```cpp
int maxProduct(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). The input is nonempty. The study implementations assume every contiguous product fits a signed 32-bit integer.

## How to think about it

Track both the maximum and minimum products ending here. A negative value can turn the smallest product into the largest, so swap states before multiplying.

## Worked trace

[2,3,-2,4]: ending maximum/minimum pairs are (2,2), (6,3), (-2,-12), (4,-48). The largest product seen is 6.

## Why this works

Multiplication by a negative reverses order. Both extremes are needed to cover every possible best extension. Zero naturally restarts the product state.

## Approaches to compare

- **Brute Force:** Enumerate every product. Time O(n^2); space O(1).
- **Better:** Bidirectional product scans. Time O(n); space O(1).
- **Optimal:** Maximum/minimum ending states. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[2, 3, -2, 4]]` | `6` |
| `[[-3, -2, -5]]` | `10` |
| `[[-2, 0, -1]]` | `0` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_152_Maximum_Product_Subarray --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
