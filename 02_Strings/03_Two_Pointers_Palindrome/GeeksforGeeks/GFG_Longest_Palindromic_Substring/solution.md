# Longest Palindrome in String — explained solution

## Input and result

```cpp
string longestPalindrome(string s)
```

Return the longest contiguous palindrome, choosing the earliest start on a length tie. Empty input returns an empty string.

## How to think about it

Expand around centers; compare a constant-space solution with a linear-time extension.

### Brute Force: Enumerate and check every interval

Try intervals by increasing start and keep only strictly longer palindromes.

Time: `O(n³)`. Space: `O(n) result`.

### Better: Expand odd and even centers

Every palindrome has a character center or a gap center; expand each while pairs match.

Time: `O(n²)`. Space: `O(1) auxiliary plus result`.

### Optimal: Manacher radius reuse (advanced extension)

Track the palindrome reaching farthest right. Mirror a center inside it, cap the copied radius at its boundary, and compare only new pairs. Odd and even radii avoid separator assumptions. Each successful expansion beyond the boundary advances it, giving linear total work.

Time: `O(n)`. Space: `O(n)`.

## Worked trace

In "cbbd", the gap between the two b characters expands to "bb". Its neighbors c and d differ, so the even radius stops at length 2. Odd centers give length 1.

## Why this works

A radius describes only matching pairs around one center; the best answer retains the earliest maximum.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Enumerate and check every interval | O(n³) | O(n) result |
| [Better](03_better_approach.cpp) | Expand odd and even centers | O(n²) | O(1) auxiliary plus result |
| [Optimal](04_optimal_solution.cpp) | Manacher radius reuse (advanced extension) | O(n) | O(n) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["babad"]` | `"bab"` |
| `["cbbd"]` | `"bb"` |
| `["aaaa"]` | `"aaaa"` |
| `["abc"]` | `"a"` |
| `[""]` | `""` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Longest_Palindromic_Substring --sanitize
```
