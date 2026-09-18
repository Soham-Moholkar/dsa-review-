# Rotate Array — explained solution

## Input and result

```cpp
void rotate(vector<int>& nums, int k)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md).

## How to think about it

Reduce k modulo the array length. Reverse the whole array, then reverse the first k elements and the remaining elements separately.

## Worked trace

[1,2,3,4,5], k=2: whole reversal gives [5,4,3,2,1]; first block gives [4,5,3,2,1]; last block gives [4,5,1,2,3].

## Why this works

Write the array as A B, where B has k elements. Reversing everything gives reverse(B) reverse(A). Reversing the two blocks produces B A.

## Approaches to compare

- **Brute Force:** Rotate one step k times. Time O(n × k); space O(1).
- **Better:** Place values in an extra vector. Time O(n); space O(n).
- **Optimal:** Three reversals. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[1], 0]` | `Input becomes [1]` |
| `[[], 0]` | `Input becomes []` |
| `[[], 1]` | `Input becomes []` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_189_Rotate_Array --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
