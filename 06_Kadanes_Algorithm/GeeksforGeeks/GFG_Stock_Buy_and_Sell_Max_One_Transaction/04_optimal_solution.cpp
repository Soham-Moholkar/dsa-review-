#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProfit(vector<int>& prices) {
        int minimumPrice = prices[0];
        int answer = 0;
        for(int i = 1; i < prices.size(); i++) {
            answer = max(answer, prices[i] - minimumPrice);
            minimumPrice = min(minimumPrice, prices[i]);
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Stock Buy and Sell - Max One Transaction
Platform: GeeksforGeeks
Pattern: Kadane's Algorithm

Problem goal:
Return the maximum profit from one buy followed by one sell.

Core insight for this problem family:
Track the cheapest earlier price and the greatest profit so far. At each day, compare selling today with the saved best, then update the cheapest price.

This particular file uses the "Minimum price seen so far" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int maximumProfit(vector<int>& prices)`

- `int` means this function returns one signed integer.
- `maximumProfit` is the function name the online judge calls.
- `prices` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The input is nonempty.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Minimum price seen so far

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `prices`: the stock price on each day, in chronological order.
- `minimumPrice`: the cheapest stock price seen before or on the current day.
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
5. `int maximumProfit(vector<int>& prices) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int minimumPrice = prices[0];`
   Creates `minimumPrice` and initializes it from `prices[0]`. This gives the algorithm its starting state.
7. `int answer = 0;`
   Creates `answer` and initializes it from `0`. This gives the algorithm its starting state.
8. `for(int i = 1; i < prices.size(); i++) {`
   Starts a loop: first `int i = 1`; keep repeating while `i < prices.size()` is true; after each iteration perform `i++`.
9. `answer = max(answer, prices[i] - minimumPrice);`
   Updates `answer` to `max(answer, prices[i] - minimumPrice)` for the next step of the algorithm.
10. `minimumPrice = min(minimumPrice, prices[i]);`
   Updates `minimumPrice` to `min(minimumPrice, prices[i])` for the next step of the algorithm.
11. `return answer;`
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
[7,1,5,3,6,4]: price 1 becomes the cheapest buy. Selling at 6 gives profit 5; later price 4 cannot improve it.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Every legal transaction has a sell day. For each such day, the cheapest earlier buy maximizes that day's profit. Taking the best covers all transactions.

The key invariant (a fact that remains true after every useful iteration) is:
minimumPrice is the cheapest value before or at i; answer is the best valid profit so far.

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
