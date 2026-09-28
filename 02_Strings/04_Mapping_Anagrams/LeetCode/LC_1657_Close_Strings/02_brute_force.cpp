#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        int a[26]={
        }
        ,b[26]={
        }
        ;
        for(char c:word1)++a[c-'a'];
        for(char c:word2)++b[c-'a'];
        for(int i=0;i<26;++i)if((a[i]==0)!=(b[i]==0))return false;
        sort(begin(a),end(a));
        sort(begin(b),end(b));
        return equal(begin(a),end(a),begin(b));
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Determine if Two Strings Are Close
Platform: LeetCode
Pattern: Mapping Anagrams

Learning goal: Separate which characters exist from how often the existing characters occur.
This file implements: Same efficient method (no distinct baseline).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`bool closeStrings(string word1, string word2)`
- `bool` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The two strings use the same characters and the same multiset of frequencies.

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
5. `bool closeStrings(string word1, string word2) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `if(word1.size()!=word2.size()) return false;`
   Runs the next block only when `word1.size()!=word2.size()` is true. The one-line action is `return false;`.
7. `int a[26]={`
   Creates `the variable` and initializes it from `{`. This gives the algorithm its starting state.
8. `,b[26]={`
   Updates `,b[26]` to `{` for the next step of the algorithm.
9. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `for(char c:word1)++a[c-'a'];`
   Starts a range-based loop. `char c:word1` means: take each element from the container in turn and run the block. Its one-line body is `++a[c-'a'];`.
11. `for(char c:word2)++b[c-'a'];`
   Starts a range-based loop. `char c:word2` means: take each element from the container in turn and run the block. Its one-line body is `++b[c-'a'];`.
12. `for(int i=0;i<26;++i)if((a[i]==0)!=(b[i]==0))return false;`
   Starts a loop: first `int i=0`; keep repeating while `i<26` is true; after each iteration perform `++i`. Its one-line body is `if((a[i]==0)!=(b[i]==0))return false;`.
13. `sort(begin(a),end(a));`
   Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible.
14. `sort(begin(b),end(b));`
   Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible.
15. `return equal(begin(a),end(a),begin(b));`
   Ends the function and sends `equal(begin(a),end(a),begin(b))` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- sort: Rearranges a range into ascending order by default. This changes the container.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "abc", "bca" -> true
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The two strings use the same characters and the same multiset of frequencies.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n).
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
