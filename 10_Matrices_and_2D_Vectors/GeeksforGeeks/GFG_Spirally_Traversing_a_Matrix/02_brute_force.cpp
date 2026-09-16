#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        int rows = mat.size();
        int columns = mat[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        vector<int> answer;
        int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int direction = 0;
        int row = 0;
        int column = 0;
        for(int step = 0; step < rows * columns; step++) {
            answer.push_back(mat[row][column]);
            visited[row][column] = true;
            int nextRow = row + directions[direction][0];
            int nextColumn = column + directions[direction][1];
            if(nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                direction = (direction + 1) % 4;
                nextRow = row + directions[direction][0];
                nextColumn = column + directions[direction][1];
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
Problem: Spirally Traversing a Matrix
Platform: GeeksforGeeks
Pattern: Matrices and Two-Dimensional Vectors

Problem goal:
Return matrix elements in clockwise spiral order.

Core insight for this problem family:
Maintain top, bottom, left, and right boundaries. Traverse the top edge, right edge, bottom edge, and left edge, shrinking the appropriate boundary after each. Recheck bounds before the last two edges.

This particular file uses the "Simulation with visited cells and directions" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> spirallyTraverse(vector<vector<int>>& mat)`

- `vector<int>` means this function returns a dynamic array of integers.
- `spirallyTraverse` is the function name the online judge calls.
- `mat` is a two-dimensional dynamic integer matrix; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The matrix is nonempty and rectangular; rotation additionally requires a square.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Simulation with visited cells and directions

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `mat`: the input two-dimensional matrix used by the GFG-style function.
- `rows`: the number of matrix rows.
- `columns`: the number of matrix columns.
- `visited`: marks matrix cells already added to the spiral result.
- `answer`: the best or complete result found so far.
- `directions`: paired row/column changes for the four matrix directions.
- `direction`: which of the four matrix movement directions is active.
- `row`: the current matrix row index.
- `column`: the current matrix column index.
- `step`: the current simulation or repeated-operation count.
- `nextRow`: the row index of the next proposed matrix cell.
- `nextColumn`: the column index of the next proposed matrix cell.

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
6. `int rows = mat.size();`
   Creates `rows` and initializes it from `mat.size()`. This gives the algorithm its starting state.
7. `int columns = mat[0].size();`
   Creates `columns` and initializes it from `mat[0].size()`. This gives the algorithm its starting state.
8. `vector<vector<bool>> visited(rows, vector<bool>(columns, false));`
   Declares `visited` so it can store state used by the algorithm.
9. `vector<int> answer;`
   Declares `answer` so it can store state used by the algorithm.
10. `int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};`
   Creates `the variable` and initializes it from `{{0,1},{1,0},{0,-1},{-1,0}}`. This gives the algorithm its starting state.
11. `int direction = 0;`
   Creates `direction` and initializes it from `0`. This gives the algorithm its starting state.
12. `int row = 0;`
   Creates `row` and initializes it from `0`. This gives the algorithm its starting state.
13. `int column = 0;`
   Creates `column` and initializes it from `0`. This gives the algorithm its starting state.
14. `for(int step = 0; step < rows * columns; step++) {`
   Starts a loop: first `int step = 0`; keep repeating while `step < rows * columns` is true; after each iteration perform `step++`.
15. `answer.push_back(mat[row][column]);`
   Appends the computed value to the end of the result/container.
16. `visited[row][column] = true;`
   Updates `visited[row][column]` to `true` for the next step of the algorithm.
17. `int nextRow = row + directions[direction][0];`
   Creates `nextRow` and initializes it from `row + directions[direction][0]`. This gives the algorithm its starting state.
18. `int nextColumn = column + directions[direction][1];`
   Creates `nextColumn` and initializes it from `column + directions[direction][1]`. This gives the algorithm its starting state.
19. `if(nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {`
   Runs the next block only when `nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]` is true.
20. `direction = (direction + 1) % 4;`
   Updates `direction` to `(direction + 1) % 4` for the next step of the algorithm.
21. `nextRow = row + directions[direction][0];`
   Updates `nextRow` to `row + directions[direction][0]` for the next step of the algorithm.
22. `nextColumn = column + directions[direction][1];`
   Updates `nextColumn` to `column + directions[direction][1]` for the next step of the algorithm.
23. `row = nextRow;`
   Updates `row` to `nextRow` for the next step of the algorithm.
24. `column = nextColumn;`
   Updates `column` to `nextColumn` for the next step of the algorithm.
25. `return answer;`
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
- Extra-space complexity: O(rows × columns).
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
