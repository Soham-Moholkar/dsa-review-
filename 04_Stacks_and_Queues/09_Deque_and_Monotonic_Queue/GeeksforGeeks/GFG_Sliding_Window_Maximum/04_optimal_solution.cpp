#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> out;
        for(int i=0;i<(int)nums.size();++i){
            while(!dq.empty()&&dq.front()<=i-k)dq.pop_front();
            while(!dq.empty()&&nums[dq.back()]<=nums[i])dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)out.push_back(nums[dq.front()]);
        }
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Sliding Window Maximum
Platform: GeeksforGeeks
Pattern: Deque and Monotonic Queue

Learning goal: Track the strongest candidate while positions leave the window.
This file implements: Monotonic deque reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> maxSlidingWindow(vector<int>& nums, int k)`
- `vector<int>` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Deque values decrease from front to back and indices stay inside the window.

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
5. `vector<int> maxSlidingWindow(vector<int>& nums, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `deque<int> dq;`
   Declares `dq` so it can store state used by the algorithm.
7. `vector<int> out;`
   Declares `out` so it can store state used by the algorithm.
8. `for(int i=0;i<(int)nums.size();++i){`
   Starts a loop: first `int i=0`; keep repeating while `i<(int)nums.size()` is true; after each iteration perform `++i`.
9. `while(!dq.empty()&&dq.front()<=i-k)dq.pop_front();`
   Repeats the following block while `!dq.empty()&&dq.front()<=i-k` is true. Its one-line body is `dq.pop_front();`.
10. `while(!dq.empty()&&nums[dq.back()]<=nums[i])dq.pop_back();`
   Repeats the following block while `!dq.empty()&&nums[dq.back()]<=nums[i]` is true. Its one-line body is `dq.pop_back();`.
11. `dq.push_back(i);`
   Appends the computed value to the end of the result/container.
12. `if(i>=k-1)out.push_back(nums[dq.front()]);`
   Runs the next block only when `i>=k-1` is true. The one-line action is `out.push_back(nums[dq.front()]);`.
13. `return out;`
   Ends the function and sends `out` back to the caller.

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
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- push_back: Adds one element to the end of a vector or deque.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
- front / back: Accesses the first or last element of a nonempty container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: [1,3,-1,-3,5,3,6,7],3 -> [3,3,5,5,6,7]
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Deque values decrease from front to back and indices stay inside the window.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n).
- Extra space: O(k) plus result.
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
