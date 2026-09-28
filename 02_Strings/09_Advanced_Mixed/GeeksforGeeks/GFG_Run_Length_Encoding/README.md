# Run Length Encoding

- **Platform:** GeeksforGeeks
- **Study difficulty:** Easy
- **Live problem:** [Run Length Encoding](https://www.geeksforgeeks.org/problems/run-length-encoding/1)
- **Stage:** Advanced Mixed
- **Module ID:** 62 · **Global ID:** 197
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Keep consecutive runs separate even when the same symbol appears again later.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Advanced Mixed](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Encode every consecutive character run as character followed by its decimal count, including count 1. This study adapter uses Solution::encode.

```cpp
string encode(string s)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Store runs before formatting | O(n) | O(n) |
| [Better](03_better_approach.cpp) | Serialize each run immediately | O(n) | O(n) result; O(1) auxiliary |
| [Optimal](04_optimal_solution.cpp) | Same linear run scan; no distinct third algorithm | O(n) | O(n) result; O(1) auxiliary |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
