# Count Subarrays with Given XOR — explained solution

## Input and result

```cpp
long long subarrayXor(vector<int>& arr, int k)
```

Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). 

## How to think about it

Store how many times each prefix XOR has appeared. For the current prefix p, earlier prefixes equal to p XOR k form subarrays with XOR k. Seed prefix 0 with count 1.

## Worked trace

For [4,2,2], k=4: prefix 4 matches initial 0 once; prefix 6 finds no earlier 2; final prefix 4 matches 0 again. There are two matching subarrays.

## Why this works

XORing two prefixes cancels their shared elements. Therefore earlier XOR = current XOR k. Counting earlier prefixes before adding the current one excludes empty subarrays.

## Approaches to compare

- **Brute Force:** Enumerate all subarrays. Time O(n^2); space O(1).
- **Better:** Ordered map of prefix XOR frequencies. Time O(n log n); space O(n).
- **Optimal:** Hashmap of prefix XOR frequencies. Time O(n) average; space O(n).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[4, 2, 2, 6, 4], 0]` | `2` |
| `[[4, 2, 2, 6, 4], 3]` | `0` |
| `[[0, 0, 0], 0]` | `6` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem GFG_Count_Subarrays_with_Given_XOR --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
