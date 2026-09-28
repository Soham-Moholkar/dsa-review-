#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int repeat=(b.size()+a.size()-1)/a.size();
        string built;
        for(int i=0;i<repeat;++i)built+=a;
        if(built.find(b)!=string::npos)return repeat;
        built+=a;
        return built.find(b)!=string::npos?repeat+1:-1;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Repeated String Match
Platform: LeetCode
Pattern: Advanced Mixed

Learning goal: Prove how many repeats are sufficient to test when the match may cross a repetition boundary.
This file implements: Repeated construction reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int repeatedStringMatch(string a, string b)`
- `int` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The built string contains exactly the current number of copies of a.

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
5. `int repeatedStringMatch(string a, string b) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int repeat=(b.size()+a.size()-1)/a.size();`
   Creates `repeat` and initializes it from `(b.size()+a.size()-1)/a.size()`. This gives the algorithm its starting state.
7. `string built;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
8. `for(int i=0;i<repeat;++i)built+=a;`
   Starts a loop: first `int i=0`; keep repeating while `i<repeat` is true; after each iteration perform `++i`. Its one-line body is `built+=a;`.
9. `if(built.find(b)!=string::npos)return repeat;`
   Runs the next block only when `built.find(b)!=string::npos` is true. The one-line action is `return repeat;`.
10. `built+=a;`
   Updates the stored state using its previous value and the expression on the right.
11. `return built.find(b)!=string::npos?repeat+1:-1;`
   Ends the function and sends `built.find(b)!=string::npos?repeat+1:-1` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- find: Searches for a value/key. A failed standard-container search returns end(). For vectors, the algorithm form find(begin, end, value) performs a linear scan.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "abcd", "cdabcdab" -> 3
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The built string contains exactly the current number of copies of a.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O((n + m)m) worst case.
- Extra space: O(n + m).
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
