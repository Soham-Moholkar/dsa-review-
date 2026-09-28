#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(string pat, string txt) {
        array<int,26> target{
        }
        ;
        for (char c : pat) ++target[c - 'a'];
        int m = pat.size(), answer = 0;
        for (int i = 0; i + m <= (int)txt.size(); ++i) {
            array<int,26> count{
            }
            ;
            for (int j = i; j < i + m; ++j) ++count[txt[j] - 'a'];
            answer += count == target;
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Count Occurrences of Anagrams: Lowercase strings, nonempty pattern; count overlapping windows whose letters form an anagram of pat. Arguments are pattern then text.

2. FUNCTION SIGNATURE, PART BY PART
int search(string pat, string txt)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Count each window afresh.
Compare frequency arrays rather than sorting; overlapping windows still repeat counting work.
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
5. `int search(string pat, string txt) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `array<int,26> target{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
7. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
8. `for (char c : pat) ++target[c - 'a'];`
   Starts a range-based loop. `char c : pat` means: take each element from the container in turn and run the block. Its one-line body is `++target[c - 'a'];`.
9. `int m = pat.size(), answer = 0;`
   Creates `m` and initializes it from `pat.size(), answer = 0`. This gives the algorithm its starting state.
10. `for (int i = 0; i + m <= (int)txt.size(); ++i) {`
   Starts a loop: first `int i = 0`; keep repeating while `i + m <= (int)txt.size()` is true; after each iteration perform `++i`.
11. `array<int,26> count{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
12. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `for (int j = i; j < i + m; ++j) ++count[txt[j] - 'a'];`
   Starts a loop: first `int j = i`; keep repeating while `j < i + m` is true; after each iteration perform `++j`. Its one-line body is `++count[txt[j] - 'a'];`.
14. `answer += count == target;`
   Updates the stored state using its previous value and the expression on the right.
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
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
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
Shared contract trace: For pat="ab", txt="abab", windows ab, ba, ab all have one a and one b, so overlapping matches give 3.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
The live frequency table covers exactly the current pattern-length window.
Compare frequency arrays rather than sorting; overlapping windows still repeat counting work.

7. COMPLEXITY
Time: O(n(m+26)). Space: O(26).
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
