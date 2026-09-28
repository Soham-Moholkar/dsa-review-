#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string uncommonChars(string s1, string s2) {
        bool x[26] = {
        }
        , y[26] = {
        }
        ;
        for (char c : s1) x[c - 'a'] = true;
        for (char c : s2) y[c - 'a'] = true;
        string out;
        for (int i = 0; i < 26; ++i) if (x[i] != y[i]) out += char('a' + i);
        return out.empty() ? "-1" : out;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Uncommon Characters: Lowercase English input. Return sorted characters present in exactly one string, or "-1" when there are none.

2. FUNCTION SIGNATURE, PART BY PART
string uncommonChars(string s1, string s2)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Two presence tables.
Scan both strings once and emit differing flags in alphabet order.
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
5. `string uncommonChars(string s1, string s2) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `bool x[26] = {`
   Creates `the variable` and initializes it from `{`. This gives the algorithm its starting state.
7. `, y[26] = {`
   Updates `, y[26]` to `{` for the next step of the algorithm.
8. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `for (char c : s1) x[c - 'a'] = true;`
   Starts a range-based loop. `char c : s1` means: take each element from the container in turn and run the block. Its one-line body is `x[c - 'a'] = true;`.
10. `for (char c : s2) y[c - 'a'] = true;`
   Starts a range-based loop. `char c : s2` means: take each element from the container in turn and run the block. Its one-line body is `y[c - 'a'] = true;`.
11. `string out;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
12. `for (int i = 0; i < 26; ++i) if (x[i] != y[i]) out += char('a' + i);`
   Starts a loop: first `int i = 0`; keep repeating while `i < 26` is true; after each iteration perform `++i`. Its one-line body is `if (x[i] != y[i]) out += char('a' + i);`.
13. `return out.empty() ? "-1" : out;`
   Ends the function and sends `out.empty() ? "-1" : out` back to the caller.

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
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- empty: Returns true when a container has no elements.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: For "abca" and "bcd", a belongs only to the first and d only to the second. b and c belong to both. Emit "ad" once each.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
A character is output exactly when its two membership flags differ.
Scan both strings once and emit differing flags in alphabet order.

7. COMPLEXITY
Time: O(n+m+26). Space: O(26).
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
