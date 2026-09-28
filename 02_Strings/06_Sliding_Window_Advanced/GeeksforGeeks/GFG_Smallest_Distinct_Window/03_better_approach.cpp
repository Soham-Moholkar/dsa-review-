#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSubString(string s) {
        set<char> required(s.begin(), s.end());
        int best = s.size();
        for (int l = 0; l < (int)s.size(); ++l) {
            set<char> current;
            for (int r = l; r < (int)s.size(); ++r) {
                current.insert(s[r]);
                if (current.size() == required.size()) {
                    best = min(best, r-l+1);
                    break;
                }
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
Method: Extend from every start.
For each left endpoint, stop at its first complete window.
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
6. `set<char> required(s.begin(), s.end());`
   Declares `required` so it can store state used by the algorithm.
7. `int best = s.size();`
   Creates `best` and initializes it from `s.size()`. This gives the algorithm its starting state.
8. `for (int l = 0; l < (int)s.size(); ++l) {`
   Starts a loop: first `int l = 0`; keep repeating while `l < (int)s.size()` is true; after each iteration perform `++l`.
9. `set<char> current;`
   Declares `current` so it can store state used by the algorithm.
10. `for (int r = l; r < (int)s.size(); ++r) {`
   Starts a loop: first `int r = l`; keep repeating while `r < (int)s.size()` is true; after each iteration perform `++r`.
11. `current.insert(s[r]);`
   Stores this value in the set/map so later iterations can find it.
12. `if (current.size() == required.size()) {`
   Runs the next block only when `current.size() == required.size()` is true.
13. `best = min(best, r-l+1);`
   Updates `best` to `min(best, r-l+1)` for the next step of the algorithm.
14. `break;`
   Stops the nearest loop immediately because no more iterations are needed.
15. `return best;`
   Ends the function and sends `best` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- set: Stores unique values in sorted order, usually with O(log n) insert and lookup.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- break: Immediately exits the nearest loop.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- insert: Adds an element to a container. A set ignores a value already present.
- min / max: Returns the smaller/larger of the supplied values.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
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
For each left endpoint, stop at its first complete window.

7. COMPLEXITY
Time: O(n²). Space: O(256).
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
