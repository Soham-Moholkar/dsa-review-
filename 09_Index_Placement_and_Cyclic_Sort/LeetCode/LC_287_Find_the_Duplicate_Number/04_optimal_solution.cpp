#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
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

This particular file uses the "Floyd cycle detection" approach.
It is the preferred/optimal reference stored in this problem folder.

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
Approach name: Floyd cycle detection

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `slow`: Floyd's pointer that advances one link at a time.
- `fast`: Floyd's pointer that advances two links at a time during cycle detection.

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
6. `int slow = nums[0];`
   Creates `slow` and initializes it from `nums[0]`. This gives the algorithm its starting state.
7. `int fast = nums[0];`
   Creates `fast` and initializes it from `nums[0]`. This gives the algorithm its starting state.
8. `do {`
   Starts a do-while loop, so its body runs at least once.
9. `slow = nums[slow];`
   Updates `slow` to `nums[slow]` for the next step of the algorithm.
10. `fast = nums[nums[fast]];`
   Updates `fast` to `nums[nums[fast]]` for the next step of the algorithm.
11. `} while(slow != fast);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
12. `slow = nums[0];`
   Updates `slow` to `nums[0]` for the next step of the algorithm.
13. `while(slow != fast) {`
   Repeats the following block while `slow != fast` is true.
14. `slow = nums[slow];`
   Updates `slow` to `nums[slow]` for the next step of the algorithm.
15. `fast = nums[fast];`
   Updates `fast` to `nums[fast]` for the next step of the algorithm.
16. `return slow;`
   Ends the function and sends `slow` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- while: Repeats a block while its condition remains true.
- do ... while: Runs the block once before checking whether it should repeat.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
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
