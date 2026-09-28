#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(auto& s:tokens){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                long long b=st.top();
                st.pop();
                long long a=st.top();
                st.pop();
                if(s=="+")st.push(a+b);
                else if(s=="-")st.push(a-b);
                else if(s=="*")st.push(a*b);
                else st.push(a/b);
            }
            else st.push(stoll(s));
        }
        return (int)st.top();
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Evaluate Reverse Polish Notation
Platform: LeetCode
Pattern: Parentheses and Expressions

Learning goal: Read an expression whose operators follow their operands, preserving subtraction/division order.
This file implements: Postfix reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int evalRPN(vector<string>& tokens)`
- `int` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Each stack value represents one fully evaluated postfix subexpression.

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
5. `int evalRPN(vector<string>& tokens) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `stack<long long> st;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
7. `for(auto& s:tokens){`
   Starts a range-based loop. `auto& s:tokens` means: take each element from the container in turn and run the block.
8. `if(s=="+"||s=="-"||s=="*"||s=="/"){`
   Runs the next block only when `s=="+"||s=="-"||s=="*"||s=="/"` is true.
9. `long long b=st.top();`
   Creates `b` and initializes it from `st.top()`. This gives the algorithm its starting state.
10. `st.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `long long a=st.top();`
   Creates `a` and initializes it from `st.top()`. This gives the algorithm its starting state.
12. `st.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `if(s=="+")st.push(a+b);`
   Runs the next block only when `s=="+"` is true. The one-line action is `st.push(a+b);`.
14. `else if(s=="-")st.push(a-b);`
   If earlier branches failed, runs this block when `s=="-"` is true. The one-line action is `st.push(a-b);`.
15. `else if(s=="*")st.push(a*b);`
   If earlier branches failed, runs this block when `s=="*"` is true. The one-line action is `st.push(a*b);`.
16. `else st.push(a/b);`
   Handles the remaining case after the preceding condition(s) were false.
17. `else st.push(stoll(s));`
   Handles the remaining case after the preceding condition(s) were false.
18. `return (int)st.top();`
   Ends the function and sends `(int)st.top()` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- long long: A wider signed whole-number type, commonly 64 bits; it is used when an int may be too small.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: ["2","1","+","3","*"] -> 9
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Each stack value represents one fully evaluated postfix subexpression.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n).
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
