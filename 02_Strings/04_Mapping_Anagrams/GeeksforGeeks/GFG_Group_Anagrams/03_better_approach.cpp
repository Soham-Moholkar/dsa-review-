#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        for(const string& word:strs){
            string key=word;
            sort(key.begin(),key.end());
            groups[key].push_back(word);
        }
        vector<vector<string>> out;
        for(auto& entry:groups)out.push_back(entry.second);
        return out;
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
This file implements: Group sorted keys in a hash map.

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
6. `unordered_map<string,vector<string>> groups;`
   Declares `groups` so it can store state used by the algorithm.
7. `for(const string& word:strs){`
   Starts a range-based loop. `const string& word:strs` means: take each element from the container in turn and run the block.
8. `string key=word;`
   Updates `string key` to `word` for the next step of the algorithm.
9. `sort(key.begin(),key.end());`
   Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible.
10. `groups[key].push_back(word);`
   Appends the computed value to the end of the result/container.
11. `vector<vector<string>> out;`
   Declares `out` so it can store state used by the algorithm.
12. `for(auto& entry:groups)out.push_back(entry.second);`
   Starts a range-based loop. `auto& entry:groups` means: take each element from the container in turn and run the block. Its one-line body is `out.push_back(entry.second);`.
13. `return out;`
   Ends the function and sends `out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- unordered_map: Stores key-value pairs in a hash table, with expected O(1) operations.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- return: Ends the current function and optionally sends a value back to the caller.
- const: Promises that the named value will not be changed through that declaration.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- push_back: Adds one element to the end of a vector or deque.
- sort: Rearranges a range into ascending order by default. This changes the container.
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
- Time: O(w L log L) expected.
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
