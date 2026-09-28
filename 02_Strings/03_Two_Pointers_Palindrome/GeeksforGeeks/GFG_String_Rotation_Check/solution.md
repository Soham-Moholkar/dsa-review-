# String Rotation Check — explained solution

## Input and result

```cpp
bool areRotations(string s1, string s2)
```

Equal-length strings are rotations when one cyclic shift matches the other. Two empty strings return true locally.

## How to think about it

Connect circular positions to substring matching and revisit after the pattern-matching stage.

### Brute Force: Compare every cyclic shift

Try every start position and compare characters with wraparound.

Time: `O(n²)`. Space: `O(1)`.

### Better: Search the doubled string

Use library substring search; do not claim a guaranteed linear std::string::find.

Time: `O(n²) worst case`. Space: `O(n)`.

### Optimal: KMP over doubled source

Build the target prefix table, then scan two source copies without materializing them. Study this file after stage 08.

Time: `O(n)`. Space: `O(n)`.

## Worked trace

For "abcd" and "cdab", the doubled source is "abcdabcd". Matching from position 2 consumes c,d,a,b; unequal lengths are rejected first.

## Why this works

A length-n rotation is a length-n substring of the doubled source.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Compare every cyclic shift | O(n²) | O(1) |
| [Better](03_better_approach.cpp) | Search the doubled string | O(n²) worst case | O(n) |
| [Optimal](04_optimal_solution.cpp) | KMP over doubled source | O(n) | O(n) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["abcd", "cdab"]` | `true` |
| `["abcd", "acbd"]` | `false` |
| `["aaaa", "aaaa"]` | `true` |
| `["ab", "a"]` | `false` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_String_Rotation_Check --sanitize
```
