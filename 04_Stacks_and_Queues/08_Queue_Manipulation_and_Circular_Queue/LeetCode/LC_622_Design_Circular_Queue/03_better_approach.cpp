#include <bits/stdc++.h>
using namespace std;
class MyCircularQueue {
    vector<int> data;
    int head=0,count=0;
public:
    explicit MyCircularQueue(int k):data(k){
    }
    bool enQueue(int value){
        if(isFull())return false;
        data[(head+count)%data.size()]=value;
        ++count;
        return true;
    }
    bool deQueue(){
        if(isEmpty())return false;
        head=(head+1)%data.size();
        --count;
        return true;
    }
    int Front(){
        return isEmpty()?-1:data[head];
    }
    int Rear(){
        return isEmpty()?-1:data[(head+count-1)%data.size()];
    }
    bool isEmpty(){
        return count==0;
    }
    bool isFull(){
        return count==(int)data.size();
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Design Circular Queue
Platform: LeetCode
Pattern: Queue Manipulation and Circular Queue

Learning goal: Reuse fixed storage safely after removals and distinguish full from empty.
This file implements: Same efficient method (no distinct intermediate).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`class MyCircularQueue { public: MyCircularQueue(int k); bool enQueue(int value); bool deQueue(); int Front(); int Rear(); bool isEmpty(); bool isFull(); };`
- This is a design class. Its declared public methods form the local exercise interface.
- The judge calls each operation separately; use the problem README for empty/capacity behavior.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The count distinguishes an empty circular buffer from a full one.

Read these executable lines in their actual order. Nested indentation shows when
an action belongs to a class, method, branch, loop, or lambda:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class MyCircularQueue {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
4. `vector<int> data;`
   Declares `data` so it can store state used by the algorithm.
5. `int head=0,count=0;`
   Creates `head` and initializes it from `0,count=0`. This gives the algorithm its starting state.
6. `public:`
   Makes the following method callable by the judge.
7. `explicit MyCircularQueue(int k):data(k){`
   Defines the judge-facing function and lists the inputs it receives.
8. `bool enQueue(int value){`
   Defines the judge-facing function and lists the inputs it receives.
9. `if(isFull())return false;`
   Runs the next block only when `isFull()` is true. The one-line action is `return false;`.
10. `data[(head+count)%data.size()]=value;`
   Updates `data[(head+count)%data.size()]` to `value` for the next step of the algorithm.
11. `++count;`
   Moves the relevant counter or pointer by one position.
12. `return true;`
   Ends the function and sends `true` back to the caller.
13. `bool deQueue(){`
   Defines the judge-facing function and lists the inputs it receives.
14. `if(isEmpty())return false;`
   Runs the next block only when `isEmpty()` is true. The one-line action is `return false;`.
15. `head=(head+1)%data.size();`
   Updates `head` to `(head+1)%data.size()` for the next step of the algorithm.
16. `--count;`
   Moves the relevant counter or pointer by one position.
17. `return true;`
   Ends the function and sends `true` back to the caller.
18. `int Front(){`
   Defines the judge-facing function and lists the inputs it receives.
19. `return isEmpty()?-1:data[head];`
   Ends the function and sends `isEmpty()?-1:data[head]` back to the caller.
20. `int Rear(){`
   Defines the judge-facing function and lists the inputs it receives.
21. `return isEmpty()?-1:data[(head+count-1)%data.size()];`
   Ends the function and sends `isEmpty()?-1:data[(head+count-1)%data.size()]` back to the caller.
22. `bool isEmpty(){`
   Defines the judge-facing function and lists the inputs it receives.
23. `return count==0;`
   Ends the function and sends `count==0` back to the caller.
24. `bool isFull(){`
   Defines the judge-facing function and lists the inputs it receives.
25. `return count==(int)data.size();`
   Ends the function and sends `count==(int)data.size()` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- true / false: The two boolean values.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- ++ / --: Increases/decreases a numeric variable by one.
- %: Remainder operator. a % b gives the remainder after integer division by b.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: k=3: enQueue(1),enQueue(2),enQueue(3),enQueue(4),Rear(),isFull() -> true,true,true,false,3,true
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The count distinguishes an empty circular buffer from a full one.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(1) per operation.
- Extra space: O(capacity).
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
