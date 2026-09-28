#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        for(auto& s:strs){
            string key=s;
            sort(key.begin(),key.end());
            bool found=false;
            for(auto& group:groups){
                string other=group[0];
                sort(other.begin(),other.end());
                if(other==key){
                    group.push_back(s);
                    found=true;
                    break;
                }
            }
            if(!found)groups.push_back({
                s
            }
            );
        }
        return groups;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Group Anagrams
Platform: GeeksforGeeks
Pattern: Mapping Anagrams

Learning goal: Create the same reliable key for every member of an anagram group.
This file implements: Scan the existing groups for each word.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<vector<string>> groupAnagrams(vector<string>& strs)`
- `vector<vector<string>>` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The preferred pattern uses this invariant: Words in the same group share the same canonical sorted-character key.

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
5. `vector<vector<string>> groupAnagrams(vector<string>& strs) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<vector<string>> groups;`
   Declares `groups` so it can store state used by the algorithm.
7. `for(auto& s:strs){`
   Starts a range-based loop. `auto& s:strs` means: take each element from the container in turn and run the block.
8. `string key=s;`
   Updates `string key` to `s` for the next step of the algorithm.
9. `sort(key.begin(),key.end());`
   Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible.
10. `bool found=false;`
   Creates `found` and initializes it from `false`. This gives the algorithm its starting state.
11. `for(auto& group:groups){`
   Starts a range-based loop. `auto& group:groups` means: take each element from the container in turn and run the block.
12. `string other=group[0];`
   Updates `string other` to `group[0]` for the next step of the algorithm.
13. `sort(other.begin(),other.end());`
   Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible.
14. `if(other==key){`
   Runs the next block only when `other==key` is true.
15. `group.push_back(s);`
   Appends the computed value to the end of the result/container.
16. `found=true;`
   Updates `found` to `true` for the next step of the algorithm.
17. `break;`
   Stops the nearest loop immediately because no more iterations are needed.
18. `if(!found)groups.push_back({`
   Runs the next block only when `!found` is true. The one-line action is `groups.push_back({`.
19. `s`
   Performs this operation to maintain the state described in the algorithm walkthrough.
20. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
21. `return groups;`
   Ends the function and sends `groups` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- break: Immediately exits the nearest loop.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- push_back: Adds one element to the end of a vector or deque.
- sort: Rearranges a range into ascending order by default. This changes the container.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: ["eat","tea","tan","ate","nat","bat"] -> groups by anagram
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The preferred pattern uses this invariant: Words in the same group share the same canonical sorted-character key.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(w² L log L).
- Extra space: O(w L).
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
