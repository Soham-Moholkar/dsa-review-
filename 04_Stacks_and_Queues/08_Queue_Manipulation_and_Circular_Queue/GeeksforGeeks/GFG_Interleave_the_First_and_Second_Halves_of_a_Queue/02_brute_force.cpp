#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void interleaveQueue(queue<int>& q) {
        int n=q.size();
        queue<int> first;
        for(int i=0;i<n/2;++i){
            first.push(q.front());
            q.pop();
        }
        queue<int> out;
        while(!first.empty()){
            out.push(first.front());
            first.pop();
            out.push(q.front());
            q.pop();
        }
        q=move(out);
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Interleave the First and Second Halves of a Queue
Platform: GeeksforGeeks
Pattern: Queue Manipulation and Circular Queue

Learning goal: Interleave two contiguous halves while preserving each half's internal order.
This file implements: Same efficient method (no distinct baseline).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`void interleaveQueue(queue<int>& q)`
- `void` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Each output pair draws one item from each original half.

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
5. `void interleaveQueue(queue<int>& q) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n=q.size();`
   Creates `n` and initializes it from `q.size()`. This gives the algorithm its starting state.
7. `queue<int> first;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
8. `for(int i=0;i<n/2;++i){`
   Starts a loop: first `int i=0`; keep repeating while `i<n/2` is true; after each iteration perform `++i`.
9. `first.push(q.front());`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `q.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `queue<int> out;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
12. `while(!first.empty()){`
   Repeats the following block while `!first.empty()` is true.
13. `out.push(first.front());`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `first.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
15. `out.push(q.front());`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `q.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
17. `q=move(out);`
   Updates `q` to `move(out)` for the next step of the algorithm.

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
Use the first entry in testcases.md: [1,2,3,4] -> [1,3,2,4]
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Each output pair draws one item from each original half.
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
