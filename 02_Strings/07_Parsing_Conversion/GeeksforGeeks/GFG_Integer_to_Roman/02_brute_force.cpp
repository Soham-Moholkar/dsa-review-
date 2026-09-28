#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> units{
            {
                1000,"M"
            }
            ,{
                900,"CM"
            }
            ,{
                500,"D"
            }
            ,{
                400,"CD"
            }
            ,{
                100,"C"
            }
            ,{
                90,"XC"
            }
            ,{
                50,"L"
            }
            ,{
                40,"XL"
            }
            ,{
                10,"X"
            }
            ,{
                9,"IX"
            }
            ,{
                5,"V"
            }
            ,{
                4,"IV"
            }
            ,{
                1,"I"
            }
        }
        ;
        string ans;
        for(auto& [v,s]:units)while(num>=v){
            ans+=s;
            num-=v;
        }
        return ans;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Integer to Roman
Platform: GeeksforGeeks
Pattern: Parsing Conversion

Learning goal: Choose the largest legal symbol repeatedly, including subtractive pairs as first-class entries.
This file implements: Same efficient method (no distinct baseline).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`string intToRoman(int num)`
- `string` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: After each symbol is chosen, num is the unrepresented remainder.

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
5. `string intToRoman(int num) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<pair<int,string>> units{`
   Declares `units` so it can store state used by the algorithm.
7. `1000,"M"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
8. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `900,"CM"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `500,"D"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
12. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `400,"CD"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
15. `100,"C"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
17. `90,"XC"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
18. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
19. `50,"L"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
20. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
21. `40,"XL"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
22. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
23. `10,"X"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
24. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
25. `9,"IX"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
26. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
27. `5,"V"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
28. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
29. `4,"IV"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
30. `,{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
31. `1,"I"`
   Performs this operation to maintain the state described in the algorithm walkthrough.
32. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
33. `string ans;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
34. `for(auto& [v,s]:units)while(num>=v){`
   Starts a range-based loop. `auto& [v,s]:units` means: take each element from the container in turn and run the block. Its one-line body is `while(num>=v){`.
35. `ans+=s;`
   Updates the stored state using its previous value and the expression on the right.
36. `num-=v;`
   Updates the stored state using its previous value and the expression on the right.
37. `return ans;`
   Ends the function and sends `ans` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- pair: Stores two values together. first names the first value and second names the second value.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: 3749 -> "MMMDCCXLIX"
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: After each symbol is chosen, num is the unrepresented remainder.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(output length).
- Extra space: O(output length).
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
