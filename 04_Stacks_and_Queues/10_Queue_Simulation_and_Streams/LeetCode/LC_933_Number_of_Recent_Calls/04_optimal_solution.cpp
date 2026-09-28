#include <bits/stdc++.h>
using namespace std;
class RecentCounter {
    queue<int> q;
public:
    RecentCounter()=default;
    int ping(int t){
        q.push(t);
        while(q.front()<t-3000)q.pop();
        return q.size();
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Number of Recent Calls
Platform: LeetCode
Pattern: Queue Simulation and Streams

Learning goal: Keep only arrivals inside a moving time interval.
This file implements: Time window reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`class RecentCounter { public: RecentCounter(); int ping(int t); };`
- This is a design class. Its declared public methods form the local exercise interface.
- The judge calls each operation separately; use the problem README for empty/capacity behavior.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Every queued timestamp is inside the inclusive recent-call interval.

Read these executable lines in their actual order. Nested indentation shows when
an action belongs to a class, method, branch, loop, or lambda:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class RecentCounter {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
4. `queue<int> q;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
5. `public:`
   Makes the following method callable by the judge.
6. `RecentCounter()=default;`
   Updates `RecentCounter()` to `default` for the next step of the algorithm.
7. `int ping(int t){`
   Defines the judge-facing function and lists the inputs it receives.
8. `q.push(t);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `while(q.front()<t-3000)q.pop();`
   Repeats the following block while `q.front()<t-3000` is true. Its one-line body is `q.pop();`.
10. `return q.size();`
   Ends the function and sends `q.size()` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- while: Repeats a block while its condition remains true.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- front / back: Accesses the first or last element of a nonempty container.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: ping(1),ping(100),ping(3001),ping(3002) -> 1,2,3,3
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Every queued timestamp is inside the inclusive recent-call interval.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(1) amortized per ping.
- Extra space: O(window).
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
