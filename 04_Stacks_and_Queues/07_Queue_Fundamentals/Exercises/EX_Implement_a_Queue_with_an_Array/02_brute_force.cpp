#include <bits/stdc++.h>
using namespace std;
class ArrayQueue {
    vector<int> data;
    size_t head=0;
public:
    void push(int x){
        data.push_back(x);
    }
    void pop(){
        if(empty())return;
        ++head;
        if(head==data.size()){
            data.clear();
            head=0;
        }
    }
    int front(){
        return empty()?-1:data[head];
    }
    int back(){
        return empty()?-1:data.back();
    }
    bool empty(){
        return head==data.size();
    }
    int size(){
        return data.size()-head;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Implement a Queue with an Array
Platform: Repository exercise
Pattern: Queue Fundamentals

Learning goal: Define the FIFO contract and consider how removed positions affect storage.
This file implements: Same efficient method (no distinct baseline).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`class ArrayQueue { public: void push(int x); void pop(); int front(); int back(); bool empty(); int size(); };`
- This is a design class. Its declared public methods form the local exercise interface.
- The judge calls each operation separately; use the problem README for empty/capacity behavior.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The head index identifies the oldest active item in the array.

Read these executable lines in their actual order. Nested indentation shows when
an action belongs to a class, method, branch, loop, or lambda:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class ArrayQueue {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
4. `vector<int> data;`
   Declares `data` so it can store state used by the algorithm.
5. `size_t head=0;`
   Updates `size_t head` to `0` for the next step of the algorithm.
6. `public:`
   Makes the following method callable by the judge.
7. `void push(int x){`
   Defines the judge-facing function and lists the inputs it receives.
8. `data.push_back(x);`
   Appends the computed value to the end of the result/container.
9. `void pop(){`
   Defines the judge-facing function and lists the inputs it receives.
10. `if(empty())return;`
   Runs the next block only when `empty()` is true. The one-line action is `return;`.
11. `++head;`
   Moves the relevant counter or pointer by one position.
12. `if(head==data.size()){`
   Runs the next block only when `head==data.size()` is true.
13. `data.clear();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `head=0;`
   Updates `head` to `0` for the next step of the algorithm.
15. `int front(){`
   Defines the judge-facing function and lists the inputs it receives.
16. `return empty()?-1:data[head];`
   Ends the function and sends `empty()?-1:data[head]` back to the caller.
17. `int back(){`
   Defines the judge-facing function and lists the inputs it receives.
18. `return empty()?-1:data.back();`
   Ends the function and sends `empty()?-1:data.back()` back to the caller.
19. `bool empty(){`
   Defines the judge-facing function and lists the inputs it receives.
20. `return head==data.size();`
   Ends the function and sends `head==data.size()` back to the caller.
21. `int size(){`
   Defines the judge-facing function and lists the inputs it receives.
22. `return data.size()-head;`
   Ends the function and sends `data.size()-head` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- front / back: Accesses the first or last element of a nonempty container.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: push(2),push(7),front(),back(),size() -> 2,7,2
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The head index identifies the oldest active item in the array.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(1) amortized per operation.
- Extra space: O(total arrivals).
- `n` means input length, `k` a window/capacity where used, `w` a word count,
  `L` word length, and `A` alphabet size. Design problems state per-operation
  costs. Recursive frames count; returned output storage may be additional.

8. EDGE CASES TO CHECK
----------------------
- Smallest valid input; empty access only when explicitly permitted.
- Repeated or equal values and strict versus nonstrict comparisons.
- The first and final valid indexes or a result that does not exist.
- Signed values and arithmetic near the declared input limits.

9. COMMON MISTAKES
------------------
- Failing to restore popped items or losing their relative order.
- Assuming an STL pop operation returns the removed value.
- Forgetting an element's index when the question asks for distance or range.
- Omitting recursion or auxiliary containers from space analysis.
- Claiming a live-platform signature without checking its current contract.

10. HOW TO STUDY THIS SOLUTION
------------------------------
1. Hide the code and describe the saved state in a sentence.
2. Explain each line and trace at least one counterexample without executing.
3. Compare all three files and their actual time/space tradeoffs.
4. Recode from memory and record your own failure in mistakes.md.

This explanatory comment does not change the C++ program's behavior.
*/
