# Design Front Middle Back Queue — explained solution

## Input and result

```cpp
class FrontMiddleBackQueue { public: FrontMiddleBackQueue(); void pushFront(int val); void pushMiddle(int val); void pushBack(int val); int popFront(); int popMiddle(); int popBack(); };
```

Follow the [live problem](https://leetcode.com/problems/design-front-middle-back-queue/) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

Maintain an explicit middle choice when both ends and the center can change. The useful state is: The two halves remain balanced so the middle is available at an end.

## Worked trace

Start from the first example `pushFront(1),pushBack(2),pushMiddle(3),popMiddle(),popFront(),popBack() -> 3,1,2`. After each input step, check: The two halves remain balanced so the middle is available at an end. The next loop step updates that state before the final result is reported.

The first local case is `pushFront(1),pushBack(2),pushMiddle(3),popMiddle(),popFront(),popBack() -> 3,1,2`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

The two halves remain balanced so the middle is available at an end. The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

- **Brute force:** Same efficient method (no distinct baseline). Time O(1) amortized per operation; extra space O(n).
- **Better:** Same efficient method (no distinct intermediate). Time O(1) amortized per operation; extra space O(n).
- **Optimal:** Two deques reference. Time O(1) amortized per operation; extra space O(n).

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `pushFront(1),pushBack(2),pushMiddle(3),popMiddle(),popFront(),popBack()` | `3,1,2` |
| `popFront() on empty` | `-1` |
| `pushBack(1),pushBack(2),popMiddle()` | `1` |

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module queues --problem LC_1670_Design_Front_Middle_Back_Queue --sanitize`.
