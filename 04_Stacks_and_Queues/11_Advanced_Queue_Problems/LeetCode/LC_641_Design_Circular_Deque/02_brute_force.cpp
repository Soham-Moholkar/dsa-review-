#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque {
    vector<int> data;
    int head=0,count=0;
public:
    explicit MyCircularDeque(int k):data(k){
    }
    bool insertFront(int value){
        if(isFull())return false;
        head=(head-1+(int)data.size())%data.size();
        data[head]=value;
        ++count;
        return true;
    }
    bool insertLast(int value){
        if(isFull())return false;
        data[(head+count)%data.size()]=value;
        ++count;
        return true;
    }
    bool deleteFront(){
        if(isEmpty())return false;
        head=(head+1)%data.size();
        --count;
        return true;
    }
    bool deleteLast(){
        if(isEmpty())return false;
        --count;
        return true;
    }
    int getFront(){
        return isEmpty()?-1:data[head];
    }
    int getRear(){
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
Problem: Design Circular Deque
Platform: LeetCode
Pattern: Advanced Queue Problems

Learning goal: Extend wraparound reasoning to insertions and removals at both ends.
This file implements: Same efficient method (no distinct baseline).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`class MyCircularDeque { public: MyCircularDeque(int k); bool insertFront(int value); bool insertLast(int value); bool deleteFront(); bool deleteLast(); int getFront(); int getRear(); bool isEmpty(); bool isFull(); };`
- This is a design class. Its declared public methods form the local exercise interface.
- The judge calls each operation separately; use the problem README for empty/capacity behavior.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The head and count define the live circular deque positions.

Read these executable lines in their actual order. Nested indentation shows when
an action belongs to a class, method, branch, loop, or lambda:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class MyCircularDeque {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
4. `vector<int> data;`
   Declares `data` so it can store state used by the algorithm.
5. `int head=0,count=0;`
   Creates `head` and initializes it from `0,count=0`. This gives the algorithm its starting state.
6. `public:`
   Makes the following method callable by the judge.
7. `explicit MyCircularDeque(int k):data(k){`
   Defines the judge-facing function and lists the inputs it receives.
8. `bool insertFront(int value){`
   Defines the judge-facing function and lists the inputs it receives.
9. `if(isFull())return false;`
   Runs the next block only when `isFull()` is true. The one-line action is `return false;`.
10. `head=(head-1+(int)data.size())%data.size();`
   Updates `head` to `(head-1+(int)data.size())%data.size()` for the next step of the algorithm.
11. `data[head]=value;`
   Updates `data[head]` to `value` for the next step of the algorithm.
12. `++count;`
   Moves the relevant counter or pointer by one position.
13. `return true;`
   Ends the function and sends `true` back to the caller.
14. `bool insertLast(int value){`
   Defines the judge-facing function and lists the inputs it receives.
15. `if(isFull())return false;`
   Runs the next block only when `isFull()` is true. The one-line action is `return false;`.
16. `data[(head+count)%data.size()]=value;`
   Updates `data[(head+count)%data.size()]` to `value` for the next step of the algorithm.
17. `++count;`
   Moves the relevant counter or pointer by one position.
18. `return true;`
   Ends the function and sends `true` back to the caller.
19. `bool deleteFront(){`
   Defines the judge-facing function and lists the inputs it receives.
20. `if(isEmpty())return false;`
   Runs the next block only when `isEmpty()` is true. The one-line action is `return false;`.
21. `head=(head+1)%data.size();`
   Updates `head` to `(head+1)%data.size()` for the next step of the algorithm.
22. `--count;`
   Moves the relevant counter or pointer by one position.
23. `return true;`
   Ends the function and sends `true` back to the caller.
24. `bool deleteLast(){`
   Defines the judge-facing function and lists the inputs it receives.
25. `if(isEmpty())return false;`
   Runs the next block only when `isEmpty()` is true. The one-line action is `return false;`.
26. `--count;`
   Moves the relevant counter or pointer by one position.
27. `return true;`
   Ends the function and sends `true` back to the caller.
28. `int getFront(){`
   Defines the judge-facing function and lists the inputs it receives.
29. `return isEmpty()?-1:data[head];`
   Ends the function and sends `isEmpty()?-1:data[head]` back to the caller.
30. `int getRear(){`
   Defines the judge-facing function and lists the inputs it receives.
31. `return isEmpty()?-1:data[(head+count-1)%data.size()];`
   Ends the function and sends `isEmpty()?-1:data[(head+count-1)%data.size()]` back to the caller.
32. `bool isEmpty(){`
   Defines the judge-facing function and lists the inputs it receives.
33. `return count==0;`
   Ends the function and sends `count==0` back to the caller.
34. `bool isFull(){`
   Defines the judge-facing function and lists the inputs it receives.
35. `return count==(int)data.size();`
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
Use the first entry in testcases.md: k=3: insertLast(1),insertLast(2),insertFront(3),insertFront(4),getRear(),isFull() -> true,true,true,false,2,true
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The head and count define the live circular deque positions.
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
