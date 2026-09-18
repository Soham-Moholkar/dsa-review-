# Largest Element in Array — explained solution

## Input and result

```cpp
int largest(vector<int> &arr)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). The input is nonempty.

## How to think about it

Keep the greatest value seen so far. Start with the first element, then replace it whenever a larger value arrives.

## Worked trace

For [-8, -3, -9], the saved value starts at -8, becomes -3, and stays -3. Starting at zero would incorrectly return a value that is not present.

## Why this works

After each visit, the saved value is the maximum of the visited prefix. After the last visit that prefix is the whole array.

## Approaches to compare

- **Brute Force:** Compare every candidate. Time O(n^2); space O(1).
- **Better:** Sort and take the last value. Time O(n log n); space O(log n).
- **Optimal:** Single linear scan. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[12, 35, 1, 10, 34, 1]]` | `35` |
| `[[-8, -3, -9]]` | `-3` |
| `[[5, 5, 5]]` | `5` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Largest_Element_in_Array --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
