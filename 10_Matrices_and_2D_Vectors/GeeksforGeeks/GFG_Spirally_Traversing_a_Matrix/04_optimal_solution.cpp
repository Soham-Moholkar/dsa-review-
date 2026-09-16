#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        vector<int> answer;
        int top = 0;
        int bottom = mat.size() - 1;
        int left = 0;
        int right = mat[0].size() - 1;
        while(top <= bottom && left <= right) {
            for(int column = left; column <= right; column++) answer.push_back(mat[top][column]);
            top++;
            for(int row = top; row <= bottom; row++) answer.push_back(mat[row][right]);
            right--;
            if(top <= bottom) {
                for(int column = right; column >= left; column--) answer.push_back(mat[bottom][column]);
                bottom--;
            }
            if(left <= right) {
                for(int row = bottom; row >= top; row--) answer.push_back(mat[row][left]);
                left++;
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
Problem: Spirally Traversing a Matrix
Platform: GeeksforGeeks
Pattern: Matrices and Two-Dimensional Vectors

Problem goal:
Return matrix elements in clockwise spiral order.

Core insight for this problem family:
Maintain top, bottom, left, and right boundaries. Traverse the top edge, right edge, bottom edge, and left edge, shrinking the appropriate boundary after each. Recheck bounds before the last two edges.

This particular file uses the "Four shrinking boundaries" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> spirallyTraverse(vector<vector<int>>& mat)`

- `vector<int>` means this function returns a dynamic array of integers.
- `spirallyTraverse` is the function name the online judge calls.
- `mat` is a two-dimensional dynamic integer matrix; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The matrix is nonempty and rectangular; rotation additionally requires a square.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Four shrinking boundaries

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `mat`: the input two-dimensional matrix used by the GFG-style function.
- `answer`: the best or complete result found so far.
- `top`: the first unprocessed matrix row.
- `bottom`: the last unprocessed matrix row.
- `left`: the left boundary or left pointer of the active search/window.
- `right`: the right boundary or right pointer of the active search/window.
- `column`: the current matrix column index.
- `row`: the current matrix row index.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `vector<int> spirallyTraverse(vector<vector<int>>& mat) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<int> answer;`
   Declares `answer` so it can store state used by the algorithm.
7. `int top = 0;`
   Creates `top` and initializes it from `0`. This gives the algorithm its starting state.
8. `int bottom = mat.size() - 1;`
   Creates `bottom` and initializes it from `mat.size() - 1`. This gives the algorithm its starting state.
9. `int left = 0;`
   Creates `left` and initializes it from `0`. This gives the algorithm its starting state.
10. `int right = mat[0].size() - 1;`
   Creates `right` and initializes it from `mat[0].size() - 1`. This gives the algorithm its starting state.
11. `while(top <= bottom && left <= right) {`
   Repeats the following block while `top <= bottom && left <= right` is true.
12. `for(int column = left; column <= right; column++) answer.push_back(mat[top][column]);`
   Starts a loop: first `int column = left`; keep repeating while `column <= right` is true; after each iteration perform `column++`. Its one-line body is `answer.push_back(mat[top][column]);`.
13. `top++;`
   Moves the relevant counter or pointer by one position.
14. `for(int row = top; row <= bottom; row++) answer.push_back(mat[row][right]);`
   Starts a loop: first `int row = top`; keep repeating while `row <= bottom` is true; after each iteration perform `row++`. Its one-line body is `answer.push_back(mat[row][right]);`.
15. `right--;`
   Moves the relevant counter or pointer by one position.
16. `if(top <= bottom) {`
   Runs the next block only when `top <= bottom` is true.
17. `for(int column = right; column >= left; column--) answer.push_back(mat[bottom][column]);`
   Starts a loop: first `int column = right`; keep repeating while `column >= left` is true; after each iteration perform `column--`. Its one-line body is `answer.push_back(mat[bottom][column]);`.
18. `bottom--;`
   Moves the relevant counter or pointer by one position.
19. `if(left <= right) {`
   Runs the next block only when `left <= right` is true.
20. `for(int row = bottom; row >= top; row--) answer.push_back(mat[row][left]);`
   Starts a loop: first `int row = bottom`; keep repeating while `row >= top` is true; after each iteration perform `row--`. Its one-line body is `answer.push_back(mat[row][left]);`.
21. `left++;`
   Moves the relevant counter or pointer by one position.
22. `return answer;`
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
- push_back: Adds one element to the end of a vector or deque.
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
[[1,2,3],[4,5,6]]: top gives 1,2,3; right gives 6; bottom gives 5,4. No left edge remains. Result [1,2,3,6,5,4].

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Each traversal removes one unvisited boundary. The bound checks prevent revisiting a final single row or single column.

The key invariant (a fact that remains true after every useful iteration) is:
All cells outside top,bottom,left,right have already been emitted exactly once.

7. COMPLEXITY
-------------
- Time complexity: O(rows × columns).
- Extra-space complexity: O(1) excluding answer.
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
