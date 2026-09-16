# Know what the function promises

The code in this repository solves the **80 handbook entries**. Some GeeksforGeeks prompts have since changed. The three numbered references in a folder share the signature in its `metadata.json`; the local runner tests that contract. A local pass is not a claim of acceptance by a live judge.

## Platform differences that matter

The following public prompt descriptions were checked on 16 September 2026. Match your editor's function signature before submitting. Do not paste a function with a different return type or indexing convention.

| Entry | Handbook references here | Current prompt / adaptation |
|---|---|---|
| [Frequencies in a Limited Array](https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1) | `void frequencyCount(arr, N, P)` overwrites `arr`, counting 1..N and ignoring original values above N | Current description requests a returned array of frequencies for 1..n. Use a frequency vector and return it; the editor supplies the exact signature. |
| [Equilibrium Point](https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1) | Returns a **one-based position**, or -1 | Current prompt uses a **zero-based index**. Change `return i + 1` to `return i` in the chosen reference. |
| [Remove Duplicates Sorted Array](https://www.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1) | Returns the number k of unique values, writing them into the first k positions | Current description requests the distinct values as an array. Return that prefix using the return type shown in your editor. |
| [Duplicates in a Limited Range Array](https://www.geeksforgeeks.org/problems/find-duplicates-in-an-array/1) | Values 0..n-1, arbitrary repetition; return sorted duplicates or {-1} | Current variant uses 1..n with at most two occurrences per value. It requires different indexing and an empty result when no values repeat. |
| [First Occurrence in Sorted](https://www.geeksforgeeks.org/problems/binary-search-1587115620/1) | `binarysearch(arr,k)` now consistently returns the **first** zero-based occurrence | Continue searching left after a match; all three references agree for duplicate values. |

These are targeted checks, not a certification that all 80 live signatures are unchanged. Problem titles alone are insufficient to identify an API contract. The original DOCX is kept as the historical source; the maintained Markdown and C++ contain the corrections.

## Preconditions shared by the references

- Arrays used for largest/minimum, second largest, majority with a guaranteed answer, Kadane, product, stock, and peak problems are nonempty. Some other functions handle empty input, but that is not a blanket guarantee.
- Fixed windows require **1 <= k <= n**. Supplied N values equal the vector/array length. A raw pointer must reference at least N elements.
- Sorted pair search, deduplication, and ordinary binary search require sorted input. Rotated search assumes distinct elements before rotation.
- The minimum-size sum windows require nonnegative values (strictly positive for LC 209) and the documented threshold. Signed arrays need another algorithm; prefix sums with a hashmap solve many signed exact-sum problems.
- LC 169 guarantees a majority; GFG's majority function verifies it and returns -1 if absent. A majority means **more than n/2**, not at least n/2.
- LC 1 and LC 167 guarantee a pair; LC 1 returns zero-based indices, LC 167 one-based indices. GFG's two-sum functions return a boolean.
- LC 162 uses strict peaks and unequal adjacent values. The handbook GFG peak accepts a value at least as large as its neighbours. Multiple answers can be valid.
- Intervals are closed: [1,3] and [3,5] overlap. Insert Interval starts with sorted, nonoverlapping intervals; general Merge Intervals need not.
- Index-placement exercises use their stated ranges. Missing Number is 0..n for LC and 1..n for GFG. Missing and Repeating returns **[repeating, missing]**. LC 287 must leave its input unchanged.
- Matrices are nonempty and rectangular; rotations require a square. LC rotation is clockwise; GFG rotation here is anticlockwise. Matrix search needs sorted rows AND columns, not necessarily a sorted row-major flattening.
- Integer results and intermediate arithmetic must fit the types documented in the signature and implementation. Product references assume every contiguous product fits `int`; sum problems returning `int` follow their platform-sized domains. Selected boundary regressions additionally check safe neighbour arithmetic and index placement at `INT_MIN`/`INT_MAX`.

## Mutation and memory

Read the function before reusing its input. Sorting changes order. Sign marking changes signs. Cyclic placement moves values. Frequency encoding replaces values with counts. Running Sum overwrites values with prefixes, and returning the vector by value also allocates result storage.

For deduplication, only the first returned k entries matter; values beyond k are unspecified. For two-sum indices or peaks, validate the answer's properties rather than expecting one arbitrary arrangement.

Space labels distinguish auxiliary storage from the required result where stated. `std::sort` is budgeted as O(log n) stack space in the usual implementation. Hash-based time bounds are expected/average, not worst-case guarantees. The `better` file is an alternative, and sometimes ties or trades time for space rather than improving both.
