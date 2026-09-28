# Look and Say Pattern

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [Look and Say Pattern](https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1)
- **Stage:** Advanced Mixed
- **Module ID:** 63 · **Global ID:** 198
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Build one representation from another while keeping source and destination separate.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Advanced Mixed](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

n >= 1. The first row is "1"; every later row describes counts then digits of consecutive runs in the previous row.

```cpp
string countAndSay(int n)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Retain every generated row | O(T) | O(T) |
| [Better](03_better_approach.cpp) | Keep only consecutive rows | O(T) | O(L) |
| [Optimal](04_optimal_solution.cpp) | Same rolling-row simulation; no distinct third algorithm | O(T) | O(L) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
