#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        if (!n) return -1;
        stack<int> people;
        for (int i = 0; i < n; ++i) people.push(i);
        while (people.size() > 1) {
            int a = people.top();
            people.pop();
            int b = people.top();
            people.pop();
            people.push(mat[a][b] ? b : a);
        }
        int candidate = people.top();
        for (int i = 0; i < n; ++i) if (i != candidate && (mat[candidate][i] || !mat[i][candidate])) return -1;
        return candidate;
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
Method: Pairwise elimination with a stack.
Pop two people; one knows-relation always eliminates at least one. Verify the survivor.
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
7. `if (!n) return -1;`
   Runs the next block only when `!n` is true. The one-line action is `return -1;`.
8. `stack<int> people;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `for (int i = 0; i < n; ++i) people.push(i);`
   Starts a loop: first `int i = 0`; keep repeating while `i < n` is true; after each iteration perform `++i`. Its one-line body is `people.push(i);`.
10. `while (people.size() > 1) {`
   Repeats the following block while `people.size() > 1` is true.
11. `int a = people.top();`
   Creates `a` and initializes it from `people.top()`. This gives the algorithm its starting state.
12. `people.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `int b = people.top();`
   Creates `b` and initializes it from `people.top()`. This gives the algorithm its starting state.
14. `people.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
15. `people.push(mat[a][b] ? b : a);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `int candidate = people.top();`
   Creates `candidate` and initializes it from `people.top()`. This gives the algorithm its starting state.
17. `for (int i = 0; i < n; ++i) if (i != candidate && (mat[candidate][i] || !mat[i][candidate])) return -1;`
   Starts a loop: first `int i = 0`; keep repeating while `i < n` is true; after each iteration perform `++i`. Its one-line body is `if (i != candidate && (mat[candidate][i] || !mat[i][candidate])) return -1;`.
18. `return candidate;`
   Ends the function and sends `candidate` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
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
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
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
Pop two people; one knows-relation always eliminates at least one. Verify the survivor.

7. COMPLEXITY
Time: O(n). Space: O(n).
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
