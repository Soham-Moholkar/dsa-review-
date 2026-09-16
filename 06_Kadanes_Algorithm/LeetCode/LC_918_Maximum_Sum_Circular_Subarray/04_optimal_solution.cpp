#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = nums[0];
        int currentMaximum = nums[0];
        int maximumSum = nums[0];
        int currentMinimum = nums[0];
        int minimumSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            totalSum = totalSum + nums[i];
            currentMaximum = max(nums[i], currentMaximum + nums[i]);
            maximumSum = max(maximumSum, currentMaximum);
            currentMinimum = min(nums[i], currentMinimum + nums[i]);
            minimumSum = min(minimumSum, currentMinimum);
        }
        if(maximumSum < 0) {
            return maximumSum;
        }
        return max(maximumSum, totalSum - minimumSum);
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Maximum Sum Circular Subarray
Platform: LeetCode
Pattern: Kadane's Algorithm

Problem goal:
Return the maximum non-empty subarray sum when the array wraps circularly.

Core insight for this problem family:
Compute ordinary maximum-subarray sum, minimum-subarray sum, and total sum. A wrapping answer is total minus a middle block of minimum sum. If all values are negative, return the ordinary maximum.

This particular file uses the "Maximum and minimum Kadane" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int maxSubarraySumCircular(vector<int>& nums)`

- `int` means this function returns one signed integer.
- `maxSubarraySumCircular` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The input is nonempty.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Maximum and minimum Kadane

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `totalSum`: the sum of the entire input, later compared with a partial sum.
- `currentMaximum`: the best maximum-sum state ending at the current element.
- `maximumSum`: the greatest valid sum found so far.
- `currentMinimum`: the best minimum-sum state ending at the current element.
- `minimumSum`: the smallest subarray sum found so far.
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
5. `int maxSubarraySumCircular(vector<int>& nums) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int totalSum = nums[0];`
   Creates `totalSum` and initializes it from `nums[0]`. This gives the algorithm its starting state.
7. `int currentMaximum = nums[0];`
   Creates `currentMaximum` and initializes it from `nums[0]`. This gives the algorithm its starting state.
8. `int maximumSum = nums[0];`
   Creates `maximumSum` and initializes it from `nums[0]`. This gives the algorithm its starting state.
9. `int currentMinimum = nums[0];`
   Creates `currentMinimum` and initializes it from `nums[0]`. This gives the algorithm its starting state.
10. `int minimumSum = nums[0];`
   Creates `minimumSum` and initializes it from `nums[0]`. This gives the algorithm its starting state.
11. `for(int i = 1; i < nums.size(); i++) {`
   Starts a loop: first `int i = 1`; keep repeating while `i < nums.size()` is true; after each iteration perform `i++`.
12. `totalSum = totalSum + nums[i];`
   Updates `totalSum` to `totalSum + nums[i]` for the next step of the algorithm.
13. `currentMaximum = max(nums[i], currentMaximum + nums[i]);`
   Updates `currentMaximum` to `max(nums[i], currentMaximum + nums[i])` for the next step of the algorithm.
14. `maximumSum = max(maximumSum, currentMaximum);`
   Updates `maximumSum` to `max(maximumSum, currentMaximum)` for the next step of the algorithm.
15. `currentMinimum = min(nums[i], currentMinimum + nums[i]);`
   Updates `currentMinimum` to `min(nums[i], currentMinimum + nums[i])` for the next step of the algorithm.
16. `minimumSum = min(minimumSum, currentMinimum);`
   Updates `minimumSum` to `min(minimumSum, currentMinimum)` for the next step of the algorithm.
17. `if(maximumSum < 0) {`
   Runs the next block only when `maximumSum < 0` is true.
18. `return maximumSum;`
   Ends the function and sends `maximumSum` back to the caller.
19. `return max(maximumSum, totalSum - minimumSum);`
   Ends the function and sends `max(maximumSum, totalSum - minimumSum)` back to the caller.

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
[5,-3,5]: ordinary maximum is 7, minimum is -3, total is 7; wrapping gives 7-(-3)=10. For [-3,-2,-5], return -2, not zero.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Every wrapping subarray excludes one contiguous middle block. Minimizing that block maximizes what remains. The all-negative guard prevents choosing an empty complement.

The key invariant (a fact that remains true after every useful iteration) is:
Both maximum and minimum Kadane states are updated over the same prefix.

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
