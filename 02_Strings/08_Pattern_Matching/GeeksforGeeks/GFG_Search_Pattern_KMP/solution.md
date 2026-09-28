# Search Pattern (KMP Algorithm) — explained solution

## Input and result

```cpp
vector<int> search(string &pat, string &txt)
```

Follow the [live problem](https://www.geeksforgeeks.org/problems/search-pattern0205/1) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

Build the prefix table and reuse matched information instead of restarting after a mismatch. The useful state is: The prefix table stores the longest proper border of each processed prefix.

## Worked trace

In `abcab`, the pattern `ab` starts at positions 0 and 3; the prefix table avoids forgetting a possible overlapping start.

The first local case is `txt="abcab", pat="ab" -> [0,3] (confirm platform index convention)`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

The prefix table stores the longest proper border of each processed prefix. The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

- **Brute force:** Compare the pattern at each text position. Time O(nm); extra space O(1) plus result.
- **Better:** Same efficient method (no distinct intermediate). Time O(n + m); extra space O(m) plus result.
- **Optimal:** Lps/prefix table reference. Time O(n + m); extra space O(m) plus result.

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `txt="abcab", pat="ab"` | `[0,3] (confirm platform index convention)` |
| `txt="aaaaa", pat="aa"` | `overlapping matches` |
| `pattern longer than text` | `[]` |

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module strings --problem GFG_Search_Pattern_KMP --sanitize`.
