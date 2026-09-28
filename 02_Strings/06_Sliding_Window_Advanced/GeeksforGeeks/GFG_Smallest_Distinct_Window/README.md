# Smallest Distinct Window

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [Smallest Distinct Window](https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1)
- **Stage:** Sliding Window Advanced
- **Module ID:** 57 · **Global ID:** 192
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Derive a window requirement from the input itself and minimize a valid range.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Sliding Window Advanced](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Return the shortest substring length containing every distinct byte present in s. Empty input returns zero.

```cpp
int findSubString(string s)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Rebuild each interval membership | O(n³) | O(256) |
| [Better](03_better_approach.cpp) | Extend from every start | O(n²) | O(256) |
| [Optimal](04_optimal_solution.cpp) | Shrink complete windows | O(n) | O(256) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
