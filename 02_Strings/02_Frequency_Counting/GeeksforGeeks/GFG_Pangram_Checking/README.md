# Pangram Checking

- **Platform:** GeeksforGeeks
- **Study difficulty:** Easy
- **Live problem:** [Pangram Checking](https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1)
- **Stage:** Frequency Counting
- **Module ID:** 48 · **Global ID:** 183
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Distinguish character presence from multiplicity and handle case consistently.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Frequency Counting](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Check whether all 26 English letters occur, ignoring ASCII case and nonletters.

```cpp
bool checkPangram(string s)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Search for every letter | O(26n) | O(1) |
| [Better](03_better_approach.cpp) | Collect letters in a set | O(n log 26) | O(26) |
| [Optimal](04_optimal_solution.cpp) | Fixed presence table | O(n) | O(26) = O(1) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
