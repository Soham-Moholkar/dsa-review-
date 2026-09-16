#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countDistinct(vector<int>& arr, int k) {
        vector<int> answer;
        for(int start = 0; start + k <= arr.size(); start++) {
            unordered_set<int> values;
            for(int i = start; i < start + k; i++) {
                values.insert(arr[i]);
            }
            answer.push_back(values.size());
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Count Distinct Elements in Every Window
Platform: GeeksforGeeks
Pattern: Sliding Window

Problem goal:
Return the number of distinct values in every contiguous window of size k.

Core insight for this problem family:
Maintain a frequency map for exactly one k-element window. Remove the outgoing value and erase its key if its count becomes zero. Add the incoming value.

This particular file uses the "Build a set for each window" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> countDistinct(vector<int>& arr, int k)`

- `vector<int>` means this function returns a dynamic array of integers.
- `countDistinct` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `k` is one signed integer value.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Require 1 <= k <= n; any supplied N equals the array length.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Build a set for each window

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `k`: the problem-supplied limit, window size, rotation count, or target parameter described by the signature.
- `answer`: the best or complete result found so far.
- `start`: the first index of a candidate subarray/window.
- `values`: stores the distinct values needed for quick membership checks.
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
5. `vector<int> countDistinct(vector<int>& arr, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<int> answer;`
   Declares `answer` so it can store state used by the algorithm.
7. `for(int start = 0; start + k <= arr.size(); start++) {`
   Starts a loop: first `int start = 0`; keep repeating while `start + k <= arr.size()` is true; after each iteration perform `start++`.
8. `unordered_set<int> values;`
   Declares `values` so it can store state used by the algorithm.
9. `for(int i = start; i < start + k; i++) {`
   Starts a loop: first `int i = start`; keep repeating while `i < start + k` is true; after each iteration perform `i++`.
10. `values.insert(arr[i]);`
   Stores this value in the set/map so later iterations can find it.
11. `answer.push_back(values.size());`
   Appends the computed value to the end of the result/container.
12. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- unordered_set: Stores unique values in a hash table, with expected O(1) insert and lookup.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- insert: Adds an element to a container. A set ignores a value already present.
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
[1,2,1,3], k=3: [1,2,1] has 2 distinct values. Sliding to [2,1,3] leaves one 1, retains 2, adds 3, and gives 3 distinct values.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
The map stores exactly the positive frequencies in the current window, so its number of keys is the requested distinct count.

The key invariant (a fact that remains true after every useful iteration) is:
frequency stores counts only for the current window.

7. COMPLEXITY
-------------
- Time complexity: O(n × k).
- Extra-space complexity: O(k).
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
