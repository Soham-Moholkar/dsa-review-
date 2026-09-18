#include <bits/stdc++.h>
using namespace std;

// Handbook contract: N == arr.size(), values in [1, P].
// Replace arr with frequencies of 1..N; ignore original values above N.
class Solution {
public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        (void)P;
        for (int &value : arr) {
            if (value > N) value = 0;
        }
        int i = 0;
        while (i < N) {
            if (arr[i] <= 0) {
                ++i; // Zero means consumed; negatives store counts.
                continue;
            }
            int index = arr[i] - 1;
            if (arr[index] > 0) {
                // Preserve the unprocessed value before using its cell as a counter.
                arr[i] = arr[index];
                arr[index] = -1;
            } else {
                --arr[index];
                arr[i] = 0;
                ++i;
            }
        }
        for (int &count : arr) count = -count;
    }
};
// O(N) time, O(1) extra space. Counts stay within [-N, 0], avoiding N*N overflow.

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Frequencies in a Limited Array
Platform: GeeksforGeeks
Pattern: Hashing and Frequency Counting

Problem goal:
Replace the first N positions with frequencies of values 1 through N; values may be limited by P.

Core insight for this problem family:
Use each cell as either an unprocessed positive value or a nonpositive counter. Move an unprocessed value out of the target cell before replacing that cell with -1. Further occurrences decrement the counter. Negate counters at the end.

This particular file uses the "Consume values into negative counters" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`void frequencyCount(vector<int>& arr, int N, int P)`

- `void` means this function does not return a value; the answer is written into an input object.
- `frequencyCount` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `N` is one signed integer value.
- `P` is one signed integer value.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). This is the handbook in-place (arr,N,P) version; values above N are ignored.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Consume values into negative counters

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `N`: the array length supplied by the GFG function contract.
- `P`: the upper bound on original values in the limited-frequency problem.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `index`: a computed zero-based position in an array/vector.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `void frequencyCount(vector<int>& arr, int N, int P) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `(void)P;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
7. `for (int &value : arr) {`
   Starts a range-based loop. `int &value : arr` means: take each element from the container in turn and run the block.
8. `if (value > N) value = 0;`
   Runs the next block only when `value > N` is true. The one-line action is `value = 0;`.
9. `int i = 0;`
   Creates `i` and initializes it from `0`. This gives the algorithm its starting state.
10. `while (i < N) {`
   Repeats the following block while `i < N` is true.
11. `if (arr[i] <= 0) {`
   Runs the next block only when `arr[i] <= 0` is true.
12. `++i;`
   Moves the relevant counter or pointer by one position.
13. `continue;`
   Skips the rest of this iteration and starts the next one.
14. `int index = arr[i] - 1;`
   Creates `index` and initializes it from `arr[i] - 1`. This gives the algorithm its starting state.
15. `if (arr[index] > 0) {`
   Runs the next block only when `arr[index] > 0` is true.
16. `arr[i] = arr[index];`
   Updates `arr[i]` to `arr[index]` for the next step of the algorithm.
17. `arr[index] = -1;`
   Updates `arr[index]` to `-1` for the next step of the algorithm.
18. `} else {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
19. `--arr[index];`
   Moves the relevant counter or pointer by one position.
20. `arr[i] = 0;`
   Updates `arr[i]` to `0` for the next step of the algorithm.
21. `++i;`
   Moves the relevant counter or pointer by one position.
22. `for (int &count : arr) count = -count;`
   Starts a range-based loop. `int &count : arr` means: take each element from the container in turn and run the block. Its one-line body is `count = -count;`.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- continue: Skips the remainder of the current loop iteration and begins the next one.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
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
[2,2,3]: process the first 2 and preserve the value from its target: [2,-1,3]. Process the second 2: [0,-2,3]. Process 3: [0,-2,-1]. Negate to get [0,2,1].

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Each original in-range value is consumed once and decrements exactly its own counter. Each iteration consumes a value or opens a new counter, so there are O(n) iterations. Counts never need n*n-sized storage.

The key invariant (a fact that remains true after every useful iteration) is:
Positive cells hold unprocessed values; nonpositive cells hold consumed slots or negative occurrence counts.

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
