#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        string vowels;
        for(char c:s)if(string("aeiouAEIOU").find(c)!=string::npos)vowels+=c;
        reverse(vowels.begin(),vowels.end());
        int i=0;
        for(char& c:s)if(string("aeiouAEIOU").find(c)!=string::npos)c=vowels[i++];
        return s;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Reverse Vowels of a String
Platform: LeetCode
Pattern: Two Pointers Palindrome

Learning goal: Skip non-target characters from both ends and swap only members of the selected set.
This file implements: Collect and reverse the vowels.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`string reverseVowels(string s)`
- `string` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The preferred pattern uses this invariant: Only vowel positions change; processed ends already contain the reversed vowels.

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
5. `string reverseVowels(string s) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `string vowels;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
7. `for(char c:s)if(string("aeiouAEIOU").find(c)!=string::npos)vowels+=c;`
   Starts a range-based loop. `char c:s` means: take each element from the container in turn and run the block. Its one-line body is `if(string("aeiouAEIOU").find(c)!=string::npos)vowels+=c;`.
8. `reverse(vowels.begin(),vowels.end());`
   Reverses the selected range in place. The second iterator is one position past the range.
9. `int i=0;`
   Creates `i` and initializes it from `0`. This gives the algorithm its starting state.
10. `for(char& c:s)if(string("aeiouAEIOU").find(c)!=string::npos)c=vowels[i++];`
   Starts a range-based loop. `char& c:s` means: take each element from the container in turn and run the block. Its one-line body is `if(string("aeiouAEIOU").find(c)!=string::npos)c=vowels[i++];`.
11. `return s;`
   Ends the function and sends `s` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- find: Searches for a value/key. A failed standard-container search returns end(). For vectors, the algorithm form find(begin, end, value) performs a linear scan.
- reverse: Reverses the order of elements in the selected iterator range.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: "IceCreAm" -> "AceCreIm"
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The preferred pattern uses this invariant: Only vowel positions change; processed ends already contain the reversed vowels.
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
