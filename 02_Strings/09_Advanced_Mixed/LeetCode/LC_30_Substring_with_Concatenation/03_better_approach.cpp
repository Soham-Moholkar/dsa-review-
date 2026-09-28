#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.empty())return ans;
        int w=words[0].size(),total=words.size(),length=w*total;
        unordered_map<string,int> need;
        for(auto& word:words)++need[word];
        for(int start=0;start<w;++start){
            unordered_map<string,int> have;
            int l=start,count=0;
            for(int r=start;r+w<=(int)s.size();r+=w){
                string token=s.substr(r,w);
                if(!need.count(token)){
                    have.clear();
                    count=0;
                    l=r+w;
                    continue;
                }
                ++have[token];
                ++count;
                while(have[token]>need[token]){
                    --have[s.substr(l,w)];
                    l+=w;
                    --count;
                }
                if(count==total){
                    ans.push_back(l);
                    --have[s.substr(l,w)];
                    l+=w;
                    --count;
                }
            }
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
This file implements: Same efficient method (no distinct intermediate).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> findSubstring(string s, vector<string>& words)`
- `vector<int>` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The map counts word multiplicities inside one aligned, word-sized window.

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
8. `int w=words[0].size(),total=words.size(),length=w*total;`
   Creates `w` and initializes it from `words[0].size(),total=words.size(),length=w*total`. This gives the algorithm its starting state.
9. `unordered_map<string,int> need;`
   Declares `need` so it can store state used by the algorithm.
10. `for(auto& word:words)++need[word];`
   Starts a range-based loop. `auto& word:words` means: take each element from the container in turn and run the block. Its one-line body is `++need[word];`.
11. `for(int start=0;start<w;++start){`
   Starts a loop: first `int start=0`; keep repeating while `start<w` is true; after each iteration perform `++start`.
12. `unordered_map<string,int> have;`
   Declares `have` so it can store state used by the algorithm.
13. `int l=start,count=0;`
   Creates `l` and initializes it from `start,count=0`. This gives the algorithm its starting state.
14. `for(int r=start;r+w<=(int)s.size();r+=w){`
   Starts a loop: first `int r=start`; keep repeating while `r+w<=(int)s.size()` is true; after each iteration perform `r+=w`.
15. `string token=s.substr(r,w);`
   Updates `string token` to `s.substr(r,w)` for the next step of the algorithm.
16. `if(!need.count(token)){`
   Runs the next block only when `!need.count(token)` is true.
17. `have.clear();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
18. `count=0;`
   Updates `count` to `0` for the next step of the algorithm.
19. `l=r+w;`
   Updates `l` to `r+w` for the next step of the algorithm.
20. `continue;`
   Skips the rest of this iteration and starts the next one.
21. `++have[token];`
   Moves the relevant counter or pointer by one position.
22. `++count;`
   Moves the relevant counter or pointer by one position.
23. `while(have[token]>need[token]){`
   Repeats the following block while `have[token]>need[token]` is true.
24. `--have[s.substr(l,w)];`
   Moves the relevant counter or pointer by one position.
25. `l+=w;`
   Updates the stored state using its previous value and the expression on the right.
26. `--count;`
   Moves the relevant counter or pointer by one position.
27. `if(count==total){`
   Runs the next block only when `count==total` is true.
28. `ans.push_back(l);`
   Appends the computed value to the end of the result/container.
29. `--have[s.substr(l,w)];`
   Moves the relevant counter or pointer by one position.
30. `l+=w;`
   Updates the stored state using its previous value and the expression on the right.
31. `--count;`
   Moves the relevant counter or pointer by one position.
32. `return ans;`
   Ends the function and sends `ans` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- unordered_map: Stores key-value pairs in a hash table, with expected O(1) operations.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- continue: Skips the remainder of the current loop iteration and begins the next one.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- push_back: Adds one element to the end of a vector or deque.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- !: Logical NOT; reverses true and false.
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
shown in the executable walkthrough. The maintained fact is: The map counts word multiplicities inside one aligned, word-sized window.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(nw) expected.
- Extra space: O(w + result).
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
