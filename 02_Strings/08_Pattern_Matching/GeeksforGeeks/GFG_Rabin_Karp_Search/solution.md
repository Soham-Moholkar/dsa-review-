# Search Pattern (Rabin-Karp Algorithm) — explained solution

## Input and result

```cpp
vector<int> search(string pat, string txt)
```

Nonempty pattern. Return all ONE-BASED starting positions, including overlaps; no match returns an empty vector.

## How to think about it

Compare hashing as a candidate filter with deterministic prefix matching.

### Brute Force: Direct matching at every start

Compare each candidate text window directly with the pattern.

Time: `O(nm)`. Space: `O(1) auxiliary plus output`.

### Better: Rolling hash with collision verification

Roll a base-257 hash modulo a prime. Verify all c hash candidates directly; collisions cannot create false matches.

Time: `O(n+m+cm), O(nm) worst case`. Space: `O(1) auxiliary plus output`.

### Optimal: KMP: guaranteed linear comparison

For a guaranteed bound, reuse the pattern border lengths after mismatch and after each full match.

Time: `O(n+m)`. Space: `O(m) plus output`.

## Worked trace

For pat="aa", txt="aaaa", windows starting at zero-based 0,1,2 match. The returned positions are [1,2,3], with overlaps retained.

## Why this works

A hash match is only a candidate; exact character comparison decides whether it is a real match.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Direct matching at every start | O(nm) | O(1) auxiliary plus output |
| [Better](03_better_approach.cpp) | Rolling hash with collision verification | O(n+m+cm), O(nm) worst case | O(1) auxiliary plus output |
| [Optimal](04_optimal_solution.cpp) | KMP: guaranteed linear comparison | O(n+m) | O(m) plus output |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["aa", "aaaa"]` | `[1, 2, 3]` |
| `["ab", "zabxab"]` | `[2, 5]` |
| `["abc", "ab"]` | `[]` |
| `["x", "aaa"]` | `[]` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Rabin_Karp_Search --sanitize
```
