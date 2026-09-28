# Gas Station (Circular Tour) — explained solution

## Input and result

```cpp
int startStation(vector<int>& gas, vector<int>& cost)
```

Equal-length nonempty nonnegative arrays. Start with an empty tank, collect gas[i], and pay cost[i] to reach the next station. Return the first feasible zero-based start, or -1. This adapter uses the modern two-array contract.

## How to think about it

Compare a circular journey simulation with eliminating impossible starting positions.

### Brute Force: Simulate every circular start

Try each start and use modulo indexing to visit exactly n stations.

Time: `O(n²)`. Space: `O(1)`.

### Better: Store prefix balances

A start after the first strict minimum prefix never drops below its initial balance; a negative total rejects all starts.

Time: `O(n)`. Space: `O(n)`.

### Optimal: Eliminate failed candidate segments

Accumulate a total and a candidate tank; reset the candidate only when its tank turns negative. This optimization no longer needs a queue.

Time: `O(n)`. Space: `O(1)`.

## Worked trace

For gas=[1,2,3], cost=[2,2,1], start 0 immediately fails. Start 1 has tank 0, then 2, then 1 after wraparound, so it completes the tour.

## Why this works

When a candidate segment runs out of fuel, every start inside that segment is also ruled out.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Simulate every circular start | O(n²) | O(1) |
| [Better](03_better_approach.cpp) | Store prefix balances | O(n) | O(n) |
| [Optimal](04_optimal_solution.cpp) | Eliminate failed candidate segments | O(n) | O(1) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `[[1, 2, 3], [2, 2, 1]]` | `1` |
| `[[1, 1], [2, 2]]` | `-1` |
| `[[2], [2]]` | `0` |
| `[[2, 2], [1, 1]]` | `0` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module queues --problem GFG_Circular_Tour --sanitize
```
