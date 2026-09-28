#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        auto pal=[](string a){
            string b=a;
            reverse(b.begin(),b.end());
            return a==b;
        }
        ;
        if(pal(s))return true;
        for(int i=0;i<(int)s.size();++i)if(pal(s.substr(0,i)+s.substr(i+1)))return true;
        return false;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Valid Palindrome II
Platform: LeetCode
Pattern: Two Pointers Palindrome

Learning goal: Branch only at the first mismatch and test the two meaningful remaining ranges.
This file implements: Try every possible deletion.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`bool validPalindrome(string s)`
- `bool` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The preferred pattern uses this invariant: After the first mismatch, only one of the two skipped ranges may be a palindrome.

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
5. `bool validPalindrome(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `auto pal=[](string a){`
   Creates `pal` and initializes it from `[](string a){`. This gives the algorithm its starting state.
7. `string b=a;`
   Updates `string b` to `a` for the next step of the algorithm.
8. `reverse(b.begin(),b.end());`
   Reverses the selected range in place. The second iterator is one position past the range.
9. `return a==b;`
   Ends the function and sends `a==b` back to the caller.
10. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `if(pal(s))return true;`
   Runs the next block only when `pal(s)` is true. The one-line action is `return true;`.
12. `for(int i=0;i<(int)s.size();++i)if(pal(s.substr(0,i)+s.substr(i+1)))return true;`
   Starts a loop: first `int i=0`; keep repeating while `i<(int)s.size()` is true; after each iteration perform `++i`. Its one-line body is `if(pal(s.substr(0,i)+s.substr(i+1)))return true;`.
13. `return false;`
   Ends the function and sends `false` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- raw array ([]): In a function parameter, this is passed as a pointer to the first element; the separate length tells the code how many elements are valid.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- reverse: Reverses the order of elements in the selected iterator range.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "aba" -> true
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The preferred pattern uses this invariant: After the first mismatch, only one of the two skipped ranges may be a palindrome.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n²).
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
