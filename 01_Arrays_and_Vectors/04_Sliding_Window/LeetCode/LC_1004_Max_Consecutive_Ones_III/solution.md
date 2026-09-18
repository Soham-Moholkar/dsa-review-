# Max Consecutive Ones III — explained solution

## Input and result

```cpp
int longestOnes(vector<int>& nums, int k)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md).

## How to think about it

Count zeros inside the window. If there are more than k, move left until at most k remain. Save the longest valid window.

## Worked trace

[1,0,1,0,1], k=1: [1,0,1] has length 3. Adding the next zero forces the left side to advance; the longest length remains 3.

## Why this works

A window is feasible exactly when it contains at most k zeros. Left only advances to remove an infeasible prefix.

## Approaches to compare

- **Brute Force:** Check every subarray. Time O(n^2); space O(1).
- **Better:** Prefix zero count with binary search. Time O(n log n); space O(n).
- **Optimal:** Variable sliding window. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[0], 0]` | `0` |
| `[[0], 1]` | `1` |
| `[[0], 1]` | `1` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_1004_Max_Consecutive_Ones_III --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
