#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string encode(string s) {
        vector<pair<char,int>> runs;
        for (char c : s) {
            if (runs.empty() || runs.back().first != c) runs.push_back({
                c,1
            }
            );
            else ++runs.back().second;
        }
        string out;
        for (auto [c, count] : runs) {
            out += c;
            out += to_string(count);
        }
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Run Length Encoding: Encode every consecutive character run as character followed by its decimal count, including count 1. This study adapter uses Solution::encode.

2. FUNCTION SIGNATURE, PART BY PART
string encode(string s)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Store runs before formatting.
Collect character/count pairs first, then serialize them into an output string.
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
5. `string encode(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<pair<char,int>> runs;`
   Declares `runs` so it can store state used by the algorithm.
7. `for (char c : s) {`
   Starts a range-based loop. `char c : s` means: take each element from the container in turn and run the block.
8. `if (runs.empty() || runs.back().first != c) runs.push_back({`
   Runs the next block only when `runs.empty() || runs.back().first != c` is true. The one-line action is `runs.push_back({`.
9. `c,1`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `else ++runs.back().second;`
   Handles the remaining case after the preceding condition(s) were false.
12. `string out;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `for (auto [c, count] : runs) {`
   Starts a range-based loop. `auto [c, count] : runs` means: take each element from the container in turn and run the block.
14. `out += c;`
   Updates the stored state using its previous value and the expression on the right.
15. `out += to_string(count);`
   Updates the stored state using its previous value and the expression on the right.
16. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- pair: Stores two values together. first names the first value and second names the second value.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- empty: Returns true when a container has no elements.
- push_back: Adds one element to the end of a vector or deque.
- front / back: Accesses the first or last element of a nonempty container.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
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
Shared contract trace: For "aaabbcaa", runs are aaa, bb, c, aa. Their encodings a3, b2, c1, a2 concatenate to "a3b2c1a2".
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Every completed run has been emitted once; the next unread index begins a new run.
Collect character/count pairs first, then serialize them into an output string.

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
