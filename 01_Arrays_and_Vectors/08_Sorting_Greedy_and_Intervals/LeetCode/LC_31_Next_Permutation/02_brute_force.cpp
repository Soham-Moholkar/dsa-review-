#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> original = nums;
        vector<int> current = nums;
        sort(current.begin(), current.end());
        vector<vector<int>> permutations;
        do {
            permutations.push_back(current);
        } while(next_permutation(current.begin(), current.end()));
        for(int i = 0; i < permutations.size(); i++) {
            if(permutations[i] == original) {
                nums = permutations[(i + 1) % permutations.size()];
                return;
            }
        }
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Next Permutation
Platform: LeetCode
Pattern: Sorting, Greedy Decisions, and Intervals

Problem goal:
Transform nums into the lexicographically next permutation, or the smallest permutation if none exists.

Core insight for this problem family:
Find the rightmost position smaller than its next value. Swap it with the rightmost larger value, then reverse the suffix. If no such position exists, reverse everything.

This particular file uses the "Generate and sort every permutation" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`void nextPermutation(vector<int>& nums)`

- `void` means this function does not return a value; the answer is written into an input object.
- `nextPermutation` is the function name the online judge calls.
- `nums` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Generate and sort every permutation

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `nums`: the input integer array used by the LeetCode-style function.
- `original`: an unchanged copy used for comparison or to prevent newly written markers from affecting the scan.
- `current`: the current candidate arrangement/value being processed.
- `permutations`: all generated unique arrangements in lexicographic order.
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
5. `void nextPermutation(vector<int>& nums) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `vector<int> original = nums;`
   Creates `original` and initializes it from `nums`. This gives the algorithm its starting state.
7. `vector<int> current = nums;`
   Creates `current` and initializes it from `nums`. This gives the algorithm its starting state.
8. `sort(current.begin(), current.end());`
   Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible.
9. `vector<vector<int>> permutations;`
   Declares `permutations` so it can store state used by the algorithm.
10. `do {`
   Starts a do-while loop, so its body runs at least once.
11. `permutations.push_back(current);`
   Appends the computed value to the end of the result/container.
12. `} while(next_permutation(current.begin(), current.end()));`
   Uses the standard algorithm to replace the sequence with its next lexicographic permutation.
13. `for(int i = 0; i < permutations.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < permutations.size()` is true; after each iteration perform `i++`.
14. `if(permutations[i] == original) {`
   Runs the next block only when `permutations[i] == original` is true.
15. `nums = permutations[(i + 1) % permutations.size()];`
   Updates `nums` to `permutations[(i + 1) % permutations.size()]` for the next step of the algorithm.
16. `return;`
   Ends the function.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- do ... while: Runs the block once before checking whether it should repeat.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- sort: Rearranges a range into ascending order by default. This changes the container.
- next_permutation: Changes a range to its next lexicographically greater ordering and wraps to the smallest ordering after the greatest one.
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
Trace this exact file using the first example in `testcases.md`. It applies the "Generate and sort every permutation" approach, so follow the numbered executable statements above and record each listed variable after it changes. Do not reuse the optimal implementation's saved variables: this file may enumerate candidates, sort values, or build auxiliary state instead.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
This file uses the exhaustive "Generate and sort every permutation" strategy. The numbered walkthrough shows the complete candidate search performed by this implementation. Because every candidate allowed by the loops is examined before the answer is returned, a valid candidate cannot be skipped; the return/update condition keeps exactly the result required by the problem.

The key invariant (a fact that remains true after every useful iteration) is:
All candidates before the current loop position have been examined according to the code's condition, and the stored result reflects those candidates.

7. COMPLEXITY
-------------
- Time complexity: O(n! × n).
- Extra-space complexity: O(n! × n).
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
