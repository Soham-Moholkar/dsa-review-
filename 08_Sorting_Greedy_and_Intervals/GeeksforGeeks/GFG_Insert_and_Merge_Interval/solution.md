# Insert and Merge Interval — explained solution

## Input and result

```cpp
vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Existing intervals are sorted by start and disjoint. 

## How to think about it

Copy intervals entirely before the new interval. Merge all intervals overlapping it. Append the merged interval, then copy the untouched intervals after it.

## Worked trace

[[1,3],[6,9]] plus [2,5]: merge [1,3] into [1,5], then append [6,9]. Touching endpoints count as overlap.

## Why this works

Sorted, initially disjoint intervals form three consecutive groups: before, overlapping, after. Only the middle group can change.

## Approaches to compare

- **Brute Force:** Append, sort, then merge all. Time O(n log n); space O(n).
- **Better:** Three-phase linear insertion. Time O(n); space O(n).
- **Optimal:** Single linear merge around new interval. Time O(n); space O(n) answer.

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[[1, 6], [8, 10]], [0, 0]]` | `[[0, 0], [1, 6], [8, 10]]` |
| `[[[1, 6], [8, 10]], [3, 8]]` | `[[1, 10]]` |
| `[[], [20, 25]]` | `[[20, 25]]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Insert_and_Merge_Interval --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
