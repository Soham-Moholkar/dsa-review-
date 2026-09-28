#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> pi(n);
        for(int i=1;i<n;++i){
            int j=pi[i-1];
            while(j&&s[i]!=s[j])j=pi[j-1];
            if(s[i]==s[j])++j;
            pi[i]=j;
        }
        return s.substr(0,pi.back());
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Longest Happy Prefix
Platform: LeetCode
Pattern: Pattern Matching

Learning goal: Understand what the final prefix-function value means even when no separate text search is performed.
This file implements: Prefix function reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`string longestPrefix(string s)`
- `string` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The last prefix-table value is the longest proper prefix that is also a suffix.

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
5. `string longestPrefix(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n=s.size();`
   Creates `n` and initializes it from `s.size()`. This gives the algorithm its starting state.
7. `vector<int> pi(n);`
   Declares `pi` so it can store state used by the algorithm.
8. `for(int i=1;i<n;++i){`
   Starts a loop: first `int i=1`; keep repeating while `i<n` is true; after each iteration perform `++i`.
9. `int j=pi[i-1];`
   Creates `j` and initializes it from `pi[i-1]`. This gives the algorithm its starting state.
10. `while(j&&s[i]!=s[j])j=pi[j-1];`
   Repeats the following block while `j&&s[i]!=s[j]` is true. Its one-line body is `j=pi[j-1];`.
11. `if(s[i]==s[j])++j;`
   Runs the next block only when `s[i]==s[j]` is true. The one-line action is `++j;`.
12. `pi[i]=j;`
   Updates `pi[i]` to `j` for the next step of the algorithm.
13. `return s.substr(0,pi.back());`
   Ends the function and sends `s.substr(0,pi.back())` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- front / back: Accesses the first or last element of a nonempty container.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "level" -> "l"
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The last prefix-table value is the longest proper prefix that is also a suffix.
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
