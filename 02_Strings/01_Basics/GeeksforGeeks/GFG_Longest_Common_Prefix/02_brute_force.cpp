#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        if (arr.empty()) return "";
        for (int len = arr[0].size(); len >= 0; --len) {
            string candidate = arr[0].substr(0, len);
            bool ok = true;
            for (const string& s : arr) if (s.compare(0, len, candidate) != 0) ok = false;
            if (ok) return candidate;
        }
        return "";
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Longest Common Prefix of Strings: Return the common prefix; return an empty string when none exists. Some older drivers display -1 for an empty result.

2. FUNCTION SIGNATURE, PART BY PART
string longestCommonPrefix(vector<string>& arr)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Shorten candidate prefixes.
Try shorter copies of the first string until each other string starts with it.
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
5. `string longestCommonPrefix(vector<string>& arr) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `if (arr.empty()) return "";`
   Runs the next block only when `arr.empty()` is true. The one-line action is `return "";`.
7. `for (int len = arr[0].size(); len >= 0; --len) {`
   Starts a loop: first `int len = arr[0].size()`; keep repeating while `len >= 0` is true; after each iteration perform `--len`.
8. `string candidate = arr[0].substr(0, len);`
   Updates `string candidate` to `arr[0].substr(0, len)` for the next step of the algorithm.
9. `bool ok = true;`
   Creates `ok` and initializes it from `true`. This gives the algorithm its starting state.
10. `for (const string& s : arr) if (s.compare(0, len, candidate) != 0) ok = false;`
   Starts a range-based loop. `const string& s : arr` means: take each element from the container in turn and run the block. Its one-line body is `if (s.compare(0, len, candidate) != 0) ok = false;`.
11. `if (ok) return candidate;`
   Runs the next block only when `ok` is true. The one-line action is `return candidate;`.
12. `return "";`
   Ends the function and sends `""` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- const: Promises that the named value will not be changed through that declaration.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- ++ / --: Increases/decreases a numeric variable by one.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: For ["flower","flow","flight"], columns f and l match. Column 2 contains o, o, i, so the answer is "fl".
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Every accepted prefix position agrees across all strings.
Try shorter copies of the first string until each other string starts with it.

7. COMPLEXITY
Time: O(w L²). Space: O(L).
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
