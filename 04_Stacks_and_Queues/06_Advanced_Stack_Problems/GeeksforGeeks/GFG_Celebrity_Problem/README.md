# Celebrity Problem

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [Celebrity Problem](https://www.geeksforgeeks.org/problems/the-celebrity-problem/1)
- **Stage:** Advanced Stack Problems
- **Module ID:** 62 · **Global ID:** 205
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Recognize pairwise candidate elimination and the need for a final verification pass.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Advanced Stack Problems](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Square binary knows matrix. A celebrity knows nobody else and is known by everyone else. Ignore the diagonal. Return zero-based index or -1.

```cpp
int celebrity(vector<vector<int>>& mat)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Verify every person | O(n²) | O(1) |
| [Better](03_better_approach.cpp) | Pairwise elimination with a stack | O(n) | O(n) |
| [Optimal](04_optimal_solution.cpp) | Carry one elimination candidate | O(n) | O(1) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
