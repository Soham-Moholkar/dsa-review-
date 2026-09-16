# Trapping Rain Water — explained solution

## Input and result

```cpp
long long maxWater(vector<int>& arr)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

Track the largest wall seen from each end. Process the smaller current boundary: its running maximum determines how much water can sit there.

## Worked trace

For [3,0,2,0,4], the middle positions hold 3,1,3 units. Their total is 7. End positions hold no water.

## Why this works

Water above a position is min(best left wall, best right wall)-height. Processing the bounded side makes its contribution final without storing both arrays.

## Approaches to compare

- **Brute Force:** Find left and right maxima for every index. Time O(n^2); space O(1).
- **Better:** Prefix and suffix maximum arrays. Time O(n); space O(n).
- **Optimal:** Two pointers with running boundaries. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[4, 2, 0, 3, 2, 5]]` | `9` |
| `[[3, 0, 2, 0, 4]]` | `7` |
| `[[1, 5, 8]]` | `0` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Trapping_Rain_Water --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
