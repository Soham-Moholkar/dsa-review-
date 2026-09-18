#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int zeroes = 0;
        int ones = 0;
        int twos = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) zeroes++;
            else if(arr[i] == 1) ones++;
            else twos++;
        }
        int index = 0;
        while(zeroes-- > 0) arr[index++] = 0;
        while(ones-- > 0) arr[index++] = 1;
        while(twos-- > 0) arr[index++] = 2;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Sort 0s, 1s and 2s
Platform: GeeksforGeeks
Pattern: Sorting, Greedy Decisions, and Intervals

Problem goal:
Sort an array containing only 0, 1, and 2.

Core insight for this problem family:
Use low, mid, and high to separate zeros, ones, unprocessed values, and twos. For a zero swap with low and advance both low and mid. For a two swap with high and only decrease high.

This particular file uses the "Count and overwrite" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`void sort012(vector<int>& arr)`

- `void` means this function does not return a value; the answer is written into an input object.
- `sort012` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Every value is 0, 1, or 2.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Count and overwrite

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `zeroes`: the number of zero values inside the current window.
- `ones`: the number of one values counted so far.
- `twos`: the number of two values counted so far.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `index`: a computed zero-based position in an array/vector.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `void sort012(vector<int>& arr) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int zeroes = 0;`
   Creates `zeroes` and initializes it from `0`. This gives the algorithm its starting state.
7. `int ones = 0;`
   Creates `ones` and initializes it from `0`. This gives the algorithm its starting state.
8. `int twos = 0;`
   Creates `twos` and initializes it from `0`. This gives the algorithm its starting state.
9. `for(int i = 0; i < arr.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < arr.size()` is true; after each iteration perform `i++`.
10. `if(arr[i] == 0) zeroes++;`
   Runs the next block only when `arr[i] == 0` is true. The one-line action is `zeroes++;`.
11. `else if(arr[i] == 1) ones++;`
   If earlier branches failed, runs this block when `arr[i] == 1` is true. The one-line action is `ones++;`.
12. `else twos++;`
   Handles the remaining case after the preceding condition(s) were false.
13. `int index = 0;`
   Creates `index` and initializes it from `0`. This gives the algorithm its starting state.
14. `while(zeroes-- > 0) arr[index++] = 0;`
   Repeats the following block while `zeroes-- > 0` is true. Its one-line body is `arr[index++] = 0;`.
15. `while(ones-- > 0) arr[index++] = 1;`
   Repeats the following block while `ones-- > 0` is true. Its one-line body is `arr[index++] = 1;`.
16. `while(twos-- > 0) arr[index++] = 2;`
   Repeats the following block while `twos-- > 0` is true. Its one-line body is `arr[index++] = 2;`.

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
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
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
Trace this exact file using the first example in `testcases.md`. It applies the "Count and overwrite" approach, so follow the numbered executable statements above and record each listed variable after it changes. Do not reuse the optimal implementation's saved variables: this file may enumerate candidates, sort values, or build auxiliary state instead.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
This file uses the intermediate "Count and overwrite" strategy. Each operation in the numbered walkthrough preserves the information needed for the answer while arranging or storing it in a form that is easier to query. After every input element or required position has been processed, the final return/update condition selects the requested result.

The key invariant (a fact that remains true after every useful iteration) is:
After each completed iteration, the auxiliary or rearranged state represents every input item processed so far without discarding information needed for the answer.

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
