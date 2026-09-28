# Generate Binary Numbers

- **Platform:** GeeksforGeeks
- **Study difficulty:** Easy
- **Live problem:** [Generate Binary Numbers](https://www.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1)
- **Stage:** Queue Fundamentals
- **Module ID:** 63 · **Global ID:** 206
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

See how FIFO expansion generates states in increasing length and numeric order.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Queue Fundamentals](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Return binary representations of decimal integers 1 through n. Zero returns an empty vector locally.

```cpp
vector<string> generate(int n)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Convert each integer separately | O(T) | O(T) output |
| [Better](03_better_approach.cpp) | Reuse earlier representations | O(T) | O(T) output |
| [Optimal](04_optimal_solution.cpp) | FIFO state expansion | O(T) | O(T) queue and output |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
