# LRU Cache — explained solution

## Input and result

```cpp
class LRUCache {
public:
    LRUCache(int capacity) {}
    int get(int key) {}
    void put(int key, int value) {}
};
```

get(key) returns the stored value or -1 and refreshes recency on hits. put refreshes updated keys. Evict the least recently used key when full. Capacity zero is a local extension. std::list supplies stable iterators; no manual node prerequisite.

## How to think about it

Distinguish arrival order from access recency and combine keyed lookup with eviction order.

### Brute Force: Scan and move in a vector

Store most recent first. Search linearly, erase the found pair, and reinsert it at the front.

Time: `O(C) per operation`. Space: `O(C)`.

### Better: Ordered map plus recency list

A tree map locates stable list iterators; splice moves a node without invalidating its iterator.

Time: `O(log C) per operation`. Space: `O(C)`.

### Optimal: Hash map plus recency list

Hash lookup locates a node, splice refreshes it, and back eviction removes the least recent key. Expected time assumes ordinary hash behavior.

Time: `O(1) expected per operation`. Space: `O(C)`.

## Worked trace

With capacity 2: put(1,10), put(2,20), get(1) makes key 1 newest. put(3,30) evicts key 2. A read miss changes no recency.

## Why this works

The list front is most recently used, the back least recently used, and each map iterator points to its unique live list node.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Scan and move in a vector | O(C) per operation | O(C) |
| [Better](03_better_approach.cpp) | Ordered map plus recency list | O(log C) per operation | O(C) |
| [Optimal](04_optimal_solution.cpp) | Hash map plus recency list | O(1) expected per operation | O(C) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["capacity 2", "put 1 10", "put 2 20", "get 1", "put 3 30", "get 2"]` | `[10, -1]` |
| `["capacity 1", "put 1 1", "put 1 2", "get 1"]` | `[2]` |
| `["capacity 0", "put 1 1", "get 1"]` | `[-1]` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module queues --problem GFG_LRU_Cache --sanitize
```
