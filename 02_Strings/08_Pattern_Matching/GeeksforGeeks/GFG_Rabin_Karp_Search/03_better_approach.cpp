#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> search(string pat, string txt) {
        vector<int> out;
        int n = txt.size(), m = pat.size();
        if (m > n) return out;
        const long long mod = 1000000007, base = 257;
        long long power = 1, target = 0, window = 0;
        for (int i = 0; i < m; ++i) {
            if (i) power = power * base % mod;
            target = (target * base + (unsigned char)pat[i] + 1) % mod;
            window = (window * base + (unsigned char)txt[i] + 1) % mod;
        }
        for (int i = 0; i + m <= n; ++i) {
            if (window == target && txt.compare(i, m, pat) == 0) out.push_back(i+1);
            if (i + m < n) {
                window = (window - ((unsigned char)txt[i]+1)*power % mod + mod) % mod;
                window = (window * base + (unsigned char)txt[i+m] + 1) % mod;
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
Method: Rolling hash with collision verification.
Roll a base-257 hash modulo a prime. Verify all c hash candidates directly; collisions cannot create false matches.
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
6. `vector<int> out;`
   Declares `out` so it can store state used by the algorithm.
7. `int n = txt.size(), m = pat.size();`
   Creates `n` and initializes it from `txt.size(), m = pat.size()`. This gives the algorithm its starting state.
8. `if (m > n) return out;`
   Runs the next block only when `m > n` is true. The one-line action is `return out;`.
9. `const long long mod = 1000000007, base = 257;`
   Creates `mod` and initializes it from `1000000007, base = 257`. This gives the algorithm its starting state.
10. `long long power = 1, target = 0, window = 0;`
   Creates `power` and initializes it from `1, target = 0, window = 0`. This gives the algorithm its starting state.
11. `for (int i = 0; i < m; ++i) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < m` is true; after each iteration perform `++i`.
12. `if (i) power = power * base % mod;`
   Runs the next block only when `i` is true. The one-line action is `power = power * base % mod;`.
13. `target = (target * base + (unsigned char)pat[i] + 1) % mod;`
   Updates `target` to `(target * base + (unsigned char)pat[i] + 1) % mod` for the next step of the algorithm.
14. `window = (window * base + (unsigned char)txt[i] + 1) % mod;`
   Updates `window` to `(window * base + (unsigned char)txt[i] + 1) % mod` for the next step of the algorithm.
15. `for (int i = 0; i + m <= n; ++i) {`
   Starts a loop: first `int i = 0`; keep repeating while `i + m <= n` is true; after each iteration perform `++i`.
16. `if (window == target && txt.compare(i, m, pat) == 0) out.push_back(i+1);`
   Runs the next block only when `window == target && txt.compare(i, m, pat) == 0` is true. The one-line action is `out.push_back(i+1);`.
17. `if (i + m < n) {`
   Runs the next block only when `i + m < n` is true.
18. `window = (window - ((unsigned char)txt[i]+1)*power % mod + mod) % mod;`
   Updates `window` to `(window - ((unsigned char)txt[i]+1)*power % mod + mod) % mod` for the next step of the algorithm.
19. `window = (window * base + (unsigned char)txt[i+m] + 1) % mod;`
   Updates `window` to `(window * base + (unsigned char)txt[i+m] + 1) % mod` for the next step of the algorithm.
20. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- long long: A wider signed whole-number type, commonly 64 bits; it is used when an int may be too small.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- const: Promises that the named value will not be changed through that declaration.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
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
Shared contract trace: For pat="aa", txt="aaaa", windows starting at zero-based 0,1,2 match. The returned positions are [1,2,3], with overlaps retained.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
A hash match is only a candidate; exact character comparison decides whether it is a real match.
Roll a base-257 hash modulo a prime. Verify all c hash candidates directly; collisions cannot create false matches.

7. COMPLEXITY
Time: O(n+m+cm), O(nm) worst case. Space: O(1) auxiliary plus output.
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
