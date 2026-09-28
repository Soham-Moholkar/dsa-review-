#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string infixToPostfix(string s) {
        auto prec = [](char c) {
            return c == '^' ? 3 : (c == '*' || c == '/') ? 2 : 1;
        }
        ;
        function<string(int,int)> convert = [&](int l, int r) -> string {
            if (l == r) return string(1,s[l]);
            int depth = 0, split = -1, best = 4;
            for (int i = l; i <= r; ++i) {
                char c = s[i];
                if (c == '(') ++depth;
                else if (c == ')') --depth;
                else if (depth == 0 && !isalnum((unsigned char)c)) {
                    int p = prec(c);
                    if (p < best || (p == best && c != '^')) {
                        best = p;
                        split = i;
                    }
                }
            }
            if (split == -1) return convert(l+1,r-1);
            return convert(l,split-1) + convert(split+1,r) + s[split];
        }
        ;
        return convert(0,(int)s.size()-1);
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
Method: Recursive expression splitting.
At depth zero, split at the lowest-precedence operator. Choose the rightmost equal-precedence operator for left associativity, but the leftmost ^ for right associativity. Strip an enclosing pair only when it wraps the entire interval.
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
6. `auto prec = [](char c) {`
   Creates `prec` and initializes it from `[](char c) {`. This gives the algorithm its starting state.
7. `return c == '^' ? 3 : (c == '*' || c == '/') ? 2 : 1;`
   Ends the function and sends `c == '^' ? 3 : (c == '*' || c == '/') ? 2 : 1` back to the caller.
8. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `function<string(int,int)> convert = [&](int l, int r) -> string {`
   Creates a callable named `convert`. `[&]` lets it use surrounding local variables by reference, which is needed for the recursive search.
10. `if (l == r) return string(1,s[l]);`
   Runs the next block only when `l == r` is true. The one-line action is `return string(1,s[l]);`.
11. `int depth = 0, split = -1, best = 4;`
   Creates `depth` and initializes it from `0, split = -1, best = 4`. This gives the algorithm its starting state.
12. `for (int i = l; i <= r; ++i) {`
   Starts a loop: first `int i = l`; keep repeating while `i <= r` is true; after each iteration perform `++i`.
13. `char c = s[i];`
   Updates `char c` to `s[i]` for the next step of the algorithm.
14. `if (c == '(') ++depth;`
   Runs the next block only when `c == '(') ++depth;` is true.
15. `else if (c == ')') --depth;`
   If earlier branches failed, runs this block when `c == '` is true. The one-line action is `') --depth;`.
16. `else if (depth == 0 && !isalnum((unsigned char)c)) {`
   If earlier branches failed, runs this block when `depth == 0 && !isalnum((unsigned char)c)` is true.
17. `int p = prec(c);`
   Creates `p` and initializes it from `prec(c)`. This gives the algorithm its starting state.
18. `if (p < best || (p == best && c != '^')) {`
   Runs the next block only when `p < best || (p == best && c != '^')` is true.
19. `best = p;`
   Updates `best` to `p` for the next step of the algorithm.
20. `split = i;`
   Updates `split` to `i` for the next step of the algorithm.
21. `if (split == -1) return convert(l+1,r-1);`
   Runs the next block only when `split == -1` is true. The one-line action is `return convert(l+1,r-1);`.
22. `return convert(l,split-1) + convert(split+1,r) + s[split];`
   Ends the function and sends `convert(l,split-1) + convert(split+1,r) + s[split]` back to the caller.
23. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
24. `return convert(0,(int)s.size()-1);`
   Ends the function and sends `convert(0,(int)s.size()-1)` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- function: A standard-library wrapper able to store a callable object such as a recursive lambda.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- raw array ([]): In a function parameter, this is passed as a pointer to the first element; the separate length tells the code how many elements are valid.
- size: Returns the number of elements in a container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- lambda ([&]): Creates an unnamed function. [&] captures surrounding local variables by reference, so the lambda can read and modify them.
- recursion: A function calls itself on a smaller remaining choice. It needs a stopping condition to avoid infinite calls.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.
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
At depth zero, split at the lowest-precedence operator. Choose the rightmost equal-precedence operator for left associativity, but the leftmost ^ for right associativity. Strip an enclosing pair only when it wraps the entire interval.

7. COMPLEXITY
Time: O(n²). Space: O(n²) conservative copied-output bound.
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
