# Search in Rotated Sorted Array — explained solution

## Input and result

```cpp
int search(vector<int>& nums, int target)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Values are distinct. 

## How to think about it

At each middle position, identify which half is sorted. Check whether the target lies inside that half's value range; keep that half if it does, otherwise keep the other.

## Worked trace

[4,5,6,7,0,1,2], target 0: the left half through 7 is sorted but cannot contain 0. Keep the right half and continue until index 4.

## Why this works

With distinct values, at least one half is sorted. Its endpoints decide whether the target can belong there. Duplicates require a different ambiguity-handling algorithm.

## Approaches to compare

- **Brute Force:** Linear search. Time O(n); space O(1).
- **Better:** Pivot plus binary search. Time O(log n); space O(1).
- **Optimal:** One modified binary search. Time O(log n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[2, 3, 4, 5, 1], 2]` | `0` |
| `[[2, 3, 4, 5, 1], 1]` | `4` |
| `[[1], 17]` | `-1` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_33_Search_in_Rotated_Sorted_Array --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
