#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, length = 0, n = s.size();
        for (int center = 0; center < n; ++center) for (int even = 0; even < 2; ++even) {
            int l = center, r = center + even;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int size = r - l + 1;
                if (size > length || (size == length && l < start)) {
                    start = l;
                    length = size;
                }
                --l;
                ++r;
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
Method: Expand odd and even centers.
Every palindrome has a character center or a gap center; expand each while pairs match.
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
7. `for (int center = 0; center < n; ++center) for (int even = 0; even < 2; ++even) {`
   Starts a loop: first `int center = 0`; keep repeating while `center < n` is true; after each iteration perform `++center`. Its one-line body is `for (int even = 0; even < 2; ++even) {`.
8. `int l = center, r = center + even;`
   Creates `l` and initializes it from `center, r = center + even`. This gives the algorithm its starting state.
9. `while (l >= 0 && r < n && s[l] == s[r]) {`
   Repeats the following block while `l >= 0 && r < n && s[l] == s[r]` is true.
10. `int size = r - l + 1;`
   Creates `size` and initializes it from `r - l + 1`. This gives the algorithm its starting state.
11. `if (size > length || (size == length && l < start)) {`
   Runs the next block only when `size > length || (size == length && l < start)` is true.
12. `start = l;`
   Updates `start` to `l` for the next step of the algorithm.
13. `length = size;`
   Updates `length` to `size` for the next step of the algorithm.
14. `--l;`
   Moves the relevant counter or pointer by one position.
15. `++r;`
   Moves the relevant counter or pointer by one position.
16. `return s.substr(start, length);`
   Ends the function and sends `s.substr(start, length)` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
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
Every palindrome has a character center or a gap center; expand each while pairs match.

7. COMPLEXITY
Time: O(n²). Space: O(1) auxiliary plus result.
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
