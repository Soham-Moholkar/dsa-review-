# Make Anagram with Removals — explained solution

## Input and result

```cpp
int remAnagram(string s1, string s2)
```

Lowercase strings; deletion from either string costs one. Return the minimum total deletions.

## How to think about it

Model unmatched character multiplicities as the minimum required deletions.

### Brute Force: Match and consume occurrences

Mark each matching occurrence in the second string; unmatched characters on either side are deletions.

Time: `O(nm)`. Space: `O(m)`.

### Better: Sort and merge

Sorted equal letters match; advance the smaller unmatched letter and count its deletion.

Time: `O(n log n + m log m)`. Space: `O(log n + log m)`.

### Optimal: Signed frequency difference

Increment for the first string, decrement for the second, and sum absolute imbalances.

Time: `O(n+m)`. Space: `O(26)`.

## Worked trace

For "aab" and "abb", a has counts 2 and 1, b has counts 1 and 2. Delete one a and one b: total 2.

## Why this works

For each letter, only the absolute difference between its counts must be deleted.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Match and consume occurrences | O(nm) | O(m) |
| [Better](03_better_approach.cpp) | Sort and merge | O(n log n + m log m) | O(log n + log m) |
| [Optimal](04_optimal_solution.cpp) | Signed frequency difference | O(n+m) | O(26) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["aab", "abb"]` | `2` |
| `["abc", "abc"]` | `0` |
| `["a", "z"]` | `2` |
| `["", "abc"]` | `3` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Make_Anagram_with_Removals --sanitize
```
