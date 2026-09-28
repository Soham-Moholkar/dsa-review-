#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> lo,hi;
        int left=0,best=0;
        for(int right=0;right<(int)nums.size();++right){
            while(!lo.empty()&&nums[lo.back()]>=nums[right])lo.pop_back();
            while(!hi.empty()&&nums[hi.back()]<=nums[right])hi.pop_back();
            lo.push_back(right);
            hi.push_back(right);
            while((long long)nums[hi.front()]-nums[lo.front()]>limit){
                if(lo.front()==left)lo.pop_front();
                if(hi.front()==left)hi.pop_front();
                ++left;
            }
            best=max(best,right-left+1);
        }
        return best;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
Platform: LeetCode
Pattern: Deque and Monotonic Queue

Learning goal: Maintain both extremes as a variable window changes.
This file implements: Two monotonic deques reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int longestSubarray(vector<int>& nums, int limit)`
- `int` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Two deques track the current minimum and maximum of the live window.

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
5. `int longestSubarray(vector<int>& nums, int limit) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `deque<int> lo,hi;`
   Declares `hi` so it can store state used by the algorithm.
7. `int left=0,best=0;`
   Creates `left` and initializes it from `0,best=0`. This gives the algorithm its starting state.
8. `for(int right=0;right<(int)nums.size();++right){`
   Starts a loop: first `int right=0`; keep repeating while `right<(int)nums.size()` is true; after each iteration perform `++right`.
9. `while(!lo.empty()&&nums[lo.back()]>=nums[right])lo.pop_back();`
   Repeats the following block while `!lo.empty()&&nums[lo.back()]>=nums[right]` is true. Its one-line body is `lo.pop_back();`.
10. `while(!hi.empty()&&nums[hi.back()]<=nums[right])hi.pop_back();`
   Repeats the following block while `!hi.empty()&&nums[hi.back()]<=nums[right]` is true. Its one-line body is `hi.pop_back();`.
11. `lo.push_back(right);`
   Appends the computed value to the end of the result/container.
12. `hi.push_back(right);`
   Appends the computed value to the end of the result/container.
13. `while((long long)nums[hi.front()]-nums[lo.front()]>limit){`
   Repeats the following block while `(long long)nums[hi.front()]-nums[lo.front()]>limit` is true.
14. `if(lo.front()==left)lo.pop_front();`
   Runs the next block only when `lo.front()==left` is true. The one-line action is `lo.pop_front();`.
15. `if(hi.front()==left)hi.pop_front();`
   Runs the next block only when `hi.front()==left` is true. The one-line action is `hi.pop_front();`.
16. `++left;`
   Moves the relevant counter or pointer by one position.
17. `best=max(best,right-left+1);`
   Updates `best` to `max(best,right-left+1)` for the next step of the algorithm.
18. `return best;`
   Ends the function and sends `best` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- long long: A wider signed whole-number type, commonly 64 bits; it is used when an int may be too small.
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
- min / max: Returns the smaller/larger of the supplied values.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: [8,2,4,7],4 -> 2
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Two deques track the current minimum and maximum of the live window.
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
