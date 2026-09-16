#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<long long, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            long long remaining = 1LL * target - nums[i];
            if(mp.find(remaining) != mp.end() && mp[remaining] != i) {
                return {i, mp[remaining]};
            }
        }
        return {-1, -1};
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Two Sum
Platform: LeetCode
Pattern: Hashing and Frequency Counting

Problem goal:
Return the two indexes whose values add up to the target.

Core insight for this problem family:
For each value x, look for target-x among earlier values. Check first, then insert x; this prevents reusing the same element. Store indices when the answer requires positions.

This particular file uses the "Two-pass hashmap" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> twoSum(vector<int>& nums, int target)`

- `vector<int>` means this function returns a dynamic array of integers.
- `twoSum` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `target` is one signed integer value.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Two-pass hashmap

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `target`: the value or sum the problem asks the algorithm to find.
- `mp`: a hash map from a previously seen value to its index.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `remaining`: the complement still needed to reach the target.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `vector<int> twoSum(vector<int>& nums, int target) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `unordered_map<long long, int> mp;`
   Declares `mp` so it can store state used by the algorithm.
7. `for(int i = 0; i < nums.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < nums.size()` is true; after each iteration perform `i++`.
8. `mp[nums[i]] = i;`
   Updates `mp[nums[i]]` to `i` for the next step of the algorithm.
9. `for(int i = 0; i < nums.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < nums.size()` is true; after each iteration perform `i++`.
10. `long long remaining = 1LL * target - nums[i];`
   Creates `remaining` and initializes it from `1LL * target - nums[i]`. This gives the algorithm its starting state.
11. `if(mp.find(remaining) != mp.end() && mp[remaining] != i) {`
   Runs the next block only when `mp.find(remaining) != mp.end() && mp[remaining] != i` is true.
12. `return {i, mp[remaining]};`
   Ends the function and sends `{i, mp[remaining]}` back to the caller.
13. `return {-1, -1};`
   Ends the function and sends `{-1, -1}` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- long long: A wider signed whole-number type, commonly 64 bits; it is used when an int may be too small.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- unordered_map: Stores key-value pairs in a hash table, with expected O(1) operations.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- find: Searches for a value/key. A failed standard-container search returns end(). For vectors, the algorithm form find(begin, end, value) performs a linear scan.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ++ / --: Increases/decreases a numeric variable by one.
- 1LL: A long long literal. Multiplying by 1LL promotes later arithmetic so it is performed with a wider integer type.

General syntax reminders:
- Parentheses `()` hold function arguments or conditions.
- Braces `{}` group statements into a class, function, loop, or condition block.
- Square brackets `[]` index a vector/array from zero; valid indices are 0 through size-1.
- A semicolon `;` ends a C++ statement.
- `==` compares values; `=` assigns a new value. Confusing them is a common bug.
- `<`, `>`, `<=`, and `>=` compare values.

5. DRY RUN
----------
For [2,7,11,15], target=9: store 2 at index 0. At 7, the missing value is 2, which is already present. Return indices [0,1] for LC or true for GFG.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Every pair is considered when its later element is visited. A successful earlier lookup uses a different index.

The key invariant (a fact that remains true after every useful iteration) is:
mp stores value-to-index mappings only for elements before i.

7. COMPLEXITY
-------------
- Time complexity: O(n) average.
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
