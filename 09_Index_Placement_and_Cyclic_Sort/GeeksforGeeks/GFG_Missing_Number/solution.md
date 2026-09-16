# Missing Number — explained solution

## Input and result

```cpp
int missingNumber(vector<int>& arr)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

XOR every value in the complete expected range, then XOR every input value. Equal values cancel, leaving the missing number.

## Worked trace

For LC [3,0,1], XOR range 0..3 with the input; 0,1,3 cancel and 2 remains. GFG instead uses range 1..n for an input of length n-1.

## Why this works

XOR is associative and x XOR x is zero. Every present value appears twice in the combined expression; only the missing value appears once.

## Approaches to compare

- **Brute Force:** Test every candidate. Time O(n^2); space O(1).
- **Better:** Sort and find first mismatch. Time O(n log n); space O(log n).
- **Optimal:** XOR full range and values. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[3, 2]]` | `1` |
| `[[1, 3]]` | `2` |
| `[[2]]` | `1` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Missing_Number --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
