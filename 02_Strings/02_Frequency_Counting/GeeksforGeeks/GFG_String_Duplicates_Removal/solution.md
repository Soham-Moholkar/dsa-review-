# String Duplicates Removal — explained solution

## Input and result

```cpp
string removeDuplicates(string s)
```

Return each distinct byte once, in first-appearance order; uppercase and lowercase differ.

## How to think about it

Keep the first occurrence while preserving case and arrival order.

### Brute Force: Search the output

Check the accumulated output before appending the next character.

Time: `O(n²)`. Space: `O(A) result`.

### Better: Ordered membership set

Use a set for membership but append to a string to preserve first-seen order.

Time: `O(n log A)`. Space: `O(A)`.

### Optimal: Byte presence table

Index by unsigned char so every byte gives a valid nonnegative table index.

Time: `O(n)`. Space: `O(256) plus result`.

## Worked trace

For "banana", retain b, a, n; the later a, n, a were already seen. The result is "ban".

## Why this works

The result contains the first occurrence of every character in the processed prefix.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Search the output | O(n²) | O(A) result |
| [Better](03_better_approach.cpp) | Ordered membership set | O(n log A) | O(A) |
| [Optimal](04_optimal_solution.cpp) | Byte presence table | O(n) | O(256) plus result |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["banana"]` | `"ban"` |
| `["aaaa"]` | `"a"` |
| `["AaA"]` | `"Aa"` |
| `["abc"]` | `"abc"` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_String_Duplicates_Removal --sanitize
```
