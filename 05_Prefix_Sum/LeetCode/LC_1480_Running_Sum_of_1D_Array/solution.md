# Running Sum of 1D Array — explained solution

## Input and result

```cpp
vector<int> runningSum(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

Starting at index 1, add the previous running total to the current value. The input vector becomes its own result.

## Worked trace

[1,2,3,4] becomes [1,3,3,4], then [1,3,6,4], then [1,3,6,10].

## Why this works

When index i is updated, index i-1 already stores the sum through i-1. Adding the original value at i gives the sum through i.

## Approaches to compare

- **Brute Force:** Recalculate each prefix. Time O(n^2); space O(n).
- **Better:** Build a separate running result. Time O(n); space O(n).
- **Optimal:** Modify the input in place. Time O(n); space O(1) extra.

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[5, 4, 4, 3, 3, 4, 3, -2]]` | `[5, 9, 13, 16, 19, 23, 26, 24]` |
| `[[-3, 5, -4, 0, 3, -2, 4]]` | `[-3, 2, -2, -2, 1, -1, 3]` |
| `[[1, 2, 3, 4]]` | `[1, 3, 6, 10]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_1480_Running_Sum_of_1D_Array --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
