#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        for(int i=0;i<(int)tickets.size();++i)q.push({
            i,tickets[i]
        }
        );
        int time=0;
        while(!q.empty()){
            auto [index,count]=q.front();
            q.pop();
            ++time;
            if(--count==0){
                if(index==k)return time;
            }
            else q.push({
                index,count
            }
            );
        }
        return time;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Time Needed to Buy Tickets
Platform: LeetCode
Pattern: Queue Fundamentals

Learning goal: Model repeated fair turns without changing the identity of the target person.
This file implements: Simulate every ticket turn in a queue.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int timeRequiredToBuy(vector<int>& tickets, int k)`
- `int` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The preferred pattern uses this invariant: One FIFO turn serves one ticket and preserves everybody else’s order.

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
5. `int timeRequiredToBuy(vector<int>& tickets, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `queue<pair<int,int>> q;`
   Declares `q` so it can store state used by the algorithm.
7. `for(int i=0;i<(int)tickets.size();++i)q.push({`
   Starts a loop: first `int i=0`; keep repeating while `i<(int)tickets.size()` is true; after each iteration perform `++i`. Its one-line body is `q.push({`.
8. `i,tickets[i]`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `int time=0;`
   Creates `time` and initializes it from `0`. This gives the algorithm its starting state.
11. `while(!q.empty()){`
   Repeats the following block while `!q.empty()` is true.
12. `auto [index,count]=q.front();`
   Updates `auto [index,count]` to `q.front()` for the next step of the algorithm.
13. `q.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `++time;`
   Moves the relevant counter or pointer by one position.
15. `if(--count==0){`
   Runs the next block only when `--count==0` is true.
16. `if(index==k)return time;`
   Runs the next block only when `index==k` is true. The one-line action is `return time;`.
17. `else q.push({`
   Handles the remaining case after the preceding condition(s) were false.
18. `index,count`
   Performs this operation to maintain the state described in the algorithm walkthrough.
19. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
20. `return time;`
   Ends the function and sends `time` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- pair: Stores two values together. first names the first value and second names the second value.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- front / back: Accesses the first or last element of a nonempty container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: [2,3,2],2 -> 6
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The preferred pattern uses this invariant: One FIFO turn serves one ticket and preserves everybody else’s order.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(total ticket turns).
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
