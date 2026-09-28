# Sort Characters by Frequency — explained solution

## Input and result

```cpp
string frequencySort(string s)
```

Follow the [live problem](https://leetcode.com/problems/sort-characters-by-frequency/) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

Move from merely counting characters to reconstructing output in frequency order. The useful state is: The output is assembled from characters in nonincreasing frequency order.

## Worked trace

Start from the first example `"tree" -> any valid frequency-sorted result`. After each input step, check: The output is assembled from characters in nonincreasing frequency order. The next loop step updates that state before the final result is reported.

The first local case is `"tree" -> any valid frequency-sorted result`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

The output is assembled from characters in nonincreasing frequency order. The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

- **Brute force:** Count, sort, and emit characters. Time O(n + A log A); extra space O(A + n).
- **Better:** Order frequency groups with a heap. Time O(n + A log A); extra space O(A + n).
- **Optimal:** Counting reference. Time O(n + A log A); extra space O(A + n).

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `"tree"` | `any valid frequency-sorted result` |
| `"cccaaa"` | `any valid result with grouped equal frequencies` |
| `"Aabb"` | `any valid frequency-sorted result` |

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module strings --problem LC_451_Sort_Characters_by_Frequency --sanitize`.
