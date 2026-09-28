# Minimum Bracket Reversals to Balance — explained solution

## Input and result

```cpp
int countRev(string s)
```

Input uses only { and }. Reverse one brace per operation. Return minimum reversals, or -1 for odd length.

## How to think about it

Distinguish reversal cost from insertion cost and reason about unavoidable repairs.

### Brute Force: Enumerate orientation choices

Try keeping or flipping every brace; reject choices with negative prefix balance or nonzero final balance. Use only small teaching cases.

Time: `O(2^n n)`. Space: `O(n) recursion`.

### Better: Cancel matched pairs with a stack

Cancel {} pairs. The remaining closings and openings each need ceiling(count/2) flips.

Time: `O(n)`. Space: `O(n)`.

### Optimal: Repair balance while scanning

A closing brace with zero balance is forced to reverse. After scanning, reverse half of the remaining openings.

Time: `O(n)`. Space: `O(1)`.

## Worked trace

For "}}{{", the first closing brace must reverse, the second closes it, and the final two openings need one reversal. Total 2. Odd length can never balance.

## Why this works

After repairing an unmatched closing brace, the processed prefix is balanced or has spare openings.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Enumerate orientation choices | O(2^n n) | O(n) recursion |
| [Better](03_better_approach.cpp) | Cancel matched pairs with a stack | O(n) | O(n) |
| [Optimal](04_optimal_solution.cpp) | Repair balance while scanning | O(n) | O(1) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["}}{{"]` | `2` |
| `["{}"]` | `0` |
| `["{{{"]` | `-1` |
| `["}}}}"]` | `2` |
| `["}{"]` | `2` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module queues --problem GFG_Minimum_Bracket_Reversals --sanitize
```
