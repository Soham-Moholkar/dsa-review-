# Add Binary Strings

- **Platform:** GeeksforGeeks
- **Study difficulty:** Easy
- **Live problem:** [Add Binary Strings](https://www.geeksforgeeks.org/problems/add-binary-strings3805/1)
- **Stage:** Parsing Conversion
- **Module ID:** 58 · **Global ID:** 193
- **Reference availability:** three implemented study files; your starter is unsolved.

## What I am meant to learn

Generalize decimal carry arithmetic to base two without converting the entire number.

## Concepts and prerequisites

Earlier exercises in this stage. Review [Parsing Conversion](../../README.md) for the stage theory and nearby exercises.

## Local contract and starter signature

Inputs are nonempty binary strings, possibly with leading zeroes. Return canonical binary output with no leading zeroes except "0".

```cpp
string addBinary(string a, string b)
```

This documented C++17 interface is the local test contract. Compare names, return types, indexing, and sentinels with the live editor before submission. See [contract guide](../../../../docs/CONTRACTS.md).

## Approach progression

Open references after making your attempt. A repeated method is explicitly labeled when no useful third algorithm is introduced.

| Reference | Method | Time | Space |
|---|---|---|---|
| [Brute Force](02_brute_force.cpp) | Prepend each computed bit | O(L²) | O(L) |
| [Better](03_better_approach.cpp) | Append reversed bits | O(L) | O(L) result |
| [Optimal](04_optimal_solution.cpp) | Same linear carry method; no distinct third algorithm | O(L) | O(L) result |

## Attempt protocol

1. Read the live prompt and restate the local input/result contract.
2. Add at least two personal cases to [testcases.md](testcases.md).
3. Put your own first attempt in [01_original_attempt.cpp](01_original_attempt.cpp).
4. Record actual mistakes in [mistakes.md](mistakes.md), then compare [the explanation](solution.md).
5. Fill [revision notes](revision_notes.md) only after doing the corresponding review.

[Module navigation](../../../README.md) · [Stage practice](../../README.md)
