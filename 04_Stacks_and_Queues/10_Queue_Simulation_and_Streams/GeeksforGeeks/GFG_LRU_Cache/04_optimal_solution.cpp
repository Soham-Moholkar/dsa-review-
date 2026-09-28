#include <bits/stdc++.h>
using namespace std;
class LRUCache {
    int capacity;
    list<pair<int,int>> order;
    unordered_map<int,list<pair<int,int>>::iterator> locations;
public:
    LRUCache(int cap) : capacity(cap) {
    }
    int get(int key) {
        auto it = locations.find(key);
        if (it == locations.end()) return -1;
        order.splice(order.begin(),order,it->second);
        return it->second->second;
    }
    void put(int key, int value) {
        if (capacity <= 0) return;
        auto it = locations.find(key);
        if (it != locations.end()) {
            it->second->second = value;
            order.splice(order.begin(),order,it->second);
            return;
        }
        if ((int)order.size() == capacity) {
            locations.erase(order.back().first);
            order.pop_back();
        }
        order.push_front({
            key,value
        }
        );
        locations[key] = order.begin();
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
Method: Hash map plus recency list.
Hash lookup locates a node, splice refreshes it, and back eviction removes the least recent key. Expected time assumes ordinary hash behavior.
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
5. `list<pair<int,int>> order;`
   Declares `order` so it can store state used by the algorithm.
6. `unordered_map<int,list<pair<int,int>>::iterator> locations;`
   Declares `locations` so it can store state used by the algorithm.
7. `public:`
   Makes the following method callable by the judge.
8. `LRUCache(int cap) : capacity(cap) {`
   Declares `LRUCache` so it can store state used by the algorithm.
9. `int get(int key) {`
   Defines the judge-facing function and lists the inputs it receives.
10. `auto it = locations.find(key);`
   Creates `it` and initializes it from `locations.find(key)`. This gives the algorithm its starting state.
11. `if (it == locations.end()) return -1;`
   Runs the next block only when `it == locations.end()` is true. The one-line action is `return -1;`.
12. `order.splice(order.begin(),order,it->second);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
13. `return it->second->second;`
   Ends the function and sends `it->second->second` back to the caller.
14. `void put(int key, int value) {`
   Defines the judge-facing function and lists the inputs it receives.
15. `if (capacity <= 0) return;`
   Runs the next block only when `capacity <= 0` is true. The one-line action is `return;`.
16. `auto it = locations.find(key);`
   Creates `it` and initializes it from `locations.find(key)`. This gives the algorithm its starting state.
17. `if (it != locations.end()) {`
   Runs the next block only when `it != locations.end()` is true.
18. `it->second->second = value;`
   Updates `it->second->second` to `value` for the next step of the algorithm.
19. `order.splice(order.begin(),order,it->second);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
20. `return;`
   Ends the function.
21. `if ((int)order.size() == capacity) {`
   Runs the next block only when `(int)order.size() == capacity` is true.
22. `locations.erase(order.back().first);`
   Removes the selected key/element so the container represents only currently relevant data.
23. `order.pop_back();`
   Removes the last element from the container.
24. `order.push_front({`
   Performs this operation to maintain the state described in the algorithm walkthrough.
25. `key,value`
   Performs this operation to maintain the state described in the algorithm walkthrough.
26. `);`
   Performs this operation to maintain the state described in the algorithm walkthrough.
27. `locations[key] = order.begin();`
   Updates `locations[key]` to `order.begin()` for the next step of the algorithm.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- void: Means the function returns no value. Any answer must be produced through mutation or another side effect.
- pair: Stores two values together. first names the first value and second names the second value.
- unordered_map: Stores key-value pairs in a hash table, with expected O(1) operations.
- auto: Asks the compiler to infer the variable's type from the value on the right.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
- front / back: Accesses the first or last element of a nonempty container.
- erase: Removes an element or position from a container.
- find: Searches for a value/key. A failed standard-container search returns end(). For vectors, the algorithm form find(begin, end, value) performs a linear scan.
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
Hash lookup locates a node, splice refreshes it, and back eviction removes the least recent key. Expected time assumes ordinary hash behavior.

7. COMPLEXITY
Time: O(1) expected per operation. Space: O(C).
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
