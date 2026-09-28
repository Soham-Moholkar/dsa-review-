#include <bits/stdc++.h>
using namespace std;
class LRUCache {
    int capacity;
    vector<pair<int,int>> order;
public:
    LRUCache(int cap) : capacity(cap) {
    }
    int get(int key) {
        for (int i = 0; i < (int)order.size(); ++i) if (order[i].first == key) {
            auto entry = order[i];
            order.erase(order.begin()+i);
            order.insert(order.begin(),entry);
            return entry.second;
        }
        return -1;
    }
    void put(int key, int value) {
        if (capacity <= 0) return;
        for (int i = 0; i < (int)order.size(); ++i) if (order[i].first == key) {
            order.erase(order.begin()+i);
            break;
        }
        order.insert(order.begin(),{
            key,value
        }
        );
        if ((int)order.size() > capacity) order.pop_back();
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
LRU Cache: get(key) returns the stored value or -1 and refreshes recency on hits. put refreshes updated keys. Evict the least recently used key when full. Capacity zero is a local extension. std::list supplies stable iterators; no manual node prerequisite.

2. FUNCTION SIGNATURE, PART BY PART
class LRUCache
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Scan and move in a vector.
Store most recent first. Search linearly, erase the found pair, and reinsert it at the front.
Read the initialization first, then trace each loop or operation, and finally
check the return expression against the required type and sentinel.

Executable-line walkthrough:
1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class LRUCache {`
   Performs this operation to maintain the state described in the algorithm walkthrough.
4. `int capacity;`
   Declares `capacity` so it can store state used by the algorithm.
5. `vector<pair<int,int>> order;`
   Declares `order` so it can store state used by the algorithm.
6. `public:`
   Makes the following method callable by the judge.
7. `LRUCache(int cap) : capacity(cap) {`
   Declares `LRUCache` so it can store state used by the algorithm.
8. `int get(int key) {`
   Defines the judge-facing function and lists the inputs it receives.
9. `for (int i = 0; i < (int)order.size(); ++i) if (order[i].first == key) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < (int)order.size()` is true; after each iteration perform `++i`. Its one-line body is `if (order[i].first == key) {`.
10. `auto entry = order[i];`
   Creates `entry` and initializes it from `order[i]`. This gives the algorithm its starting state.
11. `order.erase(order.begin()+i);`
   Removes the selected key/element so the container represents only currently relevant data.
12. `order.insert(order.begin(),entry);`
   Stores this value in the set/map so later iterations can find it.
13. `return entry.second;`
   Ends the function and sends `entry.second` back to the caller.
14. `return -1;`
   Ends the function and sends `-1` back to the caller.
15. `void put(int key, int value) {`
   Defines the judge-facing function and lists the inputs it receives.
16. `if (capacity <= 0) return;`
   Runs the next block only when `capacity <= 0` is true. The one-line action is `return;`.
17. `for (int i = 0; i < (int)order.size(); ++i) if (order[i].first == key) {`
   Starts a loop: first `int i = 0`; keep repeating while `i < (int)order.size()` is true; after each iteration perform `++i`. Its one-line body is `if (order[i].first == key) {`.
18. `order.erase(order.begin()+i);`
   Removes the selected key/element so the container represents only currently relevant data.
19. `break;`
   Stops the nearest loop immediately because no more iterations are needed.
20. `order.insert(order.begin(),{`
   Stores this value in the set/map so later iterations can find it.
21. `key,value`
   Performs this operation to maintain the state described in the algorithm walkthrough.
22. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
23. `if ((int)order.size() > capacity) order.pop_back();`
   Runs the next block only when `(int)order.size() > capacity` is true. The one-line action is `order.pop_back();`.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- vector: A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.
- pair: Stores two values together. first names the first value and second names the second value.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- for: Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- break: Immediately exits the nearest loop.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
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
Shared contract trace: With capacity 2: put(1,10), put(2,20), get(1) makes key 1 newest. put(3,30) evicts key 2. A read miss changes no recency.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
The list front is most recently used, the back least recently used, and each map iterator points to its unique live list node.
Store most recent first. Search linearly, erase the found pair, and reinsert it at the front.

7. COMPLEXITY
Time: O(C) per operation. Space: O(C).
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
