# Smallest Positive Missing Number — explained solution

## Input and result

```cpp
int missingNumber(vector<int>& arr)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

A positive answer is at most n+1. Place each value x in 1..n at index x-1. Repeatedly swap until the current value is placed, irrelevant, or a duplicate. Scan for the first mismatch.

## Worked trace

[3,4,-1,1] -> [-1,4,3,1] -> [-1,1,3,4] -> [1,-1,3,4]. Index 1 lacks value 2, so return 2.

## Why this works

Every successful swap puts a valid value into its final slot. There are at most n such placements. Check 1<=x<=n BEFORE computing x-1; INT_MIN-1 would overflow.

## Approaches to compare

- **Brute Force:** Store values in a set and scan positives. Time O(n); space O(n).
- **Better:** Sort and scan. Time O(n log n); space O(log n).
- **Optimal:** Cyclic placement. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[-2147483648, 2147483647, 1]]` | `2` |
| `[[3, 4, -1, 1]]` | `2` |
| `[[1, 2, 0]]` | `3` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Smallest_Positive_Missing_Number --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
