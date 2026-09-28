#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> out(n,INT_MIN);
        for (int k = 1; k <= n; ++k) for (int start = 0; start+k <= n; ++start) {
            int value = *min_element(arr.begin()+start,arr.begin()+start+k);
            out[k-1] = max(out[k-1],value);
        }
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Max of Min for Every Window Size: Return n values: result[k-1] is the largest minimum among all contiguous windows of size k. Negative values are supported.

2. FUNCTION SIGNATURE, PART BY PART
vector<int> maxOfMins(vector<int>& arr)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Scan every window for every size.
Enumerate window sizes and starts, then scan each window for its minimum.
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
5. `vector<int> maxOfMins(vector<int>& arr) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = arr.size();`
   Creates `n` and initializes it from `arr.size()`. This gives the algorithm its starting state.
7. `vector<int> out(n,INT_MIN);`
   Declares `out` so it can store state used by the algorithm.
8. `for (int k = 1; k <= n; ++k) for (int start = 0; start+k <= n; ++start) {`
   Starts a loop: first `int k = 1`; keep repeating while `k <= n` is true; after each iteration perform `++k`. Its one-line body is `for (int start = 0; start+k <= n; ++start) {`.
9. `int value = *min_element(arr.begin()+start,arr.begin()+start+k);`
   Creates `value` and initializes it from `*min_element(arr.begin()+start,arr.begin()+start+k)`. This gives the algorithm its starting state.
10. `out[k-1] = max(out[k-1],value);`
   Updates `out[k-1]` to `max(out[k-1],value)` for the next step of the algorithm.
11. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- min / max: Returns the smaller/larger of the supplied values.
- min_element / max_element: Returns an iterator pointing to the smallest/largest element in a range.
- INT_MIN / INT_MAX: The smallest/largest value representable by int.
- ++ / --: Increases/decreases a numeric variable by one.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: For [2,1,3], size-1 minima are 2,1,3 so best=3; size-2 minima are 1,1 so best=1; size-3 minimum is 1. Answer [3,1,1].
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Each value contributes to the largest span in which no strictly smaller value blocks it; shorter answers inherit larger-span candidates.
Enumerate window sizes and starts, then scan each window for its minimum.

7. COMPLEXITY
Time: O(n³). Space: O(n) result.
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
