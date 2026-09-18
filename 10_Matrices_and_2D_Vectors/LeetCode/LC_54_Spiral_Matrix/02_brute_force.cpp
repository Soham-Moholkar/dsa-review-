#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        vector<int> answer;
        int directionRow[4] = {0,1,0,-1};
        int directionColumn[4] = {1,0,-1,0};
        int direction = 0, row = 0, column = 0;
        for(int step = 0; step < rows * columns; step++) {
            answer.push_back(matrix[row][column]);
            visited[row][column] = true;
            int nextRow = row + directionRow[direction];
            int nextColumn = column + directionColumn[direction];
            if(nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                direction = (direction + 1) % 4;
                nextRow = row + directionRow[direction];
                nextColumn = column + directionColumn[direction];
            }
            row = nextRow;
            column = nextColumn;
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Spiral Matrix
Platform: LeetCode
Pattern: Matrices and Two-Dimensional Vectors

Problem goal:
Return all matrix values in clockwise spiral order.

Core insight for this problem family:
Maintain top, bottom, left, and right boundaries. Traverse the top edge, right edge, bottom edge, and left edge, shrinking the appropriate boundary after each. Recheck bounds before the last two edges.

This particular file uses the "Visited simulation" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> spiralOrder(vector<vector<int>>& matrix)`

- `vector<int>` means this function returns a dynamic array of integers.
- `spiralOrder` is the function name the online judge calls.
- `matrix` is a two-dimensional dynamic integer matrix; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The matrix is nonempty and rectangular; rotation additionally requires a square.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Visited simulation

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `matrix`: the input two-dimensional matrix; this function may read or update its cells.
- `rows`: the number of matrix rows.
- `columns`: the number of matrix columns.
- `visited`: marks matrix cells already added to the spiral result.
- `answer`: the best or complete result found so far.
- `directionRow`: row changes for right, down, left, and up movement.
- `directionColumn`: column changes for right, down, left, and up movement.
- `direction`: which of the four matrix movement directions is active.
- `step`: the current simulation or repeated-operation count.
- `nextRow`: the row index of the next proposed matrix cell.
- `nextColumn`: the column index of the next proposed matrix cell.
- `row`: the current matrix row index.
- `column`: the current matrix column index.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `vector<int> spiralOrder(vector<vector<int>>& matrix) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int rows = matrix.size();`
   Creates `rows` and initializes it from `matrix.size()`. This gives the algorithm its starting state.
7. `int columns = matrix[0].size();`
   Creates `columns` and initializes it from `matrix[0].size()`. This gives the algorithm its starting state.
8. `vector<vector<bool>> visited(rows, vector<bool>(columns, false));`
   Declares `visited` so it can store state used by the algorithm.
9. `vector<int> answer;`
   Declares `answer` so it can store state used by the algorithm.
10. `int directionRow[4] = {0,1,0,-1};`
   Creates `the variable` and initializes it from `{0,1,0,-1}`. This gives the algorithm its starting state.
11. `int directionColumn[4] = {1,0,-1,0};`
   Creates `the variable` and initializes it from `{1,0,-1,0}`. This gives the algorithm its starting state.
12. `int direction = 0, row = 0, column = 0;`
   Creates `direction` and initializes it from `0, row = 0, column = 0`. This gives the algorithm its starting state.
13. `for(int step = 0; step < rows * columns; step++) {`
   Starts a loop: first `int step = 0`; keep repeating while `step < rows * columns` is true; after each iteration perform `step++`.
14. `answer.push_back(matrix[row][column]);`
   Appends the computed value to the end of the result/container.
15. `visited[row][column] = true;`
   Updates `visited[row][column]` to `true` for the next step of the algorithm.
16. `int nextRow = row + directionRow[direction];`
   Creates `nextRow` and initializes it from `row + directionRow[direction]`. This gives the algorithm its starting state.
17. `int nextColumn = column + directionColumn[direction];`
   Creates `nextColumn` and initializes it from `column + directionColumn[direction]`. This gives the algorithm its starting state.
18. `if(nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {`
   Runs the next block only when `nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]` is true.
19. `direction = (direction + 1) % 4;`
   Updates `direction` to `(direction + 1) % 4` for the next step of the algorithm.
20. `nextRow = row + directionRow[direction];`
   Updates `nextRow` to `row + directionRow[direction]` for the next step of the algorithm.
21. `nextColumn = column + directionColumn[direction];`
   Updates `nextColumn` to `column + directionColumn[direction]` for the next step of the algorithm.
22. `row = nextRow;`
   Updates `row` to `nextRow` for the next step of the algorithm.
23. `column = nextColumn;`
   Updates `column` to `nextColumn` for the next step of the algorithm.
24. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
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
Trace this exact file using the first example in `testcases.md`. It applies the "Visited simulation" approach, so follow the numbered executable statements above and record each listed variable after it changes. Do not reuse the optimal implementation's saved variables: this file may enumerate candidates, sort values, or build auxiliary state instead.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
This file uses the exhaustive "Visited simulation" strategy. The numbered walkthrough shows the complete candidate search performed by this implementation. Because every candidate allowed by the loops is examined before the answer is returned, a valid candidate cannot be skipped; the return/update condition keeps exactly the result required by the problem.

The key invariant (a fact that remains true after every useful iteration) is:
All candidates before the current loop position have been examined according to the code's condition, and the stored result reflects those candidates.

7. COMPLEXITY
-------------
- Time complexity: O(r × c).
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
