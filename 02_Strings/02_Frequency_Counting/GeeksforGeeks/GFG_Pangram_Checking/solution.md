# Pangram Checking — explained solution

## Input and result

```cpp
bool checkPangram(string s)
```

Check whether all 26 English letters occur, ignoring ASCII case and nonletters.

## How to think about it

Distinguish character presence from multiplicity and handle case consistently.

### Brute Force: Search for every letter

For each letter, scan the full input and compare after lowercasing.

Time: `O(26n)`. Space: `O(1)`.

### Better: Collect letters in a set

Insert normalized letters into an ordered set and inspect its size.

Time: `O(n log 26)`. Space: `O(26)`.

### Optimal: Fixed presence table

A fixed alphabet needs only 26 flags; duplicate letters leave flags unchanged.

Time: `O(n)`. Space: `O(26) = O(1)`.

## Worked trace

In the alphabet followed by extra a characters, all 26 flags are true; repeats do not change coverage. Removing z leaves exactly one flag false.

## Why this works

Each seen bit means that its letter has appeared at least once.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Search for every letter | O(26n) | O(1) |
| [Better](03_better_approach.cpp) | Collect letters in a set | O(n log 26) | O(26) |
| [Optimal](04_optimal_solution.cpp) | Fixed presence table | O(n) | O(26) = O(1) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["The quick brown fox jumps over the lazy dog"]` | `true` |
| `["abcdefghijklmnopqrstuvwxy"]` | `false` |
| `["ABCDEFGHIJKLMNOPQRSTUVWXYZ"]` | `true` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Pangram_Checking --sanitize
```
