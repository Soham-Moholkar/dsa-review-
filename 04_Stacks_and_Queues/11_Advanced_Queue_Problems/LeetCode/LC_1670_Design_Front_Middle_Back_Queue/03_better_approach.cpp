#include <bits/stdc++.h>
using namespace std;
class FrontMiddleBackQueue {
    deque<int> left,right;
    void balance(){
        while(left.size()<right.size()){
            left.push_back(right.front());
            right.pop_front();
        }
        while(left.size()>right.size()+1){
            right.push_front(left.back());
            left.pop_back();
        }
    }
public:
    FrontMiddleBackQueue()=default;
    void pushFront(int val){
        left.push_front(val);
        balance();
    }
    void pushMiddle(int val){
        if(left.size()>right.size()){
            right.push_front(left.back());
            left.pop_back();
        }
        left.push_back(val);
    }
    void pushBack(int val){
        right.push_back(val);
        balance();
    }
    int popFront(){
        if(left.empty())return -1;
        int v=left.front();
        left.pop_front();
        balance();
        return v;
    }
    int popMiddle(){
        if(left.empty())return -1;
        int v=left.back();
        left.pop_back();
        balance();
        return v;
    }
    int popBack(){
        if(left.empty())return -1;
        int v;
        if(!right.empty()){
            v=right.back();
            right.pop_back();
        }
        else{
            v=left.back();
            left.pop_back();
        }
        balance();
        return v;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Design Front Middle Back Queue
Platform: LeetCode
Pattern: Advanced Queue Problems

Learning goal: Maintain an explicit middle choice when both ends and the center can change.
This file implements: Same efficient method (no distinct intermediate).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`class FrontMiddleBackQueue { public: FrontMiddleBackQueue(); void pushFront(int val); void pushMiddle(int val); void pushBack(int val); int popFront(); int popMiddle(); int popBack(); };`
- This is a design class. Its declared public methods form the local exercise interface.
- The judge calls each operation separately; use the problem README for empty/capacity behavior.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The two halves remain balanced so the middle is available at an end.

Read these executable lines in their actual order. Nested indentation shows when
an action belongs to a class, method, branch, loop, or lambda:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class FrontMiddleBackQueue {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
4. `deque<int> left,right;`
   Declares `right` so it can store state used by the algorithm.
5. `void balance(){`
   Defines the judge-facing function and lists the inputs it receives.
6. `while(left.size()<right.size()){`
   Repeats the following block while `left.size()<right.size()` is true.
7. `left.push_back(right.front());`
   Appends the computed value to the end of the result/container.
8. `right.pop_front();`
   Removes the oldest element from the front of the deque after it becomes irrelevant.
9. `while(left.size()>right.size()+1){`
   Repeats the following block while `left.size()>right.size()+1` is true.
10. `right.push_front(left.back());`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `left.pop_back();`
   Removes the last element from the container.
12. `public:`
   Makes the following method callable by the judge.
13. `FrontMiddleBackQueue()=default;`
   Updates `FrontMiddleBackQueue()` to `default` for the next step of the algorithm.
14. `void pushFront(int val){`
   Defines the judge-facing function and lists the inputs it receives.
15. `left.push_front(val);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
16. `balance();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
17. `void pushMiddle(int val){`
   Defines the judge-facing function and lists the inputs it receives.
18. `if(left.size()>right.size()){`
   Runs the next block only when `left.size()>right.size()` is true.
19. `right.push_front(left.back());`
   Performs this operation to maintain the state described in the algorithm walkthrough.
20. `left.pop_back();`
   Removes the last element from the container.
21. `left.push_back(val);`
   Appends the computed value to the end of the result/container.
22. `void pushBack(int val){`
   Defines the judge-facing function and lists the inputs it receives.
23. `right.push_back(val);`
   Appends the computed value to the end of the result/container.
24. `balance();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
25. `int popFront(){`
   Defines the judge-facing function and lists the inputs it receives.
26. `if(left.empty())return -1;`
   Runs the next block only when `left.empty()` is true. The one-line action is `return -1;`.
27. `int v=left.front();`
   Creates `v` and initializes it from `left.front()`. This gives the algorithm its starting state.
28. `left.pop_front();`
   Removes the oldest element from the front of the deque after it becomes irrelevant.
29. `balance();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
30. `return v;`
   Ends the function and sends `v` back to the caller.
31. `int popMiddle(){`
   Defines the judge-facing function and lists the inputs it receives.
32. `if(left.empty())return -1;`
   Runs the next block only when `left.empty()` is true. The one-line action is `return -1;`.
33. `int v=left.back();`
   Creates `v` and initializes it from `left.back()`. This gives the algorithm its starting state.
34. `left.pop_back();`
   Removes the last element from the container.
35. `balance();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
36. `return v;`
   Ends the function and sends `v` back to the caller.
37. `int popBack(){`
   Defines the judge-facing function and lists the inputs it receives.
38. `if(left.empty())return -1;`
   Runs the next block only when `left.empty()` is true. The one-line action is `return -1;`.
39. `int v;`
   Declares `v` so it can store state used by the algorithm.
40. `if(!right.empty()){`
   Runs the next block only when `!right.empty()` is true.
41. `v=right.back();`
   Updates `v` to `right.back()` for the next step of the algorithm.
42. `right.pop_back();`
   Removes the last element from the container.
43. `else{`
   Handles the remaining case after the preceding condition(s) were false.
44. `v=left.back();`
   Updates `v` to `left.back()` for the next step of the algorithm.
45. `left.pop_back();`
   Removes the last element from the container.
46. `balance();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
47. `return v;`
   Ends the function and sends `v` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- deque: A double-ended queue that can efficiently add or remove elements at both ends.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- push_back: Adds one element to the end of a vector or deque.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
- front / back: Accesses the first or last element of a nonempty container.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: pushFront(1),pushBack(2),pushMiddle(3),popMiddle(),popFront(),popBack() -> 3,1,2
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The two halves remain balanced so the middle is available at an end.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(1) amortized per operation.
- Extra space: O(n).
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
