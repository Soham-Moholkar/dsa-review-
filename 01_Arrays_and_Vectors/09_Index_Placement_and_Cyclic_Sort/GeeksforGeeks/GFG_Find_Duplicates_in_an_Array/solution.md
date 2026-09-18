# Find Duplicates in an Array — explained solution

## Input and result

```cpp
vector<int> findDuplicates(vector<int>& arr)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). This is the handbook 0..n-1 version returning {-1} when none repeat; it differs from the current 1..n platform variant.

## How to think about it

For the handbook range 0..n-1, shift values by one, then consume each positive value into a negative counter at its original-value index. Return the indices with counts below -1.

## Worked trace

[0,0,2] shifts to [1,1,3]. Consuming values gives [-2,0,-1]. Only index 0 has a count below -1, so return [0].

## Why this works

Each original occurrence contributes one decrement to exactly one counter. Scanning counters by index produces sorted distinct duplicates. Unlike adding n repeatedly, counters cannot grow to n*n.

## Approaches to compare

- **Brute Force:** Count every value separately. Time O(n^2); space O(1).
- **Better:** Frequency vector. Time O(n); space O(n).
- **Optimal:** In-place negative frequency counting. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[0]]` | `[-1]` |
| `[[0]]` | `[-1]` |
| `[[0]]` | `[-1]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Find_Duplicates_in_an_Array --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
