#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPangram(string s) {
        set<char> letters;
        for (unsigned char c : s) {
            char lower = tolower(c);
            if (lower >= 'a' && lower <= 'z') letters.insert(lower);
        }
        return letters.size() == 26;
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
Method: Collect letters in a set.
Insert normalized letters into an ordered set and inspect its size.
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
6. `set<char> letters;`
   Declares `letters` so it can store state used by the algorithm.
7. `for (unsigned char c : s) {`
   Starts a range-based loop. `unsigned char c : s` means: take each element from the container in turn and run the block.
8. `char lower = tolower(c);`
   Updates `char lower` to `tolower(c)` for the next step of the algorithm.
9. `if (lower >= 'a' && lower <= 'z') letters.insert(lower);`
   Runs the next block only when `lower >= 'a' && lower <= 'z'` is true. The one-line action is `letters.insert(lower);`.
10. `return letters.size() == 26;`
   Ends the function and sends `letters.size() == 26` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- bool: A type with only two values: true and false.
- set: Stores unique values in sorted order, usually with O(log n) insert and lookup.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- insert: Adds an element to a container. A set ignores a value already present.
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
Shared contract trace: In the alphabet followed by extra a characters, all 26 flags are true; repeats do not change coverage. Removing z leaves exactly one flag false.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Each seen bit means that its letter has appeared at least once.
Insert normalized letters into an ordered set and inspect its size.

7. COMPLEXITY
Time: O(n log 26). Space: O(26).
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
