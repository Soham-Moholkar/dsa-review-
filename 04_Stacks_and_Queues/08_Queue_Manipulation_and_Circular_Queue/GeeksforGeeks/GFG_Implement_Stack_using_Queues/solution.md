# Implement Stack using Queues — explained solution

## Input and result

```cpp
class MyStack { public: MyStack(); void push(int x); int pop(); int top(); bool empty(); };
```

Follow the [live problem](https://www.geeksforgeeks.org/problems/stack-using-queue/1) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

Compare where the work happens when implementing an opposite adapter. The useful state is: Rotating after a push makes the newest element the next queue front.

## Worked trace

Start from the first example `push(1),push(2),top(),pop(),empty() -> 2,2,false`. After each input step, check: Rotating after a push makes the newest element the next queue front. The next loop step updates that state before the final result is reported.

The first local case is `push(1),push(2),top(),pop(),empty() -> 2,2,false`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

Rotating after a push makes the newest element the next queue front. The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

- **Brute force:** Same efficient method (no distinct baseline). Time O(n) push, O(1) pop/top; extra space O(n).
- **Better:** Same efficient method (no distinct intermediate). Time O(n) push, O(1) pop/top; extra space O(n).
- **Optimal:** Lifo from fifo reference. Time O(n) push, O(1) pop/top; extra space O(n).

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `push(1),push(2),top(),pop(),empty()` | `2,2,false` |
| `push(7),pop(),empty()` | `7,true` |
| `push(1),push(2),pop(),push(3),top()` | `2,3` |

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module queues --problem GFG_Implement_Stack_using_Queues --sanitize`.
