#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[256]={
        }
        ;
        for(unsigned char c:s) ++cnt[c];
        int expected=0;
        for(int x:cnt) if(x){
            if(expected && x!=expected) return false;
            expected=x;
        }
        return true;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Check if All Characters Have Equal Number of Occurrences
Platform: LeetCode
Pattern: Frequency Counting

Learning goal: Compare only characters that actually occur and avoid treating zero counts as evidence.
This file implements: Same efficient method (no distinct intermediate).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`bool areOccurrencesEqual(string s)`
- `bool` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Every nonzero recorded frequency equals the first nonzero frequency.

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
5. `bool areOccurrencesEqual(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int cnt[256]={`
   Creates `the variable` and initializes it from `{`. This gives the algorithm its starting state.
7. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
8. `for(unsigned char c:s) ++cnt[c];`
   Starts a range-based loop. `unsigned char c:s` means: take each element from the container in turn and run the block. Its one-line body is `++cnt[c];`.
9. `int expected=0;`
   Creates `expected` and initializes it from `0`. This gives the algorithm its starting state.
10. `for(int x:cnt) if(x){`
   Starts a range-based loop. `int x:cnt` means: take each element from the container in turn and run the block. Its one-line body is `if(x){`.
11. `if(expected && x!=expected) return false;`
   Runs the next block only when `expected && x!=expected` is true. The one-line action is `return false;`.
12. `expected=x;`
   Updates `expected` to `x` for the next step of the algorithm.
13. `return true;`
   Ends the function and sends `true` back to the caller.

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
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "abacbc" -> true
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Every nonzero recorded frequency equals the first nonzero frequency.
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
