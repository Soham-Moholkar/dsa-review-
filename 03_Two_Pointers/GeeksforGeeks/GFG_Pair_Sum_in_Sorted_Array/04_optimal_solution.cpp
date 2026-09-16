#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        while(left < right) {
            long long sum = 1LL * arr[left] + arr[right];
            if(sum == target) {
                return true;
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return false;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Pair Sum in Sorted Array
Platform: GeeksforGeeks
Pattern: Two Pointers

Problem goal:
Determine whether a sorted array contains a pair whose sum equals the target.

Core insight for this problem family:
Start at the left and right ends of the SORTED array. If the sum is too small, move left forward. If it is too large, move right backward.

This particular file uses the "Opposite-end two pointers" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`bool twoSum(vector<int>& arr, int target)`

- `bool` means this function returns either true or false.
- `twoSum` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `target` is one signed integer value.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The array is sorted in nondecreasing order.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Opposite-end two pointers

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `target`: the value or sum the problem asks the algorithm to find.
- `left`: the left boundary or left pointer of the active search/window.
- `right`: the right boundary or right pointer of the active search/window.
- `sum`: the running sum of the elements currently being examined.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `bool twoSum(vector<int>& arr, int target) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int left = 0;`
   Creates `left` and initializes it from `0`. This gives the algorithm its starting state.
7. `int right = arr.size() - 1;`
   Creates `right` and initializes it from `arr.size() - 1`. This gives the algorithm its starting state.
8. `while(left < right) {`
   Repeats the following block while `left < right` is true.
9. `long long sum = 1LL * arr[left] + arr[right];`
   Creates `sum` and initializes it from `1LL * arr[left] + arr[right]`. This gives the algorithm its starting state.
10. `if(sum == target) {`
   Runs the next block only when `sum == target` is true.
11. `return true;`
   Ends the function and sends `true` back to the caller.
12. `else if(sum < target) {`
   Defines the judge-facing function and lists the inputs it receives.
13. `left++;`
   Moves the relevant counter or pointer by one position.
14. `else {`
   Handles the remaining case after the preceding condition(s) were false.
15. `right--;`
   Moves the relevant counter or pointer by one position.
16. `return false;`
   Ends the function and sends `false` back to the caller.

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
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- ++ / --: Increases/decreases a numeric variable by one.
- 1LL: A long long literal. Multiplying by 1LL promotes later arithmetic so it is performed with a wider integer type.

General syntax reminders:
- Parentheses `()` hold function arguments or conditions.
- Braces `{}` group statements into a class, function, loop, or condition block.
- Square brackets `[]` index a vector/array from zero; valid indices are 0 through size-1.
- A semicolon `;` ends a C++ statement.
- `==` compares values; `=` assigns a new value. Confusing them is a common bug.
- `<`, `>`, `<=`, and `>=` compare values.

5. DRY RUN
----------
[1,2,4,7], target=6: 1+7 is too large, so discard 7. Then 1+4 is too small, so discard 1. Finally 2+4=6.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
If the sum is too small, the left value cannot work with any smaller right value. The symmetric argument applies to a sum that is too large. LC 167 returns one-based indices.

The key invariant (a fact that remains true after every useful iteration) is:
All discarded pairs are impossible based on the sorted order.

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
