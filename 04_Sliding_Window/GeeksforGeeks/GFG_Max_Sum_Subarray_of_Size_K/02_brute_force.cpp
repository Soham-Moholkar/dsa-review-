#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSumSubarray(int K, vector<int> &Arr, int N) {
        long long answer = LLONG_MIN;
        for(int start = 0; start + K <= N; start++) {
            long long sum = 0;
            for(int i = start; i < start + K; i++) {
                sum = sum + Arr[i];
            }
            answer = max(answer, sum);
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Max Sum Subarray of Size K
Platform: GeeksforGeeks
Pattern: Sliding Window

Problem goal:
Return the maximum sum among all contiguous subarrays containing exactly K elements.

Core insight for this problem family:
Compute the sum of the first k values. Move the window by adding the incoming value and subtracting the outgoing value. Keep the largest sum.

This particular file uses the "Recalculate every window" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`long long maximumSumSubarray(int K, vector<int> &Arr, int N)`

- `long long` means this function returns a signed integer with a wider range than int.
- `maximumSumSubarray` is the function name the online judge calls.
- `K` is one signed integer value.
- `Arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `N` is one signed integer value.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Require 1 <= k <= n; any supplied N equals the array length.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Recalculate every window

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `K`: a value/container whose exact updates are shown in the numbered walkthrough below.
- `Arr`: a value/container whose exact updates are shown in the numbered walkthrough below.
- `N`: the array length supplied by the GFG function contract.
- `answer`: the best or complete result found so far.
- `start`: the first index of a candidate subarray/window.
- `sum`: the running sum of the elements currently being examined.
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
5. `long long maximumSumSubarray(int K, vector<int> &Arr, int N) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `long long answer = LLONG_MIN;`
   Creates `answer` and initializes it from `LLONG_MIN`. This gives the algorithm its starting state.
7. `for(int start = 0; start + K <= N; start++) {`
   Starts a loop: first `int start = 0`; keep repeating while `start + K <= N` is true; after each iteration perform `start++`.
8. `long long sum = 0;`
   Creates `sum` and initializes it from `0`. This gives the algorithm its starting state.
9. `for(int i = start; i < start + K; i++) {`
   Starts a loop: first `int i = start`; keep repeating while `i < start + K` is true; after each iteration perform `i++`.
10. `sum = sum + Arr[i];`
   Updates `sum` to `sum + Arr[i]` for the next step of the algorithm.
11. `answer = max(answer, sum);`
   Updates `answer` to `max(answer, sum)` for the next step of the algorithm.
12. `return answer;`
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
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- min / max: Returns the smaller/larger of the supplied values.
- LLONG_MIN: The smallest value representable by long long.
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
[1,12,-5,-6,50,3], k=4 gives window sums 2,51,42. The largest sum is 51; for the average problem return 51/4.0 = 12.75.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Two adjacent fixed-length windows share k-1 values. Replacing exactly the outgoing element preserves the exact sum. Start best from a real window, especially for negative inputs.

The key invariant (a fact that remains true after every useful iteration) is:
windowSum is the sum of the current K-element window.

7. COMPLEXITY
-------------
- Time complexity: O(n × k).
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
