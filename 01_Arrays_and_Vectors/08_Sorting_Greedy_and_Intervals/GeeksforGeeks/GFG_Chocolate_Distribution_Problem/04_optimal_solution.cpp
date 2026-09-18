#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        if(m == 0 || a.size() < m) {
            return 0;
        }
        sort(a.begin(), a.end());
        int minimumDifference = INT_MAX;
        for(int right = m - 1; right < a.size(); right++) {
            int left = right - m + 1;
            minimumDifference = min(minimumDifference, a[right] - a[left]);
        }
        return minimumDifference;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Chocolate Distribution Problem
Platform: GeeksforGeeks
Pattern: Sorting, Greedy Decisions, and Intervals

Problem goal:
Choose m packet sizes so the difference between maximum and minimum is minimized.

Core insight for this problem family:
Sort packet sizes. For every block of m consecutive packets, subtract its smallest value from its largest. Return the minimum difference.

This particular file uses the "Sorted fixed-size greedy window" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int findMinDiff(vector<int>& a, int m)`

- `int` means this function returns one signed integer.
- `findMinDiff` is the function name the online judge calls.
- `a` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `m` is one signed integer value.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Require 1 <= m <= n.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Sorted fixed-size greedy window

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `a`: the input array of packet sizes or values for this problem.
- `m`: the number of packets that must be selected.
- `minimumDifference`: the smallest maximum-minus-minimum range found for m packets.
- `right`: the right boundary or right pointer of the active search/window.
- `left`: the left boundary or left pointer of the active search/window.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int findMinDiff(vector<int>& a, int m) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `if(m == 0 || a.size() < m) {`
   Runs the next block only when `m == 0 || a.size() < m` is true.
7. `return 0;`
   Ends the function and sends `0` back to the caller.
8. `sort(a.begin(), a.end());`
   Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible.
9. `int minimumDifference = INT_MAX;`
   Creates `minimumDifference` and initializes it from `INT_MAX`. This gives the algorithm its starting state.
10. `for(int right = m - 1; right < a.size(); right++) {`
   Starts a loop: first `int right = m - 1`; keep repeating while `right < a.size()` is true; after each iteration perform `right++`.
11. `int left = right - m + 1;`
   Creates `left` and initializes it from `right - m + 1`. This gives the algorithm its starting state.
12. `minimumDifference = min(minimumDifference, a[right] - a[left]);`
   Updates `minimumDifference` to `min(minimumDifference, a[right] - a[left])` for the next step of the algorithm.
13. `return minimumDifference;`
   Ends the function and sends `minimumDifference` back to the caller.

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
- min / max: Returns the smaller/larger of the supplied values.
- INT_MIN / INT_MAX: The smallest/largest value representable by int.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
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
[7,3,2,4,9,12,56], m=3 sorts to [2,3,4,7,9,12,56]. The first block has difference 4-2=2, which is best.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For any chosen m packets, replacing gaps between the smallest and largest with closer packets cannot increase the range. Thus some optimal selection is consecutive after sorting.

The key invariant (a fact that remains true after every useful iteration) is:
Each scanned sorted window represents a candidate group with smallest and largest at its ends.

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
