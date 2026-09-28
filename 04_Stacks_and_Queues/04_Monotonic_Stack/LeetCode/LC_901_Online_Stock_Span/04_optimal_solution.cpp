#include <bits/stdc++.h>
using namespace std;
class StockSpanner {
    vector<pair<int,int>> st;
public:
    StockSpanner()=default;
    int next(int price){
        int span=1;
        while(!st.empty()&&st.back().first<=price){
            span+=st.back().second;
            st.pop_back();
        }
        st.push_back({
            price,span
        }
        );
        return span;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Online Stock Span
Platform: LeetCode
Pattern: Monotonic Stack

Learning goal: Reuse boundary reasoning when prices arrive one by one.
This file implements: Previous greater reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`class StockSpanner { public: StockSpanner(); int next(int price); };`
- This is a design class. Its declared public methods form the local exercise interface.
- The judge calls each operation separately; use the problem README for empty/capacity behavior.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Each stored price carries the number of earlier days it already spans.

Read these executable lines in their actual order. Nested indentation shows when
an action belongs to a class, method, branch, loop, or lambda:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class StockSpanner {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
4. `vector<pair<int,int>> st;`
   Declares `st` so it can store state used by the algorithm.
5. `public:`
   Makes the following method callable by the judge.
6. `StockSpanner()=default;`
   Updates `StockSpanner()` to `default` for the next step of the algorithm.
7. `int next(int price){`
   Defines the judge-facing function and lists the inputs it receives.
8. `int span=1;`
   Creates `span` and initializes it from `1`. This gives the algorithm its starting state.
9. `while(!st.empty()&&st.back().first<=price){`
   Repeats the following block while `!st.empty()&&st.back().first<=price` is true.
10. `span+=st.back().second;`
   Updates the stored state using its previous value and the expression on the right.
11. `st.pop_back();`
   Removes the last element from the container.
12. `st.push_back({`
   Appends the computed value to the end of the result/container.
13. `price,span`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
15. `return span;`
   Ends the function and sends `span` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- pair: Stores two values together. first names the first value and second names the second value.
- while: Repeats a block while its condition remains true.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- empty: Returns true when a container has no elements.
- push_back: Adds one element to the end of a vector or deque.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
- front / back: Accesses the first or last element of a nonempty container.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: next(100),next(80),next(60),next(70),next(60),next(75),next(85) -> 1,1,1,2,1,4,6
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Each stored price carries the number of earlier days it already spans.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(1) amortized per price.
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
