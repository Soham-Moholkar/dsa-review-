# Distance of Nearest Cell Having 1 — explained solution

## Input and result

```cpp
vector<vector<int>> nearest(vector<vector<int>>& grid)
```

Rectangular nonempty binary matrix. Return shortest four-direction distance to any 1. If no source exists, this local extension returns -1 at every cell.

## How to think about it

Process multiple initial sources in one FIFO wave and mark states when enqueued.

### Brute Force: Compare every cell with every source

With no obstacles, Manhattan distance equals shortest four-direction distance. Scan all ones for each cell.

Time: `O((rc)²)`. Space: `O(rc) result`.

### Better: Separate BFS from each cell

Start one queue search per cell and stop at its first one. This teaches FIFO shortest distance before sharing the searches.

Time: `O((rc)²)`. Space: `O(rc)`.

### Optimal: One multi-source BFS

Enqueue every source at distance zero. Mark a neighbor as soon as it enters the queue so it cannot be enqueued again.

Time: `O(rc)`. Space: `O(rc)`.

## Worked trace

For [[0,0,1],[0,0,0]], begin with (0,2) at distance 0. Its neighbors receive 1, then the next wave receives 2. Result [[2,1,0],[3,2,1]].

## Why this works

Each enqueued cell has its shortest distance because FIFO processes every smaller distance first.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Compare every cell with every source | O((rc)²) | O(rc) result |
| [Better](03_better_approach.cpp) | Separate BFS from each cell | O((rc)²) | O(rc) |
| [Optimal](04_optimal_solution.cpp) | One multi-source BFS | O(rc) | O(rc) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `[[[0, 0, 1], [0, 0, 0]]]` | `[[2, 1, 0], [3, 2, 1]]` |
| `[[[1]]]` | `[[0]]` |
| `[[[0, 0]]]` | `[[-1, -1]]` |
| `[[[1, 0, 1]]]` | `[[0, 1, 0]]` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module queues --problem GFG_Nearest_One_Distance --sanitize
```
