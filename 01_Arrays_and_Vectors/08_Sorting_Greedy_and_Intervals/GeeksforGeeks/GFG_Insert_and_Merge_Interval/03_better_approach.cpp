#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]) {
            answer.push_back(intervals[i]);
            i++;
        }
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        answer.push_back(newInterval);
        while(i < intervals.size()) {
            answer.push_back(intervals[i]);
            i++;
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Insert and Merge Interval
Platform: GeeksforGeeks
Pattern: Sorting, Greedy Decisions, and Intervals

Problem goal:
Insert a new interval into sorted non-overlapping intervals and merge overlaps.

Core insight for this problem family:
Copy intervals entirely before the new interval. Merge all intervals overlapping it. Append the merged interval, then copy the untouched intervals after it.

This particular file uses the "Three-phase linear insertion" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval)`

- `vector<vector<int>>` means this function returns a dynamic array whose elements are integer vectors.
- `insertInterval` is the function name the online judge calls.
- `intervals` is a two-dimensional dynamic integer matrix; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `newInterval` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Existing intervals are sorted by start and disjoint.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Three-phase linear insertion

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `intervals`: the working collection of intervals.
- `newInterval`: the interval that must be inserted and possibly expanded by overlaps.
- `answer`: the best or complete result found so far.
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
5. `vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<vector<int>> answer;`
   Declares `answer` so it can store state used by the algorithm.
7. `int i = 0;`
   Creates `i` and initializes it from `0`. This gives the algorithm its starting state.
8. `while(i < intervals.size() && intervals[i][1] < newInterval[0]) {`
   Repeats the following block while `i < intervals.size() && intervals[i][1] < newInterval[0]` is true.
9. `answer.push_back(intervals[i]);`
   Appends the computed value to the end of the result/container.
10. `i++;`
   Moves the relevant counter or pointer by one position.
11. `while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {`
   Repeats the following block while `i < intervals.size() && intervals[i][0] <= newInterval[1]` is true.
12. `newInterval[0] = min(newInterval[0], intervals[i][0]);`
   Updates `newInterval[0]` to `min(newInterval[0], intervals[i][0])` for the next step of the algorithm.
13. `newInterval[1] = max(newInterval[1], intervals[i][1]);`
   Updates `newInterval[1]` to `max(newInterval[1], intervals[i][1])` for the next step of the algorithm.
14. `i++;`
   Moves the relevant counter or pointer by one position.
15. `answer.push_back(newInterval);`
   Appends the computed value to the end of the result/container.
16. `while(i < intervals.size()) {`
   Repeats the following block while `i < intervals.size()` is true.
17. `answer.push_back(intervals[i]);`
   Appends the computed value to the end of the result/container.
18. `i++;`
   Moves the relevant counter or pointer by one position.
19. `return answer;`
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
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- min / max: Returns the smaller/larger of the supplied values.
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
Trace this exact file using the first example in `testcases.md`. It applies the "Three-phase linear insertion" approach, so follow the numbered executable statements above and record each listed variable after it changes. Do not reuse the optimal implementation's saved variables: this file may enumerate candidates, sort values, or build auxiliary state instead.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
This file uses the intermediate "Three-phase linear insertion" strategy. Each operation in the numbered walkthrough preserves the information needed for the answer while arranging or storing it in a form that is easier to query. After every input element or required position has been processed, the final return/update condition selects the requested result.

The key invariant (a fact that remains true after every useful iteration) is:
After each completed iteration, the auxiliary or rearranged state represents every input item processed so far without discarding information needed for the answer.

7. COMPLEXITY
-------------
- Time complexity: O(n).
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
