# Know what the function promises

The code in this repository covers **80 Arrays/Vectors handbook entries**, **63 Strings entries**, and **67 Stacks/Queues entries**. Some GeeksforGeeks prompts have since changed. The three numbered references in a folder share the signature in its `metadata.json`; the local runners test that contract. A local pass is not a claim of acceptance by a live judge.

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

## Later-module teaching contracts

The [Strings](../02_Strings/problem_manifest.json) and [Stacks/Queues](../04_Stacks_and_Queues/problem_manifest.json) manifests give the numbered learning order and local signatures. Each problem's README links to its live prompt; verify the current editor signature and behavior when transferring code. The `GeeksforGeeks/` path means this is a first-class exercise, even if its local class or method name needs adapting for today's judge.

| Teaching entry | Local convention to verify before submitting |
|---|---|
| [Search Pattern (KMP)](../02_Strings/08_Pattern_Matching/GeeksforGeeks/GFG_Search_Pattern_KMP/) | The local references report **zero-based** match positions and include overlapping matches. |
| [Reverse a Stack](../04_Stacks_and_Queues/02_Stack_Manipulation_and_Recursion/GeeksforGeeks/GFG_Reverse_a_Stack/) | The local method mutates the supplied `stack<int>&`; the rightmost value in a displayed sequence is its top. |
| [Delete Middle Element of a Stack](../04_Stacks_and_Queues/02_Stack_Manipulation_and_Recursion/GeeksforGeeks/GFG_Delete_Middle_Element_of_a_Stack/) | For even lengths, use the position specified in that exercise's local README before comparing with a platform variant. |
| [First Negative in Each Window](../04_Stacks_and_Queues/09_Deque_and_Monotonic_Queue/GeeksforGeeks/GFG_First_Negative_Integer_in_Every_Window_of_Size_K/) | The local return type is `vector<int>` and a window without a negative value contributes `0`. |

Repository-created `Exercises/` use their README contracts. Recursive call frames count toward extra space, and a reference being available never means the learner attempted the problem.

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


## September GFG expansion

Thirty additional GFG problems have explicit local contracts in their folder READMEs. Live titles/links were checked on 28 September 2026; several pages expose their editor only through client rendering. Local adapters and sentinels are therefore documented rather than claimed to be identical to every live editor version.

- Pattern-search references return **one-based** positions, including overlaps; count-anagram arguments are **pattern, text**.
- Longest common prefix returns an empty string when absent; some older GFG drivers display `-1` instead. Longest palindrome breaks length ties by earliest start.
- Infix conversion treats `^` as right-associative and other binary operators as left-associative; operands are single characters. No unary operators or whitespace are accepted by this contract.
- Minimum bracket reversals uses `{` and `}`, with `-1` for odd length. It counts reversals, not inserted brackets.
- The two-stack adapter documents its fixed storage bound. Empty pops return `-1`; local tests use nonnegative values.
- Circular Tour uses two arrays (`gas`, `cost`), returns a zero-based start, and documents a local first-feasible tie rule.
- LRU successful reads and all updates refresh recency. A zero-capacity cache and source-free nearest-one grids are explicitly tested local extensions.
- Run-length encoding emits every count, including `1`; look-and-say emits **count then digit**, which is a different serialization order.

Generated reference material is available for all new entries. Existing original attempts, test cases, personal notes, and global problem IDs are preserved. The append-only global ID range is 181–210; module navigation groups these new IDs by stage.
