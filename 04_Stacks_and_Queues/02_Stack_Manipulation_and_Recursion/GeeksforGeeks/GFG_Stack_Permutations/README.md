# Validate Stack Operations

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [Validate Stack Operations](https://www.geeksforgeeks.org/problems/stack-permutations/1)
- **Stage:** Stack Manipulation and Recursion
- **Module ID:** 57 · **Global ID:** 200
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Compare recursive search through operation choices with a forced-pop stack simulation.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Stack Manipulation and Recursion](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Equal-length arrays of distinct values give push and required pop order. This local adapter returns bool and omits redundant n. Revisit Validate Stack Sequences using the GFG contract.

```cpp
bool isStackPermutation(vector<int>& a, vector<int>& b)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Explore legal push/pop sequences | O(4^n n) upper bound | O(n²) copied states |
| [Better](03_better_approach.cpp) | Greedy std::stack simulation | O(n) | O(n) |
| [Optimal](04_optimal_solution.cpp) | Same linear simulation with vector storage | O(n) | O(n) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
