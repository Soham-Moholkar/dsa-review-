# 04 — Stacks & Queues

Status: **completed reference curriculum**, 55 unsolved learner starters (30 Stack, 25 Queue/Deque) in 11 stages. [Arrays & Vectors](../01_Arrays_and_Vectors/) and [Strings](../02_Strings/) also have completed references. [Linked Lists](../INDEX.md) is still planned as module 03; the number 04 is intentional.

Each [problem](problem_manifest.json) has your untouched starter, a personal mistakes log, three implemented C++ reference approaches, study notes, and a blank revision table. Read the theory, add two personal test cases, attempt the live problem, and record your mistake before reading a reference. Reference availability never implies personal completion. Repository exercises define their own contract in their README. Live platforms may change a signature; follow the current judge when submitting.

Twenty-one numbered problems are GeeksforGeeks exercises. For contract comparisons and additional variants, use the [GFG practice guide](GFG_PRACTICE.md). These links do not change the 55-problem count.

## Learning route

| Stage | Track | Entries | Main question |
|---|---|---:|---|
| [01 Stack Fundamentals](01_Stack_Fundamentals/) | Stack | 1–5 | What does LIFO guarantee? |
| [02 Stack Manipulation and Recursion](02_Stack_Manipulation_and_Recursion/) | Stack | 6–9 | What does the temporary storage cost? |
| [03 Parentheses and Expressions](03_Parentheses_and_Expressions/) | Stack | 10–14 | What must wait until a matching close or operator? |
| [04 Monotonic Stack](04_Monotonic_Stack/) | Stack | 15–21 | Which earlier candidates can be discarded? |
| [05 Stack Range and Histogram](05_Stack_Range_and_Histogram/) | Stack | 22–26 | Where does each element's valid interval end? |
| [06 Advanced Stack Problems](06_Advanced_Stack_Problems/) | Stack | 27–30 | Which changing state is naturally LIFO? |
| [07 Queue Fundamentals](07_Queue_Fundamentals/) | Queue | 31–34 | What does FIFO guarantee? |
| [08 Queue Manipulation and Circular Queue](08_Queue_Manipulation_and_Circular_Queue/) | Queue | 35–40 | How can storage or other adapters preserve FIFO? |
| [09 Deque and Monotonic Queue](09_Deque_and_Monotonic_Queue/) | Queue | 41–45 | Which window candidates remain useful? |
| [10 Queue Simulation and Streams](10_Queue_Simulation_and_Streams/) | Queue | 46–50 | What happens as new work arrives? |
| [11 Advanced Queue Problems](11_Advanced_Queue_Problems/) | Queue | 51–55 | How do two ends and breadth-first layers behave? |

## Stack: the ADT and the C++ adapter

A **stack** specifies LIFO: the last item pushed is the first popped. Picture plates: push `4`, then `7`, then `9`; `top()` is `9`, and one `pop()` leaves `7` on top. The abstract data type describes behavior. `std::stack<T>` is a C++ *container adapter* that supplies this interface over an underlying container (by default `std::deque<T>`). A vector or linked nodes can implement the same behavior. An STL adapter does not expose iterators or random access.

```cpp
#include <stack>
std::stack<int> st;
st.push(4);                  // bottom [4]
st.push(7);                  // bottom [4, 7] top
int last = st.top();         // 7; check empty() first if uncertain
st.pop();                    // removes 7; returns void
bool none = st.empty();
std::size_t count = st.size();
```

`push`, `pop`, and `top` are normally O(1) at the stack end; `empty` and `size` are O(1). `top()` or `pop()` on an empty STL stack is invalid. `pop()` does **not** return the removed item. Copying the whole stack is O(n). If the underlying storage is a vector, occasional growth reallocates, so append is amortized O(1).

### Recursion, auxiliary storage, and expressions

Each recursive call waits on the program's **call stack** with its own parameters/local state. A depth of `n` can therefore use O(n) extra memory even when no `std::stack` appears; very deep recursion can exhaust call-stack space. An explicit auxiliary stack also uses O(n) space if it stores `n` items. Stage 02 asks you to choose and account for that storage; it does not prescribe one solution in advance.

For brackets, an opening delimiter awaits its matching close. `([{}])` is valid; `([)]` closes in the wrong nesting order. Check empty before examining a top. For expressions, **infix** puts an operator between operands (`2 + 3`), **postfix** after operands (`2 3 +`), and **prefix** before operands (`+ 2 3`). Parentheses and precedence affect an infix parser; in postfix/prefix the order itself encodes grouping. For subtraction and division, operand order matters. Read the live contract for unary signs, spaces, and division rules.

### Monotonic stack: one framework, four directions

A monotonic stack keeps candidates in sorted order by value so a later value can discard candidates it makes irrelevant. Increasing stacks retain values from small to large; decreasing stacks retain large to small (describe the order **from bottom to top** when you explain your invariant). Which way to scan and which comparison to use depends on whether the target is previous/next and greater/smaller. Draw the direction and strictness before coding.

| Primitive | Question at index `i` | Stage 04 exercise |
|---|---|---|
| NGE | Closest **strictly greater** element to the right | [Next Greater](04_Monotonic_Stack/15_GFG_Next_Greater_Element_to_the_Right/) |
| NSE | Closest **strictly smaller** element to the right | [Next Smaller](04_Monotonic_Stack/16_GFG_Next_Smaller_Element_to_the_Right/) |
| PGE | Closest **strictly greater** element to the left | [Previous Greater](04_Monotonic_Stack/17_GFG_Previous_Greater_Element_to_the_Left/) |
| PSE | Closest **strictly smaller** element to the left | [Previous Smaller](04_Monotonic_Stack/18_GFG_Previous_Smaller_Element_to_the_Left/) |

For `[2, 1, 4, 3]`, the next greater *values* are `[4, 4, -1, -1]`; the previous smaller values are `[-1, -1, 1, 1]`. These first four exercises return values. Later distance/range problems need **indices**, so decide what your stack stores. Equal values make `>` different from `>=`; specify who owns a tie for contribution counting. Each index is typically pushed once and popped at most once, giving O(n) total stack operations across a scan despite a nested-looking loop. The stack itself can occupy O(n) extra space. Circular scans revisit positions without changing the original array's length.

As a baseline, independently scan to the right of every element to look for its next greater neighbor: that can take O(n²) time and O(1) auxiliary space. The useful insight is that some earlier candidates cease to matter after a new element arrives. Write down exactly what the surviving stack entries mean, then justify every discard against that invariant. This analysis belongs in your notes after the attempt; the starter folders leave the implementation to you.

In a histogram, a bar's previous smaller and next smaller **boundaries** delimit the largest span in which that bar can be the limiting height. A small trace with heights `[2, 1, 2]`: height `1` can support width `3`; height `2` on either edge cannot support that full span. Derive the width from actual boundary indices, then decide how a missing boundary and equal heights are represented. The same interval idea can count an element's contribution to many subarrays; use a consistent strict/non-strict tie convention. The [two-pointer water exercise](../01_Arrays_and_Vectors/03_Two_Pointers/) is an earlier view of a related boundary problem.

Common stack mistakes: reading `top()` before `empty()`, expecting `pop()` to return a value, confusing value with index, using the wrong direction or inequality, counting recursive frames as O(1), assuming duplicate boundaries are unambiguous, and treating an available reference as a personally solved exercise.

## Queue: FIFO, circular storage, and two-ended windows

A **queue** specifies FIFO: the first arrival is the first to leave. Enqueue `4`, then `7`, then `9`; `front()` is `4` and `back()` is `9`; one `pop()` makes `7` the front. `std::queue<T>` is an adapter (default underlying `std::deque<T>`), not a freely indexable sequence.

```cpp
#include <queue>
std::queue<int> q;
q.push(4);
q.push(7);
int oldest = q.front();      // 4; check empty() first
int newest = q.back();       // 7
q.pop();                    // removes 4; returns void
bool none = q.empty();
std::size_t count = q.size();
```

Queue-end operations, `front`, `back`, `empty`, and `size` are normally O(1). Reading either end or popping an empty queue is invalid. In an array queue, a head position advances as elements leave. A **circular queue** wraps that position back into reusable slots of fixed capacity; keep a size or other explicit condition so full and empty do not look identical. Linked queue storage needs both a head and tail pointer; removing the last node must update both. You only need the basic node concept from stage 07: full Linked Lists study remains module 03. Two stacks can simulate a queue; distinguish the amortized cost of a sequence of operations from the worst cost of one operation.

### Deque and monotonic queue

`std::deque<T>` (double-ended queue) supports `push_front`, `push_back`, `pop_front`, `pop_back`, `front`, `back`, `empty`, and `size`. End operations are generally O(1); check nonempty before end access/removal. It is a sequence container with index access, while `std::queue` exposes only a restricted FIFO interface.

```cpp
#include <deque>
std::deque<int> dq;
dq.push_back(4);
dq.push_front(2);          // front [2, 4] back
int a = dq.front();        // 2
int b = dq.back();         // 4
dq.pop_front();           // [4]
dq.pop_back();            // []
```

An ordinary sliding window from [Arrays/Vectors](../01_Arrays_and_Vectors/04_Sliding_Window/) or [Strings](../02_Strings/05_Sliding_Window_Basics/) tracks a changing interval. A **monotonic queue** adds a deque of useful candidate **indices**. Unlike a monotonic stack, its oldest candidate may expire merely because the window moves, so both ends matter: one end can discard obsolete positions while the other end maintains candidate quality. For a maximum window over `[1, 3, -1]` of width two, the first windows have maxima `3, 3`; track which positions remain eligible rather than sorting each window. Each index normally enters and leaves at most once, yielding O(n) work and up to O(k) candidates for a fixed window of width `k`. Negative values can break the usual variable-size sum-window rule, motivating a later prefix/deque problem.

As a baseline, scan every width-`k` window to find its maximum: O(nk) time. A candidate deque can reuse information between neighboring windows in O(n) total time. State two invariants when you study it: which positions are still inside the window, and why the remaining candidate values are ordered.

FIFO also models service turns, arrival-order events, and streams: a recent-call counter evicts stale timestamps, while a bounded buffer evicts the oldest item when full. In **breadth-first** processing, the queue holds the current frontier; recording a level size separates the current time/step from the next. The three final grid exercises introduce level and multi-source reasoning; general graph traversal, graph representation, and graph algorithms belong in module 08.

A **priority queue** serves the highest-priority item rather than the oldest arrival. C++ `std::priority_queue` is typically heap-backed; its algorithms and exercises belong in planned module 07, [Heaps / Priority Queue](../INDEX.md).

Common queue mistakes: expecting `pop()` to return an element, confusing front/back, accessing empty ends, losing the last node's tail pointer, failing to wrap circular indices, forgetting window expiration, confusing a monotonic deque with a stack, and marking a newly available curriculum as personally solved.

## Practice checks

From the repository root, run `python3 scripts/validate_structure.py`, `python3 scripts/test_solutions.py --sanitize` for Arrays/Vectors, and `python3 scripts/test_curriculum_references.py --sanitize` for all 100 Strings and Stacks/Queues references. Neither runner executes learner attempts.

## Ordered problem list

| # | Track | Stage | Problem | Difficulty | Folder |
|---:|---|---|---|---|---|
| 1 | Stack | Stack Fundamentals | Implement a Stack with an Array | Easy | [`01_EX_Implement_a_Stack_with_an_Array`](01_Stack_Fundamentals/01_EX_Implement_a_Stack_with_an_Array/) |
| 2 | Stack | Stack Fundamentals | Implement a Stack with Linked Nodes | Easy | [`02_EX_Implement_a_Stack_with_Linked_Nodes`](01_Stack_Fundamentals/02_EX_Implement_a_Stack_with_Linked_Nodes/) |
| 3 | Stack | Stack Fundamentals | Baseball Game | Easy | [`03_LC_682_Baseball_Game`](01_Stack_Fundamentals/03_LC_682_Baseball_Game/) |
| 4 | Stack | Stack Fundamentals | Remove All Adjacent Duplicates in String | Easy | [`04_LC_1047_Remove_All_Adjacent_Duplicates_in_String`](01_Stack_Fundamentals/04_LC_1047_Remove_All_Adjacent_Duplicates_in_String/) |
| 5 | Stack | Stack Fundamentals | Validate Stack Sequences | Medium | [`05_LC_946_Validate_Stack_Sequences`](01_Stack_Fundamentals/05_LC_946_Validate_Stack_Sequences/) |
| 6 | Stack | Stack Manipulation and Recursion | Insert at the Bottom of a Stack | Easy | [`06_EX_Insert_at_the_Bottom_of_a_Stack`](02_Stack_Manipulation_and_Recursion/06_EX_Insert_at_the_Bottom_of_a_Stack/) |
| 7 | Stack | Stack Manipulation and Recursion | Reverse a Stack | Easy | [`07_GFG_Reverse_a_Stack`](02_Stack_Manipulation_and_Recursion/07_GFG_Reverse_a_Stack/) |
| 8 | Stack | Stack Manipulation and Recursion | Delete Middle Element of a Stack | Medium | [`08_GFG_Delete_Middle_Element_of_a_Stack`](02_Stack_Manipulation_and_Recursion/08_GFG_Delete_Middle_Element_of_a_Stack/) |
| 9 | Stack | Stack Manipulation and Recursion | Sort a Stack | Medium | [`09_GFG_Sort_a_Stack`](02_Stack_Manipulation_and_Recursion/09_GFG_Sort_a_Stack/) |
| 10 | Stack | Parentheses and Expressions | Valid Parentheses | Easy | [`10_GFG_Valid_Parentheses`](03_Parentheses_and_Expressions/10_GFG_Valid_Parentheses/) |
| 11 | Stack | Parentheses and Expressions | Detect Redundant Brackets | Medium | [`11_EX_Detect_Redundant_Brackets`](03_Parentheses_and_Expressions/11_EX_Detect_Redundant_Brackets/) |
| 12 | Stack | Parentheses and Expressions | Minimum Add to Make Parentheses Valid | Medium | [`12_LC_921_Minimum_Add_to_Make_Parentheses_Valid`](03_Parentheses_and_Expressions/12_LC_921_Minimum_Add_to_Make_Parentheses_Valid/) |
| 13 | Stack | Parentheses and Expressions | Evaluate Reverse Polish Notation | Medium | [`13_LC_150_Evaluate_Reverse_Polish_Notation`](03_Parentheses_and_Expressions/13_LC_150_Evaluate_Reverse_Polish_Notation/) |
| 14 | Stack | Parentheses and Expressions | Basic Calculator II | Medium | [`14_LC_227_Basic_Calculator_II`](03_Parentheses_and_Expressions/14_LC_227_Basic_Calculator_II/) |
| 15 | Stack | Monotonic Stack | Next Greater Element to the Right | Easy | [`15_GFG_Next_Greater_Element_to_the_Right`](04_Monotonic_Stack/15_GFG_Next_Greater_Element_to_the_Right/) |
| 16 | Stack | Monotonic Stack | Next Smaller Element to the Right | Easy | [`16_GFG_Next_Smaller_Element_to_the_Right`](04_Monotonic_Stack/16_GFG_Next_Smaller_Element_to_the_Right/) |
| 17 | Stack | Monotonic Stack | Previous Greater Element to the Left | Easy | [`17_GFG_Previous_Greater_Element_to_the_Left`](04_Monotonic_Stack/17_GFG_Previous_Greater_Element_to_the_Left/) |
| 18 | Stack | Monotonic Stack | Previous Smaller Element to the Left | Easy | [`18_GFG_Previous_Smaller_Element_to_the_Left`](04_Monotonic_Stack/18_GFG_Previous_Smaller_Element_to_the_Left/) |
| 19 | Stack | Monotonic Stack | Next Greater Element II | Medium | [`19_LC_503_Next_Greater_Element_II`](04_Monotonic_Stack/19_LC_503_Next_Greater_Element_II/) |
| 20 | Stack | Monotonic Stack | Online Stock Span | Medium | [`20_LC_901_Online_Stock_Span`](04_Monotonic_Stack/20_LC_901_Online_Stock_Span/) |
| 21 | Stack | Monotonic Stack | Daily Temperatures | Medium | [`21_LC_739_Daily_Temperatures`](04_Monotonic_Stack/21_LC_739_Daily_Temperatures/) |
| 22 | Stack | Stack Range and Histogram | Largest Rectangle in Histogram | Hard | [`22_GFG_Largest_Rectangle_in_Histogram`](05_Stack_Range_and_Histogram/22_GFG_Largest_Rectangle_in_Histogram/) |
| 23 | Stack | Stack Range and Histogram | Maximal Rectangle | Hard | [`23_LC_85_Maximal_Rectangle`](05_Stack_Range_and_Histogram/23_LC_85_Maximal_Rectangle/) |
| 24 | Stack | Stack Range and Histogram | Sum of Subarray Minimums | Medium | [`24_LC_907_Sum_of_Subarray_Minimums`](05_Stack_Range_and_Histogram/24_LC_907_Sum_of_Subarray_Minimums/) |
| 25 | Stack | Stack Range and Histogram | Sum of Subarray Ranges | Medium | [`25_LC_2104_Sum_of_Subarray_Ranges`](05_Stack_Range_and_Histogram/25_LC_2104_Sum_of_Subarray_Ranges/) |
| 26 | Stack | Stack Range and Histogram | Trapping Rain Water | Hard | [`26_LC_42_Trapping_Rain_Water`](05_Stack_Range_and_Histogram/26_LC_42_Trapping_Rain_Water/) |
| 27 | Stack | Advanced Stack Problems | Min Stack | Medium | [`27_GFG_Min_Stack`](06_Advanced_Stack_Problems/27_GFG_Min_Stack/) |
| 28 | Stack | Advanced Stack Problems | Asteroid Collision | Medium | [`28_LC_735_Asteroid_Collision`](06_Advanced_Stack_Problems/28_LC_735_Asteroid_Collision/) |
| 29 | Stack | Advanced Stack Problems | Remove K Digits | Medium | [`29_GFG_Remove_K_Digits`](06_Advanced_Stack_Problems/29_GFG_Remove_K_Digits/) |
| 30 | Stack | Advanced Stack Problems | Decode String | Medium | [`30_GFG_Decode_String`](06_Advanced_Stack_Problems/30_GFG_Decode_String/) |
| 31 | Queue/Deque | Queue Fundamentals | Implement a Queue with an Array | Easy | [`31_EX_Implement_a_Queue_with_an_Array`](07_Queue_Fundamentals/31_EX_Implement_a_Queue_with_an_Array/) |
| 32 | Queue/Deque | Queue Fundamentals | Implement a Queue with Linked Nodes | Easy | [`32_EX_Implement_a_Queue_with_Linked_Nodes`](07_Queue_Fundamentals/32_EX_Implement_a_Queue_with_Linked_Nodes/) |
| 33 | Queue/Deque | Queue Fundamentals | Time Needed to Buy Tickets | Easy | [`33_LC_2073_Time_Needed_to_Buy_Tickets`](07_Queue_Fundamentals/33_LC_2073_Time_Needed_to_Buy_Tickets/) |
| 34 | Queue/Deque | Queue Fundamentals | Number of Students Unable to Eat Lunch | Easy | [`34_LC_1700_Number_of_Students_Unable_to_Eat_Lunch`](07_Queue_Fundamentals/34_LC_1700_Number_of_Students_Unable_to_Eat_Lunch/) |
| 35 | Queue/Deque | Queue Manipulation and Circular Queue | Reverse a Queue | Easy | [`35_GFG_Reverse_a_Queue`](08_Queue_Manipulation_and_Circular_Queue/35_GFG_Reverse_a_Queue/) |
| 36 | Queue/Deque | Queue Manipulation and Circular Queue | Reverse First K Elements of a Queue | Easy | [`36_GFG_Reverse_First_K_Elements_of_a_Queue`](08_Queue_Manipulation_and_Circular_Queue/36_GFG_Reverse_First_K_Elements_of_a_Queue/) |
| 37 | Queue/Deque | Queue Manipulation and Circular Queue | Interleave the First and Second Halves of a Queue | Medium | [`37_GFG_Interleave_the_First_and_Second_Halves_of_a_Queue`](08_Queue_Manipulation_and_Circular_Queue/37_GFG_Interleave_the_First_and_Second_Halves_of_a_Queue/) |
| 38 | Queue/Deque | Queue Manipulation and Circular Queue | Design Circular Queue | Medium | [`38_LC_622_Design_Circular_Queue`](08_Queue_Manipulation_and_Circular_Queue/38_LC_622_Design_Circular_Queue/) |
| 39 | Queue/Deque | Queue Manipulation and Circular Queue | Implement Queue using Stacks | Easy | [`39_GFG_Implement_Queue_using_Stacks`](08_Queue_Manipulation_and_Circular_Queue/39_GFG_Implement_Queue_using_Stacks/) |
| 40 | Queue/Deque | Queue Manipulation and Circular Queue | Implement Stack using Queues | Easy | [`40_GFG_Implement_Stack_using_Queues`](08_Queue_Manipulation_and_Circular_Queue/40_GFG_Implement_Stack_using_Queues/) |
| 41 | Queue/Deque | Deque and Monotonic Queue | Practise Deque Operations | Easy | [`41_EX_Practise_Deque_Operations`](09_Deque_and_Monotonic_Queue/41_EX_Practise_Deque_Operations/) |
| 42 | Queue/Deque | Deque and Monotonic Queue | First Negative Integer in Every Window of Size K | Medium | [`42_GFG_First_Negative_Integer_in_Every_Window_of_Size_K`](09_Deque_and_Monotonic_Queue/42_GFG_First_Negative_Integer_in_Every_Window_of_Size_K/) |
| 43 | Queue/Deque | Deque and Monotonic Queue | Sliding Window Maximum | Hard | [`43_GFG_Sliding_Window_Maximum`](09_Deque_and_Monotonic_Queue/43_GFG_Sliding_Window_Maximum/) |
| 44 | Queue/Deque | Deque and Monotonic Queue | Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit | Medium | [`44_LC_1438_Longest_Continuous_Subarray_With_Absolute_Diff_Less_Than_or_Equal_to_Limit`](09_Deque_and_Monotonic_Queue/44_LC_1438_Longest_Continuous_Subarray_With_Absolute_Diff_Less_Than_or_Equal_to_Limit/) |
| 45 | Queue/Deque | Deque and Monotonic Queue | Shortest Subarray with Sum at Least K | Hard | [`45_LC_862_Shortest_Subarray_with_Sum_at_Least_K`](09_Deque_and_Monotonic_Queue/45_LC_862_Shortest_Subarray_with_Sum_at_Least_K/) |
| 46 | Queue/Deque | Queue Simulation and Streams | First Non-repeating Character in a Stream | Medium | [`46_GFG_First_Non_repeating_Character_in_a_Stream`](10_Queue_Simulation_and_Streams/46_GFG_First_Non_repeating_Character_in_a_Stream/) |
| 47 | Queue/Deque | Queue Simulation and Streams | Number of Recent Calls | Easy | [`47_LC_933_Number_of_Recent_Calls`](10_Queue_Simulation_and_Streams/47_LC_933_Number_of_Recent_Calls/) |
| 48 | Queue/Deque | Queue Simulation and Streams | Reveal Cards In Increasing Order | Medium | [`48_LC_950_Reveal_Cards_In_Increasing_Order`](10_Queue_Simulation_and_Streams/48_LC_950_Reveal_Cards_In_Increasing_Order/) |
| 49 | Queue/Deque | Queue Simulation and Streams | Dota2 Senate | Medium | [`49_LC_649_Dota2_Senate`](10_Queue_Simulation_and_Streams/49_LC_649_Dota2_Senate/) |
| 50 | Queue/Deque | Queue Simulation and Streams | Bounded Event Buffer | Medium | [`50_EX_Bounded_Event_Buffer`](10_Queue_Simulation_and_Streams/50_EX_Bounded_Event_Buffer/) |
| 51 | Queue/Deque | Advanced Queue Problems | Design Circular Deque | Medium | [`51_LC_641_Design_Circular_Deque`](11_Advanced_Queue_Problems/51_LC_641_Design_Circular_Deque/) |
| 52 | Queue/Deque | Advanced Queue Problems | Design Front Middle Back Queue | Medium | [`52_LC_1670_Design_Front_Middle_Back_Queue`](11_Advanced_Queue_Problems/52_LC_1670_Design_Front_Middle_Back_Queue/) |
| 53 | Queue/Deque | Advanced Queue Problems | Rotting Oranges | Medium | [`53_GFG_Rotting_Oranges`](11_Advanced_Queue_Problems/53_GFG_Rotting_Oranges/) |
| 54 | Queue/Deque | Advanced Queue Problems | Nearest Exit from Entrance in Maze | Medium | [`54_LC_1926_Nearest_Exit_from_Entrance_in_Maze`](11_Advanced_Queue_Problems/54_LC_1926_Nearest_Exit_from_Entrance_in_Maze/) |
| 55 | Queue/Deque | Advanced Queue Problems | As Far from Land as Possible | Medium | [`55_LC_1162_As_Far_from_Land_as_Possible`](11_Advanced_Queue_Problems/55_LC_1162_As_Far_from_Land_as_Possible/) |
