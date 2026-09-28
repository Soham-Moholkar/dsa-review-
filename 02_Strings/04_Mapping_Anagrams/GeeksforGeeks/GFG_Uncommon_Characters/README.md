# Uncommon Characters

- **Platform:** GeeksforGeeks
- **Study difficulty:** Easy
- **Live problem:** [Uncommon Characters](https://www.geeksforgeeks.org/problems/uncommon-characters4932/1)
- **Stage:** Mapping Anagrams
- **Module ID:** 52 · **Global ID:** 187
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Separate set membership from multiplicity and produce ordered output.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Mapping Anagrams](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Lowercase English input. Return sorted characters present in exactly one string, or "-1" when there are none.

```cpp
string uncommonChars(string s1, string s2)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Search both strings for every letter | O(26(n+m)) | O(1) auxiliary |
| [Better](03_better_approach.cpp) | Symmetric difference of sets | O((n+m) log 26) | O(26) |
| [Optimal](04_optimal_solution.cpp) | Two presence tables | O(n+m+26) | O(26) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
