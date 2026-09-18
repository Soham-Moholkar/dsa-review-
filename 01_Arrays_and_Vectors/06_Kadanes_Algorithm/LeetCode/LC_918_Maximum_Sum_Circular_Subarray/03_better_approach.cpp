#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> doubled = nums;
        doubled.insert(doubled.end(), nums.begin(), nums.end());
        int answer = INT_MIN;
        for(int start = 0; start < n; start++) {
            int sum = 0;
            for(int end = start; end < start + n; end++) {
                sum = sum + doubled[end];
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
Problem: Maximum Sum Circular Subarray
Platform: LeetCode
Pattern: Kadane's Algorithm

Problem goal:
Return the maximum non-empty subarray sum when the array wraps circularly.

Core insight for this problem family:
Compute ordinary maximum-subarray sum, minimum-subarray sum, and total sum. A wrapping answer is total minus a middle block of minimum sum. If all values are negative, return the ordinary maximum.

This particular file uses the "Duplicate and enumerate bounded ranges" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int maxSubarraySumCircular(vector<int>& nums)`

- `int` means this function returns one signed integer.
- `maxSubarraySumCircular` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The input is nonempty.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Duplicate and enumerate bounded ranges

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `n`: the number of elements currently considered.
- `doubled`: a value/container whose exact updates are shown in the numbered walkthrough below.
- `answer`: the best or complete result found so far.
- `start`: the first index of a candidate subarray/window.
- `sum`: the running sum of the elements currently being examined.
- `end`: the final index or iterator boundary of a candidate range.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int maxSubarraySumCircular(vector<int>& nums) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = nums.size();`
   Creates `n` and initializes it from `nums.size()`. This gives the algorithm its starting state.
7. `vector<int> doubled = nums;`
   Creates `doubled` and initializes it from `nums`. This gives the algorithm its starting state.
8. `doubled.insert(doubled.end(), nums.begin(), nums.end());`
   Starts a do-while loop, so its body runs at least once.
9. `int answer = INT_MIN;`
   Creates `answer` and initializes it from `INT_MIN`. This gives the algorithm its starting state.
10. `for(int start = 0; start < n; start++) {`
   Starts a loop: first `int start = 0`; keep repeating while `start < n` is true; after each iteration perform `start++`.
11. `int sum = 0;`
   Creates `sum` and initializes it from `0`. This gives the algorithm its starting state.
12. `for(int end = start; end < start + n; end++) {`
   Starts a loop: first `int end = start`; keep repeating while `end < start + n` is true; after each iteration perform `end++`.
13. `sum = sum + doubled[end];`
   Updates `sum` to `sum + doubled[end]` for the next step of the algorithm.
14. `answer = max(answer, sum);`
   Updates `answer` to `max(answer, sum)` for the next step of the algorithm.
15. `return answer;`
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
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- insert: Adds an element to a container. A set ignores a value already present.
- min / max: Returns the smaller/larger of the supplied values.
- INT_MIN / INT_MAX: The smallest/largest value representable by int.
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
Trace this exact file using the first example in `testcases.md`. It applies the "Duplicate and enumerate bounded ranges" approach, so follow the numbered executable statements above and record each listed variable after it changes. Do not reuse the optimal implementation's saved variables: this file may enumerate candidates, sort values, or build auxiliary state instead.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
This file uses the intermediate "Duplicate and enumerate bounded ranges" strategy. Each operation in the numbered walkthrough preserves the information needed for the answer while arranging or storing it in a form that is easier to query. After every input element or required position has been processed, the final return/update condition selects the requested result.

The key invariant (a fact that remains true after every useful iteration) is:
After each completed iteration, the auxiliary or rearranged state represents every input item processed so far without discarding information needed for the answer.

7. COMPLEXITY
-------------
- Time complexity: O(n^2).
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
