#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, length = 0, n = s.size();
        for (int l = 0; l < n; ++l) for (int r = l; r < n; ++r) {
            bool ok = true;
            for (int a = l, b = r; a < b; ++a, --b) if (s[a] != s[b]) ok = false;
            if (ok && r - l + 1 > length) {
                start = l;
                length = r - l + 1;
            }
        }
        return s.substr(start, length);
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Longest Palindrome in String: Return the longest contiguous palindrome, choosing the earliest start on a length tie. Empty input returns an empty string.

2. FUNCTION SIGNATURE, PART BY PART
string longestPalindrome(string s)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Enumerate and check every interval.
Try intervals by increasing start and keep only strictly longer palindromes.
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
5. `string longestPalindrome(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int start = 0, length = 0, n = s.size();`
   Creates `start` and initializes it from `0, length = 0, n = s.size()`. This gives the algorithm its starting state.
7. `for (int l = 0; l < n; ++l) for (int r = l; r < n; ++r) {`
   Starts a loop: first `int l = 0`; keep repeating while `l < n` is true; after each iteration perform `++l`. Its one-line body is `for (int r = l; r < n; ++r) {`.
8. `bool ok = true;`
   Creates `ok` and initializes it from `true`. This gives the algorithm its starting state.
9. `for (int a = l, b = r; a < b; ++a, --b) if (s[a] != s[b]) ok = false;`
   Starts a loop: first `int a = l, b = r`; keep repeating while `a < b` is true; after each iteration perform `++a, --b`. Its one-line body is `if (s[a] != s[b]) ok = false;`.
10. `if (ok && r - l + 1 > length) {`
   Runs the next block only when `ok && r - l + 1 > length` is true.
11. `start = l;`
   Updates `start` to `l` for the next step of the algorithm.
12. `length = r - l + 1;`
   Updates `length` to `r - l + 1` for the next step of the algorithm.
13. `return s.substr(start, length);`
   Ends the function and sends `s.substr(start, length)` back to the caller.

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
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ++ / --: Increases/decreases a numeric variable by one.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: In "cbbd", the gap between the two b characters expands to "bb". Its neighbors c and d differ, so the even radius stops at length 2. Odd centers give length 1.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
A radius describes only matching pairs around one center; the best answer retains the earliest maximum.
Try intervals by increasing start and keep only strictly longer palindromes.

7. COMPLEXITY
Time: O(n³). Space: O(n) result.
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
