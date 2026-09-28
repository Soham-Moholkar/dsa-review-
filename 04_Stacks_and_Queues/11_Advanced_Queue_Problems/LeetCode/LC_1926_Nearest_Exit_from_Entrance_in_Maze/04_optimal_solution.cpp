#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows=maze.size(),cols=maze[0].size(),dx[4]={
            1,-1,0,0
        }
        ,dy[4]={
            0,0,1,-1
        }
        ;
        queue<pair<int,int>> q;
        q.push({
            entrance[0],entrance[1]
        }
        );
        maze[entrance[0]][entrance[1]]='+';
        int steps=0;
        while(!q.empty()){
            int batch=q.size();
            while(batch--){
                auto [x,y]=q.front();
                q.pop();
                if(steps&&(x==0||x==rows-1||y==0||y==cols-1))return steps;
                for(int z=0;z<4;++z){
                    int nx=x+dx[z],ny=y+dy[z];
                    if(nx>=0&&nx<rows&&ny>=0&&ny<cols&&maze[nx][ny]=='.'){
                        maze[nx][ny]='+';
                        q.push({
                            nx,ny
                        }
                        );
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Nearest Exit from Entrance in Maze
Platform: LeetCode
Pattern: Advanced Queue Problems

Learning goal: Count the first exit reached by increasing number of steps.
This file implements: Queue levels reference.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)`
- `int` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: The first exit removed by BFS has the fewest steps from the entrance.

Read these executable lines in their actual order. Nested indentation shows when
an action belongs to a class, method, branch, loop, or lambda:

1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int rows=maze.size(),cols=maze[0].size(),dx[4]={`
   Creates `rows` and initializes it from `maze.size(),cols=maze[0].size(),dx[4]={`. This gives the algorithm its starting state.
7. `1,-1,0,0`
   Performs this operation to maintain the state described in the algorithm walkthrough.
8. `,dy[4]={`
   Updates `,dy[4]` to `{` for the next step of the algorithm.
9. `0,0,1,-1`
   Performs this operation to maintain the state described in the algorithm walkthrough.
10. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `queue<pair<int,int>> q;`
   Declares `q` so it can store state used by the algorithm.
12. `q.push({`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `entrance[0],entrance[1]`
   Performs this operation to maintain the state described in the algorithm walkthrough.
14. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
15. `maze[entrance[0]][entrance[1]]='+';`
   Updates `maze[entrance[0]][entrance[1]]` to `'+'` for the next step of the algorithm.
16. `int steps=0;`
   Creates `steps` and initializes it from `0`. This gives the algorithm its starting state.
17. `while(!q.empty()){`
   Repeats the following block while `!q.empty()` is true.
18. `int batch=q.size();`
   Creates `batch` and initializes it from `q.size()`. This gives the algorithm its starting state.
19. `while(batch--){`
   Repeats the following block while `batch--` is true.
20. `auto [x,y]=q.front();`
   Updates `auto [x,y]` to `q.front()` for the next step of the algorithm.
21. `q.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
22. `if(steps&&(x==0||x==rows-1||y==0||y==cols-1))return steps;`
   Runs the next block only when `steps&&(x==0||x==rows-1||y==0||y==cols-1)` is true. The one-line action is `return steps;`.
23. `for(int z=0;z<4;++z){`
   Starts a loop: first `int z=0`; keep repeating while `z<4` is true; after each iteration perform `++z`.
24. `int nx=x+dx[z],ny=y+dy[z];`
   Creates `nx` and initializes it from `x+dx[z],ny=y+dy[z]`. This gives the algorithm its starting state.
25. `if(nx>=0&&nx<rows&&ny>=0&&ny<cols&&maze[nx][ny]=='.'){`
   Runs the next block only when `nx>=0&&nx<rows&&ny>=0&&ny<cols&&maze[nx][ny]=='.'` is true.
26. `maze[nx][ny]='+';`
   Updates `maze[nx][ny]` to `'+'` for the next step of the algorithm.
27. `q.push({`
   Performs this operation to maintain the state described in the algorithm walkthrough.
28. `nx,ny`
   Performs this operation to maintain the state described in the algorithm walkthrough.
29. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
30. `++steps;`
   Moves the relevant counter or pointer by one position.
31. `return -1;`
   Ends the function and sends `-1` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- pair: Stores two values together. first names the first value and second names the second value.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- front / back: Accesses the first or last element of a nonempty container.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: maze=[[+, +, .],[.,.,.],[+,+,+]], entrance=[1,0] -> 2
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: The first exit removed by BFS has the fewest steps from the entrance.
At the end, the processed state covers the entire input or each queried
operation. When this file repeats another approach, its invariant is the same;
the separate slot exists for structural comparison, not a fabricated shortcut.

7. COMPLEXITY
-------------
- Time: O(rows × columns).
- Extra space: O(rows × columns).
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
