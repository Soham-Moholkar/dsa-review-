#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countRev(string s) {
        if (s.size()%2) return -1;
        int balance = 0, flips = 0;
        for (char c : s) {
            if (c == '{') ++balance;
            else if (balance > 0) --balance;
            else {
                ++flips;
                ++balance;
            }
        }
        return flips + balance/2;
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
Method: Repair balance while scanning.
A closing brace with zero balance is forced to reverse. After scanning, reverse half of the remaining openings.
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
6. `if (s.size()%2) return -1;`
   Runs the next block only when `s.size()%2` is true. The one-line action is `return -1;`.
7. `int balance = 0, flips = 0;`
   Creates `balance` and initializes it from `0, flips = 0`. This gives the algorithm its starting state.
8. `for (char c : s) {`
   Starts a range-based loop. `char c : s` means: take each element from the container in turn and run the block.
9. `if (c == '{') ++balance;`
   Runs the next block only when `c == '{'` is true. The one-line action is `++balance;`.
10. `else if (balance > 0) --balance;`
   If earlier branches failed, runs this block when `balance > 0` is true. The one-line action is `--balance;`.
11. `else {`
   Handles the remaining case after the preceding condition(s) were false.
12. `++flips;`
   Moves the relevant counter or pointer by one position.
13. `++balance;`
   Moves the relevant counter or pointer by one position.
14. `return flips + balance/2;`
   Ends the function and sends `flips + balance/2` back to the caller.

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
- size: Returns the number of elements in a container.
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
A closing brace with zero balance is forced to reverse. After scanning, reverse half of the remaining openings.

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
