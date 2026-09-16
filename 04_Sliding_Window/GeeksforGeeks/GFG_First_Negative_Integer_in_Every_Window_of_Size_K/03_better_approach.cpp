#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> printFirstNegativeInteger(long long A[], long long N, long long K) {
        vector<int> negativeIndexes;
        for(int i = 0; i < N; i++) {
            if(A[i] < 0) {
                negativeIndexes.push_back(i);
            }
        }
        vector<long long> answer;
        int pointer = 0;
        for(int start = 0; start + K <= N; start++) {
            while(pointer < negativeIndexes.size() && negativeIndexes[pointer] < start) {
                pointer++;
            }
            if(pointer < negativeIndexes.size() && negativeIndexes[pointer] < start + K) {
                answer.push_back(A[negativeIndexes[pointer]]);
            }
            else {
                answer.push_back(0);
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
Problem: First Negative Integer in Every Window of Size K
Platform: GeeksforGeeks
Pattern: Sliding Window

Problem goal:
For every K-sized window, return its first negative value or 0 when none exists.

Core insight for this problem family:
Store indices of negative values in a deque. As the window moves, discard indices to the left of its start. The front is the first negative still inside.

This particular file uses the "Store all negative indexes and advance a pointer" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<long long> printFirstNegativeInteger(long long A[], long long N, long long K)`

- `vector<long long>` means this function returns a dynamic array of wide integers.
- `printFirstNegativeInteger` is the function name the online judge calls.
- `A` is one wide signed integer value; `[]` is a raw-array parameter and a separate length limits valid access.
- `N` is one wide signed integer value.
- `K` is one wide signed integer value.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Require 1 <= k <= n; any supplied N equals the array length.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Store all negative indexes and advance a pointer

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `A`: the raw input array used by the window function.
- `N`: the array length supplied by the GFG function contract.
- `K`: a value/container whose exact updates are shown in the numbered walkthrough below.
- `negativeIndexes`: stores indices of negative values that may still be the first negative in a window.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `answer`: the best or complete result found so far.
- `pointer`: an index into a stored list that advances without moving backwards.
- `start`: the first index of a candidate subarray/window.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `vector<long long> printFirstNegativeInteger(long long A[], long long N, long long K) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<int> negativeIndexes;`
   Declares `negativeIndexes` so it can store state used by the algorithm.
7. `for(int i = 0; i < N; i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < N` is true; after each iteration perform `i++`.
8. `if(A[i] < 0) {`
   Runs the next block only when `A[i] < 0` is true.
9. `negativeIndexes.push_back(i);`
   Appends the computed value to the end of the result/container.
10. `vector<long long> answer;`
   Declares `answer` so it can store state used by the algorithm.
11. `int pointer = 0;`
   Creates `pointer` and initializes it from `0`. This gives the algorithm its starting state.
12. `for(int start = 0; start + K <= N; start++) {`
   Starts a loop: first `int start = 0`; keep repeating while `start + K <= N` is true; after each iteration perform `start++`.
13. `while(pointer < negativeIndexes.size() && negativeIndexes[pointer] < start) {`
   Repeats the following block while `pointer < negativeIndexes.size() && negativeIndexes[pointer] < start` is true.
14. `pointer++;`
   Moves the relevant counter or pointer by one position.
15. `if(pointer < negativeIndexes.size() && negativeIndexes[pointer] < start + K) {`
   Runs the next block only when `pointer < negativeIndexes.size() && negativeIndexes[pointer] < start + K` is true.
16. `answer.push_back(A[negativeIndexes[pointer]]);`
   Appends the computed value to the end of the result/container.
17. `else {`
   Handles the remaining case after the preceding condition(s) were false.
18. `answer.push_back(0);`
   Appends the computed value to the end of the result/container.
19. `return answer;`
   Ends the function and sends `answer` back to the caller.

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
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- raw array ([]): In a function parameter, this is passed as a pointer to the first element; the separate length tells the code how many elements are valid.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
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
[12,-1,-7,8], k=3 gives -1 for [12,-1,-7] and -1 for [-1,-7,8]. A window with no stored negative gives 0.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Indices enter in increasing order, so after removing expired indices the front is the earliest valid negative. Each index enters and leaves at most once.

The key invariant (a fact that remains true after every useful iteration) is:
The deque stores negative indexes in increasing order and only from the current window.

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
