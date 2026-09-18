# Best Time to Buy and Sell Stock — explained solution

## Input and result

```cpp
int maxProfit(vector<int>& prices)
```

Inputs follow the problem summary and the [contract guide](../../../../docs/CONTRACTS.md). The input is nonempty.

## How to think about it

Track the cheapest earlier price and the greatest profit so far. At each day, compare selling today with the saved best, then update the cheapest price.

## Worked trace

[7,1,5,3,6,4]: price 1 becomes the cheapest buy. Selling at 6 gives profit 5; later price 4 cannot improve it.

## Why this works

Every legal transaction has a sell day. For each such day, the cheapest earlier buy maximizes that day's profit. Taking the best covers all transactions.

## Approaches to compare

- **Brute Force:** Try all transactions. Time O(n^2); space O(1).
- **Better:** Suffix maximum. Time O(n); space O(n).
- **Optimal:** Minimum-so-far scan. Time O(n); space O(1).

The numbered levels are teaching alternatives, not a promise that every later file is strictly faster. Sorting can change input order; marker and placement techniques overwrite input values. Copy the input before calling a reference if you need to keep it.

## Examples checked by the local runner

Arguments below are listed in signature order. These are local checks, not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[2, 3, 2, 4]]` | `2` |
| `[[3, 2, 5]]` | `3` |
| `[[2, 0, 1]]` | `1` |

## Try it yourself

1. Trace the optimal implementation on one example without executing it.
2. Explain what each saved variable means after a loop iteration.
3. Change the example to expose the mistake described in [mistakes.md](mistakes.md).
4. Reimplement the idea without copying, then run:

```bash
python3 scripts/test_solutions.py --problem LC_121_Best_Time_to_Buy_and_Sell_Stock --sanitize
```

Run this command from the repository root. [Open the optimal C++ solution](04_optimal_solution.cpp), or compare [brute force](02_brute_force.cpp) and [the intermediate approach](03_better_approach.cpp).
