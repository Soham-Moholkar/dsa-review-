#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> original = matrix;
        int rows = matrix.size();
        int columns = matrix[0].size();
        for(int row = 0; row < rows; row++) {
            for(int column = 0; column < columns; column++) {
                if(original[row][column] == 0) {
                    for(int c = 0; c < columns; c++) matrix[row][c] = 0;
                    for(int r = 0; r < rows; r++) matrix[r][column] = 0;
                }
            }
        }
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

This particular file uses the "Use a copy to preserve original zeroes" approach.
It is the brute-force baseline stored in this problem folder.

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
Approach name: Use a copy to preserve original zeroes

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `matrix`: the input two-dimensional matrix; this function may read or update its cells.
- `original`: an unchanged copy used for comparison or to prevent newly written markers from affecting the scan.
- `rows`: the number of matrix rows.
- `columns`: the number of matrix columns.
- `row`: the current matrix row index.
- `column`: the current matrix column index.
- `c`: a short column index used while traversing a matrix.
- `r`: a short row index used while traversing a matrix.

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
6. `vector<vector<int>> original = matrix;`
   Creates `original` and initializes it from `matrix`. This gives the algorithm its starting state.
7. `int rows = matrix.size();`
   Creates `rows` and initializes it from `matrix.size()`. This gives the algorithm its starting state.
8. `int columns = matrix[0].size();`
   Creates `columns` and initializes it from `matrix[0].size()`. This gives the algorithm its starting state.
9. `for(int row = 0; row < rows; row++) {`
   Starts a loop: first `int row = 0`; keep repeating while `row < rows` is true; after each iteration perform `row++`.
10. `for(int column = 0; column < columns; column++) {`
   Starts a loop: first `int column = 0`; keep repeating while `column < columns` is true; after each iteration perform `column++`.
11. `if(original[row][column] == 0) {`
   Runs the next block only when `original[row][column] == 0` is true.
12. `for(int c = 0; c < columns; c++) matrix[row][c] = 0;`
   Starts a loop: first `int c = 0`; keep repeating while `c < columns` is true; after each iteration perform `c++`. Its one-line body is `matrix[row][c] = 0;`.
13. `for(int r = 0; r < rows; r++) matrix[r][column] = 0;`
   Starts a loop: first `int r = 0`; keep repeating while `r < rows` is true; after each iteration perform `r++`. Its one-line body is `matrix[r][column] = 0;`.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
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
Trace this exact file using the first example in `testcases.md`. It applies the "Use a copy to preserve original zeroes" approach, so follow the numbered executable statements above and record each listed variable after it changes. Do not reuse the optimal implementation's saved variables: this file may enumerate candidates, sort values, or build auxiliary state instead.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
This file uses the exhaustive "Use a copy to preserve original zeroes" strategy. The numbered walkthrough shows the complete candidate search performed by this implementation. Because every candidate allowed by the loops is examined before the answer is returned, a valid candidate cannot be skipped; the return/update condition keeps exactly the result required by the problem.

The key invariant (a fact that remains true after every useful iteration) is:
All candidates before the current loop position have been examined according to the code's condition, and the stored result reflects those candidates.

7. COMPLEXITY
-------------
- Time complexity: O(r × c × (r+c)).
- Extra-space complexity: O(r × c).
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
