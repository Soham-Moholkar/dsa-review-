#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPangram(string s) {
        bool seen[26] = {
        }
        ;
        for (unsigned char c : s) {
            char lower = tolower(c);
            if (lower >= 'a' && lower <= 'z') seen[lower - 'a'] = true;
        }
        for (bool present : seen) if (!present) return false;
        return true;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Pangram Checking: Check whether all 26 English letters occur, ignoring ASCII case and nonletters.

2. FUNCTION SIGNATURE, PART BY PART
bool checkPangram(string s)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Fixed presence table.
A fixed alphabet needs only 26 flags; duplicate letters leave flags unchanged.
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
5. `bool checkPangram(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `bool seen[26] = {`
   Creates `the variable` and initializes it from `{`. This gives the algorithm its starting state.
7. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
8. `for (unsigned char c : s) {`
   Starts a range-based loop. `unsigned char c : s` means: take each element from the container in turn and run the block.
9. `char lower = tolower(c);`
   Updates `char lower` to `tolower(c)` for the next step of the algorithm.
10. `if (lower >= 'a' && lower <= 'z') seen[lower - 'a'] = true;`
   Runs the next block only when `lower >= 'a' && lower <= 'z'` is true. The one-line action is `seen[lower - 'a'] = true;`.
11. `for (bool present : seen) if (!present) return false;`
   Starts a range-based loop. `bool present : seen` means: take each element from the container in turn and run the block. Its one-line body is `if (!present) return false;`.
12. `return true;`
   Ends the function and sends `true` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
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
Shared contract trace: In the alphabet followed by extra a characters, all 26 flags are true; repeats do not change coverage. Removing z leaves exactly one flag false.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Each seen bit means that its letter has appeared at least once.
A fixed alphabet needs only 26 flags; duplicate letters leave flags unchanged.

7. COMPLEXITY
Time: O(n). Space: O(26) = O(1).
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
