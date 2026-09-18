# Contains Duplicate — explained solution

## Input and result

```cpp
bool containsDuplicate(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md).

## How to think about it

Maintain a set of values already visited. Return true on the first value that is already present. Otherwise add it and continue.

## Worked trace

[1,2,3,1]: the set becomes {1}, {1,2}, {1,2,3}; the last 1 is already there, so return true.

## Why this works

Before each lookup the set contains precisely the earlier values. A hit is equivalent to an earlier equal element.

## Approaches to compare

- **Brute Force:** Compare every pair. Time O(n^2); space O(1).
- **Better:** Sort and compare neighbours. Time O(n log n); space O(log n).
- **Optimal:** Hash set. Time O(n) average; space O(n).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[-3, 5, -4, 0, 3, -2, 4]]` | `False` |
| `[[1, 2, 3, 1]]` | `True` |
| `[[1]]` | `False` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_217_Contains_Duplicate --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
