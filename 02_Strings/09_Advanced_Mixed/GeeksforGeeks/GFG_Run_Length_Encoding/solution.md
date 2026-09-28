# Run Length Encoding — explained solution

## Input and result

```cpp
string encode(string s)
```

Encode every consecutive character run as character followed by its decimal count, including count 1. This study adapter uses Solution::encode.

## How to think about it

Keep consecutive runs separate even when the same symbol appears again later.

### Brute Force: Store runs before formatting

Collect character/count pairs first, then serialize them into an output string.

Time: `O(n)`. Space: `O(n)`.

### Better: Serialize each run immediately

Advance a run endpoint and write the run as soon as it is complete.

Time: `O(n)`. Space: `O(n) result; O(1) auxiliary`.

### Optimal: Same linear run scan; no distinct third algorithm

Every input character and output character must be visited; the run scan meets that bound.

Time: `O(n)`. Space: `O(n) result; O(1) auxiliary`.

## Worked trace

For "aaabbcaa", runs are aaa, bb, c, aa. Their encodings a3, b2, c1, a2 concatenate to "a3b2c1a2".

## Why this works

Every completed run has been emitted once; the next unread index begins a new run.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Store runs before formatting | O(n) | O(n) |
| [Better](03_better_approach.cpp) | Serialize each run immediately | O(n) | O(n) result; O(1) auxiliary |
| [Optimal](04_optimal_solution.cpp) | Same linear run scan; no distinct third algorithm | O(n) | O(n) result; O(1) auxiliary |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["aaabbcaa"]` | `"a3b2c1a2"` |
| `["abc"]` | `"a1b1c1"` |
| `["aaaaaaaaaaaa"]` | `"a12"` |
| `[""]` | `""` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Run_Length_Encoding --sanitize
```
