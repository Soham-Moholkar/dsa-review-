#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        vector<int> ans;
        if(pat.empty())return ans;
        vector<int> pi(pat.size());
        for(int i=1;i<(int)pat.size();++i){
            int j=pi[i-1];
            while(j&&pat[i]!=pat[j])j=pi[j-1];
            if(pat[i]==pat[j])++j;
            pi[i]=j;
        }
        int j=0;
        for(int i=0;i<(int)txt.size();++i){
            while(j&&txt[i]!=pat[j])j=pi[j-1];
            if(txt[i]==pat[j])++j;
            if(j==(int)pat.size()){
                ans.push_back(i-j+1);
                j=pi[j-1];
            }
        }
        return ans;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Search Pattern (KMP Algorithm)
Platform: GeeksforGeeks
Pattern: Pattern Matching

Learning goal: Build the prefix table and reuse matched information instead of restarting after a mismatch.
This file implements: Same efficient method (no distinct intermediate).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> search(string &pat, string &txt)`
- `vector<int>` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The prefix table stores the longest proper border of each processed prefix.

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
5. `vector<int> search(string &pat, string &txt) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<int> ans;`
   Declares `ans` so it can store state used by the algorithm.
7. `if(pat.empty())return ans;`
   Runs the next block only when `pat.empty()` is true. The one-line action is `return ans;`.
8. `vector<int> pi(pat.size());`
   Declares `pi` so it can store state used by the algorithm.
9. `for(int i=1;i<(int)pat.size();++i){`
   Starts a loop: first `int i=1`; keep repeating while `i<(int)pat.size()` is true; after each iteration perform `++i`.
10. `int j=pi[i-1];`
   Creates `j` and initializes it from `pi[i-1]`. This gives the algorithm its starting state.
11. `while(j&&pat[i]!=pat[j])j=pi[j-1];`
   Repeats the following block while `j&&pat[i]!=pat[j]` is true. Its one-line body is `j=pi[j-1];`.
12. `if(pat[i]==pat[j])++j;`
   Runs the next block only when `pat[i]==pat[j]` is true. The one-line action is `++j;`.
13. `pi[i]=j;`
   Updates `pi[i]` to `j` for the next step of the algorithm.
14. `int j=0;`
   Creates `j` and initializes it from `0`. This gives the algorithm its starting state.
15. `for(int i=0;i<(int)txt.size();++i){`
   Starts a loop: first `int i=0`; keep repeating while `i<(int)txt.size()` is true; after each iteration perform `++i`.
16. `while(j&&txt[i]!=pat[j])j=pi[j-1];`
   Repeats the following block while `j&&txt[i]!=pat[j]` is true. Its one-line body is `j=pi[j-1];`.
17. `if(txt[i]==pat[j])++j;`
   Runs the next block only when `txt[i]==pat[j]` is true. The one-line action is `++j;`.
18. `if(j==(int)pat.size()){`
   Runs the next block only when `j==(int)pat.size()` is true.
19. `ans.push_back(i-j+1);`
   Appends the computed value to the end of the result/container.
20. `j=pi[j-1];`
   Updates `j` to `pi[j-1]` for the next step of the algorithm.
21. `return ans;`
   Ends the function and sends `ans` back to the caller.

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
- empty: Returns true when a container has no elements.
- push_back: Adds one element to the end of a vector or deque.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: txt="abcab", pat="ab" -> [0,3] (confirm platform index convention)
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The prefix table stores the longest proper border of each processed prefix.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n + m).
- Extra space: O(m) plus result.
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
