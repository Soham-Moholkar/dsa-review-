#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeSpaces(string s) {
        for (size_t i = 0; i < s.size();) {
            if (s[i] == ' ') s.erase(i, 1);
            else ++i;
        }
        return s;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Remove Spaces: Remove literal ASCII spaces; preserve every other character in order. Empty input is a local extension.

2. FUNCTION SIGNATURE, PART BY PART
string removeSpaces(string s)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Erase each space.
Erasing shifts the remaining suffix; keep the same index after an erase.
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
5. `string removeSpaces(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `for (size_t i = 0; i < s.size();) {`
   Starts a loop: first `size_t i = 0`; keep repeating while `i < s.size()` is true; after each iteration perform ``.
7. `if (s[i] == ' ') s.erase(i, 1);`
   Runs the next block only when `s[i] == ' '` is true. The one-line action is `s.erase(i, 1);`.
8. `else ++i;`
   Handles the remaining case after the preceding condition(s) were false.
9. `return s;`
   Ends the function and sends `s` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- erase: Removes an element or position from a container.
- ++ / --: Increases/decreases a numeric variable by one.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: For "a b c", the read positions 0, 2, 4 contribute a, b, c. The write position advances only three times; resizing produces "abc".
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
The written prefix contains exactly the non-space characters already read.
Erasing shifts the remaining suffix; keep the same index after an erase.

7. COMPLEXITY
Time: O(n²). Space: O(1) auxiliary.
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
