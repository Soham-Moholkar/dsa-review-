#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> search(string pat, string txt) {
        int m = pat.size();
        vector<int> pi(m), out;
        for (int i = 1, j = 0; i < m; ++i) {
            while (j && pat[i] != pat[j]) j = pi[j-1];
            if (pat[i] == pat[j]) ++j;
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < (int)txt.size(); ++i) {
            while (j && txt[i] != pat[j]) j = pi[j-1];
            if (txt[i] == pat[j]) ++j;
            if (j == m) {
                out.push_back(i-m+2);
                j = pi[j-1];
            }
        }
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Search Pattern (Rabin-Karp Algorithm): Nonempty pattern. Return all ONE-BASED starting positions, including overlaps; no match returns an empty vector.

2. FUNCTION SIGNATURE, PART BY PART
vector<int> search(string pat, string txt)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: KMP: guaranteed linear comparison.
For a guaranteed bound, reuse the pattern border lengths after mismatch and after each full match.
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
5. `vector<int> search(string pat, string txt) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int m = pat.size();`
   Creates `m` and initializes it from `pat.size()`. This gives the algorithm its starting state.
7. `vector<int> pi(m), out;`
   Declares `pi` so it can store state used by the algorithm.
8. `for (int i = 1, j = 0; i < m; ++i) {`
   Starts a loop: first `int i = 1, j = 0`; keep repeating while `i < m` is true; after each iteration perform `++i`.
9. `while (j && pat[i] != pat[j]) j = pi[j-1];`
   Repeats the following block while `j && pat[i] != pat[j]` is true. Its one-line body is `j = pi[j-1];`.
10. `if (pat[i] == pat[j]) ++j;`
   Runs the next block only when `pat[i] == pat[j]` is true. The one-line action is `++j;`.
11. `pi[i] = j;`
   Updates `pi[i]` to `j` for the next step of the algorithm.
12. `for (int i = 0, j = 0; i < (int)txt.size(); ++i) {`
   Starts a loop: first `int i = 0, j = 0`; keep repeating while `i < (int)txt.size()` is true; after each iteration perform `++i`.
13. `while (j && txt[i] != pat[j]) j = pi[j-1];`
   Repeats the following block while `j && txt[i] != pat[j]` is true. Its one-line body is `j = pi[j-1];`.
14. `if (txt[i] == pat[j]) ++j;`
   Runs the next block only when `txt[i] == pat[j]` is true. The one-line action is `++j;`.
15. `if (j == m) {`
   Runs the next block only when `j == m` is true.
16. `out.push_back(i-m+2);`
   Appends the computed value to the end of the result/container.
17. `j = pi[j-1];`
   Updates `j` to `pi[j-1]` for the next step of the algorithm.
18. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
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
Shared contract trace: For pat="aa", txt="aaaa", windows starting at zero-based 0,1,2 match. The returned positions are [1,2,3], with overlaps retained.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
A hash match is only a candidate; exact character comparison decides whether it is a real match.
For a guaranteed bound, reuse the pattern border lengths after mismatch and after each full match.

7. COMPLEXITY
Time: O(n+m). Space: O(m) plus output.
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
