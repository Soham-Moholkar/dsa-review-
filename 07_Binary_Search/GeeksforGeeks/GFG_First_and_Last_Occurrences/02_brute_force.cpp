#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> find(vector<int>& arr, int x) {
        int first = -1;
        int last = -1;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == x) {
                if(first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return {first, last};
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: First and Last Occurrences
Platform: GeeksforGeeks
Pattern: Binary Search

Problem goal:
Return the first and last index of x in a sorted array, or {-1,-1}.

Core insight for this problem family:
Run two binary searches: one that continues left after a match and one that continues right. Return [-1,-1] when no match exists.

This particular file uses the "Linear scan" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`vector<int> find(vector<int>& arr, int x)`

- `vector<int>` means this function returns a dynamic array of integers.
- `find` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `x` is one signed integer value.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The array is sorted in nondecreasing order.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Linear scan

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `x`: the target/threshold value supplied by the problem.
- `first`: the first matching boundary/index, or a flag describing the first row.
- `last`: the last matching boundary/index or saved last value.
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
5. `vector<int> find(vector<int>& arr, int x) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int first = -1;`
   Creates `first` and initializes it from `-1`. This gives the algorithm its starting state.
7. `int last = -1;`
   Creates `last` and initializes it from `-1`. This gives the algorithm its starting state.
8. `for(int i = 0; i < arr.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < arr.size()` is true; after each iteration perform `i++`.
9. `if(arr[i] == x) {`
   Runs the next block only when `arr[i] == x` is true.
10. `if(first == -1) {`
   Runs the next block only when `first == -1` is true.
11. `first = i;`
   Updates `first` to `i` for the next step of the algorithm.
12. `last = i;`
   Updates `last` to `i` for the next step of the algorithm.
13. `return {first, last};`
   Ends the function and sends `{first, last}` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
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
Trace this exact file using the first example in `testcases.md`. It applies the "Linear scan" approach, so follow the numbered executable statements above and record each listed variable after it changes. Do not reuse the optimal implementation's saved variables: this file may enumerate candidates, sort values, or build auxiliary state instead.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
This file uses the exhaustive "Linear scan" strategy. The numbered walkthrough shows the complete candidate search performed by this implementation. Because every candidate allowed by the loops is examined before the answer is returned, a valid candidate cannot be skipped; the return/update condition keeps exactly the result required by the problem.

The key invariant (a fact that remains true after every useful iteration) is:
All candidates before the current loop position have been examined according to the code's condition, and the stored result reflects those candidates.

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
