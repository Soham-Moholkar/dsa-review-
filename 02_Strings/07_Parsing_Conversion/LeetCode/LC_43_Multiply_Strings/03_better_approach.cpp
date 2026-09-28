#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";
        vector<int> v(num1.size()+num2.size());
        for(int i=(int)num1.size()-1;i>=0;--i)for(int j=(int)num2.size()-1;j>=0;--j){
            int k=i+j+1;
            int sum=(num1[i]-'0')*(num2[j]-'0')+v[k];
            v[k]=sum%10;
            v[k-1]+=sum/10;
        }
        string out;
        int i=0;
        while(i<(int)v.size()&&v[i]==0)++i;
        for(;i<(int)v.size();++i)out+=char('0'+v[i]);
        return out.empty()?"0":out;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Multiply Strings
Platform: LeetCode
Pattern: Parsing Conversion

Learning goal: Translate grade-school multiplication into indexed accumulation while handling leading zeroes.
This file implements: Same efficient method (no distinct intermediate).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`string multiply(string num1, string num2)`
- `string` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Digit positions accumulate the products of their matching place values.

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
5. `string multiply(string num1, string num2) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `if(num1=="0"||num2=="0")return "0";`
   Runs the next block only when `num1=="0"||num2=="0"` is true. The one-line action is `return "0";`.
7. `vector<int> v(num1.size()+num2.size());`
   Declares `v` so it can store state used by the algorithm.
8. `for(int i=(int)num1.size()-1;i>=0;--i)for(int j=(int)num2.size()-1;j>=0;--j){`
   Starts a loop: first `int i=(int)num1.size()-1`; keep repeating while `i>=0` is true; after each iteration perform `--i`. Its one-line body is `for(int j=(int)num2.size()-1;j>=0;--j){`.
9. `int k=i+j+1;`
   Creates `k` and initializes it from `i+j+1`. This gives the algorithm its starting state.
10. `int sum=(num1[i]-'0')*(num2[j]-'0')+v[k];`
   Creates `sum` and initializes it from `(num1[i]-'0')*(num2[j]-'0')+v[k]`. This gives the algorithm its starting state.
11. `v[k]=sum%10;`
   Updates `v[k]` to `sum%10` for the next step of the algorithm.
12. `v[k-1]+=sum/10;`
   Updates the stored state using its previous value and the expression on the right.
13. `string out;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `int i=0;`
   Creates `i` and initializes it from `0`. This gives the algorithm its starting state.
15. `while(i<(int)v.size()&&v[i]==0)++i;`
   Repeats the following block while `i<(int)v.size()&&v[i]==0` is true. Its one-line body is `++i;`.
16. `for(;i<(int)v.size();++i)out+=char('0'+v[i]);`
   Starts a loop: first ``; keep repeating while `i<(int)v.size()` is true; after each iteration perform `++i`. Its one-line body is `out+=char('0'+v[i]);`.
17. `return out.empty()?"0":out;`
   Ends the function and sends `out.empty()?"0":out` back to the caller.

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
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.
- %: Remainder operator. a % b gives the remainder after integer division by b.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "2", "3" -> "6"
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Digit positions accumulate the products of their matching place values.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(nm).
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
