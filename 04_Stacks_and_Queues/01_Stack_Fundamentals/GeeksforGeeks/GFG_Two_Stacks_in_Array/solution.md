# Two Stacks in Array — explained solution

## Input and result

```cpp
class twoStacks {
public:
    twoStacks() {}
    void push1(int x) {}
    void push2(int x) {}
    int pop1() {}
    int pop2() {}
};
```

Public methods: push1, push2, pop1, pop2; empty pop returns -1. Local fixed-array references support at most 100000 total live elements. Values are nonnegative; test operations respect capacity.

## How to think about it

Manage two independent LIFO boundaries in shared storage.

### Brute Force: Contiguous sections with shifting

The split marks the first stack end; inserting there shifts stack2 without changing its order.

Time: `O(n) stack1 push/pop; O(1) amortized stack2 push/pop`. Space: `O(n)`.

### Better: Reserve independent halves

Give each stack C positions. This satisfies the documented bound but wastes the unused half when only one stack grows.

Time: `O(1) operations; O(C) initialization`. Space: `O(2C)`.

### Optimal: Share free space between opposing tops

With a total-live-elements bound C, grow inward from opposite ends to share every free slot.

Time: `O(1) operations; O(C) initialization`. Space: `O(C)`.

## Worked trace

Push1(10), push2(20), push1(30) leaves stack1=[10,30] and stack2=[20]. Pop1 returns 30; pop2 returns 20; neither operation changes the other stack.

## Why this works

The first stack grows from the left, the second from the right, and their occupied ranges never overlap.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Contiguous sections with shifting | O(n) stack1 push/pop; O(1) amortized stack2 push/pop | O(n) |
| [Better](03_better_approach.cpp) | Reserve independent halves | O(1) operations; O(C) initialization | O(2C) |
| [Optimal](04_optimal_solution.cpp) | Share free space between opposing tops | O(1) operations; O(C) initialization | O(C) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `["push1 10", "push2 20", "pop1", "pop2"]` | `[10, 20]` |
| `["pop1", "pop2"]` | `[-1, -1]` |
| `["push2 7", "push2 9", "pop2"]` | `[9]` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module queues --problem GFG_Two_Stacks_in_Array --sanitize
```
