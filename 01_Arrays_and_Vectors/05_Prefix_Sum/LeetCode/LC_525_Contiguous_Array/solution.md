# Contiguous Array — explained solution

## Input and result

```cpp
int findMaxLength(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md).

## How to think about it

Treat 0 as -1 and 1 as +1. Equal prefix balances enclose equal numbers of zeros and ones. Remember the earliest index for each balance.

## Worked trace

[0,1,0] gives balances -1,0,-1. At index 1 balance 0 matches initial index -1, giving length 2. The repeat of -1 also gives length 2.

## Why this works

A transformed sum of zero means the number of +1 values equals the number of -1 values. Earliest equal balances maximize length.

## Approaches to compare

- **Brute Force:** Count zeroes and ones for every subarray. Time O(n^2); space O(1).
- **Better:** Ordered map of transformed prefixes. Time O(n log n); space O(n).
- **Optimal:** Hashmap of earliest transformed prefixes. Time O(n) average; space O(n).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[0, 1, 0]]` | `2` |
| `[[0, 1]]` | `2` |
| `[[0]]` | `0` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_525_Contiguous_Array --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
