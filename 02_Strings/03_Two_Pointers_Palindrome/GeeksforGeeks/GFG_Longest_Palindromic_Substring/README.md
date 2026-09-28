# Longest Palindrome in String

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [Longest Palindrome in String](https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1)
- **Stage:** Two Pointers Palindrome
- **Module ID:** 51 · **Global ID:** 186
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Expand around centers; compare a constant-space solution with a linear-time extension.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Two Pointers Palindrome](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Return the longest contiguous palindrome, choosing the earliest start on a length tie. Empty input returns an empty string.

```cpp
string longestPalindrome(string s)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Enumerate and check every interval | O(n³) | O(n) result |
| [Better](03_better_approach.cpp) | Expand odd and even centers | O(n²) | O(1) auxiliary plus result |
| [Optimal](04_optimal_solution.cpp) | Manacher radius reuse (advanced extension) | O(n) | O(n) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
