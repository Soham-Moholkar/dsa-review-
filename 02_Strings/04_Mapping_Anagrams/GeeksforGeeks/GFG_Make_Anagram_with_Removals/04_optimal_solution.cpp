#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int remAnagram(string s1, string s2) {
        int counts[26] = {
        }
        ;
        for (char c : s1) ++counts[c - 'a'];
        for (char c : s2) --counts[c - 'a'];
        int answer = 0;
        for (int count : counts) answer += abs(count);
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Make Anagram with Removals: Lowercase strings; deletion from either string costs one. Return the minimum total deletions.

2. FUNCTION SIGNATURE, PART BY PART
int remAnagram(string s1, string s2)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Signed frequency difference.
Increment for the first string, decrement for the second, and sum absolute imbalances.
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
5. `int remAnagram(string s1, string s2) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int counts[26] = {`
   Creates `the variable` and initializes it from `{`. This gives the algorithm its starting state.
7. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
8. `for (char c : s1) ++counts[c - 'a'];`
   Starts a range-based loop. `char c : s1` means: take each element from the container in turn and run the block. Its one-line body is `++counts[c - 'a'];`.
9. `for (char c : s2) --counts[c - 'a'];`
   Starts a range-based loop. `char c : s2` means: take each element from the container in turn and run the block. Its one-line body is `--counts[c - 'a'];`.
10. `int answer = 0;`
   Creates `answer` and initializes it from `0`. This gives the algorithm its starting state.
11. `for (int count : counts) answer += abs(count);`
   Starts a range-based loop. `int count : counts` means: take each element from the container in turn and run the block. Its one-line body is `answer += abs(count);`.
12. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- return: Ends the current function and optionally sends a value back to the caller.
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
Shared contract trace: For "aab" and "abb", a has counts 2 and 1, b has counts 1 and 2. Delete one a and one b: total 2.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
For each letter, only the absolute difference between its counts must be deleted.
Increment for the first string, decrement for the second, and sum absolute imbalances.

7. COMPLEXITY
Time: O(n+m). Space: O(26).
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
