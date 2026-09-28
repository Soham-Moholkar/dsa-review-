#!/usr/bin/env python3
"""Create the 55 unsolved Stack/Queue exercises without overwriting learner work."""

from __future__ import annotations

import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MODULE = ROOT / "04_Stacks_and_Queues"
REPO = "https://github.com/Soham-Moholkar/dsa-review-"
STAGES = [
    ("01_Stack_Fundamentals", "Stack fundamentals", "LIFO, the STL adapter, and the underlying storage choices."),
    ("02_Stack_Manipulation_and_Recursion", "Stack manipulation and recursion", "Change a stack without forgetting what the call stack or auxiliary storage costs."),
    ("03_Parentheses_and_Expressions", "Parentheses and expressions", "Match nested delimiters and distinguish infix, postfix, and operator precedence."),
    ("04_Monotonic_Stack", "Monotonic stack", "Build the four nearest-neighbor primitives before circular and distance variants."),
    ("05_Stack_Range_and_Histogram", "Stack ranges and histograms", "Use nearest boundaries to understand valid ranges and element contributions."),
    ("06_Advanced_Stack_Problems", "Advanced stack problems", "Recognize stack state in design, collision, greedy deletion, and parsing."),
    ("07_Queue_Fundamentals", "Queue fundamentals", "FIFO, queue syntax, and array versus linked storage."),
    ("08_Queue_Manipulation_and_Circular_Queue", "Queue manipulation and circular queue", "Reorder a FIFO and design circular or cross-adapter implementations."),
    ("09_Deque_and_Monotonic_Queue", "Deque and monotonic queue", "Keep useful window candidates while old positions expire."),
    ("10_Queue_Simulation_and_Streams", "Queue simulation and streams", "Model arrivals, fair turns, and bounded event histories."),
    ("11_Advanced_Queue_Problems", "Advanced queue problems", "Design flexible deques and practise level/state expansion without a graph syllabus."),
]


def p(stage, title, source, difficulty, signature, concepts, prerequisites, goal, tests, contract=""):
    """source is a LeetCode number/slug, GFG URL, or 'repo'."""
    return dict(stage=stage, title=title, source=source, difficulty=difficulty,
                signature=signature, concepts=concepts, prerequisites=prerequisites,
                goal=goal, tests=tests, contract=contract)


PROBLEMS = [
    # Stage 1: first implement the ADT, then observe the STL in ordinary work.
    p(1,"Implement a Stack with an Array","repo","Easy","class ArrayStack { public: void push(int x); void pop(); int top(); bool empty(); int size(); };","LIFO; std::stack API; contiguous storage","vector; class methods","Define how the five basic operations behave, including an empty stack.",["push(2),push(7),top(),size() -> 7,2","push(4),pop(),empty() -> true","top() on empty -> -1"],"Use a growable array. pop() on empty does nothing; top() on empty returns -1. size() counts current items."),
    p(1,"Implement a Stack with Linked Nodes","repo","Easy","class LinkedStack { public: void push(int x); void pop(); int top(); bool empty(); int size(); };","LIFO; nodes; ownership","pointers; basic class design","Compare constant-time stack operations with linked storage and clean up owned nodes.",["push(3),push(5),top() -> 5","push(3),pop(),top() -> -1","empty() initially -> true"],"Use singly linked nodes. pop() on empty does nothing; top() on empty returns -1. Release owned nodes on destruction."),
    p(1,"Baseball Game","682/baseball-game","Easy","int calPoints(vector<string>& operations)","push; pop; top; rolling state","std::stack; vector<string>","Read a changing score history with valid undo and duplication commands.",["[\"5\",\"2\",\"C\",\"D\",\"+\"] -> 30","[\"1\",\"C\"] -> 0","[\"5\",\"-2\",\"4\",\"C\",\"D\",\"9\",\"+\",\"+\"] -> 27"]),
    p(1,"Remove All Adjacent Duplicates in String","1047/remove-all-adjacent-duplicates-in-string","Easy","string removeDuplicates(string s)","stack-like output; adjacency; cancellation","string push_back/pop_back or std::stack","Recognize when newly adjacent elements interact after earlier removals.",["\"abbaca\" -> \"ca\"","\"azxxzy\" -> \"ay\"","\"a\" -> \"a\""]),
    p(1,"Validate Stack Sequences","946/validate-stack-sequences","Medium","bool validateStackSequences(vector<int>& pushed, vector<int>& popped)","LIFO order; push/pop simulation","stack operations; two arrays","Test whether a proposed removal order is compatible with LIFO behavior.",["[1,2,3,4,5],[4,5,3,2,1] -> true","[1,2,3,4,5],[4,3,5,1,2] -> false","[1],[1] -> true"]),
    # Stage 2: auxiliary storage and recursion are explicit design choices.
    p(2,"Insert at the Bottom of a Stack","repo","Easy","void insertAtBottom(stack<int>& st, int value)","recursion; call stack; auxiliary space","push/pop/top; base cases","Place an element beneath the current stack while restoring existing order.",["bottom->top [1,2,3], 9 -> [9,1,2,3]","[], 4 -> [4]","[7], 2 -> [2,7]"],"Mutate the given stack; preserve the order of all existing elements. The rightmost displayed element is the top."),
    p(2,"Reverse a Stack","https://www.geeksforgeeks.org/problems/reverse-a-stack/1","Easy","void reverseStack(stack<int>& st)","auxiliary stack; recursion; reversal","insert-at-bottom; LIFO","Compare an explicit second stack with recursive call frames and account for extra space.",["bottom->top [1,2,3] -> [3,2,1]","[] -> []","[8] -> [8]"],"Mutate the given stack; the rightmost displayed element is the top."),
    p(2,"Delete Middle Element of a Stack","https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1","Medium","void deleteMiddle(stack<int>& st)","recursion; position; restoration","call stack; stack size","Keep the original order when removing the middle entry from LIFO storage.",["bottom->top [1,2,3,4,5] -> [1,2,4,5]","[1,2,3,4] -> [1,3,4]","[7] -> []"],"For even n, remove the lower middle (index (n-1)/2 from the bottom). Mutate the stack; rightmost is top."),
    p(2,"Sort a Stack","https://www.geeksforgeeks.org/problems/sort-a-stack/1","Medium","void sortStack(stack<int>& st)","recursion; auxiliary stack; ordering","insert-at-bottom; compare stack tops","Decide how to preserve order while placing values in a stack, and count hidden recursion space.",["bottom->top [3,1,2] -> [1,2,3]","[2,2,1] -> [1,2,2]","[] -> []"],"Mutate the stack into nondecreasing order from bottom to top; rightmost is top."),
    # Stage 3: the module theory introduces expression forms first.
    p(3,"Valid Parentheses","https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1","Easy","bool isValid(string s)","nested brackets; matching; empty state","stack<char>; delimiters","Recognize nesting and reject mismatched or unfinished delimiters.",["\"()[]{}\" -> true","\"([)]\" -> false","\"{[]}\" -> true"]),
    p(3,"Detect Redundant Brackets","repo","Medium","bool hasRedundantBrackets(string expression)","parentheses; expression grouping","valid brackets; operators","Distinguish grouping that changes an expression from an unnecessary pair.",["\"(a+b)\" -> false","\"((a+b))\" -> true","\"(a)\" -> true"],"Input has single-letter operands, binary + - * /, balanced parentheses, and no spaces. A pair is redundant when it encloses no operator or repeats a whole already grouped expression."),
    p(3,"Minimum Add to Make Parentheses Valid","921/minimum-add-to-make-parentheses-valid","Medium","int minAddToMakeValid(string s)","unmatched brackets; minimum edits","valid parentheses","Count precisely the missing delimiters needed to make an input valid.",["\"())\" -> 1","\"(((\" -> 3","\"()\" -> 0"]),
    p(3,"Evaluate Reverse Polish Notation","150/evaluate-reverse-polish-notation","Medium","int evalRPN(vector<string>& tokens)","postfix; operand order; integer division","stack<int>; arithmetic","Read an expression whose operators follow their operands, preserving subtraction/division order.",["[\"2\",\"1\",\"+\",\"3\",\"*\"] -> 9","[\"4\",\"13\",\"5\",\"/\",\"+\"] -> 6","[\"7\",\"-3\",\"/\"] -> -2"]),
    p(3,"Basic Calculator II","227/basic-calculator-ii","Medium","int calculate(string s)","infix; precedence; signs","postfix evaluation; parsing integers","Contrast operator precedence in infix with the immediate operand order of postfix.",["\"3+2*2\" -> 7","\" 3/2 \" -> 1","\" 3+5 / 2 \" -> 5"]),
    # Stage 4: four primitives with the same contract (strict comparisons, -1 absence).
    p(4,"Next Greater Element to the Right","https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1","Easy","vector<int> nextGreater(vector<int>& nums)","decreasing monotonic stack; right neighbor","stack; array indexes","Find the nearest strictly greater value to each element's right.",["[2,1,4,3] -> [4,4,-1,-1]","[3,3] -> [-1,-1]","[5] -> [-1]"],"Return the nearest strictly greater VALUE to the right of each position, or -1."),
    p(4,"Next Smaller Element to the Right","https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1","Easy","vector<int> nextSmaller(vector<int>& nums)","increasing monotonic stack; right neighbor","next greater; strict comparison","Swap the comparison direction without confusing equality with smaller.",["[2,1,4,3] -> [1,-1,3,-1]","[2,2] -> [-1,-1]","[1] -> [-1]"],"Return the nearest strictly smaller VALUE to the right of each position, or -1."),
    p(4,"Previous Greater Element to the Left","https://www.geeksforgeeks.org/problems/previous-greater-element/1","Easy","vector<int> previousGreater(vector<int>& nums)","decreasing monotonic stack; left neighbor","next greater; iteration direction","Track the closest greater predecessor rather than a future element.",["[2,1,4,3] -> [-1,2,-1,4]","[3,3] -> [-1,-1]","[5] -> [-1]"],"Return the nearest strictly greater VALUE to the left of each position, or -1."),
    p(4,"Previous Smaller Element to the Left","https://www.geeksforgeeks.org/problems/previous-smaller-element/1","Easy","vector<int> previousSmaller(vector<int>& nums)","increasing monotonic stack; left neighbor","next smaller; previous greater","Complete the four-direction nearest-neighbor toolkit and handle duplicates.",["[2,1,4,3] -> [-1,-1,1,1]","[2,2] -> [-1,-1]","[5] -> [-1]"],"Return the nearest strictly smaller VALUE to the left of each position, or -1."),
    p(4,"Next Greater Element II","503/next-greater-element-ii","Medium","vector<int> nextGreaterElements(vector<int>& nums)","circular scan; monotonic stack","next greater to right; modulo indexing","Adapt a nearest-neighbor pattern when traversal wraps around.",["[1,2,1] -> [2,-1,2]","[1,2,3,4,3] -> [2,3,4,-1,4]","[4] -> [-1]"]),
    p(4,"Online Stock Span","901/online-stock-span","Medium","class StockSpanner { public: StockSpanner(); int next(int price); };","previous greater; online state; span","previous greater; indices versus values","Reuse boundary reasoning when prices arrive one by one.",["next(100),next(80),next(60),next(70),next(60),next(75),next(85) -> 1,1,1,2,1,4,6","next(5),next(5) -> 1,2","next(9) -> 1"]),
    p(4,"Daily Temperatures","739/daily-temperatures","Medium","vector<int> dailyTemperatures(vector<int>& temperatures)","next greater; index distances","next greater; indices versus values","Return distances instead of neighbor values without losing position information.",["[73,74,75,71,69,72,76,73] -> [1,1,4,2,1,1,0,0]","[30,40,50,60] -> [1,1,1,0]","[30] -> [0]"]),
    # Stage 5: boundaries -> rectangle -> 2D -> contribution.
    p(5,"Largest Rectangle in Histogram","https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1","Hard","int largestRectangleArea(vector<int>& heights)","PSE/NSE boundaries; width; histogram","previous/next smaller indices","Explain why a bar's nearest lower boundaries determine the width it can support.",["[2,1,5,6,2,3] -> 10","[2,4] -> 4","[2,2,2] -> 6"]),
    p(5,"Maximal Rectangle","85/maximal-rectangle","Hard","int maximalRectangle(vector<vector<char>>& matrix)","row histogram; nearest boundaries","largest rectangle; matrix traversal","Recognize a familiar histogram inside a two-dimensional input.",["[[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]] -> 6","[[0]] -> 0","[[1]] -> 1"]),
    p(5,"Sum of Subarray Minimums","907/sum-of-subarray-minimums","Medium","int sumSubarrayMins(vector<int>& arr)","PSE/NSE; contribution; tie policy","histogram boundaries; modular arithmetic","Count the ranges in which one element acts as a minimum and resolve duplicate ownership.",["[3,1,2,4] -> 17","[11,81,94,43,3] -> 444","[2,2] -> 6"]),
    p(5,"Sum of Subarray Ranges","2104/sum-of-subarray-ranges","Medium","long long subArrayRanges(vector<int>& nums)","min/max contribution; duplicate tie policy","sum of minimums; long long","Extend boundary contributions to both minima and maxima.",["[1,2,3] -> 4","[1,3,3] -> 4","[4] -> 0"]),
    p(5,"Trapping Rain Water","42/trapping-rain-water","Hard","int trap(vector<int>& height)","bounded ranges; stack interpretation","previous/next greater; two-pointer basics","Compare the stack boundary view with the two-pointer lesson in Arrays/Vectors.",["[0,1,0,2,1,0,1,3,2,1,2,1] -> 6","[4,2,0,3,2,5] -> 9","[1] -> 0"]),
    # Stage 6: distinct stack uses, rather than four more neighbor exercises.
    p(6,"Min Stack","https://www.geeksforgeeks.org/problems/special-stack/1","Medium","class MinStack { public: MinStack(); void push(int val); void pop(); int top(); int getMin(); };","aggregate state; stack design","push/pop/top; class state","Design an API that reports a changing minimum alongside ordinary stack operations.",["push(-2),push(0),push(-3),getMin(),pop(),top(),getMin() -> -3,0,-2","push(2),push(2),getMin() -> 2","push(4),getMin() -> 4"]),
    p(6,"Asteroid Collision","735/asteroid-collision","Medium","vector<int> asteroidCollision(vector<int>& asteroids)","stack simulation; directions; cancellation","stack-like output","Determine which pairs can interact while preserving surviving order.",["[5,10,-5] -> [5,10]","[8,-8] -> []","[10,2,-5] -> [10]"]),
    p(6,"Remove K Digits","https://www.geeksforgeeks.org/problems/remove-k-digits/1","Medium","string removeKdigits(string num, int k)","stack; greedy choice; leading zeros","stack-like output; string digits","Reason about the earliest digits that affect numeric order.",["\"1432219\",3 -> \"1219\"","\"10200\",1 -> \"200\"","\"10\",2 -> \"0\""]),
    p(6,"Decode String","https://www.geeksforgeeks.org/problems/decode-the-string2444/1","Medium","string decodeString(string s)","nested frames; multi-digit counts; parsing","bracket matching; strings","Track nested repetition and restore the enclosing parse context.",["\"3[a]2[bc]\" -> \"aaabcbc\"","\"3[a2[c]]\" -> \"accaccacc\"","\"2[abc]3[cd]ef\" -> \"abcabccdcdcdef\""]),
    # Stage 7: FIFO and implementations before patterns.
    p(7,"Implement a Queue with an Array","repo","Easy","class ArrayQueue { public: void push(int x); void pop(); int front(); int back(); bool empty(); int size(); };","FIFO; std::queue API; storage","vector; class methods","Define the FIFO contract and consider how removed positions affect storage.",["push(2),push(7),front(),back(),size() -> 2,7,2","push(4),pop(),empty() -> true","front() on empty -> -1"],"Use an array-like storage choice. pop() on empty does nothing; front()/back() on empty return -1."),
    p(7,"Implement a Queue with Linked Nodes","repo","Easy","class LinkedQueue { public: void push(int x); void pop(); int front(); int back(); bool empty(); int size(); };","FIFO; head/tail nodes; ownership","pointers; basic class design","Compare head and tail updates when an initially empty queue gains or loses its last item.",["push(2),push(7),front(),back() -> 2,7","push(4),pop(),empty() -> true","back() on empty -> -1"],"Use singly linked nodes. pop() on empty does nothing; front()/back() on empty return -1. Release owned nodes on destruction."),
    p(7,"Time Needed to Buy Tickets","2073/time-needed-to-buy-tickets","Easy","int timeRequiredToBuy(vector<int>& tickets, int k)","FIFO turns; process simulation","queue push/pop; indexes","Model repeated fair turns without changing the identity of the target person.",["[2,3,2],2 -> 6","[5,1,1,1],0 -> 8","[1],0 -> 1"]),
    p(7,"Number of Students Unable to Eat Lunch","1700/number-of-students-unable-to-eat-lunch","Easy","int countStudents(vector<int>& students, vector<int>& sandwiches)","FIFO rotation; stopping condition","queue front/back; counting","Recognize when repeatedly rotating a queue cannot make further progress.",["[1,1,0,0],[0,1,0,1] -> 0","[1,1,1,0,0,1],[1,0,0,0,1,1] -> 3","[0],[1] -> 1"]),
    # Stage 8: transformations then implementation tradeoffs.
    p(8,"Reverse a Queue","https://www.geeksforgeeks.org/problems/queue-reversal/1","Easy","void reverseQueue(queue<int>& q)","queue reversal; auxiliary stack","FIFO; LIFO","Choose an auxiliary structure and explain the extra-space cost.",["front->back [1,2,3] -> [3,2,1]","[] -> []","[9] -> [9]"],"Mutate the given queue; the leftmost displayed value is the front."),
    p(8,"Reverse First K Elements of a Queue","https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1","Easy","void reverseFirstK(queue<int>& q, int k)","partial reversal; order preservation","reverse queue; queue rotation","Keep the suffix in its original order while reversing only a prefix.",["[1,2,3,4,5],3 -> [3,2,1,4,5]","[1,2],0 -> [1,2]","[1,2],2 -> [2,1]"],"0 <= k <= q.size(). Mutate the queue; leftmost is front."),
    p(8,"Interleave the First and Second Halves of a Queue","https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1","Medium","void interleaveQueue(queue<int>& q)","queue rotation; stable interleaving","reverse first K; auxiliary queue","Interleave two contiguous halves while preserving each half's internal order.",["[1,2,3,4] -> [1,3,2,4]","[1,2,3,4,5,6] -> [1,4,2,5,3,6]","[] -> []"],"Input length is even. Mutate the given queue; leftmost is front."),
    p(8,"Design Circular Queue","622/design-circular-queue","Medium","class MyCircularQueue { public: MyCircularQueue(int k); bool enQueue(int value); bool deQueue(); int Front(); int Rear(); bool isEmpty(); bool isFull(); };","circular indexing; capacity; wraparound","array queue; head/tail","Reuse fixed storage safely after removals and distinguish full from empty.",["k=3: enQueue(1),enQueue(2),enQueue(3),enQueue(4),Rear(),isFull() -> true,true,true,false,3,true","k=2: enQueue(1),deQueue(),enQueue(2),Front() -> true,true,true,2","k=1: Front(),Rear() -> -1,-1"]),
    p(8,"Implement Queue using Stacks","https://www.geeksforgeeks.org/problems/queue-using-stack/1","Easy","class MyQueue { public: MyQueue(); void push(int x); int pop(); int peek(); bool empty(); };","FIFO from LIFO; amortized cost","two stacks; basic queue contract","Preserve FIFO behavior using only stack operations and discuss the tradeoff.",["push(1),push(2),peek(),pop(),empty() -> 1,1,false","push(7),pop(),empty() -> 7,true","push(1),push(2),pop(),push(3),pop() -> 1,2"]),
    p(8,"Implement Stack using Queues","https://www.geeksforgeeks.org/problems/stack-using-queue/1","Easy","class MyStack { public: MyStack(); void push(int x); int pop(); int top(); bool empty(); };","LIFO from FIFO; rotation","queue front/back; stack contract","Compare where the work happens when implementing an opposite adapter.",["push(1),push(2),top(),pop(),empty() -> 2,2,false","push(7),pop(),empty() -> 7,true","push(1),push(2),pop(),push(3),top() -> 2,3"]),
    # Stage 9: connect earlier sliding windows to deque-based candidates.
    p(9,"Practise Deque Operations","repo","Easy","vector<int> applyDequeOperations(vector<string>& commands)","std::deque; both ends; front/back","std::queue operations; vector<string>","Become fluent with both-end insertion and removal before optimizing windows.",["[\"push_back 2\",\"push_front 1\",\"push_back 3\"] -> [1,2,3]","[\"push_front 4\",\"pop_back\"] -> []","[\"pop_front\",\"push_back 7\"] -> [7]"],"Each command is 'push_front x', 'push_back x', 'pop_front', or 'pop_back'. Ignore removals on empty; return contents from front to back."),
    p(9,"First Negative Integer in Every Window of Size K","https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1","Medium","vector<int> firstNegInt(vector<int>& arr, int k)","deque of candidate indices; window expiration","Arrays/Vectors fixed sliding window; deque","Revisit the Arrays/Vectors exercise with a position-aware FIFO candidate structure.",["[-8,2,3,-6,10],2 -> [-8,0,-6,-6]","[1,2,3],2 -> [0,0]","[-1],1 -> [-1]"]),
    p(9,"Sliding Window Maximum","https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k-using-dequeue--161044/1","Hard","vector<int> maxSlidingWindow(vector<int>& nums, int k)","monotonic deque; index expiration","fixed sliding window; first negative windows","Track the strongest candidate while positions leave the window.",["[1,3,-1,-3,5,3,6,7],3 -> [3,3,5,5,6,7]","[1],1 -> [1]","[2,2,2],2 -> [2,2]"]),
    p(9,"Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit","1438/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit","Medium","int longestSubarray(vector<int>& nums, int limit)","two monotonic deques; variable window","sliding-window maximum; minimum tracking","Maintain both extremes as a variable window changes.",["[8,2,4,7],4 -> 2","[10,1,2,4,7,2],5 -> 4","[4,4,4],0 -> 3"]),
    p(9,"Shortest Subarray with Sum at Least K","862/shortest-subarray-with-sum-at-least-k","Hard","int shortestSubarray(vector<int>& nums, int k)","prefix sums; monotonic deque; negative values","prefix sums; sliding window; index order","Understand why ordinary shrinking windows fail with signed values.",["[1],1 -> 1","[1,2],4 -> -1","[2,-1,2],3 -> 3"]),
    # Stage 10: arrival order is the shared theme.
    p(10,"First Non-repeating Character in a Stream","https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1","Medium","string FirstNonRepeating(string s)","stream; FIFO candidates; frequency","queue; character counts","Reassess the earliest unique candidate after every new arrival.",["\"aabc\" -> \"a#bb\"","\"zz\" -> \"z#\"","\"abc\" -> \"aaa\""]),
    p(10,"Number of Recent Calls","933/number-of-recent-calls","Easy","class RecentCounter { public: RecentCounter(); int ping(int t); };","time window; expiring events","FIFO; queue front","Keep only arrivals inside a moving time interval.",["ping(1),ping(100),ping(3001),ping(3002) -> 1,2,3,3","ping(1) -> 1","ping(1),ping(3002) -> 1,1"]),
    p(10,"Reveal Cards In Increasing Order","950/reveal-cards-in-increasing-order","Medium","vector<int> deckRevealedIncreasing(vector<int>& deck)","queue of positions; reorder simulation","queue rotation; sorting","Map a prescribed FIFO reveal process back to starting positions.",["[17,13,11,2,3,5,7] -> [2,13,3,11,5,17,7]","[1] -> [1]","[2,1] -> [1,2]"]),
    p(10,"Dota2 Senate","649/dota2-senate","Medium","string predictPartyVictory(string senate)","two FIFO groups; rounds","queue indexes; turn order","Preserve turn order across repeated rounds of a process.",["\"RD\" -> \"Radiant\"","\"RDD\" -> \"Dire\"","\"R\" -> \"Radiant\""]),
    p(10,"Bounded Event Buffer","repo","Medium","vector<int> lastEvents(vector<int>& events, int capacity)","bounded FIFO; eviction; stream","circular queue; enqueue/dequeue","Decide which oldest event to evict once fixed capacity is reached.",["[1,2,3,4],2 -> [3,4]","[5],3 -> [5]","[1,2],0 -> []"],"Return the last capacity arrivals in original order. capacity >= 0; empty input is allowed."),
    # Stage 11: two designs and three level/state expansion problems only.
    p(11,"Design Circular Deque","641/design-circular-deque","Medium","class MyCircularDeque { public: MyCircularDeque(int k); bool insertFront(int value); bool insertLast(int value); bool deleteFront(); bool deleteLast(); int getFront(); int getRear(); bool isEmpty(); bool isFull(); };","circular deque; two-ended capacity","circular queue; deque operations","Extend wraparound reasoning to insertions and removals at both ends.",["k=3: insertLast(1),insertLast(2),insertFront(3),insertFront(4),getRear(),isFull() -> true,true,true,false,2,true","k=1: insertFront(8),getFront(),deleteLast(),isEmpty() -> true,8,true,true","k=2: getRear() -> -1"]),
    p(11,"Design Front Middle Back Queue","1670/design-front-middle-back-queue","Medium","class FrontMiddleBackQueue { public: FrontMiddleBackQueue(); void pushFront(int val); void pushMiddle(int val); void pushBack(int val); int popFront(); int popMiddle(); int popBack(); };","two deques; balancing; middle contract","deque operations; invariants","Maintain an explicit middle choice when both ends and the center can change.",["pushFront(1),pushBack(2),pushMiddle(3),popMiddle(),popFront(),popBack() -> 3,1,2","popFront() on empty -> -1","pushBack(1),pushBack(2),popMiddle() -> 1"]),
    p(11,"Rotting Oranges","https://www.geeksforgeeks.org/problems/rotten-oranges2536/1","Medium","int orangesRotting(vector<vector<int>>& grid)","multi-source queue; level timing","FIFO; matrix indexes","Process simultaneous arrivals by rounds from several starting points.",["[[2,1,1],[1,1,0],[0,1,1]] -> 4","[[2,1,1],[0,1,1],[1,0,1]] -> -1","[[0,2]] -> 0"]),
    p(11,"Nearest Exit from Entrance in Maze","1926/nearest-exit-from-entrance-in-maze","Medium","int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)","queue levels; state expansion; visited positions","FIFO; grid neighbors","Count the first exit reached by increasing number of steps.",["maze=[[+, +, .],[.,.,.],[+,+,+]], entrance=[1,0] -> 2","maze=[[.,+]], entrance=[0,0] -> -1","maze=[[.,.,.]], entrance=[0,1] -> 1"]),
    p(11,"As Far from Land as Possible","1162/as-far-from-land-as-possible","Medium","int maxDistance(vector<vector<int>>& grid)","multi-source queue; distance layers","rotting oranges; grid neighbors","Start from all sources and recognize the final distance layer.",["[[1,0,1],[0,0,0],[1,0,1]] -> 2","[[1,0,0],[0,0,0],[0,0,0]] -> 4","[[1,1],[1,1]] -> -1"]),
]


def create_if_missing(path: Path, content: str):
    """Existing curriculum files may contain learner notes: never overwrite any of them."""
    path.parent.mkdir(parents=True, exist_ok=True)
    try:
        with path.open("x", encoding="utf-8") as out:
            out.write(content)
    except FileExistsError:
        pass


def slug(s):
    return re.sub(r"[^A-Za-z0-9]+", "_", s).strip("_")


def starter(item):
    signature = item["signature"]
    if signature.startswith("class "):
        # A declaration is sufficient boilerplate; no method body or algorithm is supplied.
        return '#include <bits/stdc++.h>\nusing namespace std;\n\n// LEARNER STARTER — implement the declared interface yourself.\n' + signature + '\n'
    return ('#include <bits/stdc++.h>\nusing namespace std;\n\nclass Solution {\npublic:\n'
            f'    {signature} {{\n        // LEARNER STARTER — write your own first attempt here.\n'
            '    }\n};\n')


def problem_readme(item):
    concepts = '\n'.join('- ' + x.strip() for x in item['concepts'].split(';'))
    prereqs = '\n'.join('- ' + x.strip() for x in item['prerequisites'].split(';'))
    contract = f'\n## Exercise contract\n\n{item["contract"]}\n' if item['contract'] else ''
    return f'''# {item['index']:02d}. {item['title']}

| Field | Value |
|---|---|
| Platform | {item['platform']} |
| Difficulty | {item['difficulty']} |
| Problem link | [Open the live problem]({item['url']}) |
| Starter signature | `{item['signature']}` |
| Reference solution available | No — intentionally locked |

## What you are meant to learn

{item['goal']}
{contract}
## Concepts required

{concepts}

## Prerequisites

{prereqs}

## Attempt protocol

1. Read the live platform statement and constraints (or the exercise contract above).
2. Add two of your own edge cases to `testcases.md`.
3. Write only your first honest solution in `01_original_attempt.cpp`.
4. Record compiler errors, wrong assumptions, and failed cases in `mistakes.md`.
5. Mark the progress tracker truthfully before requesting a hint or reference layer.

The README explains the learning target, not the algorithm.
'''


def mistakes(item):
    return f'''# Mistakes — {item['title']}

Complete this after your first attempt. Do not pre-fill a mistake you have not made.

## My initial assumption

-

## Failing test case

```text

```

## Root cause

- [ ] Syntax/API misunderstanding
- [ ] Boundary or empty-input case
- [ ] Incorrect invariant/logic
- [ ] Time complexity too high
- [ ] Space complexity too high
- [ ] Misread platform contract

## Correction in my own words

-
'''


def build():
    counts = [sum(p['stage'] == stage for p in PROBLEMS) for stage in range(1, 12)]
    assert len(PROBLEMS) == 55 and sum(counts[:6]) == 30 and sum(counts[6:]) == 25, counts
    manifest = []
    for index, problem in enumerate(PROBLEMS, 1):
        stage = problem['stage']
        category = STAGES[stage - 1][0]
        prefix = 'LC_' if '/' in problem['source'] and not problem['source'].startswith('https://') and problem['source'] != 'repo' else ('GFG_' if problem['source'].startswith('https://') else 'EX_')
        identifier = problem['source'].split('/')[0] if prefix == 'LC_' else ''
        folder_name = f'{prefix}{identifier + "_" if identifier else ""}{slug(problem["title"])}'
        platform_folder = 'LeetCode' if prefix == 'LC_' else 'GeeksforGeeks' if prefix == 'GFG_' else 'Exercises'
        folder = MODULE / category / platform_folder / folder_name
        rel = folder.relative_to(ROOT).as_posix()
        source = problem['source']
        url = ('https://leetcode.com/problems/' + source.split('/', 1)[1] + '/' if prefix == 'LC_' else
               source if prefix == 'GFG_' else REPO + '/blob/main/' + rel + '/README.md')
        item = dict(category=category, folder=rel, title=problem['title'], url=url,
                    platform='LeetCode' if prefix == 'LC_' else 'GeeksforGeeks' if prefix == 'GFG_' else 'Repository exercise',
                    difficulty=problem['difficulty'], signature=problem['signature'],
                    concepts=problem['concepts'], prerequisites=problem['prerequisites'],
                    goal=problem['goal'], tests=problem['tests'], index=index, global_index=125 + index,
                    track='Stack' if stage <= 6 else 'Queue/Deque')
        manifest.append(item)
        create_if_missing(folder / 'README.md', problem_readme(item | {'contract': problem['contract']}))
        create_if_missing(folder / '01_original_attempt.cpp', starter(item))
        for level, name in [('BRUTE FORCE','02_brute_force.cpp'),('BETTER','03_better_approach.cpp'),('OPTIMAL','04_optimal_solution.cpp')]:
            create_if_missing(folder / name, f'/*\nREFERENCE SLOT INTENTIONALLY EMPTY — {level}\n\nWrite and save 01_original_attempt.cpp before asking to unlock this layer.\nWhen this file is eventually completed, preserve the original attempt exactly.\n*/\n')
        create_if_missing(folder / 'mistakes.md', mistakes(item))
        rows = '\n'.join(f'{n}. {case}' for n, case in enumerate(item['tests'], 1))
        create_if_missing(folder / 'testcases.md', f'# Starter test cases for {item["title"]}\n# Confirm exact formatting and constraints on the live platform.\n\n{rows}\n\n# Add at least two of your own before coding:\n{len(item["tests"])+1}. [add your own case]\n{len(item["tests"])+2}. [add your own case]\n')

    create_if_missing(MODULE / 'problem_manifest.json', json.dumps(manifest, indent=2) + '\n')
    for number, (category, title, description) in enumerate(STAGES, 1):
        entries = [item for item in manifest if item['category'] == category]
        listing = '\n'.join(f'{item["index"]}. [{item["title"]}]({"/".join(Path(item["folder"]).parts[-2:])}/) — {item["difficulty"]}' for item in entries)
        create_if_missing(MODULE / category / 'README.md', f'# {title}\n\n{description}\n\nWork through these in order:\n\n{listing}\n')
    print(f'Prepared {len(manifest)} curriculum entries: {sum(counts[:6])} Stack; {sum(counts[6:])} Queue/Deque across {len(STAGES)} stages.')
    return manifest


if __name__ == '__main__':
    build()
