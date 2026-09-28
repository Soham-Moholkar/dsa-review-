# Search Pattern (Rabin-Karp Algorithm)

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [Search Pattern (Rabin-Karp Algorithm)](https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1)
- **Stage:** Pattern Matching
- **Module ID:** 60 · **Global ID:** 195
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Compare hashing as a candidate filter with deterministic prefix matching.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Pattern Matching](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Nonempty pattern. Return all ONE-BASED starting positions, including overlaps; no match returns an empty vector.

```cpp
vector<int> search(string pat, string txt)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Direct matching at every start | O(nm) | O(1) auxiliary plus output |
| [Better](03_better_approach.cpp) | Rolling hash with collision verification | O(n+m+cm), O(nm) worst case | O(1) auxiliary plus output |
| [Optimal](04_optimal_solution.cpp) | KMP: guaranteed linear comparison | O(n+m) | O(m) plus output |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
