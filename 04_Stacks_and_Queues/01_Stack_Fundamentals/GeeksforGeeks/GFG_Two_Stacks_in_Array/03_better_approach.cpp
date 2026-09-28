#include <bits/stdc++.h>
using namespace std;
class twoStacks {
    static constexpr int C = 100000;
    vector<int> data;
    int one = 0, two = C;
public:
    twoStacks() : data(2*C) {
    }
    void push1(int x) {
        data[one++] = x;
    }
    void push2(int x) {
        data[two++] = x;
    }
    int pop1() {
        return one == 0 ? -1 : data[--one];
    }
    int pop2() {
        return two == C ? -1 : data[--two];
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
Method: Reserve independent halves.
Give each stack C positions. This satisfies the documented bound but wastes the unused half when only one stack grows.
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
6. `int one = 0, two = C;`
   Creates `one` and initializes it from `0, two = C`. This gives the algorithm its starting state.
7. `public:`
   Makes the following method callable by the judge.
8. `twoStacks() : data(2*C) {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
9. `void push1(int x) {`
   Defines the judge-facing function and lists the inputs it receives.
10. `data[one++] = x;`
   Updates `data[one++]` to `x` for the next step of the algorithm.
11. `void push2(int x) {`
   Defines the judge-facing function and lists the inputs it receives.
12. `data[two++] = x;`
   Updates `data[two++]` to `x` for the next step of the algorithm.
13. `int pop1() {`
   Defines the judge-facing function and lists the inputs it receives.
14. `return one == 0 ? -1 : data[--one];`
   Ends the function and sends `one == 0 ? -1 : data[--one]` back to the caller.
15. `int pop2() {`
   Defines the judge-facing function and lists the inputs it receives.
16. `return two == C ? -1 : data[--two];`
   Ends the function and sends `two == C ? -1 : data[--two]` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
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
Give each stack C positions. This satisfies the documented bound but wastes the unused half when only one stack grows.

7. COMPLEXITY
Time: O(1) operations; O(C) initialization. Space: O(2C).
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
