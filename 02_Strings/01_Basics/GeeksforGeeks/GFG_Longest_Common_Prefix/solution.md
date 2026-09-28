# Longest Common Prefix of Strings — explained solution

## Input and result

```cpp
string longestCommonPrefix(vector<string>& arr)
```

Return the common prefix; return an empty string when none exists. Some older drivers display -1 for an empty result.

## How to think about it

Compare horizontal and vertical traversal across multiple strings.

### Brute Force: Shorten candidate prefixes

Try shorter copies of the first string until each other string starts with it.

Time: `O(w L²)`. Space: `O(L)`.

### Better: Sort a copy and compare extremes

The first and last sorted strings bound all other strings lexicographically.

Time: `O(w L log w)`. Space: `O(w L)`.

### Optimal: Compare columns

Stop at the first missing or unequal character in any string.

Time: `O(w L)`. Space: `O(L) result`.

## Worked trace

For ["flower","flow","flight"], columns f and l match. Column 2 contains o, o, i, so the answer is "fl".

## Why this works

Every accepted prefix position agrees across all strings.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Shorten candidate prefixes | O(w L²) | O(L) |
| [Better](03_better_approach.cpp) | Sort a copy and compare extremes | O(w L log w) | O(w L) |
| [Optimal](04_optimal_solution.cpp) | Compare columns | O(w L) | O(L) result |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `[["flower", "flow", "flight"]]` | `"fl"` |
| `[["dog", "racecar", "car"]]` | `""` |
| `[["solo"]]` | `"solo"` |
| `[["", "abc"]]` | `""` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Longest_Common_Prefix --sanitize
```
