#include <bits/stdc++.h>
using namespace std;
class twoStacks {
    vector<int> data;
    int split = 0;
public:
    void push1(int x) {
        data.insert(data.begin()+split, x);
        ++split;
    }
    void push2(int x) {
        data.push_back(x);
    }
    int pop1() {
        if (split == 0) return -1;
        int value = data[split-1];
        data.erase(data.begin()+--split);
        return value;
    }
    int pop2() {
        if ((int)data.size() == split) return -1;
        int value = data.back();
        data.pop_back();
        return value;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Two Stacks in Array: Public methods: push1, push2, pop1, pop2; empty pop returns -1. Local fixed-array references support at most 100000 total live elements. Values are nonnegative; test operations respect capacity.

2. FUNCTION SIGNATURE, PART BY PART
class twoStacks
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Contiguous sections with shifting.
The split marks the first stack end; inserting there shifts stack2 without changing its order.
Read the initialization first, then trace each loop or operation, and finally
check the return expression against the required type and sentinel.

Executable-line walkthrough:
1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class twoStacks {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
4. `vector<int> data;`
   Declares `data` so it can store state used by the algorithm.
5. `int split = 0;`
   Creates `split` and initializes it from `0`. This gives the algorithm its starting state.
6. `public:`
   Makes the following method callable by the judge.
7. `void push1(int x) {`
   Defines the judge-facing function and lists the inputs it receives.
8. `data.insert(data.begin()+split, x);`
   Stores this value in the set/map so later iterations can find it.
9. `++split;`
   Moves the relevant counter or pointer by one position.
10. `void push2(int x) {`
   Defines the judge-facing function and lists the inputs it receives.
11. `data.push_back(x);`
   Appends the computed value to the end of the result/container.
12. `int pop1() {`
   Defines the judge-facing function and lists the inputs it receives.
13. `if (split == 0) return -1;`
   Runs the next block only when `split == 0` is true. The one-line action is `return -1;`.
14. `int value = data[split-1];`
   Creates `value` and initializes it from `data[split-1]`. This gives the algorithm its starting state.
15. `data.erase(data.begin()+--split);`
   Removes the selected key/element so the container represents only currently relevant data.
16. `return value;`
   Ends the function and sends `value` back to the caller.
17. `int pop2() {`
   Defines the judge-facing function and lists the inputs it receives.
18. `if ((int)data.size() == split) return -1;`
   Runs the next block only when `(int)data.size() == split` is true. The one-line action is `return -1;`.
19. `int value = data.back();`
   Creates `value` and initializes it from `data.back()`. This gives the algorithm its starting state.
20. `data.pop_back();`
   Removes the last element from the container.
21. `return value;`
   Ends the function and sends `value` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- push_back: Adds one element to the end of a vector or deque.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
- front / back: Accesses the first or last element of a nonempty container.
- insert: Adds an element to a container. A set ignores a value already present.
- erase: Removes an element or position from a container.
- static_cast / C-style cast: Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.
- ++ / --: Increases/decreases a numeric variable by one.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: Push1(10), push2(20), push1(30) leaves stack1=[10,30] and stack2=[20]. Pop1 returns 30; pop2 returns 20; neither operation changes the other stack.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
The first stack grows from the left, the second from the right, and their occupied ranges never overlap.
The split marks the first stack end; inserting there shifts stack2 without changing its order.

7. COMPLEXITY
Time: O(n) stack1 push/pop; O(1) amortized stack2 push/pop. Space: O(n).
Input-by-value copying is additional to the stated auxiliary storage. n/m are
input lengths; C is capacity; T is total generated text; output space is named
separately where relevant. Small teaching baselines can exceed judge limits.

8. EDGE CASES TO CHECK
Use the normal, boundary, repeated-value, and missing-answer cases in
testcases.md. Follow the documented allowed input domain before adding cases.

9. COMMON MISTAKES
Changing argument order, using the wrong index base, dropping overlaps,
ignoring equal-value ties, and treating a missing answer as a valid empty value
can all violate the contract. State your invariant before changing a comparison.

10. HOW TO STUDY THIS SOLUTION
Try the starter first. Trace one example by hand, explain why each update is
safe, compare time and memory across references, then recode from memory.
Record only actual learner mistakes and revision dates.
*/
