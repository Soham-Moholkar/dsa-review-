# Count Occurrences of Anagrams — explained solution

## Input and result

```cpp
int search(string pat, string txt)
```

Lowercase strings, nonempty pattern; count overlapping windows whose letters form an anagram of pat. Arguments are pattern then text.

## How to think about it

Revisit fixed windows with GFG argument order and a count result instead of a list of indices.

### Brute Force: Sort each window

Sort the pattern once and compare it with a sorted copy of every length-m window.

Time: `O(n m log m)`. Space: `O(m)`.

### Better: Count each window afresh

Compare frequency arrays rather than sorting; overlapping windows still repeat counting work.

Time: `O(n(m+26))`. Space: `O(26)`.

### Optimal: Slide the frequency table

Add the incoming character and remove the outgoing character before checking equality.

Time: `O(26n+m) = O(n+m)`. Space: `O(26)`.

## Worked trace

For pat="ab", txt="abab", windows ab, ba, ab all have one a and one b, so overlapping matches give 3.

## Why this works

The live frequency table covers exactly the current pattern-length window.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Sort each window | O(n m log m) | O(m) |
| [Better](03_better_approach.cpp) | Count each window afresh | O(n(m+26)) | O(26) |
| [Optimal](04_optimal_solution.cpp) | Slide the frequency table | O(26n+m) = O(n+m) | O(26) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["ab", "abab"]` | `3` |
| `["abc", "ab"]` | `0` |
| `["aa", "aaaa"]` | `3` |
| `["a", "bbbb"]` | `0` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Count_Anagram_Occurrences --sanitize
```
