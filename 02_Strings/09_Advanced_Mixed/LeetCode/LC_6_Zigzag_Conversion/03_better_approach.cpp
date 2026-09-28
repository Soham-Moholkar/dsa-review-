#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1||numRows>=(int)s.size())return s;
        vector<string> rows(numRows);
        int row=0,step=1;
        for(char c:s){
            rows[row]+=c;
            if(row==0)step=1;
            else if(row==numRows-1)step=-1;
            row+=step;
        }
        string out;
        for(auto& part:rows)out+=part;
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Zigzag Conversion
Platform: LeetCode
Pattern: Advanced Mixed

Learning goal: Model the row movement cleanly and handle the single-row case before simulating.
This file implements: Same efficient method (no distinct intermediate).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`string convert(string s, int numRows)`
- `string` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The output rows contain the characters already assigned by zigzag position.

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
5. `string convert(string s, int numRows) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `if(numRows==1||numRows>=(int)s.size())return s;`
   Runs the next block only when `numRows==1||numRows>=(int)s.size()` is true. The one-line action is `return s;`.
7. `vector<string> rows(numRows);`
   Declares `rows` so it can store state used by the algorithm.
8. `int row=0,step=1;`
   Creates `row` and initializes it from `0,step=1`. This gives the algorithm its starting state.
9. `for(char c:s){`
   Starts a range-based loop. `char c:s` means: take each element from the container in turn and run the block.
10. `rows[row]+=c;`
   Updates the stored state using its previous value and the expression on the right.
11. `if(row==0)step=1;`
   Runs the next block only when `row==0` is true. The one-line action is `step=1;`.
12. `else if(row==numRows-1)step=-1;`
   If earlier branches failed, runs this block when `row==numRows-1` is true. The one-line action is `step=-1;`.
13. `row+=step;`
   Updates the stored state using its previous value and the expression on the right.
14. `string out;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
15. `for(auto& part:rows)out+=part;`
   Starts a range-based loop. `auto& part:rows` means: take each element from the container in turn and run the block. Its one-line body is `out+=part;`.
16. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "PAYPALISHIRING", 3 -> "PAHNAPLSIIGYIR"
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The output rows contain the characters already assigned by zigzag position.
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
