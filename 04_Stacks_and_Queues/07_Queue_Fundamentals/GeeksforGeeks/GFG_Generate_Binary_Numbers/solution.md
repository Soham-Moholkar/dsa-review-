# Generate Binary Numbers — explained solution

## Input and result

```cpp
vector<string> generate(int n)
```

Return binary representations of decimal integers 1 through n. Zero returns an empty vector locally.

## How to think about it

See how FIFO expansion generates states in increasing length and numeric order.

### Brute Force: Convert each integer separately

Repeatedly extract binary digits and reverse each number. T is the total emitted bit count, Theta(n log(n+1)).

Time: `O(T)`. Space: `O(T) output`.

### Better: Reuse earlier representations

The representation of i is that of floor(i/2), followed by its low bit; output storage also holds parent states.

Time: `O(T)`. Space: `O(T) output`.

### Optimal: FIFO state expansion

Pop a prefix and enqueue its two extensions. Avoid generating children after the final output. This is the queue-focused method, not an asymptotic improvement over conversion.

Time: `O(T)`. Space: `O(T) queue and output`.

## Worked trace

Starting with queue [1], emit 1 and enqueue 10,11. Emit 10 and enqueue 100,101. The first four outputs are 1,10,11,100.

## Why this works

The queue removes shorter binary strings before longer ones, and 0-children before 1-children.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Convert each integer separately | O(T) | O(T) output |
| [Better](03_better_approach.cpp) | Reuse earlier representations | O(T) | O(T) output |
| [Optimal](04_optimal_solution.cpp) | FIFO state expansion | O(T) | O(T) queue and output |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `[4]` | `["1", "10", "11", "100"]` |
| `[1]` | `["1"]` |
| `[0]` | `[]` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module queues --problem GFG_Generate_Binary_Numbers --sanitize
```
