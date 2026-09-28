#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.empty())return ans;
        int len=words.size()*words[0].size();
        map<string,int> required;
        for(auto& w:words)++required[w];
        for(int i=0;i+len<=s.size();++i){
            auto remain=required;
            int j=0;
            for(;j<len;j+=words[0].size()){
                auto token=s.substr(i+j,words[0].size());
                if(remain[token]--<=0)break;
            }
            if(j==len)ans.push_back(i);
        }
        return ans;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Substring with Concatenation of All Words
Platform: LeetCode
Pattern: Advanced Mixed

Learning goal: Slide in word-sized steps and treat each starting offset as an independent window stream.
This file implements: Check every word-aligned starting position.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> findSubstring(string s, vector<string>& words)`
- `vector<int>` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The preferred pattern uses this invariant: The map counts word multiplicities inside one aligned, word-sized window.

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
5. `vector<int> findSubstring(string s, vector<string>& words) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<int> ans;`
   Declares `ans` so it can store state used by the algorithm.
7. `if(words.empty())return ans;`
   Runs the next block only when `words.empty()` is true. The one-line action is `return ans;`.
8. `int len=words.size()*words[0].size();`
   Creates `len` and initializes it from `words.size()*words[0].size()`. This gives the algorithm its starting state.
9. `map<string,int> required;`
   Declares `required` so it can store state used by the algorithm.
10. `for(auto& w:words)++required[w];`
   Starts a range-based loop. `auto& w:words` means: take each element from the container in turn and run the block. Its one-line body is `++required[w];`.
11. `for(int i=0;i+len<=s.size();++i){`
   Starts a loop: first `int i=0`; keep repeating while `i+len<=s.size()` is true; after each iteration perform `++i`.
12. `auto remain=required;`
   Creates `remain` and initializes it from `required`. This gives the algorithm its starting state.
13. `int j=0;`
   Creates `j` and initializes it from `0`. This gives the algorithm its starting state.
14. `for(;j<len;j+=words[0].size()){`
   Starts a loop: first ``; keep repeating while `j<len` is true; after each iteration perform `j+=words[0].size()`.
15. `auto token=s.substr(i+j,words[0].size());`
   Creates `token` and initializes it from `s.substr(i+j,words[0].size())`. This gives the algorithm its starting state.
16. `if(remain[token]--<=0)break;`
   Runs the next block only when `remain[token]--<=0` is true. The one-line action is `break;`.
17. `if(j==len)ans.push_back(i);`
   Runs the next block only when `j==len` is true. The one-line action is `ans.push_back(i);`.
18. `return ans;`
   Ends the function and sends `ans` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- map: Stores key-value pairs in sorted-key order, usually with O(log n) operations.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- break: Immediately exits the nearest loop.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- push_back: Adds one element to the end of a vector or deque.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "barfoothefoobarman", ["foo","bar"] -> [0,9]
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The preferred pattern uses this invariant: The map counts word multiplicities inside one aligned, word-sized window.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(nw) expected.
- Extra space: O(w) plus result.
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
