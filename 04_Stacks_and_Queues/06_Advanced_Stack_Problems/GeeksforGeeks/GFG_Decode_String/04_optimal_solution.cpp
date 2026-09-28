#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        vector<int> count;
        vector<string> previous;
        string part;
        int value=0;
        for(char c:s){
            if(isdigit((unsigned char)c))value=value*10+c-'0';
            else if(c=='['){
                count.push_back(value);
                previous.push_back(part);
                value=0;
                part.clear();
            }
            else if(c==']'){
                string block=part;
                part=previous.back();
                previous.pop_back();
                int n=count.back();
                count.pop_back();
                while(n--)part+=block;
            }
            else part+=c;
        }
        return part;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Decode String
Platform: GeeksforGeeks
Pattern: Advanced Stack Problems

Learning goal: Track nested repetition and restore the enclosing parse context.
This file implements: Nested frames reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`string decodeString(string s)`
- `string` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Each closed bracket restores its previous prefix and repeats its inner block.

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
5. `string decodeString(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<int> count;`
   Declares `count` so it can store state used by the algorithm.
7. `vector<string> previous;`
   Declares `previous` so it can store state used by the algorithm.
8. `string part;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `int value=0;`
   Creates `value` and initializes it from `0`. This gives the algorithm its starting state.
10. `for(char c:s){`
   Starts a range-based loop. `char c:s` means: take each element from the container in turn and run the block.
11. `if(isdigit((unsigned char)c))value=value*10+c-'0';`
   Runs the next block only when `isdigit((unsigned char)c)` is true. The one-line action is `value=value*10+c-'0';`.
12. `else if(c=='['){`
   Defines the judge-facing function and lists the inputs it receives.
13. `count.push_back(value);`
   Appends the computed value to the end of the result/container.
14. `previous.push_back(part);`
   Appends the computed value to the end of the result/container.
15. `value=0;`
   Updates `value` to `0` for the next step of the algorithm.
16. `part.clear();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
17. `else if(c==']'){`
   Defines the judge-facing function and lists the inputs it receives.
18. `string block=part;`
   Updates `string block` to `part` for the next step of the algorithm.
19. `part=previous.back();`
   Updates `part` to `previous.back()` for the next step of the algorithm.
20. `previous.pop_back();`
   Removes the last element from the container.
21. `int n=count.back();`
   Creates `n` and initializes it from `count.back()`. This gives the algorithm its starting state.
22. `count.pop_back();`
   Removes the last element from the container.
23. `while(n--)part+=block;`
   Repeats the following block while `n--` is true. Its one-line body is `part+=block;`.
24. `else part+=c;`
   Handles the remaining case after the preceding condition(s) were false.
25. `return part;`
   Ends the function and sends `part` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- push_back: Adds one element to the end of a vector or deque.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
- front / back: Accesses the first or last element of a nonempty container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "3[a]2[bc]" -> "aaabcbc"
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Each closed bracket restores its previous prefix and repeats its inner block.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(decoded length).
- Extra space: O(decoded length + nesting).
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
