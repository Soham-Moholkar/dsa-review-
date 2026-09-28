#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minChar(string s) {
        vector<int> text;
        for (unsigned char c : s) text.push_back(c);
        text.push_back(-1);
        for (auto it = s.rbegin(); it != s.rend(); ++it) text.push_back((unsigned char)*it);
        vector<int> pi(text.size());
        for (int i = 1, j = 0; i < (int)text.size(); ++i) {
            while (j && text[i] != text[j]) j = pi[j-1];
            if (text[i] == text[j]) ++j;
            pi[i] = j;
        }
        return s.size()-pi.back();
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
Method: Prefix function with an out-of-alphabet separator.
Encode bytes as integers and use -1 as the separator so input punctuation cannot collide with it.
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
6. `vector<int> text;`
   Declares `text` so it can store state used by the algorithm.
7. `for (unsigned char c : s) text.push_back(c);`
   Starts a range-based loop. `unsigned char c : s` means: take each element from the container in turn and run the block. Its one-line body is `text.push_back(c);`.
8. `text.push_back(-1);`
   Appends the computed value to the end of the result/container.
9. `for (auto it = s.rbegin(); it != s.rend(); ++it) text.push_back((unsigned char)*it);`
   Starts a loop: first `auto it = s.rbegin()`; keep repeating while `it != s.rend()` is true; after each iteration perform `++it`. Its one-line body is `text.push_back((unsigned char)*it);`.
10. `vector<int> pi(text.size());`
   Declares `pi` so it can store state used by the algorithm.
11. `for (int i = 1, j = 0; i < (int)text.size(); ++i) {`
   Starts a loop: first `int i = 1, j = 0`; keep repeating while `i < (int)text.size()` is true; after each iteration perform `++i`.
12. `while (j && text[i] != text[j]) j = pi[j-1];`
   Repeats the following block while `j && text[i] != text[j]` is true. Its one-line body is `j = pi[j-1];`.
13. `if (text[i] == text[j]) ++j;`
   Runs the next block only when `text[i] == text[j]` is true. The one-line action is `++j;`.
14. `pi[i] = j;`
   Updates `pi[i]` to `j` for the next step of the algorithm.
15. `return s.size()-pi.back();`
   Ends the function and sends `s.size()-pi.back()` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- front / back: Accesses the first or last element of a nonempty container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
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
Shared contract trace: For "aacecaaa", the prefix "aacecaa" is palindromic, length 7. One trailing a lies outside it, so one leading a completes the palindrome.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
The final border length of source + separator + reverse(source) is its longest palindromic prefix length.
Encode bytes as integers and use -1 as the separator so input punctuation cannot collide with it.

7. COMPLEXITY
Time: O(n). Space: O(n).
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
