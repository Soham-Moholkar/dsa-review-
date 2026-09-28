#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countRev(string s) {
        int n = s.size();
        if (n%2) return -1;
        int best = n+1;
        function<void(int,int,int)> visit = [&](int i, int balance, int cost) {
            if (balance < 0 || cost >= best) return;
            if (i == n) {
                if (balance == 0) best = cost;
                return;
            }
            int delta = s[i] == '{' ? 1 : -1;
            visit(i+1,balance+delta,cost);
            visit(i+1,balance-delta,cost+1);
        }
        ;
        visit(0,0,0);
        return best;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Minimum Bracket Reversals to Balance: Input uses only { and }. Reverse one brace per operation. Return minimum reversals, or -1 for odd length.

2. FUNCTION SIGNATURE, PART BY PART
int countRev(string s)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Enumerate orientation choices.
Try keeping or flipping every brace; reject choices with negative prefix balance or nonzero final balance. Use only small teaching cases.
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
5. `int countRev(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = s.size();`
   Creates `n` and initializes it from `s.size()`. This gives the algorithm its starting state.
7. `if (n%2) return -1;`
   Runs the next block only when `n%2` is true. The one-line action is `return -1;`.
8. `int best = n+1;`
   Creates `best` and initializes it from `n+1`. This gives the algorithm its starting state.
9. `function<void(int,int,int)> visit = [&](int i, int balance, int cost) {`
   Creates a callable named `visit`. `[&]` lets it use surrounding local variables by reference, which is needed for the recursive search.
10. `if (balance < 0 || cost >= best) return;`
   Runs the next block only when `balance < 0 || cost >= best` is true. The one-line action is `return;`.
11. `if (i == n) {`
   Runs the next block only when `i == n` is true.
12. `if (balance == 0) best = cost;`
   Runs the next block only when `balance == 0` is true. The one-line action is `best = cost;`.
13. `return;`
   Ends the function.
14. `int delta = s[i] == '{' ? 1 : -1;`
   Creates `delta` and initializes it from `s[i] == '{' ? 1 : -1`. This gives the algorithm its starting state.
15. `visit(i+1,balance+delta,cost);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `visit(i+1,balance-delta,cost+1);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
17. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
18. `visit(0,0,0);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
19. `return best;`
   Ends the function and sends `best` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- function: A standard-library wrapper able to store a callable object such as a recursive lambda.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- lambda ([&]): Creates an unnamed function. [&] captures surrounding local variables by reference, so the lambda can read and modify them.
- recursion: A function calls itself on a smaller remaining choice. It needs a stopping condition to avoid infinite calls.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- ++ / --: Increases/decreases a numeric variable by one.
- %: Remainder operator. a % b gives the remainder after integer division by b.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: For "}}{{", the first closing brace must reverse, the second closes it, and the final two openings need one reversal. Total 2. Odd length can never balance.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
After repairing an unmatched closing brace, the processed prefix is balanced or has spare openings.
Try keeping or flipping every brace; reject choices with negative prefix balance or nonzero final balance. Use only small teaching cases.

7. COMPLEXITY
Time: O(2^n n). Space: O(n) recursion.
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
