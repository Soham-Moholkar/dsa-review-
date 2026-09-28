#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> out(rows,vector<int>(cols,-1));
        for (int r = 0; r < rows; ++r) for (int c = 0; c < cols; ++c) {
            int best = INT_MAX;
            for (int x = 0; x < rows; ++x) for (int y = 0; y < cols; ++y) if (grid[x][y]) best = min(best,abs(r-x)+abs(c-y));
            if (best != INT_MAX) out[r][c] = best;
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
Method: Compare every cell with every source.
With no obstacles, Manhattan distance equals shortest four-direction distance. Scan all ones for each cell.
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
8. `for (int r = 0; r < rows; ++r) for (int c = 0; c < cols; ++c) {`
   Starts a loop: first `int r = 0`; keep repeating while `r < rows` is true; after each iteration perform `++r`. Its one-line body is `for (int c = 0; c < cols; ++c) {`.
9. `int best = INT_MAX;`
   Creates `best` and initializes it from `INT_MAX`. This gives the algorithm its starting state.
10. `for (int x = 0; x < rows; ++x) for (int y = 0; y < cols; ++y) if (grid[x][y]) best = min(best,abs(r-x)+abs(c-y));`
   Starts a loop: first `int x = 0`; keep repeating while `x < rows` is true; after each iteration perform `++x`. Its one-line body is `for (int y = 0; y < cols; ++y) if (grid[x][y]) best = min(best,abs(r-x)+abs(c-y));`.
11. `if (best != INT_MAX) out[r][c] = best;`
   Runs the next block only when `best != INT_MAX` is true. The one-line action is `out[r][c] = best;`.
12. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
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
- INT_MIN / INT_MAX: The smallest/largest value representable by int.
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
With no obstacles, Manhattan distance equals shortest four-direction distance. Scan all ones for each cell.

7. COMPLEXITY
Time: O((rc)²). Space: O(rc) result.
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
