# Infix to Postfix — explained solution

## Input and result

```cpp
string infixToPostfix(string s)
```

Valid expressions with single alphanumeric operands and binary + - * / ^, with optional parentheses and no spaces. ^ is right-associative; the other operators are left-associative.

## How to think about it

Distinguish precedence, associativity, and parenthesis scope when converting representations.

### Brute Force: Recursive expression splitting

At depth zero, split at the lowest-precedence operator. Choose the rightmost equal-precedence operator for left associativity, but the leftmost ^ for right associativity. Strip an enclosing pair only when it wraps the entire interval.

Time: `O(n²)`. Space: `O(n²) conservative copied-output bound`.

### Better: Operator-stack conversion

Drain only stronger operators, or equal operators when the incoming operator associates left. Parentheses limit draining.

Time: `O(n)`. Space: `O(n)`.

### Optimal: Same linear operator-stack method

Every operator is pushed and popped once; no separate faster third method is needed.

Time: `O(n)`. Space: `O(n)`.

## Worked trace

For a^b^c, the second ^ stays above the first. Draining produces abc^^, which means a^(b^c). For a-b-c, the first - is emitted before pushing the second, producing ab-c-.

## Why this works

Output operands are already in evaluation order; pending operators wait until their right operand is complete.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Recursive expression splitting | O(n²) | O(n²) conservative copied-output bound |
| [Better](03_better_approach.cpp) | Operator-stack conversion | O(n) | O(n) |
| [Optimal](04_optimal_solution.cpp) | Same linear operator-stack method | O(n) | O(n) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["a+b*c"]` | `"abc*+"` |
| `["(a+b)*c"]` | `"ab+c*"` |
| `["a^b^c"]` | `"abc^^"` |
| `["a-b-c"]` | `"ab-c-"` |
| `["x"]` | `"x"` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module queues --problem GFG_Infix_to_Postfix --sanitize
```
