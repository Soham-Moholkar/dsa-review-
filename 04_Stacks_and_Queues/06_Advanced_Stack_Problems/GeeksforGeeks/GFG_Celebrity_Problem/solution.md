# Celebrity Problem — explained solution

## Input and result

```cpp
int celebrity(vector<vector<int>>& mat)
```

Square binary knows matrix. A celebrity knows nobody else and is known by everyone else. Ignore the diagonal. Return zero-based index or -1.

## How to think about it

Recognize pairwise candidate elimination and the need for a final verification pass.

### Brute Force: Verify every person

Test all row and column conditions for each candidate.

Time: `O(n²)`. Space: `O(1)`.

### Better: Pairwise elimination with a stack

Pop two people; one knows-relation always eliminates at least one. Verify the survivor.

Time: `O(n)`. Space: `O(n)`.

### Optimal: Carry one elimination candidate

The same pairwise elimination needs only a current candidate and the next person.

Time: `O(n)`. Space: `O(1)`.

## Worked trace

If 0 knows 1, discard 0. If 1 does not know 2, discard 2. Candidate 1 still must pass both its row and column checks.

## Why this works

Every eliminated person has a concrete witness proving they cannot be the celebrity.

The reference starts with empty or directly initialized state. Each update preserves this property; the final return reads the completed state. For the specific updates and stopping condition, compare the approach explanations above with the corresponding code.

## Approaches to compare

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Verify every person | O(n²) | O(1) |
| [Better](03_better_approach.cpp) | Pairwise elimination with a stack | O(n) | O(n) |
| [Optimal](04_optimal_solution.cpp) | Carry one elimination candidate | O(n) | O(1) |

Here n and m denote input lengths, w the number of strings, L the maximum string length, A the number of distinct symbols, C capacity, and r/c matrix dimensions unless stated otherwise. Input-by-value copies are excluded from auxiliary-space labels; they can add O(n+m) storage and copying time. Required output is included where named. Hash-table bounds are expected, not worst-case guarantees. Exponential and cubic baselines are for small examples, not maximum platform constraints.

## Examples checked by the local runner

| Arguments in signature order (or operation sequence) | Expected result |
|---|---|
| `[[[0, 1, 0], [0, 0, 0], [0, 1, 0]]]` | `1` |
| `[[[0, 1], [1, 0]]]` | `-1` |
| `[[[1]]]` | `0` |
| `[[[0, 0], [0, 0]]]` | `-1` |

These are local checks, not platform acceptance records. The runner additionally uses deterministic small randomized cases with independent expectations.

## Try it yourself

Explain the invariant aloud, trace each state change, and add a case that would break an incorrect boundary or tie rule. Compare the three files only after recording your own attempt. From the repository root:

```bash
python3 scripts/test_curriculum_references.py --module queues --problem GFG_Celebrity_Problem --sanitize
```
