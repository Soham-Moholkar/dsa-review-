# String Duplicates Removal

- **Platform:** GeeksforGeeks
- **Study difficulty:** Easy
- **Live problem:** [String Duplicates Removal](https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1)
- **Stage:** Frequency Counting
- **Module ID:** 49 · **Global ID:** 184
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Keep the first occurrence while preserving case and arrival order.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Frequency Counting](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Return each distinct byte once, in first-appearance order; uppercase and lowercase differ.

```cpp
string removeDuplicates(string s)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Search the output | O(n²) | O(A) result |
| [Better](03_better_approach.cpp) | Ordered membership set | O(n log A) | O(A) |
| [Optimal](04_optimal_solution.cpp) | Byte presence table | O(n) | O(256) plus result |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
