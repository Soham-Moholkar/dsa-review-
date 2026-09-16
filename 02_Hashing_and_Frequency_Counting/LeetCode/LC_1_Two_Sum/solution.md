# Two Sum — explained solution

## Input and result

```cpp
vector<int> twoSum(vector<int>& nums, int target)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

For each value x, look for target-x among earlier values. Check first, then insert x; this prevents reusing the same element. Store indices when the answer requires positions.

## Worked trace

For [2,7,11,15], target=9: store 2 at index 0. At 7, the missing value is 2, which is already present. Return indices [0,1] for LC or true for GFG.

## Why this works

Every pair is considered when its later element is visited. A successful earlier lookup uses a different index.

## Approaches to compare

- **Brute Force:** Compare every pair. Time O(n^2); space O(1).
- **Better:** Two-pass hashmap. Time O(n) average; space O(n).
- **Optimal:** One-pass hashmap. Time O(n) average; space O(n).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[2, 7, 11, 15], 13]` | `Any distinct indices whose values sum to target; base 0` |
| `[[-5, -1, 2, 8], -6]` | `Any distinct indices whose values sum to target; base 0` |
| `[[2, 7, 11, 15], 9]` | `Any distinct indices whose values sum to target; base 0` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_1_Two_Sum --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
