# Uncommon Characters — explained solution

## Input and result

```cpp
string uncommonChars(string s1, string s2)
```

Lowercase English input. Return sorted characters present in exactly one string, or "-1" when there are none.

## How to think about it

Separate set membership from multiplicity and produce ordered output.

### Brute Force: Search both strings for every letter

For every lowercase letter, compare whether each string contains it.

Time: `O(26(n+m))`. Space: `O(1) auxiliary`.

### Better: Symmetric difference of sets

Build ordered sets and use symmetric difference to retain membership in exactly one.

Time: `O((n+m) log 26)`. Space: `O(26)`.

### Optimal: Two presence tables

Scan both strings once and emit differing flags in alphabet order.

Time: `O(n+m+26)`. Space: `O(26)`.

## Worked trace

For "abca" and "bcd", a belongs only to the first and d only to the second. b and c belong to both. Emit "ad" once each.

## Why this works

A character is output exactly when its two membership flags differ.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Search both strings for every letter | O(26(n+m)) | O(1) auxiliary |
| [Better](03_better_approach.cpp) | Symmetric difference of sets | O((n+m) log 26) | O(26) |
| [Optimal](04_optimal_solution.cpp) | Two presence tables | O(n+m+26) | O(26) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["abca", "bcd"]` | `"ad"` |
| `["aa", "a"]` | `"-1"` |
| `["z", "a"]` | `"az"` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Uncommon_Characters --sanitize
```
