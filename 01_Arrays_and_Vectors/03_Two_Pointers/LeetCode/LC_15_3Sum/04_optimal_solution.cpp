#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                long long sum = (long long)nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                    answer.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while(left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if(sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return answer;
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

This particular file uses the "Sort, fix one value, and use two pointers" approach.
It is the preferred/optimal reference stored in this problem folder.

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
Approach name: Sort, fix one value, and use two pointers

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `answer`: the best or complete result found so far.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `left`: the left boundary or left pointer of the active search/window.
- `right`: the right boundary or right pointer of the active search/window.
- `sum`: the running sum of the elements currently being examined.

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
6. `vector<vector<int>> answer;`
   Declares `answer` so it can store state used by the algorithm.
7. `sort(nums.begin(), nums.end());`
   Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible.
8. `for(int i = 0; i < nums.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < nums.size()` is true; after each iteration perform `i++`.
9. `if(i > 0 && nums[i] == nums[i - 1]) {`
   Runs the next block only when `i > 0 && nums[i] == nums[i - 1]` is true.
10. `continue;`
   Skips the rest of this iteration and starts the next one.
11. `int left = i + 1;`
   Creates `left` and initializes it from `i + 1`. This gives the algorithm its starting state.
12. `int right = nums.size() - 1;`
   Creates `right` and initializes it from `nums.size() - 1`. This gives the algorithm its starting state.
13. `while(left < right) {`
   Repeats the following block while `left < right` is true.
14. `long long sum = (long long)nums[i] + nums[left] + nums[right];`
   Creates `sum` and initializes it from `(long long)nums[i] + nums[left] + nums[right]`. This gives the algorithm its starting state.
15. `if(sum == 0) {`
   Runs the next block only when `sum == 0` is true.
16. `answer.push_back({nums[i], nums[left], nums[right]});`
   Appends the computed value to the end of the result/container.
17. `left++;`
   Moves the relevant counter or pointer by one position.
18. `right--;`
   Moves the relevant counter or pointer by one position.
19. `while(left < right && nums[left] == nums[left - 1]) {`
   Repeats the following block while `left < right && nums[left] == nums[left - 1]` is true.
20. `left++;`
   Moves the relevant counter or pointer by one position.
21. `while(left < right && nums[right] == nums[right + 1]) {`
   Repeats the following block while `left < right && nums[right] == nums[right + 1]` is true.
22. `right--;`
   Moves the relevant counter or pointer by one position.
23. `else if(sum < 0) {`
   Defines the judge-facing function and lists the inputs it receives.
24. `left++;`
   Moves the relevant counter or pointer by one position.
25. `else {`
   Handles the remaining case after the preceding condition(s) were false.
26. `right--;`
   Moves the relevant counter or pointer by one position.
27. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- long long: A wider signed whole-number type, commonly 64 bits; it is used when an int may be too small.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- continue: Skips the remainder of the current loop iteration and begins the next one.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- sort: Rearranges a range into ascending order by default. This changes the container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
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
- Time complexity: O(n^2).
- Extra-space complexity: O(log n) excluding answer.
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
