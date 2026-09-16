#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int answer = 0;
        while(left < right) {
            int area = min(height[left], height[right]) * (right - left);
            answer = max(answer, area);
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
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
Problem: Container With Most Water
Platform: LeetCode
Pattern: Two Pointers

Problem goal:
Choose two vertical lines that form the container with maximum area.

Core insight for this problem family:
Start with the widest pair. Record its width times the shorter height. Move the shorter boundary inward; the implementation can skip all heights no taller than that boundary.

This particular file uses the "Two pointers" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int maxArea(vector<int>& height)`

- `int` means this function returns one signed integer.
- `maxArea` is the function name the online judge calls.
- `height` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Two pointers

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `height`: the input wall heights.
- `left`: the left boundary or left pointer of the active search/window.
- `right`: the right boundary or right pointer of the active search/window.
- `answer`: the best or complete result found so far.
- `area`: the container area produced by the current pair of boundaries.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int maxArea(vector<int>& height) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int left = 0;`
   Creates `left` and initializes it from `0`. This gives the algorithm its starting state.
7. `int right = height.size() - 1;`
   Creates `right` and initializes it from `height.size() - 1`. This gives the algorithm its starting state.
8. `int answer = 0;`
   Creates `answer` and initializes it from `0`. This gives the algorithm its starting state.
9. `while(left < right) {`
   Repeats the following block while `left < right` is true.
10. `int area = min(height[left], height[right]) * (right - left);`
   Creates `area` and initializes it from `min(height[left], height[right]) * (right - left)`. This gives the algorithm its starting state.
11. `answer = max(answer, area);`
   Updates `answer` to `max(answer, area)` for the next step of the algorithm.
12. `if(height[left] < height[right]) {`
   Runs the next block only when `height[left] < height[right]` is true.
13. `left++;`
   Moves the relevant counter or pointer by one position.
14. `else {`
   Handles the remaining case after the preceding condition(s) were false.
15. `right--;`
   Moves the relevant counter or pointer by one position.
16. `return answer;`
   Ends the function and sends `answer` back to the caller.

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
[1,8,6,2,5,4,8,3,7]: the first area is 8. Move past height 1; heights 8 and 7 at indices 1 and 8 give area 7*7=49.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Keeping the shorter boundary while reducing width cannot improve its area. Discarding it cannot remove an unexamined better pair using that boundary.

The key invariant (a fact that remains true after every useful iteration) is:
Every discarded pair using the shorter boundary cannot beat a future pair with that same boundary.

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
