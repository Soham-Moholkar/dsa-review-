# Find the Duplicate Number — explained solution

## Input and result

```cpp
int findDuplicate(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). There are n+1 entries in 1..n with exactly one distinct duplicated value; do not modify input. 

## How to think about it

Treat values as next indices. Move a slow pointer one step and a fast pointer two steps until they meet. Reset one pointer to the starting value, then move both one step until they meet again.

## Worked trace

[1,3,4,2,2] traces 1 -> 3 -> 2 -> 4 -> 2, entering a cycle at value 2. The duplicate is 2.

## Why this works

There are n+1 positions but only n possible next values. The reachable cycle entry is the repeated value. The second phase finds that entry; the input stays unchanged.

## Approaches to compare

- **Brute Force:** Compare every pair. Time O(n^2); space O(1).
- **Better:** Hash set. Time O(n) average; space O(n).
- **Optimal:** Floyd cycle detection. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[1, 2, 1]]` | `1` |
| `[[2, 2, 1]]` | `2` |
| `[[1, 1, 1]]` | `1` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_287_Find_the_Duplicate_Number --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
