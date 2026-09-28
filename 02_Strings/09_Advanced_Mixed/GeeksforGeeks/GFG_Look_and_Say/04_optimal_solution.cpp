#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string current = "1";
        for (int row = 1; row < n; ++row) {
            string next;
            for (int i = 0; i < (int)current.size();) {
                int j = i+1;
                while (j < (int)current.size() && current[j] == current[i]) ++j;
                next += to_string(j-i);
                next += current[i];
                i = j;
            }
            current = move(next);
        }
        return current;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Look and Say Pattern: n >= 1. The first row is "1"; every later row describes counts then digits of consecutive runs in the previous row.

2. FUNCTION SIGNATURE, PART BY PART
string countAndSay(int n)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Same rolling-row simulation; no distinct third algorithm.
Avoid inventing a closed-form shortcut; reading and constructing all intermediate rows is the documented method.
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
5. `string countAndSay(int n) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `string current = "1";`
   Updates `string current` to `"1"` for the next step of the algorithm.
7. `for (int row = 1; row < n; ++row) {`
   Starts a loop: first `int row = 1`; keep repeating while `row < n` is true; after each iteration perform `++row`.
8. `string next;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `for (int i = 0; i < (int)current.size();) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < (int)current.size()` is true; after each iteration perform ``.
10. `int j = i+1;`
   Creates `j` and initializes it from `i+1`. This gives the algorithm its starting state.
11. `while (j < (int)current.size() && current[j] == current[i]) ++j;`
   Repeats the following block while `j < (int)current.size() && current[j] == current[i]` is true. Its one-line body is `++j;`.
12. `next += to_string(j-i);`
   Updates the stored state using its previous value and the expression on the right.
13. `next += current[i];`
   Updates the stored state using its previous value and the expression on the right.
14. `i = j;`
   Updates `i` to `j` for the next step of the algorithm.
15. `current = move(next);`
   Updates `current` to `move(next)` for the next step of the algorithm.
16. `return current;`
   Ends the function and sends `current` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: Rows 1 through 5 are "1", "11", "21", "1211", "111221". In row 4, one 1, one 2, two 1s produce row 5.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Current is the complete previous row, and next describes only its fully consumed runs.
Avoid inventing a closed-form shortcut; reading and constructing all intermediate rows is the documented method.

7. COMPLEXITY
Time: O(T). Space: O(L).
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
