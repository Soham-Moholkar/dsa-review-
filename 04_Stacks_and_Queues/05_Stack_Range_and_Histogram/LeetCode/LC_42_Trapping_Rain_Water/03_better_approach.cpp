#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)return 0;
        vector<int> left(n),right(n);
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;++i)left[i]=max(left[i-1],height[i]);
        for(int i=n-2;i>=0;--i)right[i]=max(right[i+1],height[i]);
        int total=0;
        for(int i=0;i<n;++i)total+=min(left[i],right[i])-height[i];
        return total;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Trapping Rain Water
Platform: LeetCode
Pattern: Stack Range and Histogram

Learning goal: Compare the stack boundary view with the two-pointer lesson in Arrays/Vectors.
This file implements: Precompute left and right wall maxima.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int trap(vector<int>& height)`
- `int` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The preferred pattern uses this invariant: Popped valleys can hold water only after a left and right wall exist.

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
5. `int trap(vector<int>& height) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n=height.size();`
   Creates `n` and initializes it from `height.size()`. This gives the algorithm its starting state.
7. `if(n==0)return 0;`
   Runs the next block only when `n==0` is true. The one-line action is `return 0;`.
8. `vector<int> left(n),right(n);`
   Declares `left` so it can store state used by the algorithm.
9. `left[0]=height[0];`
   Updates `left[0]` to `height[0]` for the next step of the algorithm.
10. `right[n-1]=height[n-1];`
   Updates `right[n-1]` to `height[n-1]` for the next step of the algorithm.
11. `for(int i=1;i<n;++i)left[i]=max(left[i-1],height[i]);`
   Starts a loop: first `int i=1`; keep repeating while `i<n` is true; after each iteration perform `++i`. Its one-line body is `left[i]=max(left[i-1],height[i]);`.
12. `for(int i=n-2;i>=0;--i)right[i]=max(right[i+1],height[i]);`
   Starts a loop: first `int i=n-2`; keep repeating while `i>=0` is true; after each iteration perform `--i`. Its one-line body is `right[i]=max(right[i+1],height[i]);`.
13. `int total=0;`
   Creates `total` and initializes it from `0`. This gives the algorithm its starting state.
14. `for(int i=0;i<n;++i)total+=min(left[i],right[i])-height[i];`
   Starts a loop: first `int i=0`; keep repeating while `i<n` is true; after each iteration perform `++i`. Its one-line body is `total+=min(left[i],right[i])-height[i];`.
15. `return total;`
   Ends the function and sends `total` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- min / max: Returns the smaller/larger of the supplied values.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: [0,1,0,2,1,0,1,3,2,1,2,1] -> 6
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The preferred pattern uses this invariant: Popped valleys can hold water only after a left and right wall exist.
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
