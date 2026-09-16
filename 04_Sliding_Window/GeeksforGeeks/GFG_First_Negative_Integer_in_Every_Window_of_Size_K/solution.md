# First Negative Integer in Every Window of Size K — explained solution

## Input and result

```cpp
vector<long long> printFirstNegativeInteger(long long A[], long long N, long long K)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Require 1 <= k <= n; any supplied N equals the array length. 

## How to think about it

Store indices of negative values in a deque. As the window moves, discard indices to the left of its start. The front is the first negative still inside.

## Worked trace

[12,-1,-7,8], k=3 gives -1 for [12,-1,-7] and -1 for [-1,-7,8]. A window with no stored negative gives 0.

## Why this works

Indices enter in increasing order, so after removing expired indices the front is the earliest valid negative. Each index enters and leaves at most once.

## Approaches to compare

- **Brute Force:** Scan each window. Time O(n × k); space O(1).
- **Better:** Store all negative indexes and advance a pointer. Time O(n); space O(n).
- **Optimal:** Deque of negative indexes. Time O(n); space O(k).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[12, -1, -7, 8, -15, 30, 16, 28], 8, 1]` | `[0, -1, -7, 0, -15, 0, 0, 0]` |
| `[[12, -1, -7, 8, -15, 30, 16, 28], 8, 4]` | `[-1, -1, -7, -15, -15]` |
| `[[-2, -7, -1], 3, 1]` | `[-2, -7, -1]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_First_Negative_Integer_in_Every_Window_of_Size_K --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
