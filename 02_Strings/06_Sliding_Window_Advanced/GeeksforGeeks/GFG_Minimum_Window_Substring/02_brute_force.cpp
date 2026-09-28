#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        string best="";
        for(int i=0;i<(int)s.size();++i)for(int j=i;j<(int)s.size();++j){
            string part=s.substr(i,j-i+1);
            int cnt[256]={
            }
            ;
            for(unsigned char c:part)++cnt[c];
            bool ok=true;
            for(unsigned char c:t)if(--cnt[c]<0){
                ok=false;
                break;
            }
            if(ok&&(best.empty()||part.size()<best.size()))best=part;
        }
        return best;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Minimum Window Substring
Platform: GeeksforGeeks
Pattern: Sliding Window Advanced

Learning goal: Track when all required counts are satisfied, then remove unnecessary characters from the left.
This file implements: Check all candidate substrings.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`string minWindow(string s, string t)`
- `string` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The preferred pattern uses this invariant: The missing count is zero exactly when the current window covers t.

Read these executable lines in their actual order. Nested indentation shows when
an action belongs to a class, method, branch, loop, or lambda:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `string minWindow(string s, string t) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `string best="";`
   Updates `string best` to `""` for the next step of the algorithm.
7. `for(int i=0;i<(int)s.size();++i)for(int j=i;j<(int)s.size();++j){`
   Starts a loop: first `int i=0`; keep repeating while `i<(int)s.size()` is true; after each iteration perform `++i`. Its one-line body is `for(int j=i;j<(int)s.size();++j){`.
8. `string part=s.substr(i,j-i+1);`
   Updates `string part` to `s.substr(i,j-i+1)` for the next step of the algorithm.
9. `int cnt[256]={`
   Creates `the variable` and initializes it from `{`. This gives the algorithm its starting state.
10. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `for(unsigned char c:part)++cnt[c];`
   Starts a range-based loop. `unsigned char c:part` means: take each element from the container in turn and run the block. Its one-line body is `++cnt[c];`.
12. `bool ok=true;`
   Creates `ok` and initializes it from `true`. This gives the algorithm its starting state.
13. `for(unsigned char c:t)if(--cnt[c]<0){`
   Starts a range-based loop. `unsigned char c:t` means: take each element from the container in turn and run the block. Its one-line body is `if(--cnt[c]<0){`.
14. `ok=false;`
   Updates `ok` to `false` for the next step of the algorithm.
15. `break;`
   Stops the nearest loop immediately because no more iterations are needed.
16. `if(ok&&(best.empty()||part.size()<best.size()))best=part;`
   Runs the next block only when `ok&&(best.empty()||part.size()<best.size())` is true. The one-line action is `best=part;`.
17. `return best;`
   Ends the function and sends `best` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- break: Immediately exits the nearest loop.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "ADOBECODEBANC", "ABC" -> "BANC"
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The preferred pattern uses this invariant: The missing count is zero exactly when the current window covers t.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n³).
- Extra space: O(n).
- `n` means input length, `k` a window/capacity where used, `w` a word count,
  `L` word length, and `A` alphabet size. Design problems state per-operation
  costs. Recursive frames count; returned output storage may be additional.

8. EDGE CASES TO CHECK
----------------------
- Smallest valid input; empty access only when explicitly permitted.
- Repeated or equal values and strict versus nonstrict comparisons.
- The first and final valid indexes or a result that does not exist.
- Signed values and arithmetic near the declared input limits.

9. COMMON MISTAKES
------------------
- Failing to restore popped items or losing their relative order.
- Assuming an STL pop operation returns the removed value.
- Forgetting an element's index when the question asks for distance or range.
- Omitting recursion or auxiliary containers from space analysis.
- Claiming a live-platform signature without checking its current contract.

10. HOW TO STUDY THIS SOLUTION
------------------------------
1. Hide the code and describe the saved state in a sentence.
2. Explain each line and trace at least one counterexample without executing.
3. Compare all three files and their actual time/space tradeoffs.
4. Recode from memory and record your own failure in mistakes.md.

This explanatory comment does not change the C++ program's behavior.
*/
