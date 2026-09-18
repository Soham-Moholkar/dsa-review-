#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int low = 0;
        int mid = 0;
        int high = arr.size() - 1;
        while(mid <= high) {
            if(arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1) {
                mid++;
            }
            else {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Sort 0s, 1s and 2s
Platform: GeeksforGeeks
Pattern: Sorting, Greedy Decisions, and Intervals

Problem goal:
Sort an array containing only 0, 1, and 2.

Core insight for this problem family:
Use low, mid, and high to separate zeros, ones, unprocessed values, and twos. For a zero swap with low and advance both low and mid. For a two swap with high and only decrease high.

This particular file uses the "Dutch National Flag" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`void sort012(vector<int>& arr)`

- `void` means this function does not return a value; the answer is written into an input object.
- `sort012` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Every value is 0, 1, or 2.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Dutch National Flag

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `low`: the beginning of the still-unknown region in a three-way partition or search.
- `mid`: the middle position in binary search, or the scanning pointer in Dutch National Flag.
- `high`: the end of the still-unknown region.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `void sort012(vector<int>& arr) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int low = 0;`
   Creates `low` and initializes it from `0`. This gives the algorithm its starting state.
7. `int mid = 0;`
   Creates `mid` and initializes it from `0`. This gives the algorithm its starting state.
8. `int high = arr.size() - 1;`
   Creates `high` and initializes it from `arr.size() - 1`. This gives the algorithm its starting state.
9. `while(mid <= high) {`
   Repeats the following block while `mid <= high` is true.
10. `if(arr[mid] == 0) {`
   Runs the next block only when `arr[mid] == 0` is true.
11. `swap(arr[low], arr[mid]);`
   Exchanges the two selected values without needing a manual temporary variable.
12. `low++;`
   Moves the relevant counter or pointer by one position.
13. `mid++;`
   Moves the relevant counter or pointer by one position.
14. `else if(arr[mid] == 1) {`
   Defines the judge-facing function and lists the inputs it receives.
15. `mid++;`
   Moves the relevant counter or pointer by one position.
16. `else {`
   Handles the remaining case after the preceding condition(s) were false.
17. `swap(arr[mid], arr[high]);`
   Exchanges the two selected values without needing a manual temporary variable.
18. `high--;`
   Moves the relevant counter or pointer by one position.

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
- size: Returns the number of elements in a container.
- swap: Exchanges two stored values.
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
[2,0,1]: swap the 2 with the last element -> [1,0,2]. Inspect index 0 again, then move over 1. Swap 0 with low -> [0,1,2].

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Before each step, [0,low) contains zeros, [low,mid) ones, and (high,n) twos. The unknown region shrinks each step. A value swapped in from high still needs inspection.

The key invariant (a fact that remains true after every useful iteration) is:
Before low are 0s, low through mid-1 are 1s, and after high are 2s.

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
