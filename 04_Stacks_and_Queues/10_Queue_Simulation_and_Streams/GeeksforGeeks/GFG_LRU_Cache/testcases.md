# Test cases — LRU Cache

get(key) returns the stored value or -1 and refreshes recency on hits. put refreshes updated keys. Evict the least recently used key when full. Capacity zero is a local extension. std::list supplies stable iterators; no manual node prerequisite.

| Arguments / operations | Expected |
|---|---|
| `["capacity 2", "put 1 10", "put 2 20", "get 1", "put 3 30", "get 2"]` | `[10, -1]` |
| `["capacity 1", "put 1 1", "put 1 2", "get 1"]` | `[2]` |
| `["capacity 0", "put 1 1", "get 1"]` | `[-1]` |

## My cases before coding

1. [add your own case]
2. [add your own case]
