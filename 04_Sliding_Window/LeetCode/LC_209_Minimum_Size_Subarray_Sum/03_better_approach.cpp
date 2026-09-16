#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int answer = INT_MAX;
        for(int left = 0; left < n; left++) {
            long long required = prefix[left] + target;
            int right = lower_bound(prefix.begin() + left + 1, prefix.end(), required) - prefix.begin();
            if(right <= n) {
                answer = min(answer, right - left);
            }
        }
        return answer == INT_MAX ? 0 : answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Minimum Size Subarray Sum
Platform: LeetCode
Pattern: Sliding Window

Problem goal:
Return the minimum length of a contiguous subarray with sum at least target.

Core insight for this problem family:
Grow a window by moving right. Whenever its sum satisfies the threshold, save its length and remove values from the left while it remains valid.

This particular file uses the "Prefix sums with lower_bound" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int minSubArrayLen(int target, vector<int>& nums)`

- `int` means this function returns one signed integer.
- `minSubArrayLen` is the function name the online judge calls.
- `target` is one signed integer value.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). LC uses positive values and sum >= target; GFG uses nonnegative values and sum > x, with a nonnegative threshold.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Prefix sums with lower_bound

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `target`: the value or sum the problem asks the algorithm to find.
- `nums`: the input integer array used by the LeetCode-style function.
- `n`: the number of elements currently considered.
- `prefix`: an array/container of cumulative values from the start.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `answer`: the best or complete result found so far.
- `left`: the left boundary or left pointer of the active search/window.
- `required`: the complementary prefix/value needed to form the requested answer.
- `right`: the right boundary or right pointer of the active search/window.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int minSubArrayLen(int target, vector<int>& nums) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = nums.size();`
   Creates `n` and initializes it from `nums.size()`. This gives the algorithm its starting state.
7. `vector<long long> prefix(n + 1, 0);`
   Declares `prefix` so it can store state used by the algorithm.
8. `for(int i = 0; i < n; i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < n` is true; after each iteration perform `i++`.
9. `prefix[i + 1] = prefix[i] + nums[i];`
   Updates `prefix[i + 1]` to `prefix[i] + nums[i]` for the next step of the algorithm.
10. `int answer = INT_MAX;`
   Creates `answer` and initializes it from `INT_MAX`. This gives the algorithm its starting state.
11. `for(int left = 0; left < n; left++) {`
   Starts a loop: first `int left = 0`; keep repeating while `left < n` is true; after each iteration perform `left++`.
12. `long long required = prefix[left] + target;`
   Creates `required` and initializes it from `prefix[left] + target`. This gives the algorithm its starting state.
13. `int right = lower_bound(prefix.begin() + left + 1, prefix.end(), required) - prefix.begin();`
   Creates `right` and initializes it from `lower_bound(prefix.begin() + left + 1, prefix.end(), required) - prefix.begin()`. This gives the algorithm its starting state.
14. `if(right <= n) {`
   Runs the next block only when `right <= n` is true.
15. `answer = min(answer, right - left);`
   Updates `answer` to `min(answer, right - left)` for the next step of the algorithm.
16. `return answer == INT_MAX ? 0 : answer;`
   Ends the function and sends `answer == INT_MAX ? 0 : answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- long long: A wider signed whole-number type, commonly 64 bits; it is used when an int may be too small.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- min / max: Returns the smaller/larger of the supplied values.
- lower_bound: On a sorted range, returns the first position whose value is not smaller than the target.
- INT_MIN / INT_MAX: The smallest/largest value representable by int.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- ++ / --: Increases/decreases a numeric variable by one.
- iterator subtraction: Subtracting two random-access iterators gives the zero-based distance between their positions.

General syntax reminders:
- Parentheses `()` hold function arguments or conditions.
- Braces `{}` group statements into a class, function, loop, or condition block.
- Square brackets `[]` index a vector/array from zero; valid indices are 0 through size-1.
- A semicolon `;` ends a C++ statement.
- `==` compares values; `=` assigns a new value. Confusing them is a common bug.
- `<`, `>`, `<=`, and `>=` compare values.

5. DRY RUN
----------
[2,3,1,2,4,3], threshold 7 with >=: shrinking eventually finds [4,3], length 2. For a strict >7 condition that same window is not valid.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
With nonnegative values, growing cannot reduce the sum and shrinking cannot increase it. Every shortest valid window ending at each right index is considered. Negative values break this reasoning.

The key invariant (a fact that remains true after every useful iteration) is:
Whenever sum is valid, shrinking tests every shorter valid window ending at right.

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
