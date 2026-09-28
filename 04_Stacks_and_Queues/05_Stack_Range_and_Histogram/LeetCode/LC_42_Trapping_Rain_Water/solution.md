# Trapping Rain Water — explained solution

## Input and result

```cpp
int trap(vector<int>& height)
```

Follow the [live problem](https://leetcode.com/problems/trapping-rain-water/) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

Compare the stack boundary view with the two-pointer lesson in Arrays/Vectors. The useful state is: Popped valleys can hold water only after a left and right wall exist.

## Worked trace

Start from the first example `[0,1,0,2,1,0,1,3,2,1,2,1] -> 6`. After each input step, check: Popped valleys can hold water only after a left and right wall exist. The next loop step updates that state before the final result is reported.

The first local case is `[0,1,0,2,1,0,1,3,2,1,2,1] -> 6`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

Popped valleys can hold water only after a left and right wall exist. The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

- **Brute force:** Recompute both height boundaries. Time O(n²); extra space O(1).
- **Better:** Precompute left and right wall maxima. Time O(n); extra space O(n).
- **Optimal:** Bounded ranges reference. Time O(n); extra space O(n).

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[0,1,0,2,1,0,1,3,2,1,2,1]` | `6` |
| `[4,2,0,3,2,5]` | `9` |
| `[1]` | `0` |

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module queues --problem LC_42_Trapping_Rain_Water --sanitize`.
