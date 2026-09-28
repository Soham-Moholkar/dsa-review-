# Distance of Nearest Cell Having 1

- **Platform:** GeeksforGeeks
- **Study difficulty:** Medium
- **Live problem:** [Distance of Nearest Cell Having 1](https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1)
- **Stage:** Advanced Queue Problems
- **Module ID:** 67 · **Global ID:** 210
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Process multiple initial sources in one FIFO wave and mark states when enqueued.

## Concepts and prerequisites

Queue operations; rectangular matrix bounds; FIFO distance layers. Review [Advanced Queue Problems](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Rectangular nonempty binary matrix. Return shortest four-direction distance to any 1. If no source exists, this local extension returns -1 at every cell.

```cpp
vector<vector<int>> nearest(vector<vector<int>>& grid)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Compare every cell with every source | O((rc)²) | O(rc) result |
| [Better](03_better_approach.cpp) | Separate BFS from each cell | O((rc)²) | O(rc) |
| [Optimal](04_optimal_solution.cpp) | One multi-source BFS | O(rc) | O(rc) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
