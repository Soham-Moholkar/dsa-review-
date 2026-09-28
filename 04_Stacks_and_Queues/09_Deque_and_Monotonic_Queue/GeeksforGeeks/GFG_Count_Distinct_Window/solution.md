# Count Distinct Elements in Every Window — explained solution

## Input and result

```cpp
vector<int> countDistinct(vector<int>& arr, int k)
```

Return distinct-value counts for every contiguous length-k window. Invalid k returns an empty result locally.

## How to think about it

Revisit the Arrays/Vectors window problem using explicit FIFO expiration and a frequency map.

### Brute Force: Rebuild each window set

Insert each window into a fresh ordered set and report its size.

Time: `O(nk log k)`. Space: `O(k) plus output`.

### Better: Ordered frequency map

Add and remove window endpoints and erase keys only when their frequency reaches zero.

Time: `O(n log k)`. Space: `O(k) plus output`.

### Optimal: FIFO arrivals with a hash frequency map

An explicit queue supplies the expired value, which also works when input arrives as a stream.

Time: `O(n) expected`. Space: `O(k) plus output`.

## Worked trace

For [1,2,1,3], k=3, the first queue contains 1,2,1: two distinct values. Evict one 1 and append 3; the remaining 1 still counts, yielding three distinct values.

## Why this works

The queue stores exactly the active arrivals, while each map count equals its multiplicity in that queue.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Rebuild each window set | O(nk log k) | O(k) plus output |
| [Better](03_better_approach.cpp) | Ordered frequency map | O(n log k) | O(k) plus output |
| [Optimal](04_optimal_solution.cpp) | FIFO arrivals with a hash frequency map | O(n) expected | O(k) plus output |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `[[1, 2, 1, 3], 3]` | `[2, 3]` |
| `[[4, 4, 4], 2]` | `[1, 1]` |
| `[[1, 2, 3], 1]` | `[1, 1, 1]` |
| `[[1], 2]` | `[]` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module queues --problem GFG_Count_Distinct_Window --sanitize
```
