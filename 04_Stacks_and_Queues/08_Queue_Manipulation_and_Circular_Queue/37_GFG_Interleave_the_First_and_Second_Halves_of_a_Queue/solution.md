# Interleave the First and Second Halves of a Queue — reference discussion

## Contract

`void interleaveQueue(queue<int>& q)` — [GeeksforGeeks problem](https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1). The live judge may use a different C++ method name or parameters; adapt a copy of your code, not the first attempt.

## Recognition cue

Interleave two contiguous halves while preserving each half's internal order.

## Approach progression

| File | Role |
|---|---|
| [Brute force](02_brute_force.cpp) | Same efficient method; no distinct baseline recorded |
| [Better](03_better.cpp) | Intermediate alternative |
| [Optimal](04_optimal.cpp) | Efficient reference |

For a concrete dry run, trace the first case in `test_cases.txt` and identify what state each container stores. Approach labels are not a promise that all three slots have different complexity; avoid inventing an algorithm to fill a slot.

Reference availability never represents personal completion or mastery.

## Examples in the starter

These are learning cases from `test_cases.txt`, not platform acceptance records.

- `[1,2,3,4] -> [1,3,2,4]`
- `[1,2,3,4,5,6] -> [1,4,2,5,3,6]`
- `[] -> []`

## Check yourself

1. Explain the cue: Interleave two contiguous halves while preserving each half's internal order.
2. Trace one case above through each actual C++ implementation. Note when an approach uses the same algorithm as another; that is an honest absence of a distinct intermediate method.
3. State the invariant and derive time and auxiliary-space costs from the loops and containers in each file. Recursion also consumes stack space.
4. Add a counterexample in [mistakes.md](mistakes.md), then recode without looking at the reference.
5. Record your own dates in [revision notes](revision_notes.md).

Run `python3 scripts/test_curriculum_references.py --module queues --sanitize` from the repository root to check the supplied reference implementations.
