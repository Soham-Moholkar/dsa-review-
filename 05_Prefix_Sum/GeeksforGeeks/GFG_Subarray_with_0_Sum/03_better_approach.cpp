#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subArrayExists(vector<int>& arr) {
        vector<long long> prefix;
        long long sum = 0;
        prefix.push_back(0);
        for(int i = 0; i < arr.size(); i++) {
            sum = sum + arr[i];
            prefix.push_back(sum);
        }
        sort(prefix.begin(), prefix.end());
        for(int i = 1; i < prefix.size(); i++) {
            if(prefix[i] == prefix[i - 1]) {
                return true;
            }
        }
        return false;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Subarray with 0 Sum
Platform: GeeksforGeeks
Pattern: Prefix Sum and Prefix Sum with Hashmap

Problem goal:
Return whether any non-empty contiguous subarray has sum zero.

Core insight for this problem family:
Store prefix sums, starting with zero. If a prefix repeats, return true. Otherwise save it and continue.

This particular file uses the "Store, sort, and compare prefix sums" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`bool subArrayExists(vector<int>& arr)`

- `bool` means this function returns either true or false.
- `subArrayExists` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Store, sort, and compare prefix sums

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `prefix`: an array/container of cumulative values from the start.
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
5. `bool subArrayExists(vector<int>& arr) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<long long> prefix;`
   Declares `prefix` so it can store state used by the algorithm.
7. `long long sum = 0;`
   Creates `sum` and initializes it from `0`. This gives the algorithm its starting state.
8. `prefix.push_back(0);`
   Appends the computed value to the end of the result/container.
9. `for(int i = 0; i < arr.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < arr.size()` is true; after each iteration perform `i++`.
10. `sum = sum + arr[i];`
   Updates `sum` to `sum + arr[i]` for the next step of the algorithm.
11. `prefix.push_back(sum);`
   Appends the computed value to the end of the result/container.
12. `sort(prefix.begin(), prefix.end());`
   Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible.
13. `for(int i = 1; i < prefix.size(); i++) {`
   Starts a loop: first `int i = 1`; keep repeating while `i < prefix.size()` is true; after each iteration perform `i++`.
14. `if(prefix[i] == prefix[i - 1]) {`
   Runs the next block only when `prefix[i] == prefix[i - 1]` is true.
15. `return true;`
   Ends the function and sends `true` back to the caller.
16. `return false;`
   Ends the function and sends `false` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- long long: A wider signed whole-number type, commonly 64 bits; it is used when an int may be too small.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- sort: Rearranges a range into ascending order by default. This changes the container.
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
Trace this exact file using the first example in `testcases.md`. It applies the "Store, sort, and compare prefix sums" approach, so follow the numbered executable statements above and record each listed variable after it changes. Do not reuse the optimal implementation's saved variables: this file may enumerate candidates, sort values, or build auxiliary state instead.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
This file uses the intermediate "Store, sort, and compare prefix sums" strategy. Each operation in the numbered walkthrough preserves the information needed for the answer while arranging or storing it in a form that is easier to query. After every input element or required position has been processed, the final return/update condition selects the requested result.

The key invariant (a fact that remains true after every useful iteration) is:
After each completed iteration, the auxiliary or rearranged state represents every input item processed so far without discarding information needed for the answer.

7. COMPLEXITY
-------------
- Time complexity: O(n log n).
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
