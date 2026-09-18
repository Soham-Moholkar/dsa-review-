# Longest Consecutive Sequence — explained solution

## Input and result

```cpp
int longestConsecutive(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md).

## How to think about it

Put distinct values into a hash set. Only start counting at a value whose predecessor is absent. Then walk upwards while consecutive values exist.

## Worked trace

For [100,4,200,1,3,2], only 100, 200, and 1 start sequences. Starting at 1 visits 1,2,3,4, producing length 4.

## Why this works

Each sequence has one start and each distinct value is visited once in a forward walk. Hash lookups have expected constant cost; guard INT_MIN and INT_MAX before neighbour arithmetic.

## Approaches to compare

- **Brute Force:** Repeated linear existence search. Time O(n^3); space O(1).
- **Better:** Sort and scan. Time O(n log n); space O(log n).
- **Optimal:** Hash set sequence starts. Time O(n) average; space O(n).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[-2147483648, 2147483647]]` | `1` |
| `[[100, 4, 200, 1, 3, 2]]` | `4` |
| `[[1, 2, 0, 1]]` | `3` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_128_Longest_Consecutive_Sequence --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
