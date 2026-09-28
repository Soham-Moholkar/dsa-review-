# Add Binary Strings — explained solution

## Input and result

```cpp
string addBinary(string a, string b)
```

Inputs are nonempty binary strings, possibly with leading zeroes. Return canonical binary output with no leading zeroes except "0".

## How to think about it

Generalize decimal carry arithmetic to base two without converting the entire number.

### Brute Force: Prepend each computed bit

Simulate columns but insert each new bit at the front, shifting the accumulated result.

Time: `O(L²)`. Space: `O(L)`.

### Better: Append reversed bits

Append in constant amortized time and reverse once after all columns.

Time: `O(L)`. Space: `O(L) result`.

### Optimal: Same linear carry method; no distinct third algorithm

The intermediate method already meets the output-size lower bound. Keep this slot for format consistency.

Time: `O(L)`. Space: `O(L) result`.

## Worked trace

For 11 + 1, the right column gives 0 with carry 1; the next gives 0 with carry 1; the final carry gives 1. Reverse the collected 001 to get 100.

## Why this works

The produced suffix is correct; carry is the unprocessed contribution to the next column.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Prepend each computed bit | O(L²) | O(L) |
| [Better](03_better_approach.cpp) | Append reversed bits | O(L) | O(L) result |
| [Optimal](04_optimal_solution.cpp) | Same linear carry method; no distinct third algorithm | O(L) | O(L) result |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["11", "1"]` | `"100"` |
| `["000", "0"]` | `"0"` |
| `["1010", "1011"]` | `"10101"` |
| `["1", "1111"]` | `"10000"` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Add_Binary_Strings --sanitize
```
