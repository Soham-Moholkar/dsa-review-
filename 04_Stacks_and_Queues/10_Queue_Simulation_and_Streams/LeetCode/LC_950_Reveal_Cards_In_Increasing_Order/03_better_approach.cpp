#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        deque<int> slots;
        for(int i=0;i<(int)deck.size();++i)slots.push_back(i);
        vector<int> answer(deck.size());
        for(int x:deck){
            answer[slots.front()]=x;
            slots.pop_front();
            if(!slots.empty()){
                slots.push_back(slots.front());
                slots.pop_front();
            }
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Reveal Cards In Increasing Order
Platform: LeetCode
Pattern: Queue Simulation and Streams

Learning goal: Map a prescribed FIFO reveal process back to starting positions.
This file implements: Track unfilled slots in a deque.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> deckRevealedIncreasing(vector<int>& deck)`
- `vector<int>` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The preferred pattern uses this invariant: The queue contains positions not yet assigned a reveal value.

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
5. `vector<int> deckRevealedIncreasing(vector<int>& deck) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `sort(deck.begin(),deck.end());`
   Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible.
7. `deque<int> slots;`
   Declares `slots` so it can store state used by the algorithm.
8. `for(int i=0;i<(int)deck.size();++i)slots.push_back(i);`
   Starts a loop: first `int i=0`; keep repeating while `i<(int)deck.size()` is true; after each iteration perform `++i`. Its one-line body is `slots.push_back(i);`.
9. `vector<int> answer(deck.size());`
   Declares `answer` so it can store state used by the algorithm.
10. `for(int x:deck){`
   Starts a range-based loop. `int x:deck` means: take each element from the container in turn and run the block.
11. `answer[slots.front()]=x;`
   Updates `answer[slots.front()]` to `x` for the next step of the algorithm.
12. `slots.pop_front();`
   Removes the oldest element from the front of the deque after it becomes irrelevant.
13. `if(!slots.empty()){`
   Runs the next block only when `!slots.empty()` is true.
14. `slots.push_back(slots.front());`
   Appends the computed value to the end of the result/container.
15. `slots.pop_front();`
   Removes the oldest element from the front of the deque after it becomes irrelevant.
16. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- deque: A double-ended queue that can efficiently add or remove elements at both ends.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- push_back: Adds one element to the end of a vector or deque.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
- front / back: Accesses the first or last element of a nonempty container.
- sort: Rearranges a range into ascending order by default. This changes the container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: [17,13,11,2,3,5,7] -> [2,13,3,11,5,17,7]
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The preferred pattern uses this invariant: The queue contains positions not yet assigned a reveal value.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n log n).
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
