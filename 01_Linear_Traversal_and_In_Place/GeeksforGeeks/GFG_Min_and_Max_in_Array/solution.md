# Min and Max in Array — explained solution

## Input and result

```cpp
pair<int, int> getMinMax(vector<int> &arr)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The input is nonempty. 

## How to think about it

Keep two values: the smallest and largest seen so far. Compare each new element with both.

## Worked trace

For [3, -2, 7], states are (3,3), (-2,3), then (-2,7). Return {minimum, maximum} in that order.

## Why this works

Updating each bound preserves its meaning for the visited prefix; together they describe the full array at the end.

## Approaches to compare

- **Brute Force:** Sort the array. Time O(n log n); space O(log n).
- **Better:** Two separate scans. Time O(n); space O(1).
- **Optimal:** One combined scan. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[12, 35, 1, 10, 34, 1]]` | `[1, 35]` |
| `[[-8, -3, -9]]` | `[-9, -3]` |
| `[[5, 5, 5]]` | `[5, 5]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Min_and_Max_in_Array --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
