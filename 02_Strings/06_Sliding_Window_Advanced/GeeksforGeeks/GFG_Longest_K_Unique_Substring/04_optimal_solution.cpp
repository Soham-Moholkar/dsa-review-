#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestKSubstr(string s, int k) {
        if (k <= 0) return -1;
        int freq[26] = {
        }
        , distinct = 0, left = 0, answer = -1;
        for (int right = 0; right < (int)s.size(); ++right) {
            if (freq[s[right]-'a']++ == 0) ++distinct;
            while (distinct > k) if (--freq[s[left++]-'a'] == 0) --distinct;
            if (distinct == k) answer = max(answer, right-left+1);
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Longest Substring with K Uniques: Lowercase input; return the longest nonempty substring length with exactly k distinct letters, or -1 if none exists.

2. FUNCTION SIGNATURE, PART BY PART
int longestKSubstr(string s, int k)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Variable sliding window.
Move the left edge only when distinct exceeds k. Each character enters and leaves at most once.
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
5. `int longestKSubstr(string s, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `if (k <= 0) return -1;`
   Runs the next block only when `k <= 0` is true. The one-line action is `return -1;`.
7. `int freq[26] = {`
   Creates `the variable` and initializes it from `{`. This gives the algorithm its starting state.
8. `, distinct = 0, left = 0, answer = -1;`
   Updates `, distinct` to `0, left = 0, answer = -1` for the next step of the algorithm.
9. `for (int right = 0; right < (int)s.size(); ++right) {`
   Starts a loop: first `int right = 0`; keep repeating while `right < (int)s.size()` is true; after each iteration perform `++right`.
10. `if (freq[s[right]-'a']++ == 0) ++distinct;`
   Runs the next block only when `freq[s[right]-'a']++ == 0` is true. The one-line action is `++distinct;`.
11. `while (distinct > k) if (--freq[s[left++]-'a'] == 0) --distinct;`
   Repeats the following block while `distinct > k` is true. Its one-line body is `if (--freq[s[left++]-'a'] == 0) --distinct;`.
12. `if (distinct == k) answer = max(answer, right-left+1);`
   Runs the next block only when `distinct == k` is true. The one-line action is `answer = max(answer, right-left+1);`.
13. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- min / max: Returns the smaller/larger of the supplied values.
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
Shared contract trace: For "aabac", k=2, the window grows through "aaba" with two letters. Adding c makes three; removing left characters eventually restores a,c. Best length remains 4.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
After shrinking, the live window has at most k distinct letters; record it only at exactly k.
Move the left edge only when distinct exceeds k. Each character enters and leaves at most once.

7. COMPLEXITY
Time: O(n). Space: O(26).
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
