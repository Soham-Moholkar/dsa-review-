# Longest Subarray with Sum K — explained solution

## Input and result

```cpp
int longestSubarray(vector<int>& arr, int k)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md).

## How to think about it

Save the earliest index of every prefix sum. At prefix p, look for p-k. Its earliest index gives the longest matching subarray ending here.

## Worked trace

[1,-1,5,-2,3], k=3: at index 3 the prefix sum is 3. Initial prefix 0 at index -1 gives length 3-(-1)=4.

## Why this works

Subtracting prefixes gives a subarray sum. For a fixed right endpoint, the earliest matching prefix maximizes length. Never overwrite an earlier index.

## Approaches to compare

- **Brute Force:** Enumerate all subarrays. Time O(n^2); space O(1).
- **Better:** Prefix sum with earliest-index map. Time O(n log n); space O(n).
- **Optimal:** Prefix sum with unordered_map. Time O(n) average; space O(n).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[1, -1, 0], 0]` | `3` |
| `[[1, -1, 0], 3]` | `0` |
| `[[0, 0, 0], 0]` | `3` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Longest_Subarray_with_Sum_K --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
