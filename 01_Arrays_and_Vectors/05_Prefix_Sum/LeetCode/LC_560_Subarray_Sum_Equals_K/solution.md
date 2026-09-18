# Subarray Sum Equals K — explained solution

## Input and result

```cpp
int subarraySum(vector<int>& nums, int k)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md).

## How to think about it

Keep a frequency map of prefix sums. At each prefix p, add the number of earlier prefixes p-k to the answer. Then increment the frequency of p.

## Worked trace

[1,1,1], k=2: prefixes are 1,2,3. Prefix 2 matches initial 0; prefix 3 matches earlier 1. The answer is 2.

## Why this works

Each matching earlier prefix identifies one distinct nonempty subarray ending here. A set would lose multiplicity; a map of counts preserves it.

## Approaches to compare

- **Brute Force:** Enumerate all subarrays. Time O(n^2); space O(1).
- **Better:** Ordered map of prefix frequencies. Time O(n log n); space O(n).
- **Optimal:** Unordered-map prefix frequencies. Time O(n) average; space O(n).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[1, -1, 0], 0]` | `3` |
| `[[1, -1, 0], 3]` | `0` |
| `[[0, 0, 0], 0]` | `6` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_560_Subarray_Sum_Equals_K --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
