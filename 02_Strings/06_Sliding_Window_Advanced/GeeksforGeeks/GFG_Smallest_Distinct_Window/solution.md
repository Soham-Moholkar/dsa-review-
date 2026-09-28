# Smallest Distinct Window — explained solution

## Input and result

```cpp
int findSubString(string s)
```

Return the shortest substring length containing every distinct byte present in s. Empty input returns zero.

## How to think about it

Derive a window requirement from the input itself and minimize a valid range.

### Brute Force: Rebuild each interval membership

Enumerate intervals and test each set against the full required set.

Time: `O(n³)`. Space: `O(256)`.

### Better: Extend from every start

For each left endpoint, stop at its first complete window.

Time: `O(n²)`. Space: `O(256)`.

### Optimal: Shrink complete windows

Count required letters, then shrink each complete window while recording lengths.

Time: `O(n)`. Space: `O(256)`.

## Worked trace

For "aabcbcdbca", four letters are required. The suffix "dbca" contains all four in length 4; no length-3 window can contain four distinct letters.

## Why this works

A window is complete exactly when its distinct count equals the whole-string distinct count.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Rebuild each interval membership | O(n³) | O(256) |
| [Better](03_better_approach.cpp) | Extend from every start | O(n²) | O(256) |
| [Optimal](04_optimal_solution.cpp) | Shrink complete windows | O(n) | O(256) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["aabcbcdbca"]` | `4` |
| `["aaaa"]` | `1` |
| `["abc"]` | `3` |
| `[""]` | `0` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Smallest_Distinct_Window --sanitize
```
