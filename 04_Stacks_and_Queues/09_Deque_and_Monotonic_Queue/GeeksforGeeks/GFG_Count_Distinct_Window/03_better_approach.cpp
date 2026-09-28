#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countDistinct(vector<int>& arr, int k) {
        vector<int> out;
        if (k <= 0) return out;
        map<int,int> freq;
        for (int i = 0; i < (int)arr.size(); ++i) {
            ++freq[arr[i]];
            if (i >= k && --freq[arr[i-k]] == 0) freq.erase(arr[i-k]);
            if (i+1 >= k) out.push_back(freq.size());
        }
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Count Distinct Elements in Every Window: Return distinct-value counts for every contiguous length-k window. Invalid k returns an empty result locally.

2. FUNCTION SIGNATURE, PART BY PART
vector<int> countDistinct(vector<int>& arr, int k)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Ordered frequency map.
Add and remove window endpoints and erase keys only when their frequency reaches zero.
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
5. `vector<int> countDistinct(vector<int>& arr, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<int> out;`
   Declares `out` so it can store state used by the algorithm.
7. `if (k <= 0) return out;`
   Runs the next block only when `k <= 0` is true. The one-line action is `return out;`.
8. `map<int,int> freq;`
   Declares `freq` so it can store state used by the algorithm.
9. `for (int i = 0; i < (int)arr.size(); ++i) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < (int)arr.size()` is true; after each iteration perform `++i`.
10. `++freq[arr[i]];`
   Moves the relevant counter or pointer by one position.
11. `if (i >= k && --freq[arr[i-k]] == 0) freq.erase(arr[i-k]);`
   Runs the next block only when `i >= k && --freq[arr[i-k]] == 0` is true. The one-line action is `freq.erase(arr[i-k]);`.
12. `if (i+1 >= k) out.push_back(freq.size());`
   Runs the next block only when `i+1 >= k` is true. The one-line action is `out.push_back(freq.size());`.
13. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- map: Stores key-value pairs in sorted-key order, usually with O(log n) operations.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- erase: Removes an element or position from a container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ++ / --: Increases/decreases a numeric variable by one.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: For [1,2,1,3], k=3, the first queue contains 1,2,1: two distinct values. Evict one 1 and append 3; the remaining 1 still counts, yielding three distinct values.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
The queue stores exactly the active arrivals, while each map count equals its multiplicity in that queue.
Add and remove window endpoints and erase keys only when their frequency reaches zero.

7. COMPLEXITY
Time: O(n log k). Space: O(k) plus output.
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
