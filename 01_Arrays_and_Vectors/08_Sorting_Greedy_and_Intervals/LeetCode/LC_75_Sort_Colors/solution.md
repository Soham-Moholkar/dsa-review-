# Sort Colors — explained solution

## Input and result

```cpp
void sortColors(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). Every value is 0, 1, or 2.

## How to think about it

Use low, mid, and high to separate zeros, ones, unprocessed values, and twos. For a zero swap with low and advance both low and mid. For a two swap with high and only decrease high.

## Worked trace

[2,0,1]: swap the 2 with the last element -> [1,0,2]. Inspect index 0 again, then move over 1. Swap 0 with low -> [0,1,2].

## Why this works

Before each step, [0,low) contains zeros, [low,mid) ones, and (high,n) twos. The unknown region shrinks each step. A value swapped in from high still needs inspection.

## Approaches to compare

- **Brute Force:** General sorting. Time O(n log n); space O(log n).
- **Better:** Counting. Time O(n); space O(1).
- **Optimal:** Dutch National Flag. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[2, 2, 2, 2, 2, 2, 2, 2]]` | `Input becomes [2, 2, 2, 2, 2, 2, 2, 2]` |
| `[[0, 2, 0, 1, 2, 0, 2]]` | `Input becomes [0, 0, 0, 1, 2, 2, 2]` |
| `[[2, 0, 2, 1, 1, 0]]` | `Input becomes [0, 0, 1, 1, 2, 2]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_75_Sort_Colors --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
