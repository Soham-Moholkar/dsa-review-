#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        for(int i=0;i+k<=(int)s.size();++i){
            int count=0;
            for(int j=i;j<i+k;++j)count+=string("aeiou").find(s[j])!=string::npos;
            ans=max(ans,count);
        }
        return ans;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Maximum Number of Vowels in a Substring of Given Length
Platform: LeetCode
Pattern: Sliding Window Basics

Learning goal: Update one window statistic in constant time as the window slides.
This file implements: Recount every fixed window.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int maxVowels(string s, int k)`
- `int` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The preferred pattern uses this invariant: The running count covers exactly the current k-character window.

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
5. `int maxVowels(string s, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int ans=0;`
   Creates `ans` and initializes it from `0`. This gives the algorithm its starting state.
7. `for(int i=0;i+k<=(int)s.size();++i){`
   Starts a loop: first `int i=0`; keep repeating while `i+k<=(int)s.size()` is true; after each iteration perform `++i`.
8. `int count=0;`
   Creates `count` and initializes it from `0`. This gives the algorithm its starting state.
9. `for(int j=i;j<i+k;++j)count+=string("aeiou").find(s[j])!=string::npos;`
   Starts a loop: first `int j=i`; keep repeating while `j<i+k` is true; after each iteration perform `++j`. Its one-line body is `count+=string("aeiou").find(s[j])!=string::npos;`.
10. `ans=max(ans,count);`
   Updates `ans` to `max(ans,count)` for the next step of the algorithm.
11. `return ans;`
   Ends the function and sends `ans` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- find: Searches for a value/key. A failed standard-container search returns end(). For vectors, the algorithm form find(begin, end, value) performs a linear scan.
- min / max: Returns the smaller/larger of the supplied values.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "abciiidef", 3 -> 3
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The preferred pattern uses this invariant: The running count covers exactly the current k-character window.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(nk).
- Extra space: O(1).
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
