# Gas Station (Circular Tour)

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [Gas Station (Circular Tour)](https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1)
- **Stage:** Queue Manipulation and Circular Queue
- **Module ID:** 64 · **Global ID:** 207
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Compare a circular journey simulation with eliminating impossible starting positions.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Queue Manipulation and Circular Queue](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Equal-length nonempty nonnegative arrays. Start with an empty tank, collect gas[i], and pay cost[i] to reach the next station. Return the first feasible zero-based start, or -1. This adapter uses the modern two-array contract.

```cpp
int startStation(vector<int>& gas, vector<int>& cost)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Simulate every circular start | O(n²) | O(1) |
| [Better](03_better_approach.cpp) | Store prefix balances | O(n) | O(n) |
| [Optimal](04_optimal_solution.cpp) | Eliminate failed candidate segments | O(n) | O(1) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
