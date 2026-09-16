# Count Distinct Elements in Every Window — explained solution

## Input and result

```cpp
vector<int> countDistinct(vector<int>& arr, int k)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Require 1 <= k <= n; any supplied N equals the array length. 

## How to think about it

Maintain a frequency map for exactly one k-element window. Remove the outgoing value and erase its key if its count becomes zero. Add the incoming value.

## Worked trace

[1,2,1,3], k=3: [1,2,1] has 2 distinct values. Sliding to [2,1,3] leaves one 1, retains 2, adds 3, and gives 3 distinct values.

## Why this works

The map stores exactly the positive frequencies in the current window, so its number of keys is the requested distinct count.

## Approaches to compare

- **Brute Force:** Build a set for each window. Time O(n × k); space O(k).
- **Better:** Sliding ordered map. Time O(n log k); space O(k).
- **Optimal:** Sliding hashmap with zero-count erasure. Time O(n) average; space O(k).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[12, -1, -7, 8, -15, 30, 16, 28], 1]` | `[1, 1, 1, 1, 1, 1, 1, 1]` |
| `[[12, -1, -7, 8, -15, 30, 16, 28], 4]` | `[4, 4, 4, 4, 4]` |
| `[[-2, -7, -1], 1]` | `[1, 1, 1]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Count_Distinct_Elements_in_Every_Window --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
