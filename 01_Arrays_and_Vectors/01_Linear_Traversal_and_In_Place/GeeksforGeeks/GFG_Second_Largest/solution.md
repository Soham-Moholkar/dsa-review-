# Second Largest — explained solution

## Input and result

```cpp
int getSecondLargest(vector<int> &arr)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). The input is nonempty.

## How to think about it

Keep the two greatest DISTINCT values. A new largest pushes the old largest into second place. A value equal to the largest must not become second.

## Worked trace

For [12,35,35,10,34], the largest becomes 35. The second value moves from 12 to 34; the repeated 35 is ignored.

## Why this works

The two states represent the greatest two distinct values in the prefix. Every new value either enters these two positions or is too small to matter.

## Approaches to compare

- **Brute Force:** Sort and locate the first distinct value. Time O(n log n); space O(log n).
- **Better:** Two complete scans. Time O(n); space O(1).
- **Optimal:** One scan with two states. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[12, 35, 1, 10, 34, 1]]` | `34` |
| `[[-8, -3, -9]]` | `-8` |
| `[[5, 5, 5]]` | `-1` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Second_Largest --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
