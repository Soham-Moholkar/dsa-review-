# String Rotation Check

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [String Rotation Check](https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1)
- **Stage:** Two Pointers Palindrome
- **Module ID:** 50 · **Global ID:** 185
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Connect circular positions to substring matching and revisit after the pattern-matching stage.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Two Pointers Palindrome](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Equal-length strings are rotations when one cyclic shift matches the other. Two empty strings return true locally.

```cpp
bool areRotations(string s1, string s2)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Compare every cyclic shift | O(n²) | O(1) |
| [Better](03_better_approach.cpp) | Search the doubled string | O(n²) worst case | O(n) |
| [Optimal](04_optimal_solution.cpp) | KMP over doubled source | O(n) | O(n) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
