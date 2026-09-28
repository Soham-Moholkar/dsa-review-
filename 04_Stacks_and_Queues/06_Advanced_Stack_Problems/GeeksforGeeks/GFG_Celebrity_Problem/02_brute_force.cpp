#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int candidate = 0; candidate < n; ++candidate) {
            bool valid = true;
            for (int i = 0; i < n; ++i) if (i != candidate && (mat[candidate][i] || !mat[i][candidate])) valid = false;
            if (valid) return candidate;
        }
        return -1;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Celebrity Problem: Square binary knows matrix. A celebrity knows nobody else and is known by everyone else. Ignore the diagonal. Return zero-based index or -1.

2. FUNCTION SIGNATURE, PART BY PART
int celebrity(vector<vector<int>>& mat)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Verify every person.
Test all row and column conditions for each candidate.
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
5. `int celebrity(vector<vector<int>>& mat) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = mat.size();`
   Creates `n` and initializes it from `mat.size()`. This gives the algorithm its starting state.
7. `for (int candidate = 0; candidate < n; ++candidate) {`
   Starts a loop: first `int candidate = 0`; keep repeating while `candidate < n` is true; after each iteration perform `++candidate`.
8. `bool valid = true;`
   Creates `valid` and initializes it from `true`. This gives the algorithm its starting state.
9. `for (int i = 0; i < n; ++i) if (i != candidate && (mat[candidate][i] || !mat[i][candidate])) valid = false;`
   Starts a loop: first `int i = 0`; keep repeating while `i < n` is true; after each iteration perform `++i`. Its one-line body is `if (i != candidate && (mat[candidate][i] || !mat[i][candidate])) valid = false;`.
10. `if (valid) return candidate;`
   Runs the next block only when `valid` is true. The one-line action is `return candidate;`.
11. `return -1;`
   Ends the function and sends `-1` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
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
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
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
Shared contract trace: If 0 knows 1, discard 0. If 1 does not know 2, discard 2. Candidate 1 still must pass both its row and column checks.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Every eliminated person has a concrete witness proving they cannot be the celebrity.
Test all row and column conditions for each candidate.

7. COMPLEXITY
Time: O(n²). Space: O(1).
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
