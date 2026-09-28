#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        long long sum=0,last=0,number=0;
        char op='+';
        for(int i=0;i<=(int)s.size();++i){
            char c=i==(int)s.size()?'+':s[i];
            if(c==' ')continue;
            if(isdigit((unsigned char)c)){
                number=number*10+c-'0';
                continue;
            }
            if(op=='+'){
                sum+=last;
                last=number;
            }
            else if(op=='-'){
                sum+=last;
                last=-number;
            }
            else if(op=='*')last*=number;
            else last/=number;
            op=c;
            number=0;
        }
        return (int)(sum+last);
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Basic Calculator II
Platform: LeetCode
Pattern: Parentheses and Expressions

Learning goal: Contrast operator precedence in infix with the immediate operand order of postfix.
This file implements: Same efficient method (no distinct baseline).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int calculate(string s)`
- `int` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The saved last term preserves multiplication and division precedence.

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
5. `int calculate(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `long long sum=0,last=0,number=0;`
   Creates `sum` and initializes it from `0,last=0,number=0`. This gives the algorithm its starting state.
7. `char op='+';`
   Updates `char op` to `'+'` for the next step of the algorithm.
8. `for(int i=0;i<=(int)s.size();++i){`
   Starts a loop: first `int i=0`; keep repeating while `i<=(int)s.size()` is true; after each iteration perform `++i`.
9. `char c=i==(int)s.size()?'+':s[i];`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `if(c==' ')continue;`
   Runs the next block only when `c==' '` is true. The one-line action is `continue;`.
11. `if(isdigit((unsigned char)c)){`
   Runs the next block only when `isdigit((unsigned char)c)` is true.
12. `number=number*10+c-'0';`
   Updates `number` to `number*10+c-'0'` for the next step of the algorithm.
13. `continue;`
   Skips the rest of this iteration and starts the next one.
14. `if(op=='+'){`
   Runs the next block only when `op=='+'` is true.
15. `sum+=last;`
   Updates the stored state using its previous value and the expression on the right.
16. `last=number;`
   Updates `last` to `number` for the next step of the algorithm.
17. `else if(op=='-'){`
   Defines the judge-facing function and lists the inputs it receives.
18. `sum+=last;`
   Updates the stored state using its previous value and the expression on the right.
19. `last=-number;`
   Updates `last` to `-number` for the next step of the algorithm.
20. `else if(op=='*')last*=number;`
   If earlier branches failed, runs this block when `op=='*'` is true. The one-line action is `last*=number;`.
21. `else last/=number;`
   Handles the remaining case after the preceding condition(s) were false.
22. `op=c;`
   Updates `op` to `c` for the next step of the algorithm.
23. `number=0;`
   Updates `number` to `0` for the next step of the algorithm.
24. `return (int)(sum+last);`
   Ends the function and sends `(int)(sum+last)` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- long long: A wider signed whole-number type, commonly 64 bits; it is used when an int may be too small.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- continue: Skips the remainder of the current loop iteration and begins the next one.
- size: Returns the number of elements in a container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "3+2*2" -> 7
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The saved last term preserves multiplication and division precedence.
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
