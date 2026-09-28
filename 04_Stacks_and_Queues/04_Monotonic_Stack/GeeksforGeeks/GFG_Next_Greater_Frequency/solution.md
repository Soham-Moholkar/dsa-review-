# Next Element with Greater Frequency — explained solution

## Input and result

```cpp
vector<int> nextFreqGreater(vector<int>& arr)
```

For each position return the nearest value to its right whose total-array frequency is strictly greater; use -1 if none.

## How to think about it

Apply the monotonic framework to a derived key instead of comparing raw values.

### Brute Force: Recount frequencies during each search

For each candidate pair, count both values directly in the full array.

Time: `O(n³)`. Space: `O(n) result`.

### Better: Precount then scan to the right

Build frequencies once, then search directly for every position.

Time: `O(n²) expected`. Space: `O(n)`.

### Optimal: Monotonic stack on frequencies

Pop values with no greater frequency: the closer current value dominates them for future positions to its left.

Time: `O(n) expected`. Space: `O(n)`.

## Worked trace

For [1,1,2,3,2,1], frequencies are 1:3, 2:2, 3:1. The 3 resolves to the following 2; each 2 resolves to the final 1. Answer [-1,-1,1,2,1,-1].

## Why this works

Stack candidates have strictly decreasing frequency from bottom to top when scanning right to left.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Recount frequencies during each search | O(n³) | O(n) result |
| [Better](03_better_approach.cpp) | Precount then scan to the right | O(n²) expected | O(n) |
| [Optimal](04_optimal_solution.cpp) | Monotonic stack on frequencies | O(n) expected | O(n) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `[[1, 1, 2, 3, 2, 1]]` | `[-1, -1, 1, 2, 1, -1]` |
| `[[4, 4, 4]]` | `[-1, -1, -1]` |
| `[[1, 2, 3]]` | `[-1, -1, -1]` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module queues --problem GFG_Next_Greater_Frequency --sanitize
```
