# Majority Element — explained solution

## Input and result

```cpp
int majorityElement(vector<int>& arr)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

Keep a candidate and a vote count. Equal values add votes; different values cancel one vote. When the count becomes zero, choose the next value as the new candidate.

## Worked trace

For [2,2,1,1,1,2,2], candidate/count moves through 2/1, 2/2, 2/1, 2/0, 1/1, 1/0, 2/1. The final candidate is 2.

## Why this works

Removing pairs of different values cannot eliminate a strict majority. GFG needs a second pass to verify that a majority actually exists; LC 169 guarantees one.

## Approaches to compare

- **Brute Force:** Count each candidate. Time O(n^2); space O(1).
- **Better:** Frequency hashmap. Time O(n) average; space O(n).
- **Optimal:** Boyer-Moore plus verification. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[2, 2, 1, 1, 1, 2, 2]]` | `2` |
| `[[1, 2, 3, 4]]` | `-1` |
| `[[3, 3, 4]]` | `3` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Majority_Element --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
