#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row = 0; row < n; row++) {
            for(int column = row + 1; column < n; column++) {
                swap(matrix[row][column], matrix[column][row]);
            }
        }
        for(int row = 0; row < n; row++) {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Rotate Image
Platform: LeetCode
Pattern: Matrices and Two-Dimensional Vectors

Problem goal:
Rotate a square matrix 90 degrees clockwise in place.

Core insight for this problem family:
Transpose across the main diagonal. For clockwise rotation reverse each row. For anticlockwise rotation reverse the order of rows.

This particular file uses the "In-place transpose plus row reversal" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`void rotate(vector<vector<int>>& matrix)`

- `void` means this function does not return a value; the answer is written into an input object.
- `rotate` is the function name the online judge calls.
- `matrix` is a two-dimensional dynamic integer matrix; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The matrix is nonempty and rectangular; rotation additionally requires a square.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: In-place transpose plus row reversal

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `matrix`: the input two-dimensional matrix; this function may read or update its cells.
- `n`: the number of elements currently considered.
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
5. `void rotate(vector<vector<int>>& matrix) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = matrix.size();`
   Creates `n` and initializes it from `matrix.size()`. This gives the algorithm its starting state.
7. `for(int row = 0; row < n; row++) {`
   Starts a loop: first `int row = 0`; keep repeating while `row < n` is true; after each iteration perform `row++`.
8. `for(int column = row + 1; column < n; column++) {`
   Starts a loop: first `int column = row + 1`; keep repeating while `column < n` is true; after each iteration perform `column++`.
9. `swap(matrix[row][column], matrix[column][row]);`
   Exchanges the two selected values without needing a manual temporary variable.
10. `for(int row = 0; row < n; row++) {`
   Starts a loop: first `int row = 0`; keep repeating while `row < n` is true; after each iteration perform `row++`.
11. `reverse(matrix[row].begin(), matrix[row].end());`
   Reverses the selected range in place. The second iterator is one position past the range.

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
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- reverse: Reverses the order of elements in the selected iterator range.
- swap: Exchanges two stored values.
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
[[1,2],[3,4]] transposes to [[1,3],[2,4]]. Reversing each row gives clockwise [[3,1],[4,2]]. Reversing row order gives anticlockwise [[2,4],[1,3]].

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
A transpose maps (r,c) to (c,r). The following reversal yields (c,n-1-r) clockwise or (n-1-c,r) anticlockwise. The matrix must be square.

The key invariant (a fact that remains true after every useful iteration) is:
After transpose, each row contains a column of the original; reversing gives clockwise order.

7. COMPLEXITY
-------------
- Time complexity: O(n^2).
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
