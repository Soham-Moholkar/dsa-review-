#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSum(string s) {
        int answer = 0, current = 0;
        for (char c : s) {
            if (c >= '0' && c <= '9') current = 10 * current + c - '0';
            else {
                answer += current;
                current = 0;
            }
        }
        return answer + current;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Sum Numbers in a String: Alphanumeric input. Sum maximal decimal digit runs; the platform bounds the sum at 100000. No sign syntax is used.

2. FUNCTION SIGNATURE, PART BY PART
int findSum(string s)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Same constant-state parser; no distinct third algorithm.
The streaming parser already inspects each character once with constant state.
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
5. `int findSum(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int answer = 0, current = 0;`
   Creates `answer` and initializes it from `0, current = 0`. This gives the algorithm its starting state.
7. `for (char c : s) {`
   Starts a range-based loop. `char c : s` means: take each element from the container in turn and run the block.
8. `if (c >= '0' && c <= '9') current = 10 * current + c - '0';`
   Runs the next block only when `c >= '0' && c <= '9'` is true. The one-line action is `current = 10 * current + c - '0';`.
9. `else {`
   Handles the remaining case after the preceding condition(s) were false.
10. `answer += current;`
   Updates the stored state using its previous value and the expression on the right.
11. `current = 0;`
   Updates `current` to `0` for the next step of the algorithm.
12. `return answer + current;`
   Ends the function and sends `answer + current` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
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
Shared contract trace: For "12a003b4", reading a commits 12, b commits 3, and the final flush commits 4. Total 19.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Answer contains completed runs; current contains only the unfinished decimal run.
The streaming parser already inspects each character once with constant state.

7. COMPLEXITY
Time: O(n). Space: O(1).
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
