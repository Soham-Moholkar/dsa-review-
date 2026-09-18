# Max Consecutive Ones — explained solution

## Input and result

```cpp
int findMaxConsecutiveOnes(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md).

## How to think about it

Keep the length of the current run of ones and the longest run found. A zero resets only the current run.

## Worked trace

[1,1,0,1,1,1] gives current lengths 1,2,0,1,2,3 and a final best of 3.

## Why this works

Every run is counted as it is traversed; the saved best never loses an earlier longer run.

## Approaches to compare

- **Brute Force:** Start a streak from every index. Time O(n^2); space O(1).
- **Better:** Single scan with explicit reset. Time O(n); space O(1).
- **Optimal:** Single scan streak state. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[1, 1, 0, 1, 1, 1]]` | `3` |
| `[[0, 1, 0]]` | `1` |
| `[[0]]` | `0` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_485_Max_Consecutive_Ones --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
