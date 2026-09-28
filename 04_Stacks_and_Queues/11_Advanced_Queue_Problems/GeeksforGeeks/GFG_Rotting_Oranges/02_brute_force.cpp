#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size(),fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<rows;++i)for(int j=0;j<cols;++j){
            if(grid[i][j]==2)q.push({
                i,j
            }
            );
            else if(grid[i][j]==1)++fresh;
        }
        int time=0,dx[4]={
            1,-1,0,0
        }
        ,dy[4]={
            0,0,1,-1
        }
        ;
        while(!q.empty()&&fresh){
            int batch=q.size();
            while(batch--){
                auto [x,y]=q.front();
                q.pop();
                for(int z=0;z<4;++z){
                    int nx=x+dx[z],ny=y+dy[z];
                    if(nx>=0&&nx<rows&&ny>=0&&ny<cols&&grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        --fresh;
                        q.push({
                            nx,ny
                        }
                        );
                    }
                }
            }
            ++time;
        }
        return fresh?-1:time;
    }
};

/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: Rotting Oranges
Platform: GeeksforGeeks
Pattern: Advanced Queue Problems

Learning goal: Process simultaneous arrivals by rounds from several starting points.
This file implements: Same efficient method (no distinct baseline).

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`int orangesRotting(vector<vector<int>>& grid)`
- `int` is the return type.
- References (`&`) name the caller’s object; copying by value uses separate storage.
The platform can change its API; adapt a copy rather than modifying your first attempt.

3. ALGORITHM IN SIMPLE STEPS
----------------------------
The maintained fact is: Each cell enters the queue when it first becomes rotten.

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
5. `int orangesRotting(vector<vector<int>>& grid) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int rows=grid.size(),cols=grid[0].size(),fresh=0;`
   Creates `rows` and initializes it from `grid.size(),cols=grid[0].size(),fresh=0`. This gives the algorithm its starting state.
7. `queue<pair<int,int>> q;`
   Declares `q` so it can store state used by the algorithm.
8. `for(int i=0;i<rows;++i)for(int j=0;j<cols;++j){`
   Starts a loop: first `int i=0`; keep repeating while `i<rows` is true; after each iteration perform `++i`. Its one-line body is `for(int j=0;j<cols;++j){`.
9. `if(grid[i][j]==2)q.push({`
   Runs the next block only when `grid[i][j]==2` is true. The one-line action is `q.push({`.
10. `i,j`
   Performs this operation to maintain the state described in the algorithm walkthrough.
11. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
12. `else if(grid[i][j]==1)++fresh;`
   If earlier branches failed, runs this block when `grid[i][j]==1` is true. The one-line action is `++fresh;`.
13. `int time=0,dx[4]={`
   Creates `time` and initializes it from `0,dx[4]={`. This gives the algorithm its starting state.
14. `1,-1,0,0`
   Performs this operation to maintain the state described in the algorithm walkthrough.
15. `,dy[4]={`
   Updates `,dy[4]` to `{` for the next step of the algorithm.
16. `0,0,1,-1`
   Performs this operation to maintain the state described in the algorithm walkthrough.
17. `;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
18. `while(!q.empty()&&fresh){`
   Repeats the following block while `!q.empty()&&fresh` is true.
19. `int batch=q.size();`
   Creates `batch` and initializes it from `q.size()`. This gives the algorithm its starting state.
20. `while(batch--){`
   Repeats the following block while `batch--` is true.
21. `auto [x,y]=q.front();`
   Updates `auto [x,y]` to `q.front()` for the next step of the algorithm.
22. `q.pop();`
   Performs this operation to maintain the state described in the algorithm walkthrough.
23. `for(int z=0;z<4;++z){`
   Starts a loop: first `int z=0`; keep repeating while `z<4` is true; after each iteration perform `++z`.
24. `int nx=x+dx[z],ny=y+dy[z];`
   Creates `nx` and initializes it from `x+dx[z],ny=y+dy[z]`. This gives the algorithm its starting state.
25. `if(nx>=0&&nx<rows&&ny>=0&&ny<cols&&grid[nx][ny]==1){`
   Runs the next block only when `nx>=0&&nx<rows&&ny>=0&&ny<cols&&grid[nx][ny]==1` is true.
26. `grid[nx][ny]=2;`
   Updates `grid[nx][ny]` to `2` for the next step of the algorithm.
27. `--fresh;`
   Moves the relevant counter or pointer by one position.
28. `q.push({`
   Performs this operation to maintain the state described in the algorithm walkthrough.
29. `nx,ny`
   Performs this operation to maintain the state described in the algorithm walkthrough.
30. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
31. `++time;`
   Moves the relevant counter or pointer by one position.
32. `return fresh?-1:time;`
   Ends the function and sends `fresh?-1:time` back to the caller.

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
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- !: Logical NOT; reverses true and false.
- ++ / --: Increases/decreases a numeric variable by one.

Parentheses contain calls or conditions; braces group scopes, and semicolons
end statements. Access `top`, `front`, and `back` only under their valid contract.

5. DRY RUN
----------
Use the first entry in testcases.md: [[2,1,1],[1,1,0],[0,1,1]] -> 4
Trace the implementation ABOVE, keeping each intermediate stack, queue, window,
or mapping in the order shown by the executable code. For recursion, include
frames on the call stack in the trace and in extra-space accounting.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
For this approach, check every candidate, transformation, or recorded state
shown in the executable walkthrough. The maintained fact is: Each cell enters the queue when it first becomes rotten.
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
