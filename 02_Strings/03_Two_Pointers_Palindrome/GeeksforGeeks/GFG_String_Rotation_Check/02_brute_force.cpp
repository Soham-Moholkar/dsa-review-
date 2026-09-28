#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areRotations(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        if (n == 0) return true;
        for (int start = 0; start < n; ++start) {
            bool ok = true;
            for (int j = 0; j < n; ++j) if (s1[(start + j) % n] != s2[j]) {
                ok = false;
                break;
            }
            if (ok) return true;
        }
        return false;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
String Rotation Check: Equal-length strings are rotations when one cyclic shift matches the other. Two empty strings return true locally.

2. FUNCTION SIGNATURE, PART BY PART
bool areRotations(string s1, string s2)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Compare every cyclic shift.
Try every start position and compare characters with wraparound.
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
5. `bool areRotations(string s1, string s2) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `if (s1.size() != s2.size()) return false;`
   Runs the next block only when `s1.size() != s2.size()` is true. The one-line action is `return false;`.
7. `int n = s1.size();`
   Creates `n` and initializes it from `s1.size()`. This gives the algorithm its starting state.
8. `if (n == 0) return true;`
   Runs the next block only when `n == 0` is true. The one-line action is `return true;`.
9. `for (int start = 0; start < n; ++start) {`
   Starts a loop: first `int start = 0`; keep repeating while `start < n` is true; after each iteration perform `++start`.
10. `bool ok = true;`
   Creates `ok` and initializes it from `true`. This gives the algorithm its starting state.
11. `for (int j = 0; j < n; ++j) if (s1[(start + j) % n] != s2[j]) {`
   Starts a loop: first `int j = 0`; keep repeating while `j < n` is true; after each iteration perform `++j`. Its one-line body is `if (s1[(start + j) % n] != s2[j]) {`.
12. `ok = false;`
   Updates `ok` to `false` for the next step of the algorithm.
13. `break;`
   Stops the nearest loop immediately because no more iterations are needed.
14. `if (ok) return true;`
   Runs the next block only when `ok` is true. The one-line action is `return true;`.
15. `return false;`
   Ends the function and sends `false` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- break: Immediately exits the nearest loop.
- size: Returns the number of elements in a container.
- ++ / --: Increases/decreases a numeric variable by one.
- %: Remainder operator. a % b gives the remainder after integer division by b.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: For "abcd" and "cdab", the doubled source is "abcdabcd". Matching from position 2 consumes c,d,a,b; unequal lengths are rejected first.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
A length-n rotation is a length-n substring of the doubled source.
Try every start position and compare characters with wraparound.

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
