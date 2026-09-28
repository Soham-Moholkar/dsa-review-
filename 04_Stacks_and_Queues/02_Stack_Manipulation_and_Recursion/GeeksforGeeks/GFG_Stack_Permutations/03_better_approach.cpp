#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isStackPermutation(vector<int>& a, vector<int>& b) {
        if (a.size() != b.size()) return false;
        stack<int> st;
        size_t j = 0;
        for (int value : a) {
            st.push(value);
            while (!st.empty() && j < b.size() && st.top() == b[j]) {
                st.pop();
                ++j;
            }
        }
        return j == b.size();
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
Method: Greedy std::stack simulation.
Push in order, then consume every requested pop currently available at the top.
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
7. `stack<int> st;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
8. `size_t j = 0;`
   Updates `size_t j` to `0` for the next step of the algorithm.
9. `for (int value : a) {`
   Starts a range-based loop. `int value : a` means: take each element from the container in turn and run the block.
10. `st.push(value);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `while (!st.empty() && j < b.size() && st.top() == b[j]) {`
   Repeats the following block while `!st.empty() && j < b.size() && st.top() == b[j]` is true.
12. `st.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `++j;`
   Moves the relevant counter or pointer by one position.
14. `return j == b.size();`
   Ends the function and sends `j == b.size()` back to the caller.

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
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
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
Push in order, then consume every requested pop currently available at the top.

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
