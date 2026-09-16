#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int i = 0; i < nums.size(); i++) {
            if(seen.find(nums[i]) != seen.end()) return nums[i];
            seen.insert(nums[i]);
        }
        return -1;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Find the Duplicate Number
Platform: LeetCode
Pattern: Index Placement and Cyclic Sort

Problem goal:
Return the repeated value in n+1 values drawn from 1 through n without modifying nums.

Core insight for this problem family:
Treat values as next indices. Move a slow pointer one step and a fast pointer two steps until they meet. Reset one pointer to the starting value, then move both one step until they meet again.

This particular file uses the "Hash set" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int findDuplicate(vector<int>& nums)`

- `int` means this function returns one signed integer.
- `findDuplicate` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). There are n+1 entries in 1..n with exactly one distinct duplicated value; do not modify input.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Hash set

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `seen`: stores values or prefix states already visited.
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
5. `int findDuplicate(vector<int>& nums) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `unordered_set<int> seen;`
   Declares `seen` so it can store state used by the algorithm.
7. `for(int i = 0; i < nums.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < nums.size()` is true; after each iteration perform `i++`.
8. `if(seen.find(nums[i]) != seen.end()) return nums[i];`
   Runs the next block only when `seen.find(nums[i]) != seen.end()` is true. The one-line action is `return nums[i];`.
9. `seen.insert(nums[i]);`
   Stores this value in the set/map so later iterations can find it.
10. `return -1;`
   Ends the function and sends `-1` back to the caller.

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
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- insert: Adds an element to a container. A set ignores a value already present.
- find: Searches for a value/key. A failed standard-container search returns end(). For vectors, the algorithm form find(begin, end, value) performs a linear scan.
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
[1,3,4,2,2] traces 1 -> 3 -> 2 -> 4 -> 2, entering a cycle at value 2. The duplicate is 2.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
There are n+1 positions but only n possible next values. The reachable cycle entry is the repeated value. The second phase finds that entry; the input stays unchanged.

The key invariant (a fact that remains true after every useful iteration) is:
Floyd’s first phase finds a meeting inside the cycle; the second finds its entry.

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
