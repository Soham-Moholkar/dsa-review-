#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> frequency(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++) frequency[nums[i]]++;
        vector<int> answer;
        for(int value = 1; value <= nums.size(); value++) {
            if(frequency[value] == 0) answer.push_back(value);
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Find All Numbers Disappeared in an Array
Platform: LeetCode
Pattern: Index Placement and Cyclic Sort

Problem goal:
Return values from 1 through n that do not appear in nums.

Core insight for this problem family:
For each absolute value x, make the element at index x-1 negative. After marking, each positive cell corresponds to a missing value.

This particular file uses the "Frequency vector" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> findDisappearedNumbers(vector<int>& nums)`

- `vector<int>` means this function returns a dynamic array of integers.
- `findDisappearedNumbers` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Values lie in 1..n.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Frequency vector

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `frequency`: counts how many times each value/key occurs in the relevant range.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `answer`: the best or complete result found so far.
- `value`: the current element/value taken from the input or a candidate range.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `vector<int> findDisappearedNumbers(vector<int>& nums) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<int> frequency(nums.size() + 1, 0);`
   Declares `frequency` so it can store state used by the algorithm.
7. `for(int i = 0; i < nums.size(); i++) frequency[nums[i]]++;`
   Starts a loop: first `int i = 0`; keep repeating while `i < nums.size()` is true; after each iteration perform `i++`. Its one-line body is `frequency[nums[i]]++;`.
8. `vector<int> answer;`
   Declares `answer` so it can store state used by the algorithm.
9. `for(int value = 1; value <= nums.size(); value++) {`
   Starts a loop: first `int value = 1`; keep repeating while `value <= nums.size()` is true; after each iteration perform `value++`.
10. `if(frequency[value] == 0) answer.push_back(value);`
   Runs the next block only when `frequency[value] == 0` is true. The one-line action is `answer.push_back(value);`.
11. `return answer;`
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
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
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
[4,3,2,7,8,2,3,1] leaves indices 4 and 5 positive, so missing values are [5,6]. Repeated values must not flip a negative marker back to positive.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
A cell is negative exactly when its represented value appeared. Reading absolute values allows the array to serve as both data and marker storage.

The key invariant (a fact that remains true after every useful iteration) is:
A negative value at index i marks that i+1 appeared.

7. COMPLEXITY
-------------
- Time complexity: O(n).
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
