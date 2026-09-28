# Make Anagram with Removals

- **Platform:** GeeksforGeeks
- **Study difficulty:** Easy
- **Live problem:** [Make Anagram with Removals](https://www.geeksforgeeks.org/problems/anagram-of-string/1)
- **Stage:** Mapping Anagrams
- **Module ID:** 53 · **Global ID:** 188
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Model unmatched character multiplicities as the minimum required deletions.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Mapping Anagrams](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Lowercase strings; deletion from either string costs one. Return the minimum total deletions.

```cpp
int remAnagram(string s1, string s2)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Match and consume occurrences | O(nm) | O(m) |
| [Better](03_better_approach.cpp) | Sort and merge | O(n log n + m log m) | O(log n + log m) |
| [Optimal](04_optimal_solution.cpp) | Signed frequency difference | O(n+m) | O(26) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
