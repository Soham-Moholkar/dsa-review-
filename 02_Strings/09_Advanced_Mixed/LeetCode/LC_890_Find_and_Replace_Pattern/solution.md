# Find and Replace Pattern — explained solution

## Input and result

```cpp
vector<string> findAndReplacePattern(vector<string>& words, string pattern)
```

Follow the [live problem](https://leetcode.com/problems/find-and-replace-pattern/) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

Reuse bidirectional/canonical mapping across a list of candidate words. The useful state is: Processed word characters obey a consistent mapping in both directions.

## Worked trace

Start from the first example `["abc","deq","mee","aqq","dkd","ccc"], "abb" -> ["mee","aqq"]`. After each input step, check: Processed word characters obey a consistent mapping in both directions. The next loop step updates that state before the final result is reported.

The first local case is `["abc","deq","mee","aqq","dkd","ccc"], "abb" -> ["mee","aqq"]`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

Processed word characters obey a consistent mapping in both directions. The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

- **Brute force:** Same efficient method (no distinct baseline). Time O(total characters); extra space O(1) plus result.
- **Better:** Same efficient method (no distinct intermediate). Time O(total characters); extra space O(1) plus result.
- **Optimal:** Canonical mapping reference. Time O(total characters); extra space O(1) plus result.

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `["abc","deq","mee","aqq","dkd","ccc"], "abb"` | `["mee","aqq"]` |
| `["a","b","c"], "a"` | `all words` |
| `["aa","ab"], "cc"` | `["aa"]` |

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module strings --problem LC_890_Find_and_Replace_Pattern --sanitize`.
