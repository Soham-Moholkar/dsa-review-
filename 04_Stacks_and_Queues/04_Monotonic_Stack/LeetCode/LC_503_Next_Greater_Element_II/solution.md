# Next Greater Element II — explained solution

## Input and result

```cpp
vector<int> nextGreaterElements(vector<int>& nums)
```

Follow the [live problem](https://leetcode.com/problems/next-greater-element-ii/) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

Adapt a nearest-neighbor pattern when traversal wraps around. The useful state is: The repeated traversal leaves only valid circular greater candidates.

## Worked trace

Start from the first example `[1,2,1] -> [2,-1,2]`. After each input step, check: The repeated traversal leaves only valid circular greater candidates. The next loop step updates that state before the final result is reported.

The first local case is `[1,2,1] -> [2,-1,2]`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

The repeated traversal leaves only valid circular greater candidates. The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

- **Brute force:** Scan the requested direction for each element. Time O(n²); extra space O(1) plus result.
- **Better:** Same efficient method (no distinct intermediate). Time O(n); extra space O(n).
- **Optimal:** Circular scan reference. Time O(n); extra space O(n).

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[1,2,1]` | `[2,-1,2]` |
| `[1,2,3,4,3]` | `[2,3,4,-1,4]` |
| `[4]` | `[-1]` |

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module queues --problem LC_503_Next_Greater_Element_II --sanitize`.
