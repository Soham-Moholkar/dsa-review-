#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int left = 0;
        int right = arr.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == key) {
                return mid;
            }
            if(arr[left] <= arr[mid]) {
                if(arr[left] <= key && key < arr[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if(arr[mid] < key && key <= arr[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Search in Rotated Sorted Array
Platform: GeeksforGeeks
Pattern: Binary Search

Problem goal:
Return the index of key in a rotated sorted array with distinct values.

Core insight for this problem family:
At each middle position, identify which half is sorted. Check whether the target lies inside that half's value range; keep that half if it does, otherwise keep the other.

This particular file uses the "Modified binary search" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int search(vector<int>& arr, int key)`

- `int` means this function returns one signed integer.
- `search` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `key` is one signed integer value.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Values are distinct.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Modified binary search

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `key`: the target value searched for in the array.
- `left`: the left boundary or left pointer of the active search/window.
- `right`: the right boundary or right pointer of the active search/window.
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
5. `int search(vector<int>& arr, int key) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int left = 0;`
   Creates `left` and initializes it from `0`. This gives the algorithm its starting state.
7. `int right = arr.size() - 1;`
   Creates `right` and initializes it from `arr.size() - 1`. This gives the algorithm its starting state.
8. `while(left <= right) {`
   Repeats the following block while `left <= right` is true.
9. `int mid = left + (right - left) / 2;`
   Creates `mid` and initializes it from `left + (right - left) / 2`. This gives the algorithm its starting state.
10. `if(arr[mid] == key) {`
   Runs the next block only when `arr[mid] == key` is true.
11. `return mid;`
   Ends the function and sends `mid` back to the caller.
12. `if(arr[left] <= arr[mid]) {`
   Runs the next block only when `arr[left] <= arr[mid]` is true.
13. `if(arr[left] <= key && key < arr[mid]) {`
   Runs the next block only when `arr[left] <= key && key < arr[mid]` is true.
14. `right = mid - 1;`
   Updates `right` to `mid - 1` for the next step of the algorithm.
15. `else {`
   Handles the remaining case after the preceding condition(s) were false.
16. `left = mid + 1;`
   Updates `left` to `mid + 1` for the next step of the algorithm.
17. `else {`
   Handles the remaining case after the preceding condition(s) were false.
18. `if(arr[mid] < key && key <= arr[right]) {`
   Runs the next block only when `arr[mid] < key && key <= arr[right]` is true.
19. `left = mid + 1;`
   Updates `left` to `mid + 1` for the next step of the algorithm.
20. `else {`
   Handles the remaining case after the preceding condition(s) were false.
21. `right = mid - 1;`
   Updates `right` to `mid - 1` for the next step of the algorithm.
22. `return -1;`
   Ends the function and sends `-1` back to the caller.

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
[4,5,6,7,0,1,2], target 0: the left half through 7 is sorted but cannot contain 0. Keep the right half and continue until index 4.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
With distinct values, at least one half is sorted. Its endpoints decide whether the target can belong there. Duplicates require a different ambiguity-handling algorithm.

The key invariant (a fact that remains true after every useful iteration) is:
After identifying the sorted half, discard the half that cannot contain key.

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
