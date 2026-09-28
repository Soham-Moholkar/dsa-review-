#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (int value : arr) ++freq[value];
        vector<int> out(arr.size(),-1);
        stack<int> candidates;
        for (int i = (int)arr.size()-1; i >= 0; --i) {
            while (!candidates.empty() && freq[candidates.top()] <= freq[arr[i]]) candidates.pop();
            if (!candidates.empty()) out[i] = candidates.top();
            candidates.push(arr[i]);
        }
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Next Element with Greater Frequency: For each position return the nearest value to its right whose total-array frequency is strictly greater; use -1 if none.

2. FUNCTION SIGNATURE, PART BY PART
vector<int> nextFreqGreater(vector<int>& arr)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Monotonic stack on frequencies.
Pop values with no greater frequency: the closer current value dominates them for future positions to its left.
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
5. `vector<int> nextFreqGreater(vector<int>& arr) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `unordered_map<int,int> freq;`
   Declares `freq` so it can store state used by the algorithm.
7. `for (int value : arr) ++freq[value];`
   Starts a range-based loop. `int value : arr` means: take each element from the container in turn and run the block. Its one-line body is `++freq[value];`.
8. `vector<int> out(arr.size(),-1);`
   Declares `out` so it can store state used by the algorithm.
9. `stack<int> candidates;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `for (int i = (int)arr.size()-1; i >= 0; --i) {`
   Starts a loop: first `int i = (int)arr.size()-1`; keep repeating while `i >= 0` is true; after each iteration perform `--i`.
11. `while (!candidates.empty() && freq[candidates.top()] <= freq[arr[i]]) candidates.pop();`
   Repeats the following block while `!candidates.empty() && freq[candidates.top()] <= freq[arr[i]]` is true. Its one-line body is `candidates.pop();`.
12. `if (!candidates.empty()) out[i] = candidates.top();`
   Runs the next block only when `!candidates.empty()` is true. The one-line action is `out[i] = candidates.top();`.
13. `candidates.push(arr[i]);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- unordered_map: Stores key-value pairs in a hash table, with expected O(1) operations.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: For [1,1,2,3,2,1], frequencies are 1:3, 2:2, 3:1. The 3 resolves to the following 2; each 2 resolves to the final 1. Answer [-1,-1,1,2,1,-1].
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Stack candidates have strictly decreasing frequency from bottom to top when scanning right to left.
Pop values with no greater frequency: the closer current value dominates them for future positions to its left.

7. COMPLEXITY
Time: O(n) expected. Space: O(n).
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
