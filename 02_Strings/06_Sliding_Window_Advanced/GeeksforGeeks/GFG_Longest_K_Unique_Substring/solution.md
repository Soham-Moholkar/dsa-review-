# Longest Substring with K Uniques — explained solution

## Input and result

```cpp
int longestKSubstr(string s, int k)
```

Lowercase input; return the longest nonempty substring length with exactly k distinct letters, or -1 if none exists.

## How to think about it

Distinguish exactly-k acceptance from at-most-k window maintenance.

### Brute Force: Enumerate intervals and rebuild sets

For each interval, count its distinct characters from scratch.

Time: `O(n³)`. Space: `O(26)`.

### Better: Extend each left boundary

Maintain counts while extending one start, then restart for the next start.

Time: `O(n²)`. Space: `O(26)`.

### Optimal: Variable sliding window

Move the left edge only when distinct exceeds k. Each character enters and leaves at most once.

Time: `O(n)`. Space: `O(26)`.

## Worked trace

For "aabac", k=2, the window grows through "aaba" with two letters. Adding c makes three; removing left characters eventually restores a,c. Best length remains 4.

## Why this works

After shrinking, the live window has at most k distinct letters; record it only at exactly k.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Enumerate intervals and rebuild sets | O(n³) | O(26) |
| [Better](03_better_approach.cpp) | Extend each left boundary | O(n²) | O(26) |
| [Optimal](04_optimal_solution.cpp) | Variable sliding window | O(n) | O(26) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["aabac", 2]` | `4` |
| `["aaaa", 2]` | `-1` |
| `["aaaa", 1]` | `4` |
| `["abc", 0]` | `-1` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Longest_K_Unique_Substring --sanitize
```
