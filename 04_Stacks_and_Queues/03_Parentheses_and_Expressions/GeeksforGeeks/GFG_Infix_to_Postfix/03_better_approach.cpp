#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string infixToPostfix(string s) {
        auto precedence = [](char c) {
            return c == '^' ? 3 : (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : 0;
        }
        ;
        string out;
        stack<char> operators;
        for (unsigned char c : s) {
            if (isalnum(c)) out += char(c);
            else if (c == '(') operators.push(c);
            else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    out += operators.top();
                    operators.pop();
                }
                operators.pop();
            }
            else {
                while (!operators.empty() && operators.top() != '(' &&
                (precedence(operators.top()) > precedence(c) ||
                (precedence(operators.top()) == precedence(c) && c != '^'))) {
                    out += operators.top();
                    operators.pop();
                }
                operators.push(c);
            }
        }
        while (!operators.empty()) {
            out += operators.top();
            operators.pop();
        }
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Infix to Postfix: Valid expressions with single alphanumeric operands and binary + - * / ^, with optional parentheses and no spaces. ^ is right-associative; the other operators are left-associative.

2. FUNCTION SIGNATURE, PART BY PART
string infixToPostfix(string s)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Operator-stack conversion.
Drain only stronger operators, or equal operators when the incoming operator associates left. Parentheses limit draining.
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
5. `string infixToPostfix(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `auto precedence = [](char c) {`
   Creates `precedence` and initializes it from `[](char c) {`. This gives the algorithm its starting state.
7. `return c == '^' ? 3 : (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : 0;`
   Ends the function and sends `c == '^' ? 3 : (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : 0` back to the caller.
8. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `string out;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `stack<char> operators;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `for (unsigned char c : s) {`
   Starts a range-based loop. `unsigned char c : s` means: take each element from the container in turn and run the block.
12. `if (isalnum(c)) out += char(c);`
   Runs the next block only when `isalnum(c)` is true. The one-line action is `out += char(c);`.
13. `else if (c == '(') operators.push(c);`
   If earlier branches failed, runs this block when `c == '(') operators.push(c);` is true.
14. `else if (c == ')') {`
   If earlier branches failed, runs this block when `c == '` is true. The one-line action is `') {`.
15. `while (!operators.empty() && operators.top() != '(') {`
   Repeats the following block while `!operators.empty() && operators.top() != '(') {` is true.
16. `out += operators.top();`
   Updates the stored state using its previous value and the expression on the right.
17. `operators.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
18. `operators.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
19. `else {`
   Handles the remaining case after the preceding condition(s) were false.
20. `while (!operators.empty() && operators.top() != '(' &&`
   Repeats the following block while `!operators.empty() && operators.top() != '(' &&` is true.
21. `(precedence(operators.top()) > precedence(c) ||`
   Performs this operation to maintain the state described in the algorithm walkthrough.
22. `(precedence(operators.top()) == precedence(c) && c != '^'))) {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
23. `out += operators.top();`
   Updates the stored state using its previous value and the expression on the right.
24. `operators.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
25. `operators.push(c);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
26. `while (!operators.empty()) {`
   Repeats the following block while `!operators.empty()` is true.
27. `out += operators.top();`
   Updates the stored state using its previous value and the expression on the right.
28. `operators.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
29. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- raw array ([]): In a function parameter, this is passed as a pointer to the first element; the separate length tells the code how many elements are valid.
- empty: Returns true when a container has no elements.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.
- ^: Bitwise XOR. Equal bits cancel; x ^ x is 0 and x ^ 0 is x.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: For a^b^c, the second ^ stays above the first. Draining produces abc^^, which means a^(b^c). For a-b-c, the first - is emitted before pushing the second, producing ab-c-.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Output operands are already in evaluation order; pending operators wait until their right operand is complete.
Drain only stronger operators, or equal operators when the incoming operator associates left. Parentheses limit draining.

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
