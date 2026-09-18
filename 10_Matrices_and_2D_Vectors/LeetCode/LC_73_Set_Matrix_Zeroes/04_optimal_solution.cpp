#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        bool firstRowZero = false;
        bool firstColumnZero = false;
        for(int column = 0; column < columns; column++) if(matrix[0][column] == 0) firstRowZero = true;
        for(int row = 0; row < rows; row++) if(matrix[row][0] == 0) firstColumnZero = true;
        for(int row = 1; row < rows; row++) {
            for(int column = 1; column < columns; column++) {
                if(matrix[row][column] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][column] = 0;
                }
            }
        }
        for(int row = 1; row < rows; row++) {
            for(int column = 1; column < columns; column++) {
                if(matrix[row][0] == 0 || matrix[0][column] == 0) matrix[row][column] = 0;
            }
        }
        if(firstRowZero) for(int column = 0; column < columns; column++) matrix[0][column] = 0;
        if(firstColumnZero) for(int row = 0; row < rows; row++) matrix[row][0] = 0;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Set Matrix Zeroes
Platform: LeetCode
Pattern: Matrices and Two-Dimensional Vectors

Problem goal:
If a cell is zero, set its entire row and column to zero.

Core insight for this problem family:
Save whether the first row and column originally had zeros. Mark other affected rows and columns in those first cells, update the interior, then handle the saved first row and column.

This particular file uses the "First row and column as markers" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`void setZeroes(vector<vector<int>>& matrix)`

- `void` means this function does not return a value; the answer is written into an input object.
- `setZeroes` is the function name the online judge calls.
- `matrix` is a two-dimensional dynamic integer matrix; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The matrix is nonempty and rectangular; rotation additionally requires a square.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: First row and column as markers

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `matrix`: the input two-dimensional matrix; this function may read or update its cells.
- `rows`: the number of matrix rows.
- `columns`: the number of matrix columns.
- `firstRowZero`: remembers whether the original first row contained a zero.
- `firstColumnZero`: remembers whether the original first column contained a zero.
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
5. `void setZeroes(vector<vector<int>>& matrix) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int rows = matrix.size();`
   Creates `rows` and initializes it from `matrix.size()`. This gives the algorithm its starting state.
7. `int columns = matrix[0].size();`
   Creates `columns` and initializes it from `matrix[0].size()`. This gives the algorithm its starting state.
8. `bool firstRowZero = false;`
   Creates `firstRowZero` and initializes it from `false`. This gives the algorithm its starting state.
9. `bool firstColumnZero = false;`
   Creates `firstColumnZero` and initializes it from `false`. This gives the algorithm its starting state.
10. `for(int column = 0; column < columns; column++) if(matrix[0][column] == 0) firstRowZero = true;`
   Starts a loop: first `int column = 0`; keep repeating while `column < columns` is true; after each iteration perform `column++`. Its one-line body is `if(matrix[0][column] == 0) firstRowZero = true;`.
11. `for(int row = 0; row < rows; row++) if(matrix[row][0] == 0) firstColumnZero = true;`
   Starts a loop: first `int row = 0`; keep repeating while `row < rows` is true; after each iteration perform `row++`. Its one-line body is `if(matrix[row][0] == 0) firstColumnZero = true;`.
12. `for(int row = 1; row < rows; row++) {`
   Starts a loop: first `int row = 1`; keep repeating while `row < rows` is true; after each iteration perform `row++`.
13. `for(int column = 1; column < columns; column++) {`
   Starts a loop: first `int column = 1`; keep repeating while `column < columns` is true; after each iteration perform `column++`.
14. `if(matrix[row][column] == 0) {`
   Runs the next block only when `matrix[row][column] == 0` is true.
15. `matrix[row][0] = 0;`
   Updates `matrix[row][0]` to `0` for the next step of the algorithm.
16. `matrix[0][column] = 0;`
   Updates `matrix[0][column]` to `0` for the next step of the algorithm.
17. `for(int row = 1; row < rows; row++) {`
   Starts a loop: first `int row = 1`; keep repeating while `row < rows` is true; after each iteration perform `row++`.
18. `for(int column = 1; column < columns; column++) {`
   Starts a loop: first `int column = 1`; keep repeating while `column < columns` is true; after each iteration perform `column++`.
19. `if(matrix[row][0] == 0 || matrix[0][column] == 0) matrix[row][column] = 0;`
   Runs the next block only when `matrix[row][0] == 0 || matrix[0][column] == 0` is true. The one-line action is `matrix[row][column] = 0;`.
20. `if(firstRowZero) for(int column = 0; column < columns; column++) matrix[0][column] = 0;`
   Runs the next block only when `firstRowZero` is true. The one-line action is `for(int column = 0; column < columns; column++) matrix[0][column] = 0;`.
21. `if(firstColumnZero) for(int row = 0; row < rows; row++) matrix[row][0] = 0;`
   Runs the next block only when `firstColumnZero` is true. The one-line action is `for(int row = 0; row < rows; row++) matrix[row][0] = 0;`.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- true / false: The two boolean values.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
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
[[1,1,1],[1,0,1],[1,1,1]] becomes [[1,0,1],[0,0,0],[1,0,1]]. Only the original zero determines the affected row and column.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
The first row and column store original-zero information without allocating marker arrays. Delayed writes stop generated zeros from causing extra clearing.

The key invariant (a fact that remains true after every useful iteration) is:
First-row and first-column markers represent every interior row and column requiring zeroing.

7. COMPLEXITY
-------------
- Time complexity: O(r × c).
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
