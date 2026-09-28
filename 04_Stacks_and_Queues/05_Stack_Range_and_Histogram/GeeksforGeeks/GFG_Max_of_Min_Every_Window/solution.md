# Max of Min for Every Window Size — explained solution

## Input and result

```cpp
vector<int> maxOfMins(vector<int>& arr)
```

Return n values: result[k-1] is the largest minimum among all contiguous windows of size k. Negative values are supported.

## How to think about it

Use smaller-element boundaries to aggregate answers for all window sizes.

### Brute Force: Scan every window for every size

Enumerate window sizes and starts, then scan each window for its minimum.

Time: `O(n³)`. Space: `O(n) result`.

### Better: Run one monotonic deque per size

For each size, maintain a deque of increasing candidates; this computes all minima in one pass per size.

Time: `O(n²)`. Space: `O(n)`.

### Optimal: Smaller boundaries plus downward propagation

Find previous and next strictly smaller indices, assign each value to its maximum span, then propagate from larger lengths to smaller lengths. Equal heights can share a span because we maximize rather than count contributions.

Time: `O(n)`. Space: `O(n)`.

## Worked trace

For [2,1,3], size-1 minima are 2,1,3 so best=3; size-2 minima are 1,1 so best=1; size-3 minimum is 1. Answer [3,1,1].

## Why this works

Each value contributes to the largest span in which no strictly smaller value blocks it; shorter answers inherit larger-span candidates.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Scan every window for every size | O(n³) | O(n) result |
| [Better](03_better_approach.cpp) | Run one monotonic deque per size | O(n²) | O(n) |
| [Optimal](04_optimal_solution.cpp) | Smaller boundaries plus downward propagation | O(n) | O(n) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `[[2, 1, 3]]` | `[3, 1, 1]` |
| `[[2, 2]]` | `[2, 2]` |
| `[[-2, -1, -3]]` | `[-1, -2, -3]` |
| `[[7]]` | `[7]` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module queues --problem GFG_Max_of_Min_Every_Window --sanitize
```
