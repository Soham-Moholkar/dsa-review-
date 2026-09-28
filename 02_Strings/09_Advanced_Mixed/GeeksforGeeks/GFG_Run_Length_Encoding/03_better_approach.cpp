#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string encode(string s) {
        string out;
        for (int i = 0; i < (int)s.size();) {
            int j = i+1;
            while (j < (int)s.size() && s[j] == s[i]) ++j;
            out += s[i];
            out += to_string(j-i);
            i = j;
        }
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Run Length Encoding: Encode every consecutive character run as character followed by its decimal count, including count 1. This study adapter uses Solution::encode.

2. FUNCTION SIGNATURE, PART BY PART
string encode(string s)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Serialize each run immediately.
Advance a run endpoint and write the run as soon as it is complete.
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
5. `string encode(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `string out;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
7. `for (int i = 0; i < (int)s.size();) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < (int)s.size()` is true; after each iteration perform ``.
8. `int j = i+1;`
   Creates `j` and initializes it from `i+1`. This gives the algorithm its starting state.
9. `while (j < (int)s.size() && s[j] == s[i]) ++j;`
   Repeats the following block while `j < (int)s.size() && s[j] == s[i]` is true. Its one-line body is `++j;`.
10. `out += s[i];`
   Updates the stored state using its previous value and the expression on the right.
11. `out += to_string(j-i);`
   Updates the stored state using its previous value and the expression on the right.
12. `i = j;`
   Updates `i` to `j` for the next step of the algorithm.
13. `return out;`
   Ends the function and sends `out` back to the caller.

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
Shared contract trace: For "aaabbcaa", runs are aaa, bb, c, aa. Their encodings a3, b2, c1, a2 concatenate to "a3b2c1a2".
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Every completed run has been emitted once; the next unread index begins a new run.
Advance a run endpoint and write the run as soon as it is complete.

7. COMPLEXITY
Time: O(n). Space: O(n) result; O(1) auxiliary.
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
