# Rotting Oranges — explained solution

## Input and result

```cpp
int orangesRotting(vector<vector<int>>& grid)
```

Follow the [live problem](https://www.geeksforgeeks.org/problems/rotten-oranges2536/1) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

Process simultaneous arrivals by rounds from several starting points. The useful state is: Each cell enters the queue when it first becomes rotten.

## Worked trace

With one initially rotten cell, all adjacent fresh cells enter the first time layer; cells reached from them enter later layers.

The first local case is `[[2,1,1],[1,1,0],[0,1,1]] -> 4`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

Each cell enters the queue when it first becomes rotten. The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

- **Brute force:** Same efficient method (no distinct baseline). Time O(rows × columns); extra space O(rows × columns).
- **Better:** Store arrival time with every queue cell. Time O(rows × columns); extra space O(rows × columns).
- **Optimal:** Multi-source queue reference. Time O(rows × columns); extra space O(rows × columns).

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `[[2,1,1],[1,1,0],[0,1,1]]` | `4` |
| `[[2,1,1],[0,1,1],[1,0,1]]` | `-1` |
| `[[0,2]]` | `0` |

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module queues --problem GFG_Rotting_Oranges --sanitize`.
