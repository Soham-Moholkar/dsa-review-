# Substrings of Length K with K-1 Distinct Characters — explained solution

## Input and result

```cpp
int substrCount(string s, int k)
```

Lowercase input; count length-k substrings with exactly k-1 distinct characters. k outside 1..n returns zero locally.

## How to think about it

Update a distinct-character count precisely when a frequency crosses zero.

### Brute Force: Build a set for each window

Recompute membership for every window and test its cardinality.

Time: `O(nk log 26)`. Space: `O(26)`.

### Better: Slide counts and recount active letters

Reuse character counts, then inspect the 26 counts for every complete window.

Time: `O(26n)`. Space: `O(26)`.

### Optimal: Maintain zero-crossing count

A 0-to-1 count adds a distinct letter and a 1-to-0 count removes one.

Time: `O(n)`. Space: `O(26)`.

## Worked trace

For "aabac", k=3, windows aab and aba each have two distinct letters; bac has three. Answer 2.

## Why this works

Distinct equals the number of positive frequencies in the current window.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Build a set for each window | O(nk log 26) | O(26) |
| [Better](03_better_approach.cpp) | Slide counts and recount active letters | O(26n) | O(26) |
| [Optimal](04_optimal_solution.cpp) | Maintain zero-crossing count | O(n) | O(26) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["aabac", 3]` | `2` |
| `["aaaa", 2]` | `3` |
| `["abc", 1]` | `0` |
| `["abc", 4]` | `0` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_K_Length_K_Minus_One_Distinct --sanitize
```
