#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        auto contribution=[&](bool maximum){
            int n=nums.size();
            vector<int> left(n),right(n),st;
            for(int i=0;i<n;++i){
                while(!st.empty()&&(maximum?nums[st.back()]<=nums[i]:nums[st.back()]>=nums[i]))st.pop_back();
                left[i]=st.empty()?-1:st.back();
                st.push_back(i);
            }
            st.clear();
            for(int i=n-1;i>=0;--i){
                while(!st.empty()&&(maximum?nums[st.back()]<nums[i]:nums[st.back()]>nums[i]))st.pop_back();
                right[i]=st.empty()?n:st.back();
                st.push_back(i);
            }
            long long ans=0;
            for(int i=0;i<n;++i)ans+=(long long)nums[i]*(i-left[i])*(right[i]-i);
            return ans;
        }
        ;
        return contribution(true)-contribution(false);
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Sum of Subarray Ranges
Platform: LeetCode
Pattern: Stack Range and Histogram

Learning goal: Extend boundary contributions to both minima and maxima.
This file implements: Min/max contribution reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`long long subArrayRanges(vector<int>& nums)`
- `long` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Each subarray contributes its maximum minus its minimum exactly once.

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
5. `long long subArrayRanges(vector<int>& nums) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `auto contribution=[&](bool maximum){`
   Creates `contribution` and initializes it from `[&](bool maximum){`. This gives the algorithm its starting state.
7. `int n=nums.size();`
   Creates `n` and initializes it from `nums.size()`. This gives the algorithm its starting state.
8. `vector<int> left(n),right(n),st;`
   Declares `left` so it can store state used by the algorithm.
9. `for(int i=0;i<n;++i){`
   Starts a loop: first `int i=0`; keep repeating while `i<n` is true; after each iteration perform `++i`.
10. `while(!st.empty()&&(maximum?nums[st.back()]<=nums[i]:nums[st.back()]>=nums[i]))st.pop_back();`
   Repeats the following block while `!st.empty()&&(maximum?nums[st.back()]<=nums[i]:nums[st.back()]>=nums[i])` is true. Its one-line body is `st.pop_back();`.
11. `left[i]=st.empty()?-1:st.back();`
   Updates `left[i]` to `st.empty()?-1:st.back()` for the next step of the algorithm.
12. `st.push_back(i);`
   Appends the computed value to the end of the result/container.
13. `st.clear();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `for(int i=n-1;i>=0;--i){`
   Starts a loop: first `int i=n-1`; keep repeating while `i>=0` is true; after each iteration perform `--i`.
15. `while(!st.empty()&&(maximum?nums[st.back()]<nums[i]:nums[st.back()]>nums[i]))st.pop_back();`
   Repeats the following block while `!st.empty()&&(maximum?nums[st.back()]<nums[i]:nums[st.back()]>nums[i])` is true. Its one-line body is `st.pop_back();`.
16. `right[i]=st.empty()?n:st.back();`
   Updates `right[i]` to `st.empty()?n:st.back()` for the next step of the algorithm.
17. `st.push_back(i);`
   Appends the computed value to the end of the result/container.
18. `long long ans=0;`
   Creates `ans` and initializes it from `0`. This gives the algorithm its starting state.
19. `for(int i=0;i<n;++i)ans+=(long long)nums[i]*(i-left[i])*(right[i]-i);`
   Starts a loop: first `int i=0`; keep repeating while `i<n` is true; after each iteration perform `++i`. Its one-line body is `ans+=(long long)nums[i]*(i-left[i])*(right[i]-i);`.
20. `return ans;`
   Ends the function and sends `ans` back to the caller.
21. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
22. `return contribution(true)-contribution(false);`
   Ends the function and sends `contribution(true)-contribution(false)` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- long long: A wider signed whole-number type, commonly 64 bits; it is used when an int may be too small.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- push_back: Adds one element to the end of a vector or deque.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
- front / back: Accesses the first or last element of a nonempty container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- lambda ([&]): Creates an unnamed function. [&] captures surrounding local variables by reference, so the lambda can read and modify them.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: [1,2,3] -> 4
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Each subarray contributes its maximum minus its minimum exactly once.
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
