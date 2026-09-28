# Next Element with Greater Frequency

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [Next Element with Greater Frequency](https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1)
- **Stage:** Monotonic Stack
- **Module ID:** 60 · **Global ID:** 203
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Apply the monotonic framework to a derived key instead of comparing raw values.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Monotonic Stack](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

For each position return the nearest value to its right whose total-array frequency is strictly greater; use -1 if none.

```cpp
vector<int> nextFreqGreater(vector<int>& arr)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Recount frequencies during each search | O(n³) | O(n) result |
| [Better](03_better_approach.cpp) | Precount then scan to the right | O(n²) expected | O(n) |
| [Optimal](04_optimal_solution.cpp) | Monotonic stack on frequencies | O(n) expected | O(n) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
