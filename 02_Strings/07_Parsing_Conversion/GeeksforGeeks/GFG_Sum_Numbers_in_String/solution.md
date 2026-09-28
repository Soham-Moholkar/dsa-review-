# Sum Numbers in a String — explained solution

## Input and result

```cpp
int findSum(string s)
```

Alphanumeric input. Sum maximal decimal digit runs; the platform bounds the sum at 100000. No sign syntax is used.

## How to think about it

Recognize digit runs, flush parsing state at delimiters, and handle a trailing number.

### Brute Force: Collect and parse digit-run strings

Store completed runs, then convert and sum them. Leading zeros are discarded during conversion.

Time: `O(n)`. Space: `O(n)`.

### Better: Streaming decimal accumulator

Keep one current number and commit it when a nondigit arrives.

Time: `O(n)`. Space: `O(1)`.

### Optimal: Same constant-state parser; no distinct third algorithm

The streaming parser already inspects each character once with constant state.

Time: `O(n)`. Space: `O(1)`.

## Worked trace

For "12a003b4", reading a commits 12, b commits 3, and the final flush commits 4. Total 19.

## Why this works

Answer contains completed runs; current contains only the unfinished decimal run.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Collect and parse digit-run strings | O(n) | O(n) |
| [Better](03_better_approach.cpp) | Streaming decimal accumulator | O(n) | O(1) |
| [Optimal](04_optimal_solution.cpp) | Same constant-state parser; no distinct third algorithm | O(n) | O(1) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["12a003b4"]` | `19` |
| `["abc"]` | `0` |
| `["0007"]` | `7` |
| `["1a2b3"]` | `6` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module strings --problem GFG_Sum_Numbers_in_String --sanitize
```
