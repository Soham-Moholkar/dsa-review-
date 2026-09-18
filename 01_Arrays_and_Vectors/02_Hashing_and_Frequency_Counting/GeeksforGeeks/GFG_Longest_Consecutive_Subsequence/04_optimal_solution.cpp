#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> values;
        for(int i = 0; i < arr.size(); i++) {
            values.insert(arr[i]);
        }
        int maximumLength = 0;
        for(auto value : values) {
            if(value == INT_MIN || values.find(value - 1) == values.end()) {
                int currentValue = value;
                int currentLength = 1;
                while(currentValue != INT_MAX && values.find(currentValue + 1) != values.end()) {
                    currentValue++;
                    currentLength++;
                }
                maximumLength = max(maximumLength, currentLength);
            }
        }
        return maximumLength;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Longest Consecutive Subsequence
Platform: GeeksforGeeks
Pattern: Hashing and Frequency Counting

Problem goal:
Return the length of the longest set of consecutive integer values.

Core insight for this problem family:
Put distinct values into a hash set. Only start counting at a value whose predecessor is absent. Then walk upwards while consecutive values exist.

This particular file uses the "Hash set and sequence starts" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int longestConsecutive(vector<int>& arr)`

- `int` means this function returns one signed integer.
- `longestConsecutive` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Hash set and sequence starts

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `values`: stores the distinct values needed for quick membership checks.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `maximumLength`: the longest valid sequence length found so far.
- `value`: the current element/value taken from the input or a candidate range.
- `currentValue`: the sequence value currently being checked or extended.
- `currentLength`: the length of the consecutive sequence currently being extended.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int longestConsecutive(vector<int>& arr) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `unordered_set<int> values;`
   Declares `values` so it can store state used by the algorithm.
7. `for(int i = 0; i < arr.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < arr.size()` is true; after each iteration perform `i++`.
8. `values.insert(arr[i]);`
   Stores this value in the set/map so later iterations can find it.
9. `int maximumLength = 0;`
   Creates `maximumLength` and initializes it from `0`. This gives the algorithm its starting state.
10. `for(auto value : values) {`
   Starts a range-based loop. `auto value : values` means: take each element from the container in turn and run the block.
11. `if(value == INT_MIN || values.find(value - 1) == values.end()) {`
   Runs the next block only when `value == INT_MIN || values.find(value - 1) == values.end()` is true.
12. `int currentValue = value;`
   Creates `currentValue` and initializes it from `value`. This gives the algorithm its starting state.
13. `int currentLength = 1;`
   Creates `currentLength` and initializes it from `1`. This gives the algorithm its starting state.
14. `while(currentValue != INT_MAX && values.find(currentValue + 1) != values.end()) {`
   Repeats the following block while `currentValue != INT_MAX && values.find(currentValue + 1) != values.end()` is true.
15. `currentValue++;`
   Moves the relevant counter or pointer by one position.
16. `currentLength++;`
   Moves the relevant counter or pointer by one position.
17. `maximumLength = max(maximumLength, currentLength);`
   Updates `maximumLength` to `max(maximumLength, currentLength)` for the next step of the algorithm.
18. `return maximumLength;`
   Ends the function and sends `maximumLength` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- unordered_set: Stores unique values in a hash table, with expected O(1) insert and lookup.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- range-based for: Visits every element of a container directly, without manually writing an index.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- insert: Adds an element to a container. A set ignores a value already present.
- find: Searches for a value/key. A failed standard-container search returns end(). For vectors, the algorithm form find(begin, end, value) performs a linear scan.
- min / max: Returns the smaller/larger of the supplied values.
- INT_MIN / INT_MAX: The smallest/largest value representable by int.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
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
For [100,4,200,1,3,2], only 100, 200, and 1 start sequences. Starting at 1 visits 1,2,3,4, producing length 4.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Each sequence has one start and each distinct value is visited once in a forward walk. Hash lookups have expected constant cost; guard INT_MIN and INT_MAX before neighbour arithmetic.

The key invariant (a fact that remains true after every useful iteration) is:
A sequence is expanded only from a value whose predecessor is absent.

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
