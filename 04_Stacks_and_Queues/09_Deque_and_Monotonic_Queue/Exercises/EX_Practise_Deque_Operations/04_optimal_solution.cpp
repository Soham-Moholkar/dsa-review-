#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> applyDequeOperations(vector<string>& commands) {
        deque<int> dq;
        for(auto& command:commands){
            istringstream in(command);
            string op;
            int x;
            in>>op;
            if(op=="push_front"){
                in>>x;
                dq.push_front(x);
            }
            else if(op=="push_back"){
                in>>x;
                dq.push_back(x);
            }
            else if(op=="pop_front"&&!dq.empty())dq.pop_front();
            else if(op=="pop_back"&&!dq.empty())dq.pop_back();
        }
        return vector<int>(dq.begin(),dq.end());
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Practise Deque Operations
Platform: Repository exercise
Pattern: Deque and Monotonic Queue

Learning goal: Become fluent with both-end insertion and removal before optimizing windows.
This file implements: Std::deque reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> applyDequeOperations(vector<string>& commands)`
- `vector<int>` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The deque contents follow each requested front or back operation.

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
5. `vector<int> applyDequeOperations(vector<string>& commands) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `deque<int> dq;`
   Declares `dq` so it can store state used by the algorithm.
7. `for(auto& command:commands){`
   Starts a range-based loop. `auto& command:commands` means: take each element from the container in turn and run the block.
8. `istringstream in(command);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `string op;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `int x;`
   Declares `x` so it can store state used by the algorithm.
11. `in>>op;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
12. `if(op=="push_front"){`
   Runs the next block only when `op=="push_front"` is true.
13. `in>>x;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `dq.push_front(x);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
15. `else if(op=="push_back"){`
   Defines the judge-facing function and lists the inputs it receives.
16. `in>>x;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
17. `dq.push_back(x);`
   Appends the computed value to the end of the result/container.
18. `else if(op=="pop_front"&&!dq.empty())dq.pop_front();`
   If earlier branches failed, runs this block when `op=="pop_front"&&!dq.empty()` is true. The one-line action is `dq.pop_front();`.
19. `else if(op=="pop_back"&&!dq.empty())dq.pop_back();`
   If earlier branches failed, runs this block when `op=="pop_back"&&!dq.empty()` is true. The one-line action is `dq.pop_back();`.
20. `return vector<int>(dq.begin(),dq.end());`
   Ends the function and sends `vector<int>(dq.begin(),dq.end())` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- deque: A double-ended queue that can efficiently add or remove elements at both ends.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- empty: Returns true when a container has no elements.
- push_back: Adds one element to the end of a vector or deque.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: ["push_back 2","push_front 1","push_back 3"] -> [1,2,3]
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The deque contents follow each requested front or back operation.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(commands + output).
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
