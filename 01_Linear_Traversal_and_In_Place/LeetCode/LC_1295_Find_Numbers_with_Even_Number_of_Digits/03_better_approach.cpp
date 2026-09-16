#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int answer = 0;
        for(int i = 0; i < nums.size(); i++) {
            int number = abs(nums[i]);
            int digits = 0;
            if(number == 0) {
                digits = 1;
            }
            while(number > 0) {
                digits++;
                number = number / 10;
            }
            if(digits % 2 == 0) {
                answer++;
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
Problem: Find Numbers with Even Number of Digits
Platform: LeetCode
Pattern: Linear Traversal and In-Place Manipulation

Problem goal:
Count how many numbers contain an even number of decimal digits.

Core insight for this problem family:
Count each number's digits by repeatedly dividing by 10. Add one to the answer when that count is even.

This particular file uses the "Repeated division by 10" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int findNumbers(vector<int>& nums)`

- `int` means this function returns one signed integer.
- `findNumbers` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Repeated division by 10

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `answer`: the best or complete result found so far.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `number`: a working copy of the number whose digits are being counted.
- `digits`: the number of decimal digits found in the working number.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int findNumbers(vector<int>& nums) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int answer = 0;`
   Creates `answer` and initializes it from `0`. This gives the algorithm its starting state.
7. `for(int i = 0; i < nums.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < nums.size()` is true; after each iteration perform `i++`.
8. `int number = abs(nums[i]);`
   Creates `number` and initializes it from `abs(nums[i])`. This gives the algorithm its starting state.
9. `int digits = 0;`
   Creates `digits` and initializes it from `0`. This gives the algorithm its starting state.
10. `if(number == 0) {`
   Runs the next block only when `number == 0` is true.
11. `digits = 1;`
   Updates `digits` to `1` for the next step of the algorithm.
12. `while(number > 0) {`
   Repeats the following block while `number > 0` is true.
13. `digits++;`
   Moves the relevant counter or pointer by one position.
14. `number = number / 10;`
   Updates `number` to `number / 10` for the next step of the algorithm.
15. `if(digits % 2 == 0) {`
   Runs the next block only when `digits % 2 == 0` is true.
16. `answer++;`
   Moves the relevant counter or pointer by one position.
17. `return answer;`
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
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- ++ / --: Increases/decreases a numeric variable by one.
- %: Remainder operator. a % b gives the remainder after integer division by b.

General syntax reminders:
- Parentheses `()` hold function arguments or conditions.
- Braces `{}` group statements into a class, function, loop, or condition block.
- Square brackets `[]` index a vector/array from zero; valid indices are 0 through size-1.
- A semicolon `;` ends a C++ statement.
- `==` compares values; `=` assigns a new value. Confusing them is a common bug.
- `<`, `>`, `<=`, and `>=` compare values.

5. DRY RUN
----------
For 120: 120 -> 12 -> 1 -> 0 gives 3 digits, so skip it. For 45, two divisions give 2 digits, so count it.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Integer division removes one decimal digit. The loop therefore counts every digit exactly once.

The key invariant (a fact that remains true after every useful iteration) is:
answer equals the number of processed values whose digit count is even.

7. COMPLEXITY
-------------
- Time complexity: O(total digits).
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
