#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generate(int n) {
        vector<string> out;
        if (n <= 0) return out;
        queue<string> pending;
        pending.push("1");
        while ((int)out.size() < n) {
            string current = pending.front();
            pending.pop();
            out.push_back(current);
            if ((int)out.size() < n) {
                pending.push(current+'0');
                pending.push(current+'1');
            }
        }
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Generate Binary Numbers: Return binary representations of decimal integers 1 through n. Zero returns an empty vector locally.

2. FUNCTION SIGNATURE, PART BY PART
vector<string> generate(int n)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: FIFO state expansion.
Pop a prefix and enqueue its two extensions. Avoid generating children after the final output. This is the queue-focused method, not an asymptotic improvement over conversion.
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
5. `vector<string> generate(int n) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<string> out;`
   Declares `out` so it can store state used by the algorithm.
7. `if (n <= 0) return out;`
   Runs the next block only when `n <= 0` is true. The one-line action is `return out;`.
8. `queue<string> pending;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `pending.push("1");`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `while ((int)out.size() < n) {`
   Repeats the following block while `(int)out.size() < n` is true.
11. `string current = pending.front();`
   Updates `string current` to `pending.front()` for the next step of the algorithm.
12. `pending.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `out.push_back(current);`
   Appends the computed value to the end of the result/container.
14. `if ((int)out.size() < n) {`
   Runs the next block only when `(int)out.size() < n` is true.
15. `pending.push(current+'0');`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `pending.push(current+'1');`
   Performs this operation to maintain the state described in the algorithm walkthrough.
17. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- front / back: Accesses the first or last element of a nonempty container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ++ / --: Increases/decreases a numeric variable by one.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: Starting with queue [1], emit 1 and enqueue 10,11. Emit 10 and enqueue 100,101. The first four outputs are 1,10,11,100.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
The queue removes shorter binary strings before longer ones, and 0-children before 1-children.
Pop a prefix and enqueue its two extensions. Avoid generating children after the final output. This is the queue-focused method, not an asymptotic improvement over conversion.

7. COMPLEXITY
Time: O(T). Space: O(T) queue and output.
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
