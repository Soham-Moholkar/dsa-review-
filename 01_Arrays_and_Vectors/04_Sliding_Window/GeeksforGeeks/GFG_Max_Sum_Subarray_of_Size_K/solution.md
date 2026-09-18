# Max Sum Subarray of Size K — explained solution

## Input and result

```cpp
long long maximumSumSubarray(int K, vector<int> &Arr, int N)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). Require 1 <= k <= n; any supplied N equals the array length.

## How to think about it

Compute the sum of the first k values. Move the window by adding the incoming value and subtracting the outgoing value. Keep the largest sum.

## Worked trace

[1,12,-5,-6,50,3], k=4 gives window sums 2,51,42. The largest sum is 51; for the average problem return 51/4.0 = 12.75.

## Why this works

Two adjacent fixed-length windows share k-1 values. Replacing exactly the outgoing element preserves the exact sum. Start best from a real window, especially for negative inputs.

## Approaches to compare

- **Brute Force:** Recalculate every window. Time O(n × k); space O(1).
- **Better:** Prefix sums. Time O(n); space O(n).
- **Optimal:** Fixed sliding window. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[1, [12, -1, -7, 8, -15, 30, 16, 28], 8]` | `30` |
| `[4, [12, -1, -7, 8, -15, 30, 16, 28], 8]` | `59` |
| `[1, [-2, -7, -1], 3]` | `-1` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Max_Sum_Subarray_of_Size_K --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
