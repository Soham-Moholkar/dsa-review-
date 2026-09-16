#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int circularSubarraySum(vector<int>& arr) {
        int n = arr.size();
        int answer = INT_MIN;
        for(int start = 0; start < n; start++) {
            int sum = 0;
            for(int length = 1; length <= n; length++) {
                int index = (start + length - 1) % n;
                sum = sum + arr[index];
                answer = max(answer, sum);
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
Problem: Maximum Circular Subarray Sum
Platform: GeeksforGeeks
Pattern: Kadane's Algorithm

Problem goal:
Return the maximum sum of a non-empty contiguous subarray in a circular array.

Core insight for this problem family:
Compute ordinary maximum-subarray sum, minimum-subarray sum, and total sum. A wrapping answer is total minus a middle block of minimum sum. If all values are negative, return the ordinary maximum.

This particular file uses the "Enumerate circular starts and lengths" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int circularSubarraySum(vector<int>& arr)`

- `int` means this function returns one signed integer.
- `circularSubarraySum` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The input is nonempty.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Enumerate circular starts and lengths

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `n`: the number of elements currently considered.
- `answer`: the best or complete result found so far.
- `start`: the first index of a candidate subarray/window.
- `sum`: the running sum of the elements currently being examined.
- `length`: the length of the candidate sequence/subarray currently examined.
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
5. `int circularSubarraySum(vector<int>& arr) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = arr.size();`
   Creates `n` and initializes it from `arr.size()`. This gives the algorithm its starting state.
7. `int answer = INT_MIN;`
   Creates `answer` and initializes it from `INT_MIN`. This gives the algorithm its starting state.
8. `for(int start = 0; start < n; start++) {`
   Starts a loop: first `int start = 0`; keep repeating while `start < n` is true; after each iteration perform `start++`.
9. `int sum = 0;`
   Creates `sum` and initializes it from `0`. This gives the algorithm its starting state.
10. `for(int length = 1; length <= n; length++) {`
   Starts a loop: first `int length = 1`; keep repeating while `length <= n` is true; after each iteration perform `length++`.
11. `int index = (start + length - 1) % n;`
   Creates `index` and initializes it from `(start + length - 1) % n`. This gives the algorithm its starting state.
12. `sum = sum + arr[index];`
   Updates `sum` to `sum + arr[index]` for the next step of the algorithm.
13. `answer = max(answer, sum);`
   Updates `answer` to `max(answer, sum)` for the next step of the algorithm.
14. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- min / max: Returns the smaller/larger of the supplied values.
- INT_MIN / INT_MAX: The smallest/largest value representable by int.
- ++ / --: Increases/decreases a numeric variable by one.
- %: Remainder operator. a % b gives the remainder after integer division by b.

General syntax reminders:
- Parentheses `()` hold function arguments or conditions.
- Braces `{}` group statements into a class, function, loop, or condition block.
- Square brackets `[]` index a vector/array from zero; valid indices are 0 through size-1.
- A semicolon `;` ends a C++ statement.
- `==` compares values; `=` assigns a new value. Confusing them is a common bug.
- `<`, `>`, `<=`, and `>=` compare values.

5. DRY RUN
----------
[5,-3,5]: ordinary maximum is 7, minimum is -3, total is 7; wrapping gives 7-(-3)=10. For [-3,-2,-5], return -2, not zero.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Every wrapping subarray excludes one contiguous middle block. Minimizing that block maximizes what remains. The all-negative guard prevents choosing an empty complement.

The key invariant (a fact that remains true after every useful iteration) is:
Normal Kadane covers non-wrapping ranges; total-minimum covers wrapping ranges.

7. COMPLEXITY
-------------
- Time complexity: O(n^2).
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
