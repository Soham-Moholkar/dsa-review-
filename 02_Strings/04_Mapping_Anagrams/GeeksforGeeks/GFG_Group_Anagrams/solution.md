# Group Anagrams — explained solution

## Input and result

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs)
```

Follow the [live problem](https://www.geeksforgeeks.org/problems/print-anagrams-together/1) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

Create the same reliable key for every member of an anagram group. The useful state is: Words in the same group share the same canonical sorted-character key.

## Worked trace

Start from the first example `["eat","tea","tan","ate","nat","bat"] -> groups by anagram`. After each input step, check: Words in the same group share the same canonical sorted-character key. The next loop step updates that state before the final result is reported.

The first local case is `["eat","tea","tan","ate","nat","bat"] -> groups by anagram`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

Words in the same group share the same canonical sorted-character key. The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

- **Brute force:** Scan the existing groups for each word. Time O(w² L log L); extra space O(w L).
- **Better:** Group sorted keys in a hash map. Time O(w L log L) expected; extra space O(w L).
- **Optimal:** Canonical keys reference. Time O(w L log L + w log w); extra space O(w L).

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `["eat","tea","tan","ate","nat","bat"]` | `groups by anagram` |
| `[""]` | `[[""]]` |
| `["a"]` | `[["a"]]` |

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module strings --problem GFG_Group_Anagrams --sanitize`.
