# Minimum Characters to Add for Palindrome — explained solution

## Input and result

```cpp
int minChar(string s)
```

Only additions at the FRONT are permitted. Return their minimum count; empty input returns zero.

## How to think about it

Use a border computation to recognize the longest palindromic prefix.

### Brute Force: Test decreasing prefix lengths

Find the longest palindromic prefix by comparing mirrored pairs.

Time: `O(n²)`. Space: `O(1)`.

### Better: Same low-memory baseline; no artificial intermediate

This preserves the useful constant-space alternative before introducing the prefix table.

Time: `O(n²)`. Space: `O(1)`.

### Optimal: Prefix function with an out-of-alphabet separator

Encode bytes as integers and use -1 as the separator so input punctuation cannot collide with it.

Time: `O(n)`. Space: `O(n)`.

## Worked trace

For "aacecaaa", the prefix "aacecaa" is palindromic, length 7. One trailing a lies outside it, so one leading a completes the palindrome.

## Why this works

The final border length of source + separator + reverse(source) is its longest palindromic prefix length.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Test decreasing prefix lengths | O(n²) | O(1) |
| [Better](03_better_approach.cpp) | Same low-memory baseline; no artificial intermediate | O(n²) | O(1) |
| [Optimal](04_optimal_solution.cpp) | Prefix function with an out-of-alphabet separator | O(n) | O(n) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["aacecaaa"]` | `1` |
| `["abcd"]` | `3` |
| `["aba"]` | `0` |
| `[""]` | `0` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Min_Chars_for_Palindrome --sanitize
```
