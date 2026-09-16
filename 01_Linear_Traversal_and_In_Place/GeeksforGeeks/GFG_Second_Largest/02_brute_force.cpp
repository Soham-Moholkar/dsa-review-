#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int largestValue = arr[arr.size() - 1];
        for(int i = arr.size() - 2; i >= 0; i--) {
            if(arr[i] != largestValue) {
                return arr[i];
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
Problem: Second Largest
Platform: GeeksforGeeks
Pattern: Linear Traversal and In-Place Manipulation

Problem goal:
Return the second-largest distinct value, or -1 when it does not exist.

Core insight for this problem family:
Keep the two greatest DISTINCT values. A new largest pushes the old largest into second place. A value equal to the largest must not become second.

This particular file uses the "Sort and locate the first distinct value" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int getSecondLargest(vector<int> &arr)`

- `int` means this function returns one signed integer.
- `getSecondLargest` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The input is nonempty.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Sort and locate the first distinct value

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `largestValue`: the largest distinct value seen so far.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int getSecondLargest(vector<int> &arr) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `sort(arr.begin(), arr.end());`
   Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible.
7. `int largestValue = arr[arr.size() - 1];`
   Creates `largestValue` and initializes it from `arr[arr.size() - 1]`. This gives the algorithm its starting state.
8. `for(int i = arr.size() - 2; i >= 0; i--) {`
   Starts a loop: first `int i = arr.size() - 2`; keep repeating while `i >= 0` is true; after each iteration perform `i--`.
9. `if(arr[i] != largestValue) {`
   Runs the next block only when `arr[i] != largestValue` is true.
10. `return arr[i];`
   Ends the function and sends `arr[i]` back to the caller.
11. `return -1;`
   Ends the function and sends `-1` back to the caller.

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
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- sort: Rearranges a range into ascending order by default. This changes the container.
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
For [12,35,35,10,34], the largest becomes 35. The second value moves from 12 to 34; the repeated 35 is ignored.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
The two states represent the greatest two distinct values in the prefix. Every new value either enters these two positions or is too small to matter.

The key invariant (a fact that remains true after every useful iteration) is:
largest and secondLargest are the greatest and second-greatest distinct values seen so far.

7. COMPLEXITY
-------------
- Time complexity: O(n log n).
- Extra-space complexity: O(log n).
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
