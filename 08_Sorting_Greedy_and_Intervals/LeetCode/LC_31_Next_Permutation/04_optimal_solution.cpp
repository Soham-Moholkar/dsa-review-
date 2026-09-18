#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = n - 2;
        while(pivot >= 0 && nums[pivot] >= nums[pivot + 1]) {
            pivot--;
        }
        if(pivot >= 0) {
            int successor = n - 1;
            while(nums[successor] <= nums[pivot]) {
                successor--;
            }
            swap(nums[pivot], nums[successor]);
        }
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Next Permutation
Platform: LeetCode
Pattern: Sorting, Greedy Decisions, and Intervals

Problem goal:
Transform nums into the lexicographically next permutation, or the smallest permutation if none exists.

Core insight for this problem family:
Find the rightmost position smaller than its next value. Swap it with the rightmost larger value, then reverse the suffix. If no such position exists, reverse everything.

This particular file uses the "Manual pivot, successor, and suffix reversal" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`void nextPermutation(vector<int>& nums)`

- `void` means this function does not return a value; the answer is written into an input object.
- `nextPermutation` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Manual pivot, successor, and suffix reversal

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `n`: the number of elements currently considered.
- `pivot`: the special split position: a rotation minimum or next-permutation increase point.
- `successor`: the smallest suitable value to swap with the next-permutation pivot.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `void nextPermutation(vector<int>& nums) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = nums.size();`
   Creates `n` and initializes it from `nums.size()`. This gives the algorithm its starting state.
7. `int pivot = n - 2;`
   Creates `pivot` and initializes it from `n - 2`. This gives the algorithm its starting state.
8. `while(pivot >= 0 && nums[pivot] >= nums[pivot + 1]) {`
   Repeats the following block while `pivot >= 0 && nums[pivot] >= nums[pivot + 1]` is true.
9. `pivot--;`
   Moves the relevant counter or pointer by one position.
10. `if(pivot >= 0) {`
   Runs the next block only when `pivot >= 0` is true.
11. `int successor = n - 1;`
   Creates `successor` and initializes it from `n - 1`. This gives the algorithm its starting state.
12. `while(nums[successor] <= nums[pivot]) {`
   Repeats the following block while `nums[successor] <= nums[pivot]` is true.
13. `successor--;`
   Moves the relevant counter or pointer by one position.
14. `swap(nums[pivot], nums[successor]);`
   Exchanges the two selected values without needing a manual temporary variable.
15. `reverse(nums.begin() + pivot + 1, nums.end());`
   Reverses the selected range in place. The second iterator is one position past the range.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- reverse: Reverses the order of elements in the selected iterator range.
- swap: Exchanges two stored values.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
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
[1,3,2]: the pivot is 1. Swap with 2 -> [2,3,1], then reverse the suffix -> [2,1,3]. For [3,2,1], wrap to [1,2,3].

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
The suffix is already the greatest ordering of its values. Increasing the rightmost possible pivot by the smallest amount and minimizing the suffix gives the immediate next ordering.

The key invariant (a fact that remains true after every useful iteration) is:
The suffix after the pivot is non-increasing and can be reversed into its smallest order.

7. COMPLEXITY
-------------
- Time complexity: O(n).
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
