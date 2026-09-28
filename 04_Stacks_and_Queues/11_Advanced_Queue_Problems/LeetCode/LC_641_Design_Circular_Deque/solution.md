# Design Circular Deque — explained solution

## Input and result

```cpp
class MyCircularDeque { public: MyCircularDeque(int k); bool insertFront(int value); bool insertLast(int value); bool deleteFront(); bool deleteLast(); int getFront(); int getRear(); bool isEmpty(); bool isFull(); };
```

Follow the [live problem](https://leetcode.com/problems/design-circular-deque/) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

Extend wraparound reasoning to insertions and removals at both ends. The useful state is: The head and count define the live circular deque positions.

## Worked trace

Start from the first example `k=3: insertLast(1),insertLast(2),insertFront(3),insertFront(4),getRear(),isFull() -> true,true,true,false,2,true`. After each input step, check: The head and count define the live circular deque positions. The next loop step updates that state before the final result is reported.

The first local case is `k=3: insertLast(1),insertLast(2),insertFront(3),insertFront(4),getRear(),isFull() -> true,true,true,false,2,true`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

The head and count define the live circular deque positions. The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

- **Brute force:** Same efficient method (no distinct baseline). Time O(1) per operation; extra space O(capacity).
- **Better:** Same efficient method (no distinct intermediate). Time O(1) per operation; extra space O(capacity).
- **Optimal:** Circular deque reference. Time O(1) per operation; extra space O(capacity).

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `k=3: insertLast(1),insertLast(2),insertFront(3),insertFront(4),getRear(),isFull()` | `true,true,true,false,2,true` |
| `k=1: insertFront(8),getFront(),deleteLast(),isEmpty()` | `true,8,true,true` |
| `k=2: getRear()` | `-1` |

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module queues --problem LC_641_Design_Circular_Deque --sanitize`.
