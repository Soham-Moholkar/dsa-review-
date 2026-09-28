# Validate Stack Operations — explained solution

## Input and result

```cpp
bool isStackPermutation(vector<int>& a, vector<int>& b)
```

Equal-length arrays of distinct values give push and required pop order. This local adapter returns bool and omits redundant n. Revisit Validate Stack Sequences using the GFG contract.

## How to think about it

Compare recursive search through operation choices with a forced-pop stack simulation.

### Brute Force: Explore legal push/pop sequences

Recursively try pushing the next input and popping only a matching top. This exponential teaching baseline is for small examples.

Time: `O(4^n n) upper bound`. Space: `O(n²) copied states`.

### Better: Greedy std::stack simulation

Push in order, then consume every requested pop currently available at the top.

Time: `O(n)`. Space: `O(n)`.

### Optimal: Same linear simulation with vector storage

A vector back is another LIFO implementation; the algorithm and asymptotic bound are the same.

Time: `O(n)`. Space: `O(n)`.

## Worked trace

For a=[1,2,3], b=[2,1,3], push 1 and 2, pop 2 and 1, then push and pop 3. For b=[3,1,2], 2 blocks access to 1 after popping 3.

## Why this works

The explicit stack holds pushed values not yet consumed by the requested pop prefix.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Explore legal push/pop sequences | O(4^n n) upper bound | O(n²) copied states |
| [Better](03_better_approach.cpp) | Greedy std::stack simulation | O(n) | O(n) |
| [Optimal](04_optimal_solution.cpp) | Same linear simulation with vector storage | O(n) | O(n) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `[[1, 2, 3], [2, 1, 3]]` | `true` |
| `[[1, 2, 3], [3, 1, 2]]` | `false` |
| `[[1], [1]]` | `true` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module queues --problem GFG_Stack_Permutations --sanitize
```
