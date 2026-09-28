# LRU Cache

- **Platform:** GeeksforGeeks
- **Study difficulty:** Hard
- **Live problem:** [LRU Cache](https://www.geeksforgeeks.org/problems/lru-cache/1)
- **Stage:** Queue Simulation and Streams
- **Module ID:** 66 · **Global ID:** 209
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Distinguish arrival order from access recency and combine keyed lookup with eviction order.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Queue Simulation and Streams](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

get(key) returns the stored value or -1 and refreshes recency on hits. put refreshes updated keys. Evict the least recently used key when full. Capacity zero is a local extension. std::list supplies stable iterators; no manual node prerequisite.

```cpp
class LRUCache {
public:
    LRUCache(int capacity) {}
    int get(int key) {}
    void put(int key, int value) {}
};
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Scan and move in a vector | O(C) per operation | O(C) |
| [Better](03_better_approach.cpp) | Ordered map plus recency list | O(log C) per operation | O(C) |
| [Optimal](04_optimal_solution.cpp) | Hash map plus recency list | O(1) expected per operation | O(C) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
