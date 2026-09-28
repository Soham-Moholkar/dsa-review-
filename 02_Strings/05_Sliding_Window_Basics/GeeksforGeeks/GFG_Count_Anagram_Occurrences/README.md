# Count Occurrences of Anagrams

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [Count Occurrences of Anagrams](https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1)
- **Stage:** Sliding Window Basics
- **Module ID:** 54 · **Global ID:** 189
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Revisit fixed windows with GFG argument order and a count result instead of a list of indices.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Sliding Window Basics](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Lowercase strings, nonempty pattern; count overlapping windows whose letters form an anagram of pat. Arguments are pattern then text.

```cpp
int search(string pat, string txt)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Sort each window | O(n m log m) | O(m) |
| [Better](03_better_approach.cpp) | Count each window afresh | O(n(m+26)) | O(26) |
| [Optimal](04_optimal_solution.cpp) | Slide the frequency table | O(26n+m) = O(n+m) | O(26) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
