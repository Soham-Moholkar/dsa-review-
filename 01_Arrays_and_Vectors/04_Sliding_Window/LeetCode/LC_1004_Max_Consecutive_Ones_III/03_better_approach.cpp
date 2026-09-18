#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == 0);
        }
        int answer = 0;
        for(int left = 0; left < n; left++) {
            int low = left;
            int high = n - 1;
            int best = left - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                int zeroes = prefix[mid + 1] - prefix[left];
                if(zeroes <= k) {
                    best = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            answer = max(answer, best - left + 1);
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Max Consecutive Ones III
Platform: LeetCode
Pattern: Sliding Window

Problem goal:
Return the longest binary subarray that can contain at most k zeroes after flips.

Core insight for this problem family:
Count zeros inside the window. If there are more than k, move left until at most k remain. Save the longest valid window.

This particular file uses the "Prefix zero count with binary search" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int longestOnes(vector<int>& nums, int k)`

- `int` means this function returns one signed integer.
- `longestOnes` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `k` is one signed integer value.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Prefix zero count with binary search

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `k`: the problem-supplied limit, window size, rotation count, or target parameter described by the signature.
- `n`: the number of elements currently considered.
- `prefix`: an array/container of cumulative values from the start.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `answer`: the best or complete result found so far.
- `left`: the left boundary or left pointer of the active search/window.
- `low`: the beginning of the still-unknown region in a three-way partition or search.
- `high`: the end of the still-unknown region.
- `best`: the best valid boundary/index found during the current search.
- `mid`: the middle position in binary search, or the scanning pointer in Dutch National Flag.
- `zeroes`: the number of zero values inside the current window.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int longestOnes(vector<int>& nums, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = nums.size();`
   Creates `n` and initializes it from `nums.size()`. This gives the algorithm its starting state.
7. `vector<int> prefix(n + 1, 0);`
   Declares `prefix` so it can store state used by the algorithm.
8. `for(int i = 0; i < n; i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < n` is true; after each iteration perform `i++`.
9. `prefix[i + 1] = prefix[i] + (nums[i] == 0);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `int answer = 0;`
   Creates `answer` and initializes it from `0`. This gives the algorithm its starting state.
11. `for(int left = 0; left < n; left++) {`
   Starts a loop: first `int left = 0`; keep repeating while `left < n` is true; after each iteration perform `left++`.
12. `int low = left;`
   Creates `low` and initializes it from `left`. This gives the algorithm its starting state.
13. `int high = n - 1;`
   Creates `high` and initializes it from `n - 1`. This gives the algorithm its starting state.
14. `int best = left - 1;`
   Creates `best` and initializes it from `left - 1`. This gives the algorithm its starting state.
15. `while(low <= high) {`
   Repeats the following block while `low <= high` is true.
16. `int mid = low + (high - low) / 2;`
   Creates `mid` and initializes it from `low + (high - low) / 2`. This gives the algorithm its starting state.
17. `int zeroes = prefix[mid + 1] - prefix[left];`
   Creates `zeroes` and initializes it from `prefix[mid + 1] - prefix[left]`. This gives the algorithm its starting state.
18. `if(zeroes <= k) {`
   Runs the next block only when `zeroes <= k` is true.
19. `best = mid;`
   Updates `best` to `mid` for the next step of the algorithm.
20. `low = mid + 1;`
   Updates `low` to `mid + 1` for the next step of the algorithm.
21. `else {`
   Handles the remaining case after the preceding condition(s) were false.
22. `high = mid - 1;`
   Updates `high` to `mid - 1` for the next step of the algorithm.
23. `answer = max(answer, best - left + 1);`
   Updates `answer` to `max(answer, best - left + 1)` for the next step of the algorithm.
24. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- min / max: Returns the smaller/larger of the supplied values.
- ++ / --: Increases/decreases a numeric variable by one.

General syntax reminders:
- Parentheses `()` hold function arguments or conditions.
- Braces `{}` group statements into a class, function, loop, or condition block.
- Square brackets `[]` index a vector/array from zero; valid indices are 0 through size-1.
- A semicolon `;` ends a C++ statement.
- `==` compares values; `=` assigns a new value. Confusing them is a common bug.
- `<`, `>`, `<=`, and `>=` compare values.

5. DRY RUN
----------
Trace this exact file using the first example in `testcases.md`. It applies the "Prefix zero count with binary search" approach, so follow the numbered executable statements above and record each listed variable after it changes. Do not reuse the optimal implementation's saved variables: this file may enumerate candidates, sort values, or build auxiliary state instead.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
This file uses the intermediate "Prefix zero count with binary search" strategy. Each operation in the numbered walkthrough preserves the information needed for the answer while arranging or storing it in a form that is easier to query. After every input element or required position has been processed, the final return/update condition selects the requested result.

The key invariant (a fact that remains true after every useful iteration) is:
After each completed iteration, the auxiliary or rearranged state represents every input item processed so far without discarding information needed for the answer.

7. COMPLEXITY
-------------
- Time complexity: O(n log n).
- Extra-space complexity: O(n).
- `n` normally means the number of array elements. For matrix problems, use rows and columns as described in the approach.
- Required output storage is excluded only when the complexity text explicitly says so.

8. EDGE CASES TO CHECK
----------------------
- The smallest input allowed by the contract.
- Repeated values and an answer at the first or last valid position.
- Already sorted/reversed input when ordering matters.
- All-negative values, zeroes, or a missing answer when the problem permits them.
- Values near integer limits when the code adds, subtracts, multiplies, or forms a complement.
- For in-place code, remember that the input may look different after the call.

9. COMMON MISTAKES
------------------
- Using `=` when a comparison needs `==`.
- Reading index `size()` even though the final valid index is `size() - 1`.
- Moving a pointer/counter in the wrong branch or forgetting to move it, causing an infinite loop.
- Returning the right value with the wrong index base (zero-based versus one-based).
- Copying this approach to inputs that do not satisfy its sortedness, positivity, range, or matrix-shape assumptions.
- Ignoring overflow: promote before arithmetic when the implementation uses `long long` or `1LL`.

10. HOW TO STUDY THIS SOLUTION
------------------------------
1. Hide the code and state the main idea in one sentence.
2. Explain every variable without using its name as the explanation.
3. Perform the dry run and state the invariant after each iteration.
4. Re-code the method from memory.
5. Compare it with the other numbered approaches in this folder and explain the time/space trade-off.

Comments are ignored by the C++ compiler, so this appendix changes documentation only, not program behaviour.
*/
