# Max of Min for Every Window Size

- **Platform:** GeeksforGeeks
- **Study difficulty:** Hard
- **Live problem:** [Max of Min for Every Window Size](https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1)
- **Stage:** Stack Range and Histogram
- **Module ID:** 61 · **Global ID:** 204
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Use smaller-element boundaries to aggregate answers for all window sizes.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Stack Range and Histogram](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Return n values: result[k-1] is the largest minimum among all contiguous windows of size k. Negative values are supported.

```cpp
vector<int> maxOfMins(vector<int>& arr)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Scan every window for every size | O(n³) | O(n) result |
| [Better](03_better_approach.cpp) | Run one monotonic deque per size | O(n²) | O(n) |
| [Optimal](04_optimal_solution.cpp) | Smaller boundaries plus downward propagation | O(n) | O(n) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
