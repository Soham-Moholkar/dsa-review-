# Find Numbers with Even Number of Digits — explained solution

## Input and result

```cpp
int findNumbers(vector<int>& nums)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md).

## How to think about it

Count each number's digits by repeatedly dividing by 10. Add one to the answer when that count is even.

## Worked trace

For 120: 120 -> 12 -> 1 -> 0 gives 3 digits, so skip it. For 45, two divisions give 2 digits, so count it.

## Why this works

Integer division removes one decimal digit. The loop therefore counts every digit exactly once.

## Approaches to compare

- **Brute Force:** Convert every number to text. Time O(total digits); space O(max digits).
- **Better:** Repeated division by 10. Time O(total digits); space O(1).
- **Optimal:** Digit count with division and no extra storage. Time O(total digits); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[1, 9, 10, 99, 100, 999, 1000, 9999, 10000, 99999, 100000]]` | `5` |
| `[[86754, 75112, 79049, 65658, 96356, 73611, 80293, 70112]]` | `0` |
| `[[20864, 84362, 14227, 48435, 66120, 31619, 99871]]` | `0` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_1295_Find_Numbers_with_Even_Number_of_Digits --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
