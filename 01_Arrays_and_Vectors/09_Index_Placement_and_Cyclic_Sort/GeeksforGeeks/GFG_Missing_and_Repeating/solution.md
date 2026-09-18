# Missing and Repeating — explained solution

## Input and result

```cpp
vector<int> findTwoElement(vector<int>& arr)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). Values lie in 1..n.

## How to think about it

For each absolute value x, mark cell x-1 negative. If that cell was already negative, x repeats. Afterwards a positive cell identifies the missing number.

## Worked trace

[1,3,3]: mark positions 0 and 2. The second 3 sees position 2 already negative, so 3 repeats. Position 1 is positive, so 2 is missing. Return [3,2].

## Why this works

The sign of each cell records whether its corresponding value was seen. Absolute values preserve original values while the same array holds markers.

## Approaches to compare

- **Brute Force:** Count every possible value. Time O(n^2); space O(1).
- **Better:** Frequency array. Time O(n); space O(n).
- **Optimal:** Sign marking. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[2, 2]]` | `[2, 1]` |
| `[[2, 2]]` | `[2, 1]` |
| `[[1, 1]]` | `[1, 2]` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Missing_and_Repeating --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
