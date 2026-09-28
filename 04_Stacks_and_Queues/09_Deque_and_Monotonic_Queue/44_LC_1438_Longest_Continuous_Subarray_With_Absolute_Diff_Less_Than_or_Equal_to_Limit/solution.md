# Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit — reference discussion

## Contract

`int longestSubarray(vector<int>& nums, int limit)` — [LeetCode problem](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/). The live judge may use a different C++ method name or parameters; adapt a copy of your code, not the first attempt.

## Recognition cue

Maintain both extremes as a variable window changes.

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

- `[8,2,4,7],4 -> 2`
- `[10,1,2,4,7,2],5 -> 4`
- `[4,4,4],0 -> 3`

## Check yourself

1. Explain the cue: Maintain both extremes as a variable window changes.
2. Trace one case above through each actual C++ implementation. Note when an approach uses the same algorithm as another; that is an honest absence of a distinct intermediate method.
3. State the invariant and derive time and auxiliary-space costs from the loops and containers in each file. Recursion also consumes stack space.
4. Add a counterexample in [mistakes.md](mistakes.md), then recode without looking at the reference.
5. Record your own dates in [revision notes](revision_notes.md).

Run `python3 scripts/test_curriculum_references.py --module queues --sanitize` from the repository root to check the supplied reference implementations.
