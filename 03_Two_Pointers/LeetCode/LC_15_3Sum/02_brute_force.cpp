#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> uniqueTriplets;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                for(int k = j + 1; k < nums.size(); k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        uniqueTriplets.insert(triplet);
                    }
                }
            }
        }
        return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: 3Sum
Platform: LeetCode
Pattern: Two Pointers

Problem goal:
Return all unique triplets whose values sum to zero.

Core insight for this problem family:
Sort the array. Fix one value and solve the remaining two-sum problem with opposite-end pointers. Skip equal fixed values and equal values after recording an answer.

This particular file uses the "Check every triplet and deduplicate with a set" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<vector<int>> threeSum(vector<int>& nums)`

- `vector<vector<int>>` means this function returns a dynamic array whose elements are integer vectors.
- `threeSum` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Check every triplet and deduplicate with a set

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `uniqueTriplets`: an ordered set used to remove repeated 3Sum triplets.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `j`: a second index, often used to compare another element or mark the next write position.
- `k`: the problem-supplied limit, window size, rotation count, or target parameter described by the signature.
- `triplet`: one candidate group of three values.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `vector<vector<int>> threeSum(vector<int>& nums) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `set<vector<int>> uniqueTriplets;`
   Declares `uniqueTriplets` so it can store state used by the algorithm.
7. `for(int i = 0; i < nums.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < nums.size()` is true; after each iteration perform `i++`.
8. `for(int j = i + 1; j < nums.size(); j++) {`
   Starts a loop: first `int j = i + 1`; keep repeating while `j < nums.size()` is true; after each iteration perform `j++`.
9. `for(int k = j + 1; k < nums.size(); k++) {`
   Starts a loop: first `int k = j + 1`; keep repeating while `k < nums.size()` is true; after each iteration perform `k++`.
10. `if(nums[i] + nums[j] + nums[k] == 0) {`
   Runs the next block only when `nums[i] + nums[j] + nums[k] == 0` is true.
11. `vector<int> triplet = {nums[i], nums[j], nums[k]};`
   Creates `triplet` and initializes it from `{nums[i], nums[j], nums[k]}`. This gives the algorithm its starting state.
12. `sort(triplet.begin(), triplet.end());`
   Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible.
13. `uniqueTriplets.insert(triplet);`
   Stores this value in the set/map so later iterations can find it.
14. `return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());`
   Ends the function and sends `vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end())` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- set: Stores unique values in sorted order, usually with O(log n) insert and lookup.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- insert: Adds an element to a container. A set ignores a value already present.
- sort: Rearranges a range into ascending order by default. This changes the container.
- ++ / --: Increases/decreases a numeric variable by one.

General syntax reminders:
- Parentheses `()` hold function arguments or conditions.
- Braces `{}` group statements into a class, function, loop, or condition block.
- Square brackets `[]` index a vector/array from zero; valid indices are 0 through size-1.
- A semicolon `;` ends a C++ statement.
- `==` compares values; `=` assigns a new value. Confusing them is a common bug.
- `<`, `>`, `<=`, and `>=` compare values.

5. DRY RUN
----------
[-1,0,1,2,-1,-4] sorts to [-4,-1,-1,0,1,2]. Fixing -1 finds [-1,-1,2] and [-1,0,1]. Skip the next fixed -1 to avoid duplicates.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
The sorted two-pointer argument finds every pair for each fixed value. Skipping equal values removes repeated value triplets without removing distinct solutions.

The key invariant (a fact that remains true after every useful iteration) is:
For each fixed i, left and right search the only remaining range and duplicates are skipped.

7. COMPLEXITY
-------------
- Time complexity: O(n^3 log n).
- Extra-space complexity: O(number of answers).
- `n` normally means the number of array elements. For matrix problems, use rows and columns as described in the approach.
- Required output storage is excluded only when the complexity text explicitly says so.

8. EDGE CASES TO CHECK
----------------------
- The smallest input allowed by the contract.
- Repeated values and an answer at the first or last valid position.
- Already sorted/reversed input when ordering matters.
- All-negative values, zeroes, or a missing answer when the problem permits them.
- Values near integer limits when the code adds, subtracts, multiplies, or forms a complement.
- For in-place code, remember that the input may look different after the call.

9. COMMON MISTAKES
------------------
- Using `=` when a comparison needs `==`.
- Reading index `size()` even though the final valid index is `size() - 1`.
- Moving a pointer/counter in the wrong branch or forgetting to move it, causing an infinite loop.
- Returning the right value with the wrong index base (zero-based versus one-based).
- Copying this approach to inputs that do not satisfy its sortedness, positivity, range, or matrix-shape assumptions.
- Ignoring overflow: promote before arithmetic when the implementation uses `long long` or `1LL`.

10. HOW TO STUDY THIS SOLUTION
------------------------------
1. Hide the code and state the main idea in one sentence.
2. Explain every variable without using its name as the explanation.
3. Perform the dry run and state the invariant after each iteration.
4. Re-code the method from memory.
5. Compare it with the other numbered approaches in this folder and explain the time/space trade-off.

Comments are ignored by the C++ compiler, so this appendix changes documentation only, not program behaviour.
*/
