# Peak Element — explained solution

## Input and result

```cpp
int peakElement(vector<int>& arr)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The input is nonempty. 

## How to think about it

Compare the middle value with its right neighbour. If the slope rises, keep the right side; otherwise keep the left side including the middle.

## Worked trace

[1,3,2,4,1]: at middle index 2 the slope rises to 4, so keep indices 3..4. The next comparison falls, leaving index 3 as a peak.

## Why this works

Following an uphill direction must eventually reach a peak or an endpoint. The remaining interval always contains one. LC needs strict neighbours; the handbook GFG version permits equality.

## Approaches to compare

- **Brute Force:** Check every index and both neighbours. Time O(n); space O(1).
- **Better:** Linear slope scan. Time O(n); space O(1).
- **Optimal:** Binary search on slope. Time O(log n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[1, 3, 2, 4, 1]]` | `Any index in [1, 3]` |
| `[[1, 2, 3]]` | `Any index in [2]` |
| `[[3, 2, 1]]` | `Any index in [0]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Peak_Element --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
