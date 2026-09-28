# Sum Numbers in a String

- **Platform:** GeeksforGeeks
- **Study difficulty:** Easy
- **Live problem:** [Sum Numbers in a String](https://www.geeksforgeeks.org/problems/sum-of-numbers-in-string-1587115621/1)
- **Stage:** Parsing Conversion
- **Module ID:** 59 · **Global ID:** 194
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Recognize digit runs, flush parsing state at delimiters, and handle a trailing number.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Parsing Conversion](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Alphanumeric input. Sum maximal decimal digit runs; the platform bounds the sum at 100000. No sign syntax is used.

```cpp
int findSum(string s)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Collect and parse digit-run strings | O(n) | O(n) |
| [Better](03_better_approach.cpp) | Streaming decimal accumulator | O(n) | O(1) |
| [Optimal](04_optimal_solution.cpp) | Same constant-state parser; no distinct third algorithm | O(n) | O(1) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
