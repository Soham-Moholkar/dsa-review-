# First Negative Integer in Every Window of Size K — explained solution

## Input and result

```cpp
vector<int> firstNegInt(vector<int>& arr, int k)
```

Follow the [live problem](https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

Revisit the Arrays/Vectors exercise with a position-aware FIFO candidate structure. The useful state is: The deque holds unexpired positions of negative values.

## Worked trace

Start from the first example `[-8,2,3,-6,10],2 -> [-8,0,-6,-6]`. After each input step, check: The deque holds unexpired positions of negative values. The next loop step updates that state before the final result is reported.

The first local case is `[-8,2,3,-6,10],2 -> [-8,0,-6,-6]`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

The deque holds unexpired positions of negative values. The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

- **Brute force:** Scan each window for its first negative. Time O(nk); extra space O(1) plus result.
- **Better:** Same efficient method (no distinct intermediate). Time O(n); extra space O(k) plus result.
- **Optimal:** Deque of candidate indices reference. Time O(n); extra space O(k) plus result.

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[-8,2,3,-6,10],2` | `[-8,0,-6,-6]` |
| `[1,2,3],2` | `[0,0]` |
| `[-1],1` | `[-1]` |

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module queues --problem GFG_First_Negative_Integer_in_Every_Window_of_Size_K --sanitize`.
