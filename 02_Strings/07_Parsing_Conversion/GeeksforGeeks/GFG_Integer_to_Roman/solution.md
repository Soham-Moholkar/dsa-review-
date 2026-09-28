# Integer to Roman — explained solution

## Input and result

```cpp
string intToRoman(int num)
```

Follow the [live problem](https://www.geeksforgeeks.org/problems/convert-to-roman-no/1) for its exact parameter names, constraints, return conventions, and allowed inputs. The first-attempt file preserves the local teaching signature.

## How to think about it

Choose the largest legal symbol repeatedly, including subtractive pairs as first-class entries. The useful state is: After each symbol is chosen, num is the unrepresented remainder.

## Worked trace

Start from the first example `3749 -> "MMMDCCXLIX"`. After each input step, check: After each symbol is chosen, num is the unrepresented remainder. The next loop step updates that state before the final result is reported.

The first local case is `3749 -> "MMMDCCXLIX"`. Follow the actual variables in [the optimal reference](04_optimal_solution.cpp); after every iteration, say which part of the case the stored state describes. For design classes, call each listed operation in order.

## Why this works

After each symbol is chosen, num is the unrepresented remainder. The code updates its state for every input item and chooses a result only after the required range or operation has been processed. Trace the boundary case in [testcases.md](testcases.md) and check the live contract before using the reference on a different platform variant.

## Approaches to compare

- **Brute force:** Same efficient method (no distinct baseline). Time O(output length); extra space O(output length).
- **Better:** Same efficient method (no distinct intermediate). Time O(output length); extra space O(output length).
- **Optimal:** Greedy representation reference. Time O(output length); extra space O(output length).

The middle approach can use more memory for the same time bound; a repeated efficient approach is labeled explicitly rather than assigned invented complexity. Recursion frames count as extra space. For methods returning a vector or string, the output itself may require space even when auxiliary space is O(1).

## Examples checked by the local runner

These starter cases describe the local contract; the runner also checks selected extra boundary cases. They are not platform acceptance records.

| Arguments | Expected result |
|---|---|
| `3749` | `"MMMDCCXLIX"` |
| `58` | `"LVIII"` |
| `1994` | `"MCMXCIV"` |

## Try it yourself

1. Make your first attempt before opening a reference, and add two of your own [test cases](testcases.md).
2. Trace the preferred implementation on a small input and explain every saved variable and condition.
3. Compare [brute force](02_brute_force.cpp), [the intermediate approach](03_better_approach.cpp), and [the preferred reference](04_optimal_solution.cpp).
4. Record an actual error in [mistakes.md](mistakes.md) and reimplement from memory; leave the original attempt intact.
5. Add dates and your own invariant explanation to [revision notes](revision_notes.md).

From the repository root, run `python3 scripts/test_curriculum_references.py --module strings --problem GFG_Integer_to_Roman --sanitize`.
