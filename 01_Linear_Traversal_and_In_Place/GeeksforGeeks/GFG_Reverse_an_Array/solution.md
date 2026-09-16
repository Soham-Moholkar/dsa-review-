# Reverse an Array — explained solution

## Input and result

```cpp
void reverseArray(vector<int> &arr)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

Put one pointer at each end. Swap their elements, then move both pointers towards the centre. Stop when they meet or cross.

## Worked trace

[1,2,3,4] becomes [4,2,3,1], then [4,3,2,1]. An odd-length middle element stays where it is.

## Why this works

Everything outside the pointers is already in its final reversed position. Each swap fixes two more positions.

## Approaches to compare

- **Brute Force:** Build a reversed copy. Time O(n); space O(n).
- **Better:** Swap using indexed half traversal. Time O(n); space O(1).
- **Optimal:** Two-pointer in-place reversal. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[-3, 5, -4, 0, 3, -2, 4]]` | `Input becomes [4, -2, 3, 0, -4, 5, -3]` |
| `[[1, 2, 3, 4]]` | `Input becomes [4, 3, 2, 1]` |
| `[[1]]` | `Input becomes [1]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Reverse_an_Array --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
