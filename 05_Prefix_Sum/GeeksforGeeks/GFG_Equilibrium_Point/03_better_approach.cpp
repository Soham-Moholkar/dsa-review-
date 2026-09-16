#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equilibriumPoint(vector<int>& arr) {
        int n = arr.size();
        vector<long long> prefix(n, 0);
        vector<long long> suffix(n, 0);
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        suffix[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + arr[i];
        }
        for(int i = 0; i < n; i++) {
            long long leftSum = i == 0 ? 0 : prefix[i - 1];
            long long rightSum = i == n - 1 ? 0 : suffix[i + 1];
            if(leftSum == rightSum) {
                return i + 1;
            }
        }
        return -1;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Equilibrium Point
Platform: GeeksforGeeks
Pattern: Prefix Sum and Prefix Sum with Hashmap

Problem goal:
Return the one-based index where the sum on the left equals the sum on the right, or -1.

Core insight for this problem family:
Compute the total sum. At each index subtract the current value from the remaining total, compare that right sum with the left sum, then add the current value to the left.

This particular file uses the "Prefix and suffix arrays" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int equilibriumPoint(vector<int>& arr)`

- `int` means this function returns one signed integer.
- `equilibriumPoint` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). The GFG handbook returns one-based positions; LC and the current GFG prompt use zero-based indices.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Prefix and suffix arrays

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `n`: the number of elements currently considered.
- `prefix`: an array/container of cumulative values from the start.
- `suffix`: an array/container of cumulative values from the end.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `leftSum`: the sum strictly to the left of the current index.
- `rightSum`: the sum strictly to the right of the current index.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int equilibriumPoint(vector<int>& arr) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = arr.size();`
   Creates `n` and initializes it from `arr.size()`. This gives the algorithm its starting state.
7. `vector<long long> prefix(n, 0);`
   Declares `prefix` so it can store state used by the algorithm.
8. `vector<long long> suffix(n, 0);`
   Declares `suffix` so it can store state used by the algorithm.
9. `prefix[0] = arr[0];`
   Updates `prefix[0]` to `arr[0]` for the next step of the algorithm.
10. `for(int i = 1; i < n; i++) {`
   Starts a loop: first `int i = 1`; keep repeating while `i < n` is true; after each iteration perform `i++`.
11. `prefix[i] = prefix[i - 1] + arr[i];`
   Updates `prefix[i]` to `prefix[i - 1] + arr[i]` for the next step of the algorithm.
12. `suffix[n - 1] = arr[n - 1];`
   Updates `suffix[n - 1]` to `arr[n - 1]` for the next step of the algorithm.
13. `for(int i = n - 2; i >= 0; i--) {`
   Starts a loop: first `int i = n - 2`; keep repeating while `i >= 0` is true; after each iteration perform `i--`.
14. `suffix[i] = suffix[i + 1] + arr[i];`
   Updates `suffix[i]` to `suffix[i + 1] + arr[i]` for the next step of the algorithm.
15. `for(int i = 0; i < n; i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < n` is true; after each iteration perform `i++`.
16. `long long leftSum = i == 0 ? 0 : prefix[i - 1];`
   Creates `leftSum` and initializes it from `i == 0 ? 0 : prefix[i - 1]`. This gives the algorithm its starting state.
17. `long long rightSum = i == n - 1 ? 0 : suffix[i + 1];`
   Creates `rightSum` and initializes it from `i == n - 1 ? 0 : suffix[i + 1]`. This gives the algorithm its starting state.
18. `if(leftSum == rightSum) {`
   Runs the next block only when `leftSum == rightSum` is true.
19. `return i + 1;`
   Ends the function and sends `i + 1` back to the caller.
20. `return -1;`
   Ends the function and sends `-1` back to the caller.

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
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
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
[1,7,3,6,5,6]: at index 3 both sides sum to 11. LC returns 3; the handbook GFG implementation returns position 4.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Before comparison, left excludes the current value and the remaining total is precisely the right side. The first equality is the leftmost equilibrium.

The key invariant (a fact that remains true after every useful iteration) is:
leftSum is the sum before i; totalSum after subtraction is the sum after i.

7. COMPLEXITY
-------------
- Time complexity: O(n).
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
