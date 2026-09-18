#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) {
                if(nums[mid] == target) first = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        left = 0;
        right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target) {
                if(nums[mid] == target) last = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return {first, last};
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Find First and Last Position of Element in Sorted Array
Platform: LeetCode
Pattern: Binary Search

Problem goal:
Return the first and last target positions in sorted nums.

Core insight for this problem family:
Run two binary searches: one that continues left after a match and one that continues right. Return [-1,-1] when no match exists.

This particular file uses the "Two manual binary searches" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> searchRange(vector<int>& nums, int target)`

- `vector<int>` means this function returns a dynamic array of integers.
- `searchRange` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `target` is one signed integer value.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The array is sorted in nondecreasing order.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Two manual binary searches

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `target`: the value or sum the problem asks the algorithm to find.
- `first`: the first matching boundary/index, or a flag describing the first row.
- `last`: the last matching boundary/index or saved last value.
- `left`: the left boundary or left pointer of the active search/window.
- `right`: the right boundary or right pointer of the active search/window.
- `mid`: the middle position in binary search, or the scanning pointer in Dutch National Flag.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `vector<int> searchRange(vector<int>& nums, int target) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int first = -1;`
   Creates `first` and initializes it from `-1`. This gives the algorithm its starting state.
7. `int last = -1;`
   Creates `last` and initializes it from `-1`. This gives the algorithm its starting state.
8. `int left = 0;`
   Creates `left` and initializes it from `0`. This gives the algorithm its starting state.
9. `int right = nums.size() - 1;`
   Creates `right` and initializes it from `nums.size() - 1`. This gives the algorithm its starting state.
10. `while(left <= right) {`
   Repeats the following block while `left <= right` is true.
11. `int mid = left + (right - left) / 2;`
   Creates `mid` and initializes it from `left + (right - left) / 2`. This gives the algorithm its starting state.
12. `if(nums[mid] >= target) {`
   Runs the next block only when `nums[mid] >= target` is true.
13. `if(nums[mid] == target) first = mid;`
   Runs the next block only when `nums[mid] == target` is true. The one-line action is `first = mid;`.
14. `right = mid - 1;`
   Updates `right` to `mid - 1` for the next step of the algorithm.
15. `else {`
   Handles the remaining case after the preceding condition(s) were false.
16. `left = mid + 1;`
   Updates `left` to `mid + 1` for the next step of the algorithm.
17. `left = 0;`
   Updates `left` to `0` for the next step of the algorithm.
18. `right = nums.size() - 1;`
   Updates `right` to `nums.size() - 1` for the next step of the algorithm.
19. `while(left <= right) {`
   Repeats the following block while `left <= right` is true.
20. `int mid = left + (right - left) / 2;`
   Creates `mid` and initializes it from `left + (right - left) / 2`. This gives the algorithm its starting state.
21. `if(nums[mid] <= target) {`
   Runs the next block only when `nums[mid] <= target` is true.
22. `if(nums[mid] == target) last = mid;`
   Runs the next block only when `nums[mid] == target` is true. The one-line action is `last = mid;`.
23. `left = mid + 1;`
   Updates `left` to `mid + 1` for the next step of the algorithm.
24. `else {`
   Handles the remaining case after the preceding condition(s) were false.
25. `right = mid - 1;`
   Updates `right` to `mid - 1` for the next step of the algorithm.
26. `return {first, last};`
   Ends the function and sends `{first, last}` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
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
[5,7,7,8,8,10], target 8 gives first index 3 and last index 4. lower_bound finds the first >= target; upper_bound finds the first > target.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
The first search discards positions that cannot precede its best match; the second does the symmetric operation for the last match.

The key invariant (a fact that remains true after every useful iteration) is:
A recorded match remains a candidate while search continues toward the desired boundary.

7. COMPLEXITY
-------------
- Time complexity: O(log n).
- Extra-space complexity: O(1).
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
