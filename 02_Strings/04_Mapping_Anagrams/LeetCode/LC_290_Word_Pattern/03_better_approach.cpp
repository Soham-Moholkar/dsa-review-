#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream in(s);
        vector<string> words;
        string w;
        while(in>>w) words.push_back(w);
        if(words.size()!=pattern.size()) return false;
        unordered_map<char,string> f;
        unordered_map<string,char> g;
        for(int i=0;i<(int)words.size();++i){
            char c=pattern[i];
            if((f.count(c)&&f[c]!=words[i])||(g.count(words[i])&&g[words[i]]!=c)) return false;
            f[c]=words[i];
            g[words[i]]=c;
        }
        return true;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Word Pattern
Platform: LeetCode
Pattern: Mapping Anagrams

Learning goal: Apply the same one-to-one mapping idea across different element types: characters and whole words.
This file implements: Same efficient method (no distinct intermediate).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`bool wordPattern(string pattern, string s)`
- `bool` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The character-to-word and word-to-character maps agree on processed tokens.

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
5. `bool wordPattern(string pattern, string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `istringstream in(s);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
7. `vector<string> words;`
   Declares `words` so it can store state used by the algorithm.
8. `string w;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `while(in>>w) words.push_back(w);`
   Repeats the following block while `in>>w` is true. Its one-line body is `words.push_back(w);`.
10. `if(words.size()!=pattern.size()) return false;`
   Runs the next block only when `words.size()!=pattern.size()` is true. The one-line action is `return false;`.
11. `unordered_map<char,string> f;`
   Declares `f` so it can store state used by the algorithm.
12. `unordered_map<string,char> g;`
   Declares `g` so it can store state used by the algorithm.
13. `for(int i=0;i<(int)words.size();++i){`
   Starts a loop: first `int i=0`; keep repeating while `i<(int)words.size()` is true; after each iteration perform `++i`.
14. `char c=pattern[i];`
   Updates `char c` to `pattern[i]` for the next step of the algorithm.
15. `if((f.count(c)&&f[c]!=words[i])||(g.count(words[i])&&g[words[i]]!=c)) return false;`
   Runs the next block only when `(f.count(c)&&f[c]!=words[i])||(g.count(words[i])&&g[words[i]]!=c)` is true. The one-line action is `return false;`.
16. `f[c]=words[i];`
   Updates `f[c]` to `words[i]` for the next step of the algorithm.
17. `g[words[i]]=c;`
   Updates `g[words[i]]` to `c` for the next step of the algorithm.
18. `return true;`
   Ends the function and sends `true` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- unordered_map: Stores key-value pairs in a hash table, with expected O(1) operations.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "abba", "dog cat cat dog" -> true
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The character-to-word and word-to-character maps agree on processed tokens.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(n).
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
