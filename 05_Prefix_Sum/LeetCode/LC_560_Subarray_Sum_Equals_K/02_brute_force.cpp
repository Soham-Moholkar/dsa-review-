#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0;
        for(int start = 0; start < nums.size(); start++) {
            int sum = 0;
            for(int end = start; end < nums.size(); end++) {
                sum = sum + nums[end];
                if(sum == k) {
                    answer++;
                }
            }
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Subarray Sum Equals K
Platform: LeetCode
Pattern: Prefix Sum and Prefix Sum with Hashmap

Problem goal:
Count contiguous subarrays whose sum equals k.

Core insight for this problem family:
Keep a frequency map of prefix sums. At each prefix p, add the number of earlier prefixes p-k to the answer. Then increment the frequency of p.

This particular file uses the "Enumerate all subarrays" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int subarraySum(vector<int>& nums, int k)`

- `int` means this function returns one signed integer.
- `subarraySum` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `k` is one signed integer value.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Enumerate all subarrays

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `k`: the problem-supplied limit, window size, rotation count, or target parameter described by the signature.
- `answer`: the best or complete result found so far.
- `start`: the first index of a candidate subarray/window.
- `sum`: the running sum of the elements currently being examined.
- `end`: the final index or iterator boundary of a candidate range.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int subarraySum(vector<int>& nums, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int answer = 0;`
   Creates `answer` and initializes it from `0`. This gives the algorithm its starting state.
7. `for(int start = 0; start < nums.size(); start++) {`
   Starts a loop: first `int start = 0`; keep repeating while `start < nums.size()` is true; after each iteration perform `start++`.
8. `int sum = 0;`
   Creates `sum` and initializes it from `0`. This gives the algorithm its starting state.
9. `for(int end = start; end < nums.size(); end++) {`
   Starts a loop: first `int end = start`; keep repeating while `end < nums.size()` is true; after each iteration perform `end++`.
10. `sum = sum + nums[end];`
   Updates `sum` to `sum + nums[end]` for the next step of the algorithm.
11. `if(sum == k) {`
   Runs the next block only when `sum == k` is true.
12. `answer++;`
   Moves the relevant counter or pointer by one position.
13. `return answer;`
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
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
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
[1,1,1], k=2: prefixes are 1,2,3. Prefix 2 matches initial 0; prefix 3 matches earlier 1. The answer is 2.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Each matching earlier prefix identifies one distinct nonempty subarray ending here. A set would lose multiplicity; a map of counts preserves it.

The key invariant (a fact that remains true after every useful iteration) is:
frequency contains all prior prefix sums and their occurrence counts.

7. COMPLEXITY
-------------
- Time complexity: O(n^2).
- Extra-space complexity: O(1).
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
