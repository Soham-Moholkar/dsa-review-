#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        string out;
        int i=(int)num1.size()-1,j=(int)num2.size()-1,carry=0;
        while(i>=0||j>=0||carry){
            int sum=carry+(i>=0?num1[i--]-'0':0)+(j>=0?num2[j--]-'0':0);
            out+=char('0'+sum%10);
            carry=sum/10;
        }
        reverse(out.begin(),out.end());
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Add Strings
Platform: LeetCode
Pattern: Parsing Conversion

Learning goal: Simulate column addition without converting the entire inputs to built-in numeric types.
This file implements: Digit simulation reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`string addStrings(string num1, string num2)`
- `string` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Every produced digit equals the column sum modulo ten; carry moves left.

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
5. `string addStrings(string num1, string num2) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `string out;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
7. `int i=(int)num1.size()-1,j=(int)num2.size()-1,carry=0;`
   Creates `i` and initializes it from `(int)num1.size()-1,j=(int)num2.size()-1,carry=0`. This gives the algorithm its starting state.
8. `while(i>=0||j>=0||carry){`
   Repeats the following block while `i>=0||j>=0||carry` is true.
9. `int sum=carry+(i>=0?num1[i--]-'0':0)+(j>=0?num2[j--]-'0':0);`
   Creates `sum` and initializes it from `carry+(i>=0?num1[i--]-'0':0)+(j>=0?num2[j--]-'0':0)`. This gives the algorithm its starting state.
10. `out+=char('0'+sum%10);`
   Updates the stored state using its previous value and the expression on the right.
11. `carry=sum/10;`
   Updates `carry` to `sum/10` for the next step of the algorithm.
12. `reverse(out.begin(),out.end());`
   Reverses the selected range in place. The second iterator is one position past the range.
13. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- while: Repeats a block while its condition remains true.
- return: Ends the current function and optionally sends a value back to the caller.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- reverse: Reverses the order of elements in the selected iterator range.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.
- %: Remainder operator. a % b gives the remainder after integer division by b.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "11", "123" -> "134"
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Every produced digit equals the column sum modulo ten; carry moves left.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(max(n,m)).
- Extra space: O(max(n,m)).
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
