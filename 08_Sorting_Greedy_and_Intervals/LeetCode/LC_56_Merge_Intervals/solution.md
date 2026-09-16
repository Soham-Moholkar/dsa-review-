# Merge Intervals — explained solution

## Input and result

```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

Sort intervals by start. Keep the most recent merged interval. Extend its end when the next interval overlaps; otherwise begin another interval.

## Worked trace

[[1,3],[2,6],[8,10],[9,12]] becomes [[1,6],[8,12]]. The second interval extends the first group; the fourth extends the second group.

## Why this works

After sorting, a later interval cannot overlap an earlier completed group without also touching the current group. Comparing with the last group is sufficient.

## Approaches to compare

- **Brute Force:** Repeated pair merging. Time O(n^3); space O(n).
- **Better:** Sort and merge. Time O(n log n); space O(n).
- **Optimal:** One sorted pass. Time O(n log n); space O(n) answer.

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[[1, 12], [3, 5], [7, 11], [7, 14], [5, 7], [8, 13]]]` | `[[1, 14]]` |
| `[[[1, 3], [2, 6], [8, 10]]]` | `[[1, 6], [8, 10]]` |
| `[[[1, 10], [2, 3]]]` | `[[1, 10]]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_56_Merge_Intervals --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
