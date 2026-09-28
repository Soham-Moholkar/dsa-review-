#include <bits/stdc++.h>
using namespace std;
class MyQueue {
    stack<int> incoming,outgoing;
    void transfer(){
        if(!outgoing.empty())return;
        while(!incoming.empty()){
            outgoing.push(incoming.top());
            incoming.pop();
        }
    }
public:
    MyQueue()=default;
    void push(int x){
        incoming.push(x);
    }
    int pop(){
        transfer();
        int v=outgoing.top();
        outgoing.pop();
        return v;
    }
    int peek(){
        transfer();
        return outgoing.top();
    }
    bool empty(){
        return incoming.empty()&&outgoing.empty();
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Implement Queue using Stacks
Platform: GeeksforGeeks
Pattern: Queue Manipulation and Circular Queue

Learning goal: Preserve FIFO behavior using only stack operations and discuss the tradeoff.
This file implements: Same efficient method (no distinct baseline).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`class MyQueue { public: MyQueue(); void push(int x); int pop(); int peek(); bool empty(); };`
- This is a design class. Its declared public methods form the local exercise interface.
- The judge calls each operation separately; use the problem README for empty/capacity behavior.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Outgoing stack items precede all incoming items in FIFO order.

Read these executable lines in their actual order. Nested indentation shows when
an action belongs to a class, method, branch, loop, or lambda:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class MyQueue {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
4. `stack<int> incoming,outgoing;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
5. `void transfer(){`
   Defines the judge-facing function and lists the inputs it receives.
6. `if(!outgoing.empty())return;`
   Runs the next block only when `!outgoing.empty()` is true. The one-line action is `return;`.
7. `while(!incoming.empty()){`
   Repeats the following block while `!incoming.empty()` is true.
8. `outgoing.push(incoming.top());`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `incoming.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `public:`
   Makes the following method callable by the judge.
11. `MyQueue()=default;`
   Updates `MyQueue()` to `default` for the next step of the algorithm.
12. `void push(int x){`
   Defines the judge-facing function and lists the inputs it receives.
13. `incoming.push(x);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `int pop(){`
   Defines the judge-facing function and lists the inputs it receives.
15. `transfer();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `int v=outgoing.top();`
   Creates `v` and initializes it from `outgoing.top()`. This gives the algorithm its starting state.
17. `outgoing.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
18. `return v;`
   Ends the function and sends `v` back to the caller.
19. `int peek(){`
   Defines the judge-facing function and lists the inputs it receives.
20. `transfer();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
21. `return outgoing.top();`
   Ends the function and sends `outgoing.top()` back to the caller.
22. `bool empty(){`
   Defines the judge-facing function and lists the inputs it receives.
23. `return incoming.empty()&&outgoing.empty();`
   Ends the function and sends `incoming.empty()&&outgoing.empty()` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- empty: Returns true when a container has no elements.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: push(1),push(2),peek(),pop(),empty() -> 1,1,false
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Outgoing stack items precede all incoming items in FIFO order.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(1) amortized per operation.
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
