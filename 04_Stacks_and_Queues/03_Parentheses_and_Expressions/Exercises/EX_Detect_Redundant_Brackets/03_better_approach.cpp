#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasRedundantBrackets(string expression) {
        stack<char> st;
        for(char c:expression){
            if(c!=')'){
                st.push(c);
                continue;
            }
            bool hasOperator=false;
            while(!st.empty()&&st.top()!='('){
                char x=st.top();
                st.pop();
                hasOperator|=(x=='+'||x=='-'||x=='*'||x=='/');
            }
            if(st.empty())return false;
            st.pop();
            if(!hasOperator)return true;
            st.push('a');
        }
        return false;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Detect Redundant Brackets
Platform: Repository exercise
Pattern: Parentheses and Expressions

Learning goal: Distinguish grouping that changes an expression from an unnecessary pair.
This file implements: Same efficient method (no distinct intermediate).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`bool hasRedundantBrackets(string expression)`
- `bool` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: A closed group is redundant when no operator lies inside its matching pair.

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
5. `bool hasRedundantBrackets(string expression) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `stack<char> st;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
7. `for(char c:expression){`
   Starts a range-based loop. `char c:expression` means: take each element from the container in turn and run the block.
8. `if(c!=')'){`
   Runs the next block only when `c!='` is true. The one-line action is `'){`.
9. `st.push(c);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `continue;`
   Skips the rest of this iteration and starts the next one.
11. `bool hasOperator=false;`
   Creates `hasOperator` and initializes it from `false`. This gives the algorithm its starting state.
12. `while(!st.empty()&&st.top()!='('){`
   Repeats the following block while `!st.empty()&&st.top()!='('){` is true.
13. `char x=st.top();`
   Updates `char x` to `st.top()` for the next step of the algorithm.
14. `st.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
15. `hasOperator|=(x=='+'||x=='-'||x=='*'||x=='/');`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `if(st.empty())return false;`
   Runs the next block only when `st.empty()` is true. The one-line action is `return false;`.
17. `st.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
18. `if(!hasOperator)return true;`
   Runs the next block only when `!hasOperator` is true. The one-line action is `return true;`.
19. `st.push('a');`
   Performs this operation to maintain the state described in the algorithm walkthrough.
20. `return false;`
   Ends the function and sends `false` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- continue: Skips the remainder of the current loop iteration and begins the next one.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- empty: Returns true when a container has no elements.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "(a+b)" -> false
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: A closed group is redundant when no operator lies inside its matching pair.
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
