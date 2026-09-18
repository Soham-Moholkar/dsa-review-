#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxWater(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) {
            return 0;
        }
        vector<int> leftMaximum(n);
        vector<int> rightMaximum(n);
        leftMaximum[0] = arr[0];
        for(int i = 1; i < n; i++) {
            leftMaximum[i] = max(leftMaximum[i - 1], arr[i]);
        }
        rightMaximum[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            rightMaximum[i] = max(rightMaximum[i + 1], arr[i]);
        }
        long long water = 0;
        for(int i = 0; i < n; i++) {
            water = water + min(leftMaximum[i], rightMaximum[i]) - arr[i];
        }
        return water;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Trapping Rain Water
Platform: GeeksforGeeks
Pattern: Two Pointers

Problem goal:
Return the total water trapped between elevation bars.

Core insight for this problem family:
Track the largest wall seen from each end. Process the smaller current boundary: its running maximum determines how much water can sit there.

This particular file uses the "Prefix and suffix maximum arrays" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`long long maxWater(vector<int>& arr)`

- `long long` means this function returns a signed integer with a wider range than int.
- `maxWater` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Prefix and suffix maximum arrays

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `n`: the number of elements currently considered.
- `leftMaximum`: the highest wall seen from the left.
- `rightMaximum`: the highest wall seen from the right.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `water`: the total trapped-water units accumulated so far.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `long long maxWater(vector<int>& arr) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = arr.size();`
   Creates `n` and initializes it from `arr.size()`. This gives the algorithm its starting state.
7. `if(n == 0) {`
   Runs the next block only when `n == 0` is true.
8. `return 0;`
   Ends the function and sends `0` back to the caller.
9. `vector<int> leftMaximum(n);`
   Declares `leftMaximum` so it can store state used by the algorithm.
10. `vector<int> rightMaximum(n);`
   Declares `rightMaximum` so it can store state used by the algorithm.
11. `leftMaximum[0] = arr[0];`
   Updates `leftMaximum[0]` to `arr[0]` for the next step of the algorithm.
12. `for(int i = 1; i < n; i++) {`
   Starts a loop: first `int i = 1`; keep repeating while `i < n` is true; after each iteration perform `i++`.
13. `leftMaximum[i] = max(leftMaximum[i - 1], arr[i]);`
   Updates `leftMaximum[i]` to `max(leftMaximum[i - 1], arr[i])` for the next step of the algorithm.
14. `rightMaximum[n - 1] = arr[n - 1];`
   Updates `rightMaximum[n - 1]` to `arr[n - 1]` for the next step of the algorithm.
15. `for(int i = n - 2; i >= 0; i--) {`
   Starts a loop: first `int i = n - 2`; keep repeating while `i >= 0` is true; after each iteration perform `i--`.
16. `rightMaximum[i] = max(rightMaximum[i + 1], arr[i]);`
   Updates `rightMaximum[i]` to `max(rightMaximum[i + 1], arr[i])` for the next step of the algorithm.
17. `long long water = 0;`
   Creates `water` and initializes it from `0`. This gives the algorithm its starting state.
18. `for(int i = 0; i < n; i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < n` is true; after each iteration perform `i++`.
19. `water = water + min(leftMaximum[i], rightMaximum[i]) - arr[i];`
   Updates `water` to `water + min(leftMaximum[i], rightMaximum[i]) - arr[i]` for the next step of the algorithm.
20. `return water;`
   Ends the function and sends `water` back to the caller.

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
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- min / max: Returns the smaller/larger of the supplied values.
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
Trace this exact file using the first example in `testcases.md`. It applies the "Prefix and suffix maximum arrays" approach, so follow the numbered executable statements above and record each listed variable after it changes. Do not reuse the optimal implementation's saved variables: this file may enumerate candidates, sort values, or build auxiliary state instead.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
This file uses the intermediate "Prefix and suffix maximum arrays" strategy. Each operation in the numbered walkthrough preserves the information needed for the answer while arranging or storing it in a form that is easier to query. After every input element or required position has been processed, the final return/update condition selects the requested result.

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
