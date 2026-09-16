# Kadane's Algorithm — explained solution

## Input and result

```cpp
long long maxSubarraySum(vector<int>& arr)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The input is nonempty. 

## How to think about it

At each value choose whether to extend the previous subarray or start a new one here. Keep the best ending sum and the best overall sum separately.

## Worked trace

[-2,1,-3,4,-1,2,1,-5,4] gives best ending sums -2,1,-2,4,3,5,6,1,5. The answer is 6 from [4,-1,2,1].

## Why this works

Every nonempty subarray ending here is either the current element alone or an extension of a subarray ending one position earlier. Keeping the best extension is sufficient.

## Approaches to compare

- **Brute Force:** Generate every subarray and rescan it. Time O(n^3); space O(1).
- **Better:** Running sum for every start. Time O(n^2); space O(1).
- **Optimal:** Kadane state transition. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[2, 3, -2, 4]]` | `7` |
| `[[-3, -2, -5]]` | `-2` |
| `[[-2, 0, -1]]` | `0` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Kadanes_Algorithm --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
