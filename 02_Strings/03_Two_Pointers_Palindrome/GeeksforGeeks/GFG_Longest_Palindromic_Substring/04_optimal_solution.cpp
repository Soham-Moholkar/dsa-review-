#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, length = 0;
        vector<int> odd(n), even(n);
        auto record = [&](int begin, int size) {
            if (size > length || (size == length && begin < start)) {
                start = begin;
                length = size;
            }
        }
        ;
        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = i > r ? 1 : min(odd[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
            odd[i] = k;
            record(i - k + 1, 2 * k - 1);
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }
        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = i > r ? 0 : min(even[l + r - i + 1], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) ++k;
            even[i] = k;
            record(i - k, 2 * k);
            if (i + k - 1 > r) {
                l = i - k;
                r = i + k - 1;
            }
        }
        return s.substr(start, length);
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Longest Palindrome in String: Return the longest contiguous palindrome, choosing the earliest start on a length tie. Empty input returns an empty string.

2. FUNCTION SIGNATURE, PART BY PART
string longestPalindrome(string s)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Manacher radius reuse (advanced extension).
Track the palindrome reaching farthest right. Mirror a center inside it, cap the copied radius at its boundary, and compare only new pairs. Odd and even radii avoid separator assumptions. Each successful expansion beyond the boundary advances it, giving linear total work.
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
5. `string longestPalindrome(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = s.size(), start = 0, length = 0;`
   Creates `n` and initializes it from `s.size(), start = 0, length = 0`. This gives the algorithm its starting state.
7. `vector<int> odd(n), even(n);`
   Declares `odd` so it can store state used by the algorithm.
8. `auto record = [&](int begin, int size) {`
   Creates `record` and initializes it from `[&](int begin, int size) {`. This gives the algorithm its starting state.
9. `if (size > length || (size == length && begin < start)) {`
   Runs the next block only when `size > length || (size == length && begin < start)` is true.
10. `start = begin;`
   Updates `start` to `begin` for the next step of the algorithm.
11. `length = size;`
   Updates `length` to `size` for the next step of the algorithm.
12. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `for (int i = 0, l = 0, r = -1; i < n; ++i) {`
   Starts a loop: first `int i = 0, l = 0, r = -1`; keep repeating while `i < n` is true; after each iteration perform `++i`.
14. `int k = i > r ? 1 : min(odd[l + r - i], r - i + 1);`
   Creates `k` and initializes it from `i > r ? 1 : min(odd[l + r - i], r - i + 1)`. This gives the algorithm its starting state.
15. `while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;`
   Repeats the following block while `i - k >= 0 && i + k < n && s[i - k] == s[i + k]` is true. Its one-line body is `++k;`.
16. `odd[i] = k;`
   Updates `odd[i]` to `k` for the next step of the algorithm.
17. `record(i - k + 1, 2 * k - 1);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
18. `if (i + k - 1 > r) {`
   Runs the next block only when `i + k - 1 > r` is true.
19. `l = i - k + 1;`
   Updates `l` to `i - k + 1` for the next step of the algorithm.
20. `r = i + k - 1;`
   Updates `r` to `i + k - 1` for the next step of the algorithm.
21. `for (int i = 0, l = 0, r = -1; i < n; ++i) {`
   Starts a loop: first `int i = 0, l = 0, r = -1`; keep repeating while `i < n` is true; after each iteration perform `++i`.
22. `int k = i > r ? 0 : min(even[l + r - i + 1], r - i + 1);`
   Creates `k` and initializes it from `i > r ? 0 : min(even[l + r - i + 1], r - i + 1)`. This gives the algorithm its starting state.
23. `while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) ++k;`
   Repeats the following block while `i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]` is true. Its one-line body is `++k;`.
24. `even[i] = k;`
   Updates `even[i]` to `k` for the next step of the algorithm.
25. `record(i - k, 2 * k);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
26. `if (i + k - 1 > r) {`
   Runs the next block only when `i + k - 1 > r` is true.
27. `l = i - k;`
   Updates `l` to `i - k` for the next step of the algorithm.
28. `r = i + k - 1;`
   Updates `r` to `i + k - 1` for the next step of the algorithm.
29. `return s.substr(start, length);`
   Ends the function and sends `s.substr(start, length)` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- min / max: Returns the smaller/larger of the supplied values.
- lambda ([&]): Creates an unnamed function. [&] captures surrounding local variables by reference, so the lambda can read and modify them.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- ++ / --: Increases/decreases a numeric variable by one.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: In "cbbd", the gap between the two b characters expands to "bb". Its neighbors c and d differ, so the even radius stops at length 2. Odd centers give length 1.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
A radius describes only matching pairs around one center; the best answer retains the earliest maximum.
Track the palindrome reaching farthest right. Mirror a center inside it, cap the copied radius at its boundary, and compare only new pairs. Odd and even radii avoid separator assumptions. Each successful expansion beyond the boundary advances it, giving linear total work.

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
