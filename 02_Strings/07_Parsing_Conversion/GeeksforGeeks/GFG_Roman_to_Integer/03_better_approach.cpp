#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> val{
            {
                'I',1
            }
            ,{
                'V',5
            }
            ,{
                'X',10
            }
            ,{
                'L',50
            }
            ,{
                'C',100
            }
            ,{
                'D',500
            }
            ,{
                'M',1000
            }
        }
        ;
        int ans=0;
        for(int i=0;i<(int)s.size();++i){
            int v=val[s[i]];
            ans+=(i+1<(int)s.size()&&v<val[s[i+1]])?-v:v;
        }
        return ans;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Roman to Integer
Platform: GeeksforGeeks
Pattern: Parsing Conversion

Learning goal: Recognize when a smaller symbol before a larger one changes the operation from addition to subtraction.
This file implements: Same efficient method (no distinct intermediate).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int romanToInt(string s)`
- `int` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Each processed Roman symbol contributes according to the following symbol.

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
5. `int romanToInt(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `unordered_map<char,int> val{`
   Declares `val` so it can store state used by the algorithm.
7. `'I',1`
   Performs this operation to maintain the state described in the algorithm walkthrough.
8. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `'V',5`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `'X',10`
   Performs this operation to maintain the state described in the algorithm walkthrough.
12. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `'L',50`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
15. `'C',100`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
17. `'D',500`
   Performs this operation to maintain the state described in the algorithm walkthrough.
18. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
19. `'M',1000`
   Performs this operation to maintain the state described in the algorithm walkthrough.
20. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
21. `int ans=0;`
   Creates `ans` and initializes it from `0`. This gives the algorithm its starting state.
22. `for(int i=0;i<(int)s.size();++i){`
   Starts a loop: first `int i=0`; keep repeating while `i<(int)s.size()` is true; after each iteration perform `++i`.
23. `int v=val[s[i]];`
   Creates `v` and initializes it from `val[s[i]]`. This gives the algorithm its starting state.
24. `ans+=(i+1<(int)s.size()&&v<val[s[i+1]])?-v:v;`
   Updates the stored state using its previous value and the expression on the right.
25. `return ans;`
   Ends the function and sends `ans` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- unordered_map: Stores key-value pairs in a hash table, with expected O(1) operations.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "III" -> 3
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Each processed Roman symbol contributes according to the following symbol.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n).
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
