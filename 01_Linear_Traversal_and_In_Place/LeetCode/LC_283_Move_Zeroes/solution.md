# Move Zeroes — explained solution

## Input and result

```cpp
void moveZeroes(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

A write pointer marks where the next nonzero belongs. Scan left to right and move each nonzero to that pointer, then advance it.

## Worked trace

[0,1,0,3,12]: place 1 at index 0, 3 at index 1, and 12 at index 2. The result is [1,3,12,0,0].

## Why this works

Nonzero values are written in their original encounter order. The prefix before the write pointer contains exactly the nonzeros processed so far.

## Approaches to compare

- **Brute Force:** Use an additional result vector. Time O(n); space O(n).
- **Better:** Overwrite non-zero values then fill zeroes. Time O(n); space O(1).
- **Optimal:** Stable swap with read and write pointers. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[0, 1, 0, 3, 12]]` | `Input becomes [1, 3, 12, 0, 0]` |
| `[[0, 0, 0]]` | `Input becomes [0, 0, 0]` |
| `[[0]]` | `Input becomes [0]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_283_Move_Zeroes --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
