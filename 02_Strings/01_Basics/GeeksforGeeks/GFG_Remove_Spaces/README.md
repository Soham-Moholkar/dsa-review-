# Remove Spaces

- **Platform:** GeeksforGeeks
- **Study difficulty:** Easy
- **Live problem:** [Remove Spaces](https://www.geeksforgeeks.org/problems/remove-spaces0128/1)
- **Stage:** Basics
- **Module ID:** 46 · **Global ID:** 181
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Practise stable filtering and compare erasing with compacting a string.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Basics](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Remove literal ASCII spaces; preserve every other character in order. Empty input is a local extension.

```cpp
string removeSpaces(string s)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Erase each space | O(n²) | O(1) auxiliary |
| [Better](03_better_approach.cpp) | Build a filtered output | O(n) | O(n) result |
| [Optimal](04_optimal_solution.cpp) | Compact with a write position | O(n) | O(1) auxiliary |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
