# Bounded Event Buffer — reference discussion

## Contract

`vector<int> lastEvents(vector<int>& events, int capacity)` — [Repository exercise problem](https://github.com/Soham-Moholkar/dsa-review-/blob/topic/stacks-queues/04_Stacks_and_Queues/10_Queue_Simulation_and_Streams/50_EX_Bounded_Event_Buffer/README.md). The live judge may use a different C++ method name or parameters; adapt a copy of your code, not the first attempt.

## Recognition cue

Decide which oldest event to evict once fixed capacity is reached.

## Approach progression

| File | Role |
|---|---|
| [Brute force](02_brute_force.cpp) | Direct baseline for comparison |
| [Better](03_better.cpp) | Intermediate alternative |
| [Optimal](04_optimal.cpp) | Efficient reference |

For a concrete dry run, trace the first case in `test_cases.txt` and identify what state each container stores. Approach labels are not a promise that all three slots have different complexity; avoid inventing an algorithm to fill a slot.

Reference availability never represents personal completion or mastery.

## Examples in the starter

These are learning cases from `test_cases.txt`, not platform acceptance records.

- `[1,2,3,4],2 -> [3,4]`
- `[5],3 -> [5]`
- `[1,2],0 -> []`

## Check yourself

1. Explain the cue: Decide which oldest event to evict once fixed capacity is reached.
2. Trace one case above through each actual C++ implementation. Note when an approach uses the same algorithm as another; that is an honest absence of a distinct intermediate method.
3. State the invariant and derive time and auxiliary-space costs from the loops and containers in each file. Recursion also consumes stack space.
4. Add a counterexample in [mistakes.md](mistakes.md), then recode without looking at the reference.
5. Record your own dates in [revision notes](revision_notes.md).

Run `python3 scripts/test_curriculum_references.py --module queues --sanitize` from the repository root to check the supplied reference implementations.
