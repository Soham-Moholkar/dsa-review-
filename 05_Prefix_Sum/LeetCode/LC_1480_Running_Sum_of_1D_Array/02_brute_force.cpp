#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> answer(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j <= i; j++) {
                answer[i] = answer[i] + nums[j];
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
Problem: Running Sum of 1D Array
Platform: LeetCode
Pattern: Prefix Sum and Prefix Sum with Hashmap

Problem goal:
Return an array where each position contains the sum from index 0 through that position.

Core insight for this problem family:
Starting at index 1, add the previous running total to the current value. The input vector becomes its own result.

This particular file uses the "Recalculate each prefix" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> runningSum(vector<int>& nums)`

- `vector<int>` means this function returns a dynamic array of integers.
- `runningSum` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Recalculate each prefix

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `answer`: the best or complete result found so far.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `j`: a second index, often used to compare another element or mark the next write position.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `vector<int> runningSum(vector<int>& nums) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<int> answer(nums.size(), 0);`
   Declares `answer` so it can store state used by the algorithm.
7. `for(int i = 0; i < nums.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < nums.size()` is true; after each iteration perform `i++`.
8. `for(int j = 0; j <= i; j++) {`
   Starts a loop: first `int j = 0`; keep repeating while `j <= i` is true; after each iteration perform `j++`.
9. `answer[i] = answer[i] + nums[j];`
   Updates `answer[i]` to `answer[i] + nums[j]` for the next step of the algorithm.
10. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
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
[1,2,3,4] becomes [1,3,3,4], then [1,3,6,4], then [1,3,6,10].

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
When index i is updated, index i-1 already stores the sum through i-1. Adding the original value at i gives the sum through i.

The key invariant (a fact that remains true after every useful iteration) is:
After processing i, nums[i] equals the prefix sum through i.

7. COMPLEXITY
-------------
- Time complexity: O(n^2).
- Extra-space complexity: O(n).
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
