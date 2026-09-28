# Look and Say Pattern — explained solution

## Input and result

```cpp
string countAndSay(int n)
```

n >= 1. The first row is "1"; every later row describes counts then digits of consecutive runs in the previous row.

## How to think about it

Build one representation from another while keeping source and destination separate.

### Brute Force: Retain every generated row

Save every row for easy inspection; T is the total number of characters generated across rows.

Time: `O(T)`. Space: `O(T)`.

### Better: Keep only consecutive rows

Replace the current row after the next row is complete; L is the largest row length.

Time: `O(T)`. Space: `O(L)`.

### Optimal: Same rolling-row simulation; no distinct third algorithm

Avoid inventing a closed-form shortcut; reading and constructing all intermediate rows is the documented method.

Time: `O(T)`. Space: `O(L)`.

## Worked trace

Rows 1 through 5 are "1", "11", "21", "1211", "111221". In row 4, one 1, one 2, two 1s produce row 5.

## Why this works

Current is the complete previous row, and next describes only its fully consumed runs.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Retain every generated row | O(T) | O(T) |
| [Better](03_better_approach.cpp) | Keep only consecutive rows | O(T) | O(L) |
| [Optimal](04_optimal_solution.cpp) | Same rolling-row simulation; no distinct third algorithm | O(T) | O(L) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `[1]` | `"1"` |
| `[4]` | `"1211"` |
| `[5]` | `"111221"` |
| `[6]` | `"312211"` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Look_and_Say --sanitize
```
