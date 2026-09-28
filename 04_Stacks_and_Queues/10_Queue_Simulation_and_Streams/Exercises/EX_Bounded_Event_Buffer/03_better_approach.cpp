#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> lastEvents(vector<int>& events, int capacity) {
        vector<int> out;
        for(int x:events){
            if(capacity<=0)continue;
            if((int)out.size()==capacity)out.erase(out.begin());
            out.push_back(x);
        }
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Bounded Event Buffer
Platform: Repository exercise
Pattern: Queue Simulation and Streams

Learning goal: Decide which oldest event to evict once fixed capacity is reached.
This file implements: Erase the oldest vector element on overflow.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> lastEvents(vector<int>& events, int capacity)`
- `vector<int>` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The preferred pattern uses this invariant: The buffer contains the last capacity arrivals in their original order.

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
5. `vector<int> lastEvents(vector<int>& events, int capacity) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<int> out;`
   Declares `out` so it can store state used by the algorithm.
7. `for(int x:events){`
   Starts a range-based loop. `int x:events` means: take each element from the container in turn and run the block.
8. `if(capacity<=0)continue;`
   Runs the next block only when `capacity<=0` is true. The one-line action is `continue;`.
9. `if((int)out.size()==capacity)out.erase(out.begin());`
   Runs the next block only when `(int)out.size()==capacity` is true. The one-line action is `out.erase(out.begin());`.
10. `out.push_back(x);`
   Appends the computed value to the end of the result/container.
11. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- continue: Skips the remainder of the current loop iteration and begins the next one.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- erase: Removes an element or position from a container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: [1,2,3,4],2 -> [3,4]
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The preferred pattern uses this invariant: The buffer contains the last capacity arrivals in their original order.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n × capacity).
- Extra space: O(capacity) plus result.
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
