# Remove Spaces — explained solution

## Input and result

```cpp
string removeSpaces(string s)
```

Remove literal ASCII spaces; preserve every other character in order. Empty input is a local extension.

## How to think about it

Practise stable filtering and compare erasing with compacting a string.

### Brute Force: Erase each space

Erasing shifts the remaining suffix; keep the same index after an erase.

Time: `O(n²)`. Space: `O(1) auxiliary`.

### Better: Build a filtered output

Append each eligible character to a separate string.

Time: `O(n)`. Space: `O(n) result`.

### Optimal: Compact with a write position

Read each character once, place kept characters in the prefix, then shrink.

Time: `O(n)`. Space: `O(1) auxiliary`.

## Worked trace

For "a b c", the read positions 0, 2, 4 contribute a, b, c. The write position advances only three times; resizing produces "abc".

## Why this works

The written prefix contains exactly the non-space characters already read.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Erase each space | O(n²) | O(1) auxiliary |
| [Better](03_better_approach.cpp) | Build a filtered output | O(n) | O(n) result |
| [Optimal](04_optimal_solution.cpp) | Compact with a write position | O(n) | O(1) auxiliary |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["a b c"]` | `"abc"` |
| `["   "]` | `""` |
| `["x"]` | `"x"` |
| `[" a  b "]` | `"ab"` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Remove_Spaces --sanitize
```
