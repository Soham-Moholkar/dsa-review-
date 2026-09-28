#include <bits/stdc++.h>
using namespace std;
class MyStack {
    queue<int> q;
public:
    MyStack()=default;
    void push(int x){
        q.push(x);
        for(int i=1,n=q.size();i<n;++i){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){
        int v=q.front();
        q.pop();
        return v;
    }
    int top(){
        return q.front();
    }
    bool empty(){
        return q.empty();
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Implement Stack using Queues
Platform: GeeksforGeeks
Pattern: Queue Manipulation and Circular Queue

Learning goal: Compare where the work happens when implementing an opposite adapter.
This file implements: Same efficient method (no distinct baseline).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`class MyStack { public: MyStack(); void push(int x); int pop(); int top(); bool empty(); };`
- This is a design class. Its declared public methods form the local exercise interface.
- The judge calls each operation separately; use the problem README for empty/capacity behavior.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Rotating after a push makes the newest element the next queue front.

Read these executable lines in their actual order. Nested indentation shows when
an action belongs to a class, method, branch, loop, or lambda:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class MyStack {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
4. `queue<int> q;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
5. `public:`
   Makes the following method callable by the judge.
6. `MyStack()=default;`
   Updates `MyStack()` to `default` for the next step of the algorithm.
7. `void push(int x){`
   Defines the judge-facing function and lists the inputs it receives.
8. `q.push(x);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `for(int i=1,n=q.size();i<n;++i){`
   Starts a loop: first `int i=1,n=q.size()`; keep repeating while `i<n` is true; after each iteration perform `++i`.
10. `q.push(q.front());`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `q.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
12. `int pop(){`
   Defines the judge-facing function and lists the inputs it receives.
13. `int v=q.front();`
   Creates `v` and initializes it from `q.front()`. This gives the algorithm its starting state.
14. `q.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
15. `return v;`
   Ends the function and sends `v` back to the caller.
16. `int top(){`
   Defines the judge-facing function and lists the inputs it receives.
17. `return q.front();`
   Ends the function and sends `q.front()` back to the caller.
18. `bool empty(){`
   Defines the judge-facing function and lists the inputs it receives.
19. `return q.empty();`
   Ends the function and sends `q.empty()` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- front / back: Accesses the first or last element of a nonempty container.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: push(1),push(2),top(),pop(),empty() -> 2,2,false
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Rotating after a push makes the newest element the next queue front.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n) push, O(1) pop/top.
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
