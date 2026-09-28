#include <bits/stdc++.h>
using namespace std;
class LinkedQueue {
    struct Node{
        int value;
        Node* next;
        explicit Node(int v):value(v),next(nullptr){
        }
    }
    ;
    Node* head=nullptr;
    Node* tail=nullptr;
    int count=0;
public:
    LinkedQueue()=default;
    LinkedQueue(const LinkedQueue&)=delete;
    LinkedQueue& operator=(const LinkedQueue&)=delete;
    ~LinkedQueue(){
        while(head)pop();
    }
    void push(int x){
        Node* node=new Node(x);
        if(tail)tail->next=node;
        else head=node;
        tail=node;
        ++count;
    }
    void pop(){
        if(!head)return;
        Node* old=head;
        head=head->next;
        if(!head)tail=nullptr;
        delete old;
        --count;
    }
    int front(){
        return head?head->value:-1;
    }
    int back(){
        return tail?tail->value:-1;
    }
    bool empty(){
        return !head;
    }
    int size(){
        return count;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Implement a Queue with Linked Nodes
Platform: Repository exercise
Pattern: Queue Fundamentals

Learning goal: Compare head and tail updates when an initially empty queue gains or loses its last item.
This file implements: Fifo reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`class LinkedQueue { public: void push(int x); void pop(); int front(); int back(); bool empty(); int size(); };`
- This is a design class. Its declared public methods form the local exercise interface.
- The judge calls each operation separately; use the problem README for empty/capacity behavior.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The head and tail nodes identify the oldest and newest active values.

Read these executable lines in their actual order. Nested indentation shows when
an action belongs to a class, method, branch, loop, or lambda:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class LinkedQueue {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
4. `struct Node{`
   Performs this operation to maintain the state described in the algorithm walkthrough.
5. `int value;`
   Declares `value` so it can store state used by the algorithm.
6. `Node* next;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
7. `explicit Node(int v):value(v),next(nullptr){`
   Defines the judge-facing function and lists the inputs it receives.
8. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `Node* head=nullptr;`
   Updates `Node* head` to `nullptr` for the next step of the algorithm.
10. `Node* tail=nullptr;`
   Updates `Node* tail` to `nullptr` for the next step of the algorithm.
11. `int count=0;`
   Creates `count` and initializes it from `0`. This gives the algorithm its starting state.
12. `public:`
   Makes the following method callable by the judge.
13. `LinkedQueue()=default;`
   Updates `LinkedQueue()` to `default` for the next step of the algorithm.
14. `LinkedQueue(const LinkedQueue&)=delete;`
   Updates `LinkedQueue(const LinkedQueue&)` to `delete` for the next step of the algorithm.
15. `LinkedQueue& operator=(const LinkedQueue&)=delete;`
   Updates `LinkedQueue& operator` to `(const LinkedQueue&)=delete` for the next step of the algorithm.
16. `~LinkedQueue(){`
   Performs this operation to maintain the state described in the algorithm walkthrough.
17. `while(head)pop();`
   Repeats the following block while `head` is true. Its one-line body is `pop();`.
18. `void push(int x){`
   Defines the judge-facing function and lists the inputs it receives.
19. `Node* node=new Node(x);`
   Updates `Node* node` to `new Node(x)` for the next step of the algorithm.
20. `if(tail)tail->next=node;`
   Runs the next block only when `tail` is true. The one-line action is `tail->next=node;`.
21. `else head=node;`
   Handles the remaining case after the preceding condition(s) were false.
22. `tail=node;`
   Updates `tail` to `node` for the next step of the algorithm.
23. `++count;`
   Moves the relevant counter or pointer by one position.
24. `void pop(){`
   Defines the judge-facing function and lists the inputs it receives.
25. `if(!head)return;`
   Runs the next block only when `!head` is true. The one-line action is `return;`.
26. `Node* old=head;`
   Updates `Node* old` to `head` for the next step of the algorithm.
27. `head=head->next;`
   Updates `head` to `head->next` for the next step of the algorithm.
28. `if(!head)tail=nullptr;`
   Runs the next block only when `!head` is true. The one-line action is `tail=nullptr;`.
29. `delete old;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
30. `--count;`
   Moves the relevant counter or pointer by one position.
31. `int front(){`
   Defines the judge-facing function and lists the inputs it receives.
32. `return head?head->value:-1;`
   Ends the function and sends `head?head->value:-1` back to the caller.
33. `int back(){`
   Defines the judge-facing function and lists the inputs it receives.
34. `return tail?tail->value:-1;`
   Ends the function and sends `tail?tail->value:-1` back to the caller.
35. `bool empty(){`
   Defines the judge-facing function and lists the inputs it receives.
36. `return !head;`
   Ends the function and sends `!head` back to the caller.
37. `int size(){`
   Defines the judge-facing function and lists the inputs it receives.
38. `return count;`
   Ends the function and sends `count` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- bool: A type with only two values: true and false.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- const: Promises that the named value will not be changed through that declaration.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: push(2),push(7),front(),back() -> 2,7
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The head and tail nodes identify the oldest and newest active values.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(1) per operation.
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
