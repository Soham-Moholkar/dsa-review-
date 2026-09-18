# Find First and Last Position of Element in Sorted Array — explained solution

## Input and result

```cpp
vector<int> searchRange(vector<int>& nums, int target)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). The array is sorted in nondecreasing order.

## How to think about it

Run two binary searches: one that continues left after a match and one that continues right. Return [-1,-1] when no match exists.

## Worked trace

[5,7,7,8,8,10], target 8 gives first index 3 and last index 4. lower_bound finds the first >= target; upper_bound finds the first > target.

## Why this works

The first search discards positions that cannot precede its best match; the second does the symmetric operation for the last match.

## Approaches to compare

- **Brute Force:** Linear scan. Time O(n); space O(1).
- **Better:** STL boundaries. Time O(log n); space O(1).
- **Optimal:** Two manual binary searches. Time O(log n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[1, 2, 3, 4, 5], 1]` | `[0, 0]` |
| `[[1, 2, 3, 4, 5], 5]` | `[4, 4]` |
| `[[1], 17]` | `[-1, -1]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_34_Find_First_and_Last_Position --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
