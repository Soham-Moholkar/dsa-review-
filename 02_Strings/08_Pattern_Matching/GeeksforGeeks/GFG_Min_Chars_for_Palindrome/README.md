# Minimum Characters to Add for Palindrome

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [Minimum Characters to Add for Palindrome](https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1)
- **Stage:** Pattern Matching
- **Module ID:** 61 · **Global ID:** 196
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Use a border computation to recognize the longest palindromic prefix.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Pattern Matching](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Only additions at the FRONT are permitted. Return their minimum count; empty input returns zero.

```cpp
int minChar(string s)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Test decreasing prefix lengths | O(n²) | O(1) |
| [Better](03_better_approach.cpp) | Same low-memory baseline; no artificial intermediate | O(n²) | O(1) |
| [Optimal](04_optimal_solution.cpp) | Prefix function with an out-of-alphabet separator | O(n) | O(n) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
