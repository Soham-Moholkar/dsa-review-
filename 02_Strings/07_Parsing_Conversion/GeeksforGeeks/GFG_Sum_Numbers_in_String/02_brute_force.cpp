#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSum(string s) {
        vector<string> runs;
        string current;
        for (char c : s) {
            if (c >= '0' && c <= '9') current += c;
            else if (!current.empty()) {
                runs.push_back(current);
                current.clear();
            }
        }
        if (!current.empty()) runs.push_back(current);
        int answer = 0;
        for (const string& run : runs) {
            int value = 0;
            for (char c : run) value = value*10+c-'0';
            answer += value;
        }
        return answer;
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
Method: Collect and parse digit-run strings.
Store completed runs, then convert and sum them. Leading zeros are discarded during conversion.
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
6. `vector<string> runs;`
   Declares `runs` so it can store state used by the algorithm.
7. `string current;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
8. `for (char c : s) {`
   Starts a range-based loop. `char c : s` means: take each element from the container in turn and run the block.
9. `if (c >= '0' && c <= '9') current += c;`
   Runs the next block only when `c >= '0' && c <= '9'` is true. The one-line action is `current += c;`.
10. `else if (!current.empty()) {`
   If earlier branches failed, runs this block when `!current.empty()` is true.
11. `runs.push_back(current);`
   Appends the computed value to the end of the result/container.
12. `current.clear();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `if (!current.empty()) runs.push_back(current);`
   Runs the next block only when `!current.empty()` is true. The one-line action is `runs.push_back(current);`.
14. `int answer = 0;`
   Creates `answer` and initializes it from `0`. This gives the algorithm its starting state.
15. `for (const string& run : runs) {`
   Starts a range-based loop. `const string& run : runs` means: take each element from the container in turn and run the block.
16. `int value = 0;`
   Creates `value` and initializes it from `0`. This gives the algorithm its starting state.
17. `for (char c : run) value = value*10+c-'0';`
   Starts a range-based loop. `char c : run` means: take each element from the container in turn and run the block. Its one-line body is `value = value*10+c-'0';`.
18. `answer += value;`
   Updates the stored state using its previous value and the expression on the right.
19. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- const: Promises that the named value will not be changed through that declaration.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- empty: Returns true when a container has no elements.
- push_back: Adds one element to the end of a vector or deque.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- !: Logical NOT; reverses true and false.
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
Store completed runs, then convert and sum them. Leading zeros are discarded during conversion.

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
