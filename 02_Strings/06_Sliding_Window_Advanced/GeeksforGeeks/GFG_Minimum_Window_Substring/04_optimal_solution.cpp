#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty())return "";
        int need[256]={
        }
        ;
        for(unsigned char c:t)++need[c];
        int missing=t.size(),left=0,start=0,best=INT_MAX;
        for(int right=0;right<(int)s.size();++right){
            unsigned char c=s[right];
            if(need[c]-- >0)--missing;
            while(missing==0){
                if(right-left+1<best){
                    start=left;
                    best=right-left+1;
                }
                unsigned char out=s[left++];
                if(++need[out]>0)++missing;
            }
        }
        return best==INT_MAX?"":s.substr(start,best);
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
This file implements: Variable window reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`string minWindow(string s, string t)`
- `string` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The missing count is zero exactly when the current window covers t.

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
6. `if(t.empty())return "";`
   Runs the next block only when `t.empty()` is true. The one-line action is `return "";`.
7. `int need[256]={`
   Creates `the variable` and initializes it from `{`. This gives the algorithm its starting state.
8. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `for(unsigned char c:t)++need[c];`
   Starts a range-based loop. `unsigned char c:t` means: take each element from the container in turn and run the block. Its one-line body is `++need[c];`.
10. `int missing=t.size(),left=0,start=0,best=INT_MAX;`
   Creates `missing` and initializes it from `t.size(),left=0,start=0,best=INT_MAX`. This gives the algorithm its starting state.
11. `for(int right=0;right<(int)s.size();++right){`
   Starts a loop: first `int right=0`; keep repeating while `right<(int)s.size()` is true; after each iteration perform `++right`.
12. `unsigned char c=s[right];`
   Updates `unsigned char c` to `s[right]` for the next step of the algorithm.
13. `if(need[c]-- >0)--missing;`
   Runs the next block only when `need[c]-- >0` is true. The one-line action is `--missing;`.
14. `while(missing==0){`
   Repeats the following block while `missing==0` is true.
15. `if(right-left+1<best){`
   Runs the next block only when `right-left+1<best` is true.
16. `start=left;`
   Updates `start` to `left` for the next step of the algorithm.
17. `best=right-left+1;`
   Updates `best` to `right-left+1` for the next step of the algorithm.
18. `unsigned char out=s[left++];`
   Updates `unsigned char out` to `s[left++]` for the next step of the algorithm.
19. `if(++need[out]>0)++missing;`
   Runs the next block only when `++need[out]>0` is true. The one-line action is `++missing;`.
20. `return best==INT_MAX?"":s.substr(start,best);`
   Ends the function and sends `best==INT_MAX?"":s.substr(start,best)` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- INT_MIN / INT_MAX: The smallest/largest value representable by int.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
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
shown in the executable walkthrough. The maintained fact is: The missing count is zero exactly when the current window covers t.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n + m).
- Extra space: O(1).
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
