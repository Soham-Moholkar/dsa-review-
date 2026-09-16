#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subarrayXor(vector<int>& arr, int k) {
        long long answer = 0;
        for(int start = 0; start < arr.size(); start++) {
            int currentXor = 0;
            for(int end = start; end < arr.size(); end++) {
                currentXor = currentXor ^ arr[end];
                if(currentXor == k) {
                    answer++;
                }
            }
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Count Subarrays with Given XOR
Platform: GeeksforGeeks
Pattern: Prefix Sum and Prefix Sum with Hashmap

Problem goal:
Count contiguous subarrays whose bitwise XOR equals k.

Core insight for this problem family:
Store how many times each prefix XOR has appeared. For the current prefix p, earlier prefixes equal to p XOR k form subarrays with XOR k. Seed prefix 0 with count 1.

This particular file uses the "Enumerate all subarrays" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`long long subarrayXor(vector<int>& arr, int k)`

- `long long` means this function returns a signed integer with a wider range than int.
- `subarrayXor` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `k` is one signed integer value.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Enumerate all subarrays

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `k`: the problem-supplied limit, window size, rotation count, or target parameter described by the signature.
- `answer`: the best or complete result found so far.
- `start`: the first index of a candidate subarray/window.
- `currentXor`: the XOR of the candidate subarray currently being enumerated.
- `end`: the final index or iterator boundary of a candidate range.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `long long subarrayXor(vector<int>& arr, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `long long answer = 0;`
   Creates `answer` and initializes it from `0`. This gives the algorithm its starting state.
7. `for(int start = 0; start < arr.size(); start++) {`
   Starts a loop: first `int start = 0`; keep repeating while `start < arr.size()` is true; after each iteration perform `start++`.
8. `int currentXor = 0;`
   Creates `currentXor` and initializes it from `0`. This gives the algorithm its starting state.
9. `for(int end = start; end < arr.size(); end++) {`
   Starts a loop: first `int end = start`; keep repeating while `end < arr.size()` is true; after each iteration perform `end++`.
10. `currentXor = currentXor ^ arr[end];`
   Updates `currentXor` to `currentXor ^ arr[end]` for the next step of the algorithm.
11. `if(currentXor == k) {`
   Runs the next block only when `currentXor == k` is true.
12. `answer++;`
   Moves the relevant counter or pointer by one position.
13. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- long long: A wider signed whole-number type, commonly 64 bits; it is used when an int may be too small.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- ++ / --: Increases/decreases a numeric variable by one.
- ^: Bitwise XOR. Equal bits cancel; x ^ x is 0 and x ^ 0 is x.

General syntax reminders:
- Parentheses `()` hold function arguments or conditions.
- Braces `{}` group statements into a class, function, loop, or condition block.
- Square brackets `[]` index a vector/array from zero; valid indices are 0 through size-1.
- A semicolon `;` ends a C++ statement.
- `==` compares values; `=` assigns a new value. Confusing them is a common bug.
- `<`, `>`, `<=`, and `>=` compare values.

5. DRY RUN
----------
For [4,2,2], k=4: prefix 4 matches initial 0 once; prefix 6 finds no earlier 2; final prefix 4 matches 0 again. There are two matching subarrays.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
XORing two prefixes cancels their shared elements. Therefore earlier XOR = current XOR k. Counting earlier prefixes before adding the current one excludes empty subarrays.

The key invariant (a fact that remains true after every useful iteration) is:
frequency stores how many times every earlier prefix XOR has occurred.

7. COMPLEXITY
-------------
- Time complexity: O(n^2).
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
