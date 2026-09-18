# Fruit Into Baskets — explained solution

## Input and result

```cpp
int totalFruit(vector<int>& fruits)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md).

## How to think about it

Track counts of fruit types in the window. Allow at most two keys in the map. When a third type appears, shrink from the left until a type disappears.

## Worked trace

[1,2,1,3]: the first three trees fit in two baskets. Adding 3 forces removal of 1, then 2; the new window [1,3] fits. Best length is 3.

## Why this works

The frequency map represents the current window. Shrinking only while it is invalid leaves the longest feasible window for each right endpoint.

## Approaches to compare

- **Brute Force:** Check every starting index. Time O(n^2); space O(1) distinct keys.
- **Better:** Sliding frequency map. Time O(n) average; space O(1) distinct keys.
- **Optimal:** Two-type sliding window. Time O(n) average; space O(1) distinct keys.

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[0, 1, 2, 2]]` | `3` |
| `[[1, 2, 1]]` | `3` |
| `[[0, 2, 4]]` | `2` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_904_Fruit_Into_Baskets --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
