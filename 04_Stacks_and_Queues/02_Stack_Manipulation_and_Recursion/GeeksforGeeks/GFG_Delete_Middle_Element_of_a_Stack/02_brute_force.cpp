#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void deleteMiddle(stack<int>& st) {
        int depth=(int)st.size()-1-((int)st.size()-1)/2;
        function<void(int)> remove=[&](int d){
            if(d==0){
                st.pop();
                return;
            }
            int x=st.top();
            st.pop();
            remove(d-1);
            st.push(x);
        }
        ;
        if(!st.empty())remove(depth);
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Delete Middle Element of a Stack
Platform: GeeksforGeeks
Pattern: Stack Manipulation and Recursion

Learning goal: Keep the original order when removing the middle entry from LIFO storage.
This file implements: Same efficient method (no distinct baseline).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`void deleteMiddle(stack<int>& st)`
- `void` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: After deleting the target depth, the removed elements return in order.

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
5. `void deleteMiddle(stack<int>& st) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int depth=(int)st.size()-1-((int)st.size()-1)/2;`
   Creates `depth` and initializes it from `(int)st.size()-1-((int)st.size()-1)/2`. This gives the algorithm its starting state.
7. `function<void(int)> remove=[&](int d){`
   Creates a callable named `remove`. `[&]` lets it use surrounding local variables by reference, which is needed for the recursive search.
8. `if(d==0){`
   Runs the next block only when `d==0` is true.
9. `st.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `return;`
   Ends the function.
11. `int x=st.top();`
   Creates `x` and initializes it from `st.top()`. This gives the algorithm its starting state.
12. `st.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `remove(d-1);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `st.push(x);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
15. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `if(!st.empty())remove(depth);`
   Runs the next block only when `!st.empty()` is true. The one-line action is `remove(depth);`.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- function: A standard-library wrapper able to store a callable object such as a recursive lambda.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- lambda ([&]): Creates an unnamed function. [&] captures surrounding local variables by reference, so the lambda can read and modify them.
- recursion: A function calls itself on a smaller remaining choice. It needs a stopping condition to avoid infinite calls.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: bottom->top [1,2,3,4,5] -> [1,2,4,5]
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: After deleting the target depth, the removed elements return in order.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n).
- Extra space: O(n) recursion.
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
