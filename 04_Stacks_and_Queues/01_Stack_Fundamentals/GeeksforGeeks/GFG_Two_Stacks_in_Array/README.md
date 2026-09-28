# Two Stacks in Array

- **Platform:** GeeksforGeeks
- **Study difficulty:** Easy
- **Live problem:** [Two Stacks in Array](https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1)
- **Stage:** Stack Fundamentals
- **Module ID:** 56 · **Global ID:** 199
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Manage two independent LIFO boundaries in shared storage.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Stack Fundamentals](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Public methods: push1, push2, pop1, pop2; empty pop returns -1. Local fixed-array references support at most 100000 total live elements. Values are nonnegative; test operations respect capacity.

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

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Contiguous sections with shifting | O(n) stack1 push/pop; O(1) amortized stack2 push/pop | O(n) |
| [Better](03_better_approach.cpp) | Reserve independent halves | O(1) operations; O(C) initialization | O(2C) |
| [Optimal](04_optimal_solution.cpp) | Share free space between opposing tops | O(1) operations; O(C) initialization | O(C) |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
