# Count Distinct Elements in Every Window

- **Platform:** GeeksforGeeks
- **Study difficulty:** Easy
- **Live problem:** [Count Distinct Elements in Every Window](https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1)
- **Stage:** Deque and Monotonic Queue
- **Module ID:** 65 · **Global ID:** 208
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Revisit the Arrays/Vectors window problem using explicit FIFO expiration and a frequency map.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Deque and Monotonic Queue](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Return distinct-value counts for every contiguous length-k window. Invalid k returns an empty result locally.

```cpp
vector<int> countDistinct(vector<int>& arr, int k)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Rebuild each window set | O(nk log k) | O(k) plus output |
| [Better](03_better_approach.cpp) | Ordered frequency map | O(n log k) | O(k) plus output |
| [Optimal](04_optimal_solution.cpp) | FIFO arrivals with a hash frequency map | O(n) expected | O(k) plus output |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
