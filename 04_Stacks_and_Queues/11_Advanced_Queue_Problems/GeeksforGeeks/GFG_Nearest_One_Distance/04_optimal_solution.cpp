#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> out(rows,vector<int>(cols,-1));
        queue<pair<int,int>> pending;
        for (int r = 0; r < rows; ++r) for (int c = 0; c < cols; ++c) if (grid[r][c]) {
            out[r][c] = 0;
            pending.push({
                r,c
            }
            );
        }
        int dr[4] = {
            1,-1,0,0
        }
        , dc[4] = {
            0,0,1,-1
        }
        ;
        while (!pending.empty()) {
            auto [r,c] = pending.front();
            pending.pop();
            for (int d = 0; d < 4; ++d) {
                int nr = r+dr[d], nc = c+dc[d];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && out[nr][nc] == -1) {
                    out[nr][nc] = out[r][c]+1;
                    pending.push({
                        nr,nc
                    }
                    );
                }
            }
        }
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Distance of Nearest Cell Having 1: Rectangular nonempty binary matrix. Return shortest four-direction distance to any 1. If no source exists, this local extension returns -1 at every cell.

2. FUNCTION SIGNATURE, PART BY PART
vector<vector<int>> nearest(vector<vector<int>>& grid)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: One multi-source BFS.
Enqueue every source at distance zero. Mark a neighbor as soon as it enters the queue so it cannot be enqueued again.
Read the initialization first, then trace each loop or operation, and finally
check the return expression against the required type and sentinel.

Executable-line walkthrough:
1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `vector<vector<int>> nearest(vector<vector<int>>& grid) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int rows = grid.size(), cols = grid[0].size();`
   Creates `rows` and initializes it from `grid.size(), cols = grid[0].size()`. This gives the algorithm its starting state.
7. `vector<vector<int>> out(rows,vector<int>(cols,-1));`
   Declares `out` so it can store state used by the algorithm.
8. `queue<pair<int,int>> pending;`
   Declares `pending` so it can store state used by the algorithm.
9. `for (int r = 0; r < rows; ++r) for (int c = 0; c < cols; ++c) if (grid[r][c]) {`
   Starts a loop: first `int r = 0`; keep repeating while `r < rows` is true; after each iteration perform `++r`. Its one-line body is `for (int c = 0; c < cols; ++c) if (grid[r][c]) {`.
10. `out[r][c] = 0;`
   Updates `out[r][c]` to `0` for the next step of the algorithm.
11. `pending.push({`
   Performs this operation to maintain the state described in the algorithm walkthrough.
12. `r,c`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `int dr[4] = {`
   Creates `the variable` and initializes it from `{`. This gives the algorithm its starting state.
15. `1,-1,0,0`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `, dc[4] = {`
   Updates `, dc[4]` to `{` for the next step of the algorithm.
17. `0,0,1,-1`
   Performs this operation to maintain the state described in the algorithm walkthrough.
18. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
19. `while (!pending.empty()) {`
   Repeats the following block while `!pending.empty()` is true.
20. `auto [r,c] = pending.front();`
   Updates `auto [r,c]` to `pending.front()` for the next step of the algorithm.
21. `pending.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
22. `for (int d = 0; d < 4; ++d) {`
   Starts a loop: first `int d = 0`; keep repeating while `d < 4` is true; after each iteration perform `++d`.
23. `int nr = r+dr[d], nc = c+dc[d];`
   Creates `nr` and initializes it from `r+dr[d], nc = c+dc[d]`. This gives the algorithm its starting state.
24. `if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && out[nr][nc] == -1) {`
   Runs the next block only when `nr >= 0 && nr < rows && nc >= 0 && nc < cols && out[nr][nc] == -1` is true.
25. `out[nr][nc] = out[r][c]+1;`
   Updates `out[nr][nc]` to `out[r][c]+1` for the next step of the algorithm.
26. `pending.push({`
   Performs this operation to maintain the state described in the algorithm walkthrough.
27. `nr,nc`
   Performs this operation to maintain the state described in the algorithm walkthrough.
28. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
29. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- pair: Stores two values together. first names the first value and second names the second value.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- front / back: Accesses the first or last element of a nonempty container.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: For [[0,0,1],[0,0,0]], begin with (0,2) at distance 0. Its neighbors receive 1, then the next wave receives 2. Result [[2,1,0],[3,2,1]].
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Each enqueued cell has its shortest distance because FIFO processes every smaller distance first.
Enqueue every source at distance zero. Mark a neighbor as soon as it enters the queue so it cannot be enqueued again.

7. COMPLEXITY
Time: O(rc). Space: O(rc).
Input-by-value copying is additional to the stated auxiliary storage. n/m are
input lengths; C is capacity; T is total generated text; output space is named
separately where relevant. Small teaching baselines can exceed judge limits.

8. EDGE CASES TO CHECK
Use the normal, boundary, repeated-value, and missing-answer cases in
testcases.md. Follow the documented allowed input domain before adding cases.

9. COMMON MISTAKES
Changing argument order, using the wrong index base, dropping overlaps,
ignoring equal-value ties, and treating a missing answer as a valid empty value
can all violate the contract. State your invariant before changing a comparison.

10. HOW TO STUDY THIS SOLUTION
Try the starter first. Trace one example by hand, explain why each update is
safe, compare time and memory across references, then recode from memory.
Record only actual learner mistakes and revision dates.
*/
