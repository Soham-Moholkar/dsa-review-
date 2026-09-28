#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int substrCount(string s, int k) {
        if (k <= 0) return 0;
        int freq[26] = {
        }
        , answer = 0;
        for (int r = 0; r < (int)s.size(); ++r) {
            ++freq[s[r] - 'a'];
            if (r >= k) --freq[s[r-k] - 'a'];
            int distinct = 0;
            for (int x : freq) distinct += x > 0;
            if (r + 1 >= k && distinct == k - 1) ++answer;
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Substrings of Length K with K-1 Distinct Characters: Lowercase input; count length-k substrings with exactly k-1 distinct characters. k outside 1..n returns zero locally.

2. FUNCTION SIGNATURE, PART BY PART
int substrCount(string s, int k)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Slide counts and recount active letters.
Reuse character counts, then inspect the 26 counts for every complete window.
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
5. `int substrCount(string s, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `if (k <= 0) return 0;`
   Runs the next block only when `k <= 0` is true. The one-line action is `return 0;`.
7. `int freq[26] = {`
   Creates `the variable` and initializes it from `{`. This gives the algorithm its starting state.
8. `, answer = 0;`
   Updates `, answer` to `0` for the next step of the algorithm.
9. `for (int r = 0; r < (int)s.size(); ++r) {`
   Starts a loop: first `int r = 0`; keep repeating while `r < (int)s.size()` is true; after each iteration perform `++r`.
10. `++freq[s[r] - 'a'];`
   Moves the relevant counter or pointer by one position.
11. `if (r >= k) --freq[s[r-k] - 'a'];`
   Runs the next block only when `r >= k` is true. The one-line action is `--freq[s[r-k] - 'a'];`.
12. `int distinct = 0;`
   Creates `distinct` and initializes it from `0`. This gives the algorithm its starting state.
13. `for (int x : freq) distinct += x > 0;`
   Starts a range-based loop. `int x : freq` means: take each element from the container in turn and run the block. Its one-line body is `distinct += x > 0;`.
14. `if (r + 1 >= k && distinct == k - 1) ++answer;`
   Runs the next block only when `r + 1 >= k && distinct == k - 1` is true. The one-line action is `++answer;`.
15. `return answer;`
   Ends the function and sends `answer` back to the caller.

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
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
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
Shared contract trace: For "aabac", k=3, windows aab and aba each have two distinct letters; bac has three. Answer 2.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
Distinct equals the number of positive frequencies in the current window.
Reuse character counts, then inspect the 26 counts for every complete window.

7. COMPLEXITY
Time: O(26n). Space: O(26).
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
