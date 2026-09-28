#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        if (gas.empty()) return -1;
        long long total = 0, tank = 0;
        int start = 0;
        for (int i = 0; i < (int)gas.size(); ++i) {
            long long delta = (long long)gas[i]-cost[i];
            total += delta;
            tank += delta;
            if (tank < 0) {
                start = i+1;
                tank = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Gas Station (Circular Tour): Equal-length nonempty nonnegative arrays. Start with an empty tank, collect gas[i], and pay cost[i] to reach the next station. Return the first feasible zero-based start, or -1. This adapter uses the modern two-array contract.

2. FUNCTION SIGNATURE, PART BY PART
int startStation(vector<int>& gas, vector<int>& cost)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Eliminate failed candidate segments.
Accumulate a total and a candidate tank; reset the candidate only when its tank turns negative. This optimization no longer needs a queue.
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
5. `int startStation(vector<int>& gas, vector<int>& cost) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `if (gas.empty()) return -1;`
   Runs the next block only when `gas.empty()` is true. The one-line action is `return -1;`.
7. `long long total = 0, tank = 0;`
   Creates `total` and initializes it from `0, tank = 0`. This gives the algorithm its starting state.
8. `int start = 0;`
   Creates `start` and initializes it from `0`. This gives the algorithm its starting state.
9. `for (int i = 0; i < (int)gas.size(); ++i) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < (int)gas.size()` is true; after each iteration perform `++i`.
10. `long long delta = (long long)gas[i]-cost[i];`
   Creates `delta` and initializes it from `(long long)gas[i]-cost[i]`. This gives the algorithm its starting state.
11. `total += delta;`
   Updates the stored state using its previous value and the expression on the right.
12. `tank += delta;`
   Updates the stored state using its previous value and the expression on the right.
13. `if (tank < 0) {`
   Runs the next block only when `tank < 0` is true.
14. `start = i+1;`
   Updates `start` to `i+1` for the next step of the algorithm.
15. `tank = 0;`
   Updates `tank` to `0` for the next step of the algorithm.
16. `return total < 0 ? -1 : start;`
   Ends the function and sends `total < 0 ? -1 : start` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- long long: A wider signed whole-number type, commonly 64 bits; it is used when an int may be too small.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
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
Shared contract trace: For gas=[1,2,3], cost=[2,2,1], start 0 immediately fails. Start 1 has tank 0, then 2, then 1 after wraparound, so it completes the tour.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
When a candidate segment runs out of fuel, every start inside that segment is also ruled out.
Accumulate a total and a candidate tank; reset the candidate only when its tank turns negative. This optimization no longer needs a queue.

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
