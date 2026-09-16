# Find All Numbers Disappeared in an Array — explained solution

## Input and result

```cpp
vector<int> findDisappearedNumbers(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Values lie in 1..n. 

## How to think about it

For each absolute value x, make the element at index x-1 negative. After marking, each positive cell corresponds to a missing value.

## Worked trace

[4,3,2,7,8,2,3,1] leaves indices 4 and 5 positive, so missing values are [5,6]. Repeated values must not flip a negative marker back to positive.

## Why this works

A cell is negative exactly when its represented value appeared. Reading absolute values allows the array to serve as both data and marker storage.

## Approaches to compare

- **Brute Force:** Search for every value. Time O(n^2); space O(1).
- **Better:** Frequency vector. Time O(n); space O(n).
- **Optimal:** Sign marking. Time O(n); space O(1) extra.

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[1]]` | `[]` |
| `[[1]]` | `[]` |
| `[[1]]` | `[]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_448_Find_All_Numbers_Disappeared --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
