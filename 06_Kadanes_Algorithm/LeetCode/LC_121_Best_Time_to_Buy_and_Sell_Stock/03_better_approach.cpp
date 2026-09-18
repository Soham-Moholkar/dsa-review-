#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suffixMaximum(n);
        suffixMaximum[n - 1] = prices[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffixMaximum[i] = max(suffixMaximum[i + 1], prices[i]);
        }
        int answer = 0;
        for(int i = 0; i < n; i++) {
            answer = max(answer, suffixMaximum[i] - prices[i]);
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Best Time to Buy and Sell Stock
Platform: LeetCode
Pattern: Kadane's Algorithm

Problem goal:
Return the best profit from one buy and one later sell.

Core insight for this problem family:
Track the cheapest earlier price and the greatest profit so far. At each day, compare selling today with the saved best, then update the cheapest price.

This particular file uses the "Suffix maximum" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int maxProfit(vector<int>& prices)`

- `int` means this function returns one signed integer.
- `maxProfit` is the function name the online judge calls.
- `prices` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The input is nonempty.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Suffix maximum

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `prices`: the stock price on each day, in chronological order.
- `n`: the number of elements currently considered.
- `suffixMaximum`: the best/largest value from each index through the end.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `answer`: the best or complete result found so far.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int maxProfit(vector<int>& prices) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = prices.size();`
   Creates `n` and initializes it from `prices.size()`. This gives the algorithm its starting state.
7. `vector<int> suffixMaximum(n);`
   Declares `suffixMaximum` so it can store state used by the algorithm.
8. `suffixMaximum[n - 1] = prices[n - 1];`
   Updates `suffixMaximum[n - 1]` to `prices[n - 1]` for the next step of the algorithm.
9. `for(int i = n - 2; i >= 0; i--) {`
   Starts a loop: first `int i = n - 2`; keep repeating while `i >= 0` is true; after each iteration perform `i--`.
10. `suffixMaximum[i] = max(suffixMaximum[i + 1], prices[i]);`
   Updates `suffixMaximum[i]` to `max(suffixMaximum[i + 1], prices[i])` for the next step of the algorithm.
11. `int answer = 0;`
   Creates `answer` and initializes it from `0`. This gives the algorithm its starting state.
12. `for(int i = 0; i < n; i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < n` is true; after each iteration perform `i++`.
13. `answer = max(answer, suffixMaximum[i] - prices[i]);`
   Updates `answer` to `max(answer, suffixMaximum[i] - prices[i])` for the next step of the algorithm.
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
Trace this exact file using the first example in `testcases.md`. It applies the "Suffix maximum" approach, so follow the numbered executable statements above and record each listed variable after it changes. Do not reuse the optimal implementation's saved variables: this file may enumerate candidates, sort values, or build auxiliary state instead.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
This file uses the intermediate "Suffix maximum" strategy. Each operation in the numbered walkthrough preserves the information needed for the answer while arranging or storing it in a form that is easier to query. After every input element or required position has been processed, the final return/update condition selects the requested result.

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
