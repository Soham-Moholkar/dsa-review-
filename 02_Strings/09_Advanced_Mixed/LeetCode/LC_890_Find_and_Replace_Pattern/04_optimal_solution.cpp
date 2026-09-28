#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        auto match=[&](const string& a){
            if(a.size()!=pattern.size())return false;
            int f[256],g[256];
            fill(begin(f),end(f),-1);
            fill(begin(g),end(g),-1);
            for(int i=0;i<(int)a.size();++i){
                unsigned char x=a[i],y=pattern[i];
                if((f[x]!=-1&&f[x]!=y)||(g[y]!=-1&&g[y]!=x))return false;
                f[x]=y;
                g[y]=x;
            }
            return true;
        }
        ;
        vector<string> out;
        for(auto& w:words)if(match(w))out.push_back(w);
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Find and Replace Pattern
Platform: LeetCode
Pattern: Advanced Mixed

Learning goal: Reuse bidirectional/canonical mapping across a list of candidate words.
This file implements: Canonical mapping reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<string> findAndReplacePattern(vector<string>& words, string pattern)`
- `vector<string>` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Processed word characters obey a consistent mapping in both directions.

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
5. `vector<string> findAndReplacePattern(vector<string>& words, string pattern) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `auto match=[&](const string& a){`
   Creates `match` and initializes it from `[&](const string& a){`. This gives the algorithm its starting state.
7. `if(a.size()!=pattern.size())return false;`
   Runs the next block only when `a.size()!=pattern.size()` is true. The one-line action is `return false;`.
8. `int f[256],g[256];`
   Declares `the variable` so it can store state used by the algorithm.
9. `fill(begin(f),end(f),-1);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `fill(begin(g),end(g),-1);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `for(int i=0;i<(int)a.size();++i){`
   Starts a loop: first `int i=0`; keep repeating while `i<(int)a.size()` is true; after each iteration perform `++i`.
12. `unsigned char x=a[i],y=pattern[i];`
   Updates `unsigned char x` to `a[i],y=pattern[i]` for the next step of the algorithm.
13. `if((f[x]!=-1&&f[x]!=y)||(g[y]!=-1&&g[y]!=x))return false;`
   Runs the next block only when `(f[x]!=-1&&f[x]!=y)||(g[y]!=-1&&g[y]!=x)` is true. The one-line action is `return false;`.
14. `f[x]=y;`
   Updates `f[x]` to `y` for the next step of the algorithm.
15. `g[y]=x;`
   Updates `g[y]` to `x` for the next step of the algorithm.
16. `return true;`
   Ends the function and sends `true` back to the caller.
17. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
18. `vector<string> out;`
   Declares `out` so it can store state used by the algorithm.
19. `for(auto& w:words)if(match(w))out.push_back(w);`
   Starts a range-based loop. `auto& w:words` means: take each element from the container in turn and run the block. Its one-line body is `if(match(w))out.push_back(w);`.
20. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- true / false: The two boolean values.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- const: Promises that the named value will not be changed through that declaration.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- lambda ([&]): Creates an unnamed function. [&] captures surrounding local variables by reference, so the lambda can read and modify them.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: ["abc","deq","mee","aqq","dkd","ccc"], "abb" -> ["mee","aqq"]
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Processed word characters obey a consistent mapping in both directions.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(total characters).
- Extra space: O(1) plus result.
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
