# 3Sum — explained solution

## Input and result

```cpp
vector<vector<int>> threeSum(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

Sort the array. Fix one value and solve the remaining two-sum problem with opposite-end pointers. Skip equal fixed values and equal values after recording an answer.

## Worked trace

[-1,0,1,2,-1,-4] sorts to [-4,-1,-1,0,1,2]. Fixing -1 finds [-1,-1,2] and [-1,0,1]. Skip the next fixed -1 to avoid duplicates.

## Why this works

The sorted two-pointer argument finds every pair for each fixed value. Skipping equal values removes repeated value triplets without removing distinct solutions.

## Approaches to compare

- **Brute Force:** Check every triplet and deduplicate with a set. Time O(n^3 log n); space O(number of answers).
- **Better:** Fix two values and use a hash set. Time O(n^2 log n) expected; space O(n) excluding answers.
- **Optimal:** Sort, fix one value, and use two pointers. Time O(n^2); space O(log n) excluding answer.

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[-5, 5, 1, -3, 5, -4, 0, 3]]` | `[[-5, 0, 5], [-4, 1, 3], [-3, 0, 3]]` |
| `[[-1, 0, 1, 2, -1, -4]]` | `[[-1, -1, 2], [-1, 0, 1]]` |
| `[[0, 0, 0, 0]]` | `[[0, 0, 0]]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_15_3Sum --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
