#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minChar(string s) {
        int n = s.size();
        for (int length = n; length >= 0; --length) {
            bool ok = true;
            for (int l = 0, r = length-1; l < r; ++l, --r) if (s[l] != s[r]) {
                ok = false;
                break;
            }
            if (ok) return n-length;
        }
        return n;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Minimum Characters to Add for Palindrome: Only additions at the FRONT are permitted. Return their minimum count; empty input returns zero.

2. FUNCTION SIGNATURE, PART BY PART
int minChar(string s)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Same low-memory baseline; no artificial intermediate.
This preserves the useful constant-space alternative before introducing the prefix table.
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
5. `int minChar(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = s.size();`
   Creates `n` and initializes it from `s.size()`. This gives the algorithm its starting state.
7. `for (int length = n; length >= 0; --length) {`
   Starts a loop: first `int length = n`; keep repeating while `length >= 0` is true; after each iteration perform `--length`.
8. `bool ok = true;`
   Creates `ok` and initializes it from `true`. This gives the algorithm its starting state.
9. `for (int l = 0, r = length-1; l < r; ++l, --r) if (s[l] != s[r]) {`
   Starts a loop: first `int l = 0, r = length-1`; keep repeating while `l < r` is true; after each iteration perform `++l, --r`. Its one-line body is `if (s[l] != s[r]) {`.
10. `ok = false;`
   Updates `ok` to `false` for the next step of the algorithm.
11. `break;`
   Stops the nearest loop immediately because no more iterations are needed.
12. `if (ok) return n-length;`
   Runs the next block only when `ok` is true. The one-line action is `return n-length;`.
13. `return n;`
   Ends the function and sends `n` back to the caller.

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

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: For "aacecaaa", the prefix "aacecaa" is palindromic, length 7. One trailing a lies outside it, so one leading a completes the palindrome.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
The final border length of source + separator + reverse(source) is its longest palindromic prefix length.
This preserves the useful constant-space alternative before introducing the prefix table.

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
