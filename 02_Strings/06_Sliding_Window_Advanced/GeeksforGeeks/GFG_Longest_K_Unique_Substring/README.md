# Longest Substring with K Uniques

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [Longest Substring with K Uniques](https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)
- **Stage:** Sliding Window Advanced
- **Module ID:** 56 · **Global ID:** 191
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Distinguish exactly-k acceptance from at-most-k window maintenance.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Sliding Window Advanced](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Lowercase input; return the longest nonempty substring length with exactly k distinct letters, or -1 if none exists.

```cpp
int longestKSubstr(string s, int k)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Enumerate intervals and rebuild sets | O(n³) | O(26) |
| [Better](03_better_approach.cpp) | Extend each left boundary | O(n²) | O(26) |
| [Optimal](04_optimal_solution.cpp) | Variable sliding window | O(n) | O(26) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
