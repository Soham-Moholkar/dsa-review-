#include <bits/stdc++.h>
using namespace std;
class twoStacks {
    static constexpr int C = 100000;
    vector<int> data;
    int left = 0, right = C-1;
public:
    twoStacks() : data(C) {
    }
    void push1(int x) {
        if (left > right) throw overflow_error("full");
        data[left++] = x;
    }
    void push2(int x) {
        if (left > right) throw overflow_error("full");
        data[right--] = x;
    }
    int pop1() {
        return left == 0 ? -1 : data[--left];
    }
    int pop2() {
        return right == C-1 ? -1 : data[++right];
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
Method: Share free space between opposing tops.
With a total-live-elements bound C, grow inward from opposite ends to share every free slot.
Read the initialization first, then trace each loop or operation, and finally
check the return expression against the required type and sentinel.

Executable-line walkthrough:
1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class twoStacks {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
4. `static constexpr int C = 100000;`
   Creates `C` and initializes it from `100000`. This gives the algorithm its starting state.
5. `vector<int> data;`
   Declares `data` so it can store state used by the algorithm.
6. `int left = 0, right = C-1;`
   Creates `left` and initializes it from `0, right = C-1`. This gives the algorithm its starting state.
7. `public:`
   Makes the following method callable by the judge.
8. `twoStacks() : data(C) {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `void push1(int x) {`
   Defines the judge-facing function and lists the inputs it receives.
10. `if (left > right) throw overflow_error("full");`
   Runs the next block only when `left > right` is true. The one-line action is `throw overflow_error("full");`.
11. `data[left++] = x;`
   Updates `data[left++]` to `x` for the next step of the algorithm.
12. `void push2(int x) {`
   Defines the judge-facing function and lists the inputs it receives.
13. `if (left > right) throw overflow_error("full");`
   Runs the next block only when `left > right` is true. The one-line action is `throw overflow_error("full");`.
14. `data[right--] = x;`
   Updates `data[right--]` to `x` for the next step of the algorithm.
15. `int pop1() {`
   Defines the judge-facing function and lists the inputs it receives.
16. `return left == 0 ? -1 : data[--left];`
   Ends the function and sends `left == 0 ? -1 : data[--left]` back to the caller.
17. `int pop2() {`
   Defines the judge-facing function and lists the inputs it receives.
18. `return right == C-1 ? -1 : data[++right];`
   Ends the function and sends `right == C-1 ? -1 : data[++right]` back to the caller.

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
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
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
With a total-live-elements bound C, grow inward from opposite ends to share every free slot.

7. COMPLEXITY
Time: O(1) operations; O(C) initialization. Space: O(C).
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
