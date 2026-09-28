#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isStackPermutation(vector<int>& a, vector<int>& b) {
        if (a.size() != b.size()) return false;
        int n = a.size();
        function<bool(int,int,vector<int>)> visit = [&](int i, int j, vector<int> st) {
            if (j == n) return true;
            if (!st.empty() && st.back() == b[j]) {
                auto next = st;
                next.pop_back();
                if (visit(i, j+1, next)) return true;
            }
            if (i < n) {
                st.push_back(a[i]);
                if (visit(i+1, j, st)) return true;
            }
            return false;
        }
        ;
        return visit(0,0,{
        }
        );
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Validate Stack Operations: Equal-length arrays of distinct values give push and required pop order. This local adapter returns bool and omits redundant n. Revisit Validate Stack Sequences using the GFG contract.

2. FUNCTION SIGNATURE, PART BY PART
bool isStackPermutation(vector<int>& a, vector<int>& b)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Explore legal push/pop sequences.
Recursively try pushing the next input and popping only a matching top. This exponential teaching baseline is for small examples.
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
5. `bool isStackPermutation(vector<int>& a, vector<int>& b) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `if (a.size() != b.size()) return false;`
   Runs the next block only when `a.size() != b.size()` is true. The one-line action is `return false;`.
7. `int n = a.size();`
   Creates `n` and initializes it from `a.size()`. This gives the algorithm its starting state.
8. `function<bool(int,int,vector<int>)> visit = [&](int i, int j, vector<int> st) {`
   Creates a callable named `visit`. `[&]` lets it use surrounding local variables by reference, which is needed for the recursive search.
9. `if (j == n) return true;`
   Runs the next block only when `j == n` is true. The one-line action is `return true;`.
10. `if (!st.empty() && st.back() == b[j]) {`
   Runs the next block only when `!st.empty() && st.back() == b[j]` is true.
11. `auto next = st;`
   Creates `next` and initializes it from `st`. This gives the algorithm its starting state.
12. `next.pop_back();`
   Removes the last element from the container.
13. `if (visit(i, j+1, next)) return true;`
   Runs the next block only when `visit(i, j+1, next)` is true. The one-line action is `return true;`.
14. `if (i < n) {`
   Runs the next block only when `i < n` is true.
15. `st.push_back(a[i]);`
   Appends the computed value to the end of the result/container.
16. `if (visit(i+1, j, st)) return true;`
   Runs the next block only when `visit(i+1, j, st)` is true. The one-line action is `return true;`.
17. `return false;`
   Ends the function and sends `false` back to the caller.
18. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
19. `return visit(0,0,{`
   Ends the function and sends `visit(0,0,{` back to the caller.
20. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- function: A standard-library wrapper able to store a callable object such as a recursive lambda.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- push_back: Adds one element to the end of a vector or deque.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
- front / back: Accesses the first or last element of a nonempty container.
- lambda ([&]): Creates an unnamed function. [&] captures surrounding local variables by reference, so the lambda can read and modify them.
- recursion: A function calls itself on a smaller remaining choice. It needs a stopping condition to avoid infinite calls.
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
Shared contract trace: For a=[1,2,3], b=[2,1,3], push 1 and 2, pop 2 and 1, then push and pop 3. For b=[3,1,2], 2 blocks access to 1 after popping 3.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
The explicit stack holds pushed values not yet consumed by the requested pop prefix.
Recursively try pushing the next input and popping only a matching top. This exponential teaching baseline is for small examples.

7. COMPLEXITY
Time: O(4^n n) upper bound. Space: O(n²) copied states.
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
