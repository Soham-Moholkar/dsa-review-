# Frequencies in a Limited Array — explained solution

## Input and result

```cpp
void frequencyCount(vector<int>& arr, int N, int P)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). This is the handbook in-place (arr,N,P) version; values above N are ignored.

## How to think about it

Use each cell as either an unprocessed positive value or a nonpositive counter. Move an unprocessed value out of the target cell before replacing that cell with -1. Further occurrences decrement the counter. Negate counters at the end.

## Worked trace

[2,2,3]: process the first 2 and preserve the value from its target: [2,-1,3]. Process the second 2: [0,-2,3]. Process 3: [0,-2,-1]. Negate to get [0,2,1].

## Why this works

Each original in-range value is consumed once and decrements exactly its own counter. Each iteration consumes a value or opens a new counter, so there are O(n) iterations. Counts never need n*n-sized storage.

## Approaches to compare

- **Brute Force:** Count every value separately. Time O(n^2); space O(n).
- **Better:** Use a separate frequency array. Time O(n); space O(n).
- **Optimal:** Consume values into negative counters. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[2, 3, 2, 3, 5], 5, 5]` | `Input becomes [0, 2, 2, 0, 1]` |
| `[[4, 4, 4, 4], 4, 4]` | `Input becomes [0, 0, 0, 4]` |
| `[[8, 8, 8], 3, 8]` | `Input becomes [0, 0, 0]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Frequencies_in_a_Limited_Array --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
