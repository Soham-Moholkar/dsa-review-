#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maximumEnding = nums[0];
        int minimumEnding = nums[0];
        int answer = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                swap(maximumEnding, minimumEnding);
            }
            maximumEnding = max(nums[i], maximumEnding * nums[i]);
            minimumEnding = min(nums[i], minimumEnding * nums[i]);
            answer = max(answer, maximumEnding);
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Maximum Product Subarray
Platform: LeetCode
Pattern: Kadane's Algorithm

Problem goal:
Return the maximum product of a non-empty contiguous subarray.

Core insight for this problem family:
Track both the maximum and minimum products ending here. A negative value can turn the smallest product into the largest, so swap states before multiplying.

This particular file uses the "Maximum/minimum ending states" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int maxProduct(vector<int>& nums)`

- `int` means this function returns one signed integer.
- `maxProduct` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The input is nonempty. The study implementations assume every contiguous product fits a signed 32-bit integer.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Maximum/minimum ending states

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `maximumEnding`: the largest product of a subarray ending at the current element.
- `minimumEnding`: the smallest product ending here; a later negative value may turn it into the largest.
- `answer`: the best or complete result found so far.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int maxProduct(vector<int>& nums) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int maximumEnding = nums[0];`
   Creates `maximumEnding` and initializes it from `nums[0]`. This gives the algorithm its starting state.
7. `int minimumEnding = nums[0];`
   Creates `minimumEnding` and initializes it from `nums[0]`. This gives the algorithm its starting state.
8. `int answer = nums[0];`
   Creates `answer` and initializes it from `nums[0]`. This gives the algorithm its starting state.
9. `for(int i = 1; i < nums.size(); i++) {`
   Starts a loop: first `int i = 1`; keep repeating while `i < nums.size()` is true; after each iteration perform `i++`.
10. `if(nums[i] < 0) {`
   Runs the next block only when `nums[i] < 0` is true.
11. `swap(maximumEnding, minimumEnding);`
   Exchanges the two selected values without needing a manual temporary variable.
12. `maximumEnding = max(nums[i], maximumEnding * nums[i]);`
   Updates `maximumEnding` to `max(nums[i], maximumEnding * nums[i])` for the next step of the algorithm.
13. `minimumEnding = min(nums[i], minimumEnding * nums[i]);`
   Updates `minimumEnding` to `min(nums[i], minimumEnding * nums[i])` for the next step of the algorithm.
14. `answer = max(answer, maximumEnding);`
   Updates `answer` to `max(answer, maximumEnding)` for the next step of the algorithm.
15. `return answer;`
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
- swap: Exchanges two stored values.
- min / max: Returns the smaller/larger of the supplied values.
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
[2,3,-2,4]: ending maximum/minimum pairs are (2,2), (6,3), (-2,-12), (4,-48). The largest product seen is 6.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Multiplication by a negative reverses order. Both extremes are needed to cover every possible best extension. Zero naturally restarts the product state.

The key invariant (a fact that remains true after every useful iteration) is:
maximumEnding and minimumEnding capture both sign possibilities ending at i.

7. COMPLEXITY
-------------
- Time complexity: O(n).
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
