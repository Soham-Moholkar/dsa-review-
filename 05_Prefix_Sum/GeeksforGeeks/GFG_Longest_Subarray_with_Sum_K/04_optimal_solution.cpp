#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> firstIndex;
        firstIndex[0] = -1;
        long long prefixSum = 0;
        int answer = 0;
        for(int i = 0; i < arr.size(); i++) {
            prefixSum = prefixSum + arr[i];
            long long required = prefixSum - k;
            if(firstIndex.find(required) != firstIndex.end()) {
                answer = max(answer, i - firstIndex[required]);
            }
            if(firstIndex.find(prefixSum) == firstIndex.end()) {
                firstIndex[prefixSum] = i;
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
Problem: Longest Subarray with Sum K
Platform: GeeksforGeeks
Pattern: Prefix Sum and Prefix Sum with Hashmap

Problem goal:
Return the maximum length of a contiguous subarray whose sum equals k.

Core insight for this problem family:
Save the earliest index of every prefix sum. At prefix p, look for p-k. Its earliest index gives the longest matching subarray ending here.

This particular file uses the "Prefix sum with unordered_map" approach.
It is the preferred/optimal reference stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int longestSubarray(vector<int>& arr, int k)`

- `int` means this function returns one signed integer.
- `longestSubarray` is the function name the online judge calls.
- `arr` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `k` is one signed integer value.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Prefix sum with unordered_map

This file implements exactly the approach named above. It is the preferred implementation under the stated input contract.

Important variables and what they mean:

- `arr`: the input integer array used by the GFG-style function.
- `k`: the problem-supplied limit, window size, rotation count, or target parameter described by the signature.
- `firstIndex`: stores the earliest index at which each prefix state occurred.
- `prefixSum`: the cumulative sum from index 0 through the current position.
- `answer`: the best or complete result found so far.
- `i`: the main zero-based loop index; it usually marks the element currently being processed.
- `required`: the complementary prefix/value needed to form the requested answer.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int longestSubarray(vector<int>& arr, int k) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `unordered_map<long long, int> firstIndex;`
   Declares `firstIndex` so it can store state used by the algorithm.
7. `firstIndex[0] = -1;`
   Updates `firstIndex[0]` to `-1` for the next step of the algorithm.
8. `long long prefixSum = 0;`
   Creates `prefixSum` and initializes it from `0`. This gives the algorithm its starting state.
9. `int answer = 0;`
   Creates `answer` and initializes it from `0`. This gives the algorithm its starting state.
10. `for(int i = 0; i < arr.size(); i++) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < arr.size()` is true; after each iteration perform `i++`.
11. `prefixSum = prefixSum + arr[i];`
   Updates `prefixSum` to `prefixSum + arr[i]` for the next step of the algorithm.
12. `long long required = prefixSum - k;`
   Creates `required` and initializes it from `prefixSum - k`. This gives the algorithm its starting state.
13. `if(firstIndex.find(required) != firstIndex.end()) {`
   Runs the next block only when `firstIndex.find(required) != firstIndex.end()` is true.
14. `answer = max(answer, i - firstIndex[required]);`
   Updates `answer` to `max(answer, i - firstIndex[required])` for the next step of the algorithm.
15. `if(firstIndex.find(prefixSum) == firstIndex.end()) {`
   Runs the next block only when `firstIndex.find(prefixSum) == firstIndex.end()` is true.
16. `firstIndex[prefixSum] = i;`
   Updates `firstIndex[prefixSum]` to `i` for the next step of the algorithm.
17. `return answer;`
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
- unordered_map: Stores key-value pairs in a hash table, with expected O(1) operations.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- find: Searches for a value/key. A failed standard-container search returns end(). For vectors, the algorithm form find(begin, end, value) performs a linear scan.
- min / max: Returns the smaller/larger of the supplied values.
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
[1,-1,5,-2,3], k=3: at index 3 the prefix sum is 3. Initial prefix 0 at index -1 gives length 3-(-1)=4.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
Subtracting prefixes gives a subarray sum. For a fixed right endpoint, the earliest matching prefix maximizes length. Never overwrite an earlier index.

The key invariant (a fact that remains true after every useful iteration) is:
firstIndex stores the earliest index for each prefix sum, which maximizes later length.

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
