#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarysearch(vector<int> &arr, int k) {
        int left = 0;
        int right = arr.size() - 1;
        int answer = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == k) {
                answer = mid;
                right = mid - 1; // Keep looking for an earlier occurrence.
            }
            else if(arr[mid] < k) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
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
Problem: Binary Search
Platform: GeeksforGeeks
Pattern: Binary Search

Problem goal:
Return the first zero-based index of k in a sorted array, or -1.

Core insight for this problem family:
Search a sorted array by checking its middle. Discard the half that cannot contain the target. For GFG, save a matching index and continue left to find the first occurrence.

This particular file uses the "Manual iterative binary search" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int binarysearch(vector<int> &arr, int k)`

- `int` means this function returns one signed integer.
- `binarysearch` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `k` is one signed integer value.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The array is sorted in nondecreasing order.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Manual iterative binary search

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `k`: the problem-supplied limit, window size, rotation count, or target parameter described by the signature.
- `left`: the left boundary or left pointer of the active search/window.
- `right`: the right boundary or right pointer of the active search/window.
- `answer`: the best or complete result found so far.
- `mid`: the middle position in binary search, or the scanning pointer in Dutch National Flag.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int binarysearch(vector<int> &arr, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int left = 0;`
   Creates `left` and initializes it from `0`. This gives the algorithm its starting state.
7. `int right = arr.size() - 1;`
   Creates `right` and initializes it from `arr.size() - 1`. This gives the algorithm its starting state.
8. `int answer = -1;`
   Creates `answer` and initializes it from `-1`. This gives the algorithm its starting state.
9. `while(left <= right) {`
   Repeats the following block while `left <= right` is true.
10. `int mid = left + (right - left) / 2;`
   Creates `mid` and initializes it from `left + (right - left) / 2`. This gives the algorithm its starting state.
11. `if(arr[mid] == k) {`
   Runs the next block only when `arr[mid] == k` is true.
12. `answer = mid;`
   Updates `answer` to `mid` for the next step of the algorithm.
13. `right = mid - 1;`
   Updates `right` to `mid - 1` for the next step of the algorithm.
14. `else if(arr[mid] < k) {`
   Defines the judge-facing function and lists the inputs it receives.
15. `left = mid + 1;`
   Updates `left` to `mid + 1` for the next step of the algorithm.
16. `else {`
   Handles the remaining case after the preceding condition(s) were false.
17. `right = mid - 1;`
   Updates `right` to `mid - 1` for the next step of the algorithm.
18. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- while: Repeats a block while its condition remains true.
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
[1,2,2,2,5], target 2: a middle match does not prove it is the first. Searching farther left finds index 1. LC 704 has distinct elements and can return immediately.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
The target, if still unseen, remains in the active interval. Comparisons eliminate only impossible positions; saving matches preserves a valid answer while searching earlier positions.

The key invariant (a fact that remains true after every useful iteration) is:
answer is a known matching index or -1; any earlier undiscovered occurrence remains inside left through right.

7. COMPLEXITY
-------------
- Time complexity: O(log n).
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
