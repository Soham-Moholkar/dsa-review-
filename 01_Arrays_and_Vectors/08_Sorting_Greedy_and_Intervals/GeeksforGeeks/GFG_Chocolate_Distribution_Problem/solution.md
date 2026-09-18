# Chocolate Distribution Problem — explained solution

## Input and result

```cpp
int findMinDiff(vector<int>& a, int m)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). Require 1 <= m <= n.

## How to think about it

Sort packet sizes. For every block of m consecutive packets, subtract its smallest value from its largest. Return the minimum difference.

## Worked trace

[7,3,2,4,9,12,56], m=3 sorts to [2,3,4,7,9,12,56]. The first block has difference 4-2=2, which is best.

## Why this works

For any chosen m packets, replacing gaps between the smallest and largest with closer packets cannot increase the range. Thus some optimal selection is consecutive after sorting.

## Approaches to compare

- **Brute Force:** Enumerate subsets recursively. Time Exponential; space O(n) recursion stack.
- **Better:** Sort and test all m-sized windows. Time O(n log n); space O(log n).
- **Optimal:** Sorted fixed-size greedy window. Time O(n log n); space O(log n).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[7, 3, 2, 4, 9, 12, 56], 1]` | `0` |
| `[[7, 3, 2, 4, 9, 12, 56], 3]` | `2` |
| `[[7, 3, 2, 4, 9, 12, 56], 7]` | `54` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Chocolate_Distribution_Problem --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
