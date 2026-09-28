#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c:s)++freq[c];
        priority_queue<pair<int,char>> heap;
        for(auto [c,n]:freq)heap.push({
            n,c
        }
        );
        string out;
        while(!heap.empty()){
            auto [n,c]=heap.top();
            heap.pop();
            out.append(n,c);
        }
        return out;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Sort Characters by Frequency
Platform: LeetCode
Pattern: Frequency Counting

Learning goal: Move from merely counting characters to reconstructing output in frequency order.
This file implements: Order frequency groups with a heap.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`string frequencySort(string s)`
- `string` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The preferred pattern uses this invariant: The output is assembled from characters in nonincreasing frequency order.

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
5. `string frequencySort(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `unordered_map<char,int> freq;`
   Declares `freq` so it can store state used by the algorithm.
7. `for(char c:s)++freq[c];`
   Starts a range-based loop. `char c:s` means: take each element from the container in turn and run the block. Its one-line body is `++freq[c];`.
8. `priority_queue<pair<int,char>> heap;`
   Declares `heap` so it can store state used by the algorithm.
9. `for(auto [c,n]:freq)heap.push({`
   Starts a range-based loop. `auto [c,n]:freq` means: take each element from the container in turn and run the block. Its one-line body is `heap.push({`.
10. `n,c`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
12. `string out;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `while(!heap.empty()){`
   Repeats the following block while `!heap.empty()` is true.
14. `auto [n,c]=heap.top();`
   Updates `auto [n,c]` to `heap.top()` for the next step of the algorithm.
15. `heap.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `out.append(n,c);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
17. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- pair: Stores two values together. first names the first value and second names the second value.
- unordered_map: Stores key-value pairs in a hash table, with expected O(1) operations.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- return: Ends the current function and optionally sends a value back to the caller.
- empty: Returns true when a container has no elements.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "tree" -> any valid frequency-sorted result
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The preferred pattern uses this invariant: The output is assembled from characters in nonincreasing frequency order.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n + A log A).
- Extra space: O(A + n).
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
