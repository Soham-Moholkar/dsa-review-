# Longest Common Prefix of Strings

- **Platform:** GeeksforGeeks
- **Study difficulty:** Easy
- **Live problem:** [Longest Common Prefix of Strings](https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1)
- **Stage:** Basics
- **Module ID:** 47 · **Global ID:** 182
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Compare horizontal and vertical traversal across multiple strings.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Basics](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Return the common prefix; return an empty string when none exists. Some older drivers display -1 for an empty result.

```cpp
string longestCommonPrefix(vector<string>& arr)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Shorten candidate prefixes | O(w L²) | O(L) |
| [Better](03_better_approach.cpp) | Sort a copy and compare extremes | O(w L log w) | O(w L) |
| [Optimal](04_optimal_solution.cpp) | Compare columns | O(w L) | O(L) result |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
