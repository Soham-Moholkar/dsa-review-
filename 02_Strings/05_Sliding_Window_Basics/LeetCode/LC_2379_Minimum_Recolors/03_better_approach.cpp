#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        vector<int> prefix(blocks.size()+1);
        for(int i=0;i<(int)blocks.size();++i)prefix[i+1]=prefix[i]+(blocks[i]=='W');
        int best=k;
        for(int i=k;i<(int)prefix.size();++i)best=min(best,prefix[i]-prefix[i-k]);
        return best;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Minimum Recolors to Get K Consecutive Black Blocks
Platform: LeetCode
Pattern: Sliding Window Basics

Learning goal: Interpret the cost of a candidate substring as the count of characters that must change.
This file implements: Query recolors with prefix counts.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int minimumRecolors(string blocks, int k)`
- `int` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The preferred pattern uses this invariant: The count of white blocks equals the recolors needed for the current window.

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
5. `int minimumRecolors(string blocks, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<int> prefix(blocks.size()+1);`
   Declares `prefix` so it can store state used by the algorithm.
7. `for(int i=0;i<(int)blocks.size();++i)prefix[i+1]=prefix[i]+(blocks[i]=='W');`
   Starts a loop: first `int i=0`; keep repeating while `i<(int)blocks.size()` is true; after each iteration perform `++i`. Its one-line body is `prefix[i+1]=prefix[i]+(blocks[i]=='W');`.
8. `int best=k;`
   Creates `best` and initializes it from `k`. This gives the algorithm its starting state.
9. `for(int i=k;i<(int)prefix.size();++i)best=min(best,prefix[i]-prefix[i-k]);`
   Starts a loop: first `int i=k`; keep repeating while `i<(int)prefix.size()` is true; after each iteration perform `++i`. Its one-line body is `best=min(best,prefix[i]-prefix[i-k]);`.
10. `return best;`
   Ends the function and sends `best` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- min / max: Returns the smaller/larger of the supplied values.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "WBBWWBBWBW", 7 -> 3
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The preferred pattern uses this invariant: The count of white blocks equals the recolors needed for the current window.
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
