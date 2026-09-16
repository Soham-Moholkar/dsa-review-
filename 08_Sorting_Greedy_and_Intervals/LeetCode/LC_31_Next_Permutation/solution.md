# Next Permutation — explained solution

## Input and result

```cpp
void nextPermutation(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

Find the rightmost position smaller than its next value. Swap it with the rightmost larger value, then reverse the suffix. If no such position exists, reverse everything.

## Worked trace

[1,3,2]: the pivot is 1. Swap with 2 -> [2,3,1], then reverse the suffix -> [2,1,3]. For [3,2,1], wrap to [1,2,3].

## Why this works

The suffix is already the greatest ordering of its values. Increasing the rightmost possible pivot by the smallest amount and minimizing the suffix gives the immediate next ordering.

## Approaches to compare

- **Brute Force:** Generate and sort every permutation. Time O(n! × n); space O(n! × n).
- **Better:** Use the standard library operation. Time O(n); space O(1).
- **Optimal:** Manual pivot, successor, and suffix reversal. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[0, 3, 1, 0, 2, 1]]` | `Input becomes [0, 3, 1, 1, 0, 2]` |
| `[[1, 2, 3]]` | `Input becomes [1, 3, 2]` |
| `[[3, 2, 1]]` | `Input becomes [1, 2, 3]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_31_Next_Permutation --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
