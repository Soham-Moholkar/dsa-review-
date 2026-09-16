# Container With Most Water — explained solution

## Input and result

```cpp
int maxArea(vector<int>& height)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

Start with the widest pair. Record its width times the shorter height. Move the shorter boundary inward; the implementation can skip all heights no taller than that boundary.

## Worked trace

[1,8,6,2,5,4,8,3,7]: the first area is 8. Move past height 1; heights 8 and 7 at indices 1 and 8 give area 7*7=49.

## Why this works

Keeping the shorter boundary while reducing width cannot improve its area. Discarding it cannot remove an unexamined better pair using that boundary.

## Approaches to compare

- **Brute Force:** Check every pair. Time O(n^2); space O(1).
- **Better:** Two pointers. Time O(n); space O(1).
- **Optimal:** Two pointers with equal-height skip. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[1, 8, 6, 2, 5, 4, 8, 3, 7]]` | `49` |
| `[[7, 8, 8, 8, 3, 3, 2, 6]]` | `42` |
| `[[0, 6, 2, 1, 5, 8, 3]]` | `24` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_11_Container_With_Most_Water --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
