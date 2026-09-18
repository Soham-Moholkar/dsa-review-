#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        int answer = INT_MAX;
        vector<int> chosen;
        function<void(int)> solve = [&](int index) {
            if(chosen.size() == m) {
                int minimumValue = *min_element(chosen.begin(), chosen.end());
                int maximumValue = *max_element(chosen.begin(), chosen.end());
                answer = min(answer, maximumValue - minimumValue);
                return;
            }
            if(index == n) return;
            chosen.push_back(a[index]);
            solve(index + 1);
            chosen.pop_back();
            solve(index + 1);
        };
        solve(0);
        return answer;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Chocolate Distribution Problem
Platform: GeeksforGeeks
Pattern: Sorting, Greedy Decisions, and Intervals

Problem goal:
Choose m packet sizes so the difference between maximum and minimum is minimized.

Core insight for this problem family:
Sort packet sizes. For every block of m consecutive packets, subtract its smallest value from its largest. Return the minimum difference.

This particular file uses the "Enumerate subsets recursively" approach.
It is the brute-force baseline stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int findMinDiff(vector<int>& a, int m)`

- `int` means this function returns one signed integer.
- `findMinDiff` is the function name the online judge calls.
- `a` is a dynamic array of integers; `&` passes the original object without copying it, so mutations remain visible to the caller.
- `m` is one signed integer value.
- Mutates an input object: No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough.

Contract/preconditions recorded for this repository:
Inputs follow the problem summary and the [contract guide](../../../docs/CONTRACTS.md). Require 1 <= m <= n.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: Enumerate subsets recursively

This file implements exactly the approach named above. It deliberately uses a direct baseline so you can see the complete search before optimizing it.

Important variables and what they mean:

- `a`: the input array of packet sizes or values for this problem.
- `m`: the number of packets that must be selected.
- `n`: the number of elements currently considered.
- `answer`: the best or complete result found so far.
- `chosen`: the packet values currently selected by recursive subset generation.
- `index`: a computed zero-based position in an array/vector.
- `minimumValue`: the smallest value found in the relevant range.
- `maximumValue`: the largest value found in the relevant range.

Read the executable code in this order:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int findMinDiff(vector<int>& a, int m) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int n = a.size();`
   Creates `n` and initializes it from `a.size()`. This gives the algorithm its starting state.
7. `int answer = INT_MAX;`
   Creates `answer` and initializes it from `INT_MAX`. This gives the algorithm its starting state.
8. `vector<int> chosen;`
   Declares `chosen` so it can store state used by the algorithm.
9. `function<void(int)> solve = [&](int index) {`
   Creates a callable named `solve`. `[&]` lets it use surrounding local variables by reference, which is needed for the recursive search.
10. `if(chosen.size() == m) {`
   Runs the next block only when `chosen.size() == m` is true.
11. `int minimumValue = *min_element(chosen.begin(), chosen.end());`
   Creates `minimumValue` and initializes it from `*min_element(chosen.begin(), chosen.end())`. This gives the algorithm its starting state.
12. `int maximumValue = *max_element(chosen.begin(), chosen.end());`
   Creates `maximumValue` and initializes it from `*max_element(chosen.begin(), chosen.end())`. This gives the algorithm its starting state.
13. `answer = min(answer, maximumValue - minimumValue);`
   Updates `answer` to `min(answer, maximumValue - minimumValue)` for the next step of the algorithm.
14. `return;`
   Ends the function.
15. `if(index == n) return;`
   Runs the next block only when `index == n` is true. The one-line action is `return;`.
16. `chosen.push_back(a[index]);`
   Appends the computed value to the end of the result/container.
17. `solve(index + 1);`
   Recursively calls the local `solve` function with the next index, exploring the next include/exclude decision.
18. `chosen.pop_back();`
   Removes the last element from the container.
19. `solve(index + 1);`
   Recursively calls the local `solve` function with the next index, exploring the next include/exclude decision.
20. `solve(0);`
   Starts the recursive search at index 0, before any input element has been considered.
21. `return answer;`
   Ends the function and sends `answer` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- function: A standard-library wrapper able to store a callable object such as a recursive lambda.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
- min / max: Returns the smaller/larger of the supplied values.
- min_element / max_element: Returns an iterator pointing to the smallest/largest element in a range.
- INT_MIN / INT_MAX: The smallest/largest value representable by int.
- lambda ([&]): Creates an unnamed function. [&] captures surrounding local variables by reference, so the lambda can read and modify them.
- recursion: A function calls itself on a smaller remaining choice. It needs a stopping condition to avoid infinite calls.
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
Trace this exact file using the first example in `testcases.md`. It applies the "Enumerate subsets recursively" approach, so follow the numbered executable statements above and record each listed variable after it changes. Do not reuse the optimal implementation's saved variables: this file may enumerate candidates, sort values, or build auxiliary state instead.

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
This file uses the exhaustive "Enumerate subsets recursively" strategy. The numbered walkthrough shows the complete candidate search performed by this implementation. Because every candidate allowed by the loops is examined before the answer is returned, a valid candidate cannot be skipped; the return/update condition keeps exactly the result required by the problem.

The key invariant (a fact that remains true after every useful iteration) is:
All candidates before the current loop position have been examined according to the code's condition, and the stored result reflects those candidates.

7. COMPLEXITY
-------------
- Time complexity: Exponential.
- Extra-space complexity: O(n) recursion stack.
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
