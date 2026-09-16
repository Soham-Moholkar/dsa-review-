#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int answer = 0;
        unordered_map<int, int> frequency;
        for(int right = 0; right < fruits.size(); right++) {
            frequency[fruits[right]]++;
            while(frequency.size() > 2) {
                frequency[fruits[left]]--;
                if(frequency[fruits[left]] == 0) {
                    frequency.erase(fruits[left]);
                }
                left++;
            }
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Fruit Into Baskets
Platform: LeetCode
Pattern: Sliding Window

Problem goal:
Return the longest contiguous subarray containing at most two distinct values.

Core insight for this problem family:
Track counts of fruit types in the window. Allow at most two keys in the map. When a third type appears, shrink from the left until a type disappears.

This particular file uses the "Sliding frequency map" approach.
It is the intermediate comparison stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int totalFruit(vector<int>& fruits)`

- `int` means this function returns one signed integer.
- `totalFruit` is the function name the online judge calls.
- `fruits` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- Mutates an input object: Yes.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md).

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Sliding frequency map

This file implements exactly the approach named above. It demonstrates an intermediate method or a different time/space trade-off.

Important variables and what they mean:

- `fruits`: the fruit type at every consecutive tree position.
- `left`: the left boundary or left pointer of the active search/window.
- `answer`: the best or complete result found so far.
- `frequency`: counts how many times each value/key occurs in the relevant range.
- `right`: the right boundary or right pointer of the active search/window.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int totalFruit(vector<int>& fruits) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int left = 0;`
   Creates `left` and initializes it from `0`. This gives the algorithm its starting state.
7. `int answer = 0;`
   Creates `answer` and initializes it from `0`. This gives the algorithm its starting state.
8. `unordered_map<int, int> frequency;`
   Declares `frequency` so it can store state used by the algorithm.
9. `for(int right = 0; right < fruits.size(); right++) {`
   Starts a loop: first `int right = 0`; keep repeating while `right < fruits.size()` is true; after each iteration perform `right++`.
10. `frequency[fruits[right]]++;`
   Moves the relevant counter or pointer by one position.
11. `while(frequency.size() > 2) {`
   Repeats the following block while `frequency.size() > 2` is true.
12. `frequency[fruits[left]]--;`
   Moves the relevant counter or pointer by one position.
13. `if(frequency[fruits[left]] == 0) {`
   Runs the next block only when `frequency[fruits[left]] == 0` is true.
14. `frequency.erase(fruits[left]);`
   Removes the selected key/element so the container represents only currently relevant data.
15. `left++;`
   Moves the relevant counter or pointer by one position.
16. `answer = max(answer, right - left + 1);`
   Updates `answer` to `max(answer, right - left + 1)` for the next step of the algorithm.
17. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- unordered_map: Stores key-value pairs in a hash table, with expected O(1) operations.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- erase: Removes an element or position from a container.
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
[1,2,1,3]: the first three trees fit in two baskets. Adding 3 forces removal of 1, then 2; the new window [1,3] fits. Best length is 3.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
The frequency map represents the current window. Shrinking only while it is invalid leaves the longest feasible window for each right endpoint.

The key invariant (a fact that remains true after every useful iteration) is:
The current window contains no more than two keys in the frequency map.

7. COMPLEXITY
-------------
- Time complexity: O(n) average.
- Extra-space complexity: O(1) distinct keys.
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
