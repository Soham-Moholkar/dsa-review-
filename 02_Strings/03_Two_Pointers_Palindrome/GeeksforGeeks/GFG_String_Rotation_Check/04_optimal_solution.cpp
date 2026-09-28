#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areRotations(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        if (n == 0) return true;
        vector<int> pi(n);
        for (int i = 1, j = 0; i < n; ++i) {
            while (j && s2[i] != s2[j]) j = pi[j - 1];
            if (s2[i] == s2[j]) ++j;
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < 2 * n; ++i) {
            char c = s1[i % n];
            while (j && c != s2[j]) j = pi[j - 1];
            if (c == s2[j]) ++j;
            if (j == n) return true;
        }
        return false;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
String Rotation Check: Equal-length strings are rotations when one cyclic shift matches the other. Two empty strings return true locally.

2. FUNCTION SIGNATURE, PART BY PART
bool areRotations(string s1, string s2)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: KMP over doubled source.
Build the target prefix table, then scan two source copies without materializing them. Study this file after stage 08.
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
5. `bool areRotations(string s1, string s2) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `if (s1.size() != s2.size()) return false;`
   Runs the next block only when `s1.size() != s2.size()` is true. The one-line action is `return false;`.
7. `int n = s1.size();`
   Creates `n` and initializes it from `s1.size()`. This gives the algorithm its starting state.
8. `if (n == 0) return true;`
   Runs the next block only when `n == 0` is true. The one-line action is `return true;`.
9. `vector<int> pi(n);`
   Declares `pi` so it can store state used by the algorithm.
10. `for (int i = 1, j = 0; i < n; ++i) {`
   Starts a loop: first `int i = 1, j = 0`; keep repeating while `i < n` is true; after each iteration perform `++i`.
11. `while (j && s2[i] != s2[j]) j = pi[j - 1];`
   Repeats the following block while `j && s2[i] != s2[j]` is true. Its one-line body is `j = pi[j - 1];`.
12. `if (s2[i] == s2[j]) ++j;`
   Runs the next block only when `s2[i] == s2[j]` is true. The one-line action is `++j;`.
13. `pi[i] = j;`
   Updates `pi[i]` to `j` for the next step of the algorithm.
14. `for (int i = 0, j = 0; i < 2 * n; ++i) {`
   Starts a loop: first `int i = 0, j = 0`; keep repeating while `i < 2 * n` is true; after each iteration perform `++i`.
15. `char c = s1[i % n];`
   Updates `char c` to `s1[i % n]` for the next step of the algorithm.
16. `while (j && c != s2[j]) j = pi[j - 1];`
   Repeats the following block while `j && c != s2[j]` is true. Its one-line body is `j = pi[j - 1];`.
17. `if (c == s2[j]) ++j;`
   Runs the next block only when `c == s2[j]` is true. The one-line action is `++j;`.
18. `if (j == n) return true;`
   Runs the next block only when `j == n` is true. The one-line action is `return true;`.
19. `return false;`
   Ends the function and sends `false` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
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
Shared contract trace: For "abcd" and "cdab", the doubled source is "abcdabcd". Matching from position 2 consumes c,d,a,b; unequal lengths are rejected first.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
A length-n rotation is a length-n substring of the doubled source.
Build the target prefix table, then scan two source copies without materializing them. Study this file after stage 08.

7. COMPLEXITY
Time: O(n). Space: O(n).
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
