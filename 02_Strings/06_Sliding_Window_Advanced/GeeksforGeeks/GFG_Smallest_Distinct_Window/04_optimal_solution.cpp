#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSubString(string s) {
        if (s.empty()) return 0;
        bool seen[256] = {
        }
        ;
        int required = 0;
        for (unsigned char c : s) if (!seen[c]) {
            seen[c] = true;
            ++required;
        }
        int freq[256] = {
        }
        , have = 0, left = 0, best = s.size();
        for (int right = 0; right < (int)s.size(); ++right) {
            if (freq[(unsigned char)s[right]]++ == 0) ++have;
            while (have == required) {
                best = min(best, right-left+1);
                if (--freq[(unsigned char)s[left++]] == 0) --have;
            }
        }
        return best;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Smallest Distinct Window: Return the shortest substring length containing every distinct byte present in s. Empty input returns zero.

2. FUNCTION SIGNATURE, PART BY PART
int findSubString(string s)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Shrink complete windows.
Count required letters, then shrink each complete window while recording lengths.
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
5. `int findSubString(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `if (s.empty()) return 0;`
   Runs the next block only when `s.empty()` is true. The one-line action is `return 0;`.
7. `bool seen[256] = {`
   Creates `the variable` and initializes it from `{`. This gives the algorithm its starting state.
8. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `int required = 0;`
   Creates `required` and initializes it from `0`. This gives the algorithm its starting state.
10. `for (unsigned char c : s) if (!seen[c]) {`
   Starts a range-based loop. `unsigned char c : s` means: take each element from the container in turn and run the block. Its one-line body is `if (!seen[c]) {`.
11. `seen[c] = true;`
   Updates `seen[c]` to `true` for the next step of the algorithm.
12. `++required;`
   Moves the relevant counter or pointer by one position.
13. `int freq[256] = {`
   Creates `the variable` and initializes it from `{`. This gives the algorithm its starting state.
14. `, have = 0, left = 0, best = s.size();`
   Updates `, have` to `0, left = 0, best = s.size()` for the next step of the algorithm.
15. `for (int right = 0; right < (int)s.size(); ++right) {`
   Starts a loop: first `int right = 0`; keep repeating while `right < (int)s.size()` is true; after each iteration perform `++right`.
16. `if (freq[(unsigned char)s[right]]++ == 0) ++have;`
   Runs the next block only when `freq[(unsigned char)s[right]]++ == 0` is true. The one-line action is `++have;`.
17. `while (have == required) {`
   Repeats the following block while `have == required` is true.
18. `best = min(best, right-left+1);`
   Updates `best` to `min(best, right-left+1)` for the next step of the algorithm.
19. `if (--freq[(unsigned char)s[left++]] == 0) --have;`
   Runs the next block only when `--freq[(unsigned char)s[left++]] == 0` is true. The one-line action is `--have;`.
20. `return best;`
   Ends the function and sends `best` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- min / max: Returns the smaller/larger of the supplied values.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
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
Shared contract trace: For "aabcbcdbca", four letters are required. The suffix "dbca" contains all four in length 4; no length-3 window can contain four distinct letters.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
A window is complete exactly when its distinct count equals the whole-string distinct count.
Count required letters, then shrink each complete window while recording lengths.

7. COMPLEXITY
Time: O(n). Space: O(256).
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
