#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseFirstK(queue<int>& q, int k) {
        stack<int> st;
        int n=q.size();
        for(int i=0;i<k;++i){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        for(int i=0;i<n-k;++i){
            q.push(q.front());
            q.pop();
        }
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Reverse First K Elements of a Queue
Platform: GeeksforGeeks
Pattern: Queue Manipulation and Circular Queue

Learning goal: Keep the suffix in its original order while reversing only a prefix.
This file implements: Same efficient method (no distinct baseline).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`void reverseFirstK(queue<int>& q, int k)`
- `void` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Only the first k elements change order; the suffix remains in order.

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
5. `void reverseFirstK(queue<int>& q, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `stack<int> st;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
7. `int n=q.size();`
   Creates `n` and initializes it from `q.size()`. This gives the algorithm its starting state.
8. `for(int i=0;i<k;++i){`
   Starts a loop: first `int i=0`; keep repeating while `i<k` is true; after each iteration perform `++i`.
9. `st.push(q.front());`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `q.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `while(!st.empty()){`
   Repeats the following block while `!st.empty()` is true.
12. `q.push(st.top());`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `st.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `for(int i=0;i<n-k;++i){`
   Starts a loop: first `int i=0`; keep repeating while `i<n-k` is true; after each iteration perform `++i`.
15. `q.push(q.front());`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `q.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- front / back: Accesses the first or last element of a nonempty container.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: [1,2,3,4,5],3 -> [3,2,1,4,5]
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Only the first k elements change order; the suffix remains in order.
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
