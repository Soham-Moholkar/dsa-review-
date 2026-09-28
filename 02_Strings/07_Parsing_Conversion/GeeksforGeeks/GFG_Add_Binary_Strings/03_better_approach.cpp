#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1, carry = 0;
        string out;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            out += char('0' + sum % 2);
            carry = sum / 2;
        }
        while (out.size() > 1 && out.back() == '0') out.pop_back();
        reverse(out.begin(), out.end());
        return out.empty() ? "0" : out;
    }
};

/*
DETAILED BEGINNER EXPLANATION

1. WHAT THIS FILE SOLVES
Add Binary Strings: Inputs are nonempty binary strings, possibly with leading zeroes. Return canonical binary output with no leading zeroes except "0".

2. FUNCTION SIGNATURE, PART BY PART
string addBinary(string a, string b)
The public method receives the inputs documented in README.md. A vector is a
resizable sequence; string is a character sequence; & passes an existing object
by reference. A returned value is the answer. A design class stores state across
calls; its constructor initializes that state. See the operation contract above.

3. ALGORITHM IN SIMPLE STEPS
Method: Append reversed bits.
Append in constant amortized time and reverse once after all columns.
Read the initialization first, then trace each loop or operation, and finally
check the return expression against the required type and sentinel.

Executable-line walkthrough:
1. `#include <bits/stdc++.h>`
   Loads the standard-library declarations used later in the file.
2. `using namespace std;`
   Allows standard-library names to be written without the `std::` prefix.
3. `class Solution {`
   Defines the class name expected by the online judge.
4. `public:`
   Makes the following method callable by the judge.
5. `string addBinary(string a, string b) {`
   Defines the judge-facing function and lists the inputs it receives.
6. `int i = a.size()-1, j = b.size()-1, carry = 0;`
   Creates `i` and initializes it from `a.size()-1, j = b.size()-1, carry = 0`. This gives the algorithm its starting state.
7. `string out;`
   Performs this operation to maintain the state described in the algorithm walkthrough.
8. `while (i >= 0 || j >= 0 || carry) {`
   Repeats the following block while `i >= 0 || j >= 0 || carry` is true.
9. `int sum = carry;`
   Creates `sum` and initializes it from `carry`. This gives the algorithm its starting state.
10. `if (i >= 0) sum += a[i--] - '0';`
   Runs the next block only when `i >= 0` is true. The one-line action is `sum += a[i--] - '0';`.
11. `if (j >= 0) sum += b[j--] - '0';`
   Runs the next block only when `j >= 0` is true. The one-line action is `sum += b[j--] - '0';`.
12. `out += char('0' + sum % 2);`
   Updates the stored state using its previous value and the expression on the right.
13. `carry = sum / 2;`
   Updates `carry` to `sum / 2` for the next step of the algorithm.
14. `while (out.size() > 1 && out.back() == '0') out.pop_back();`
   Repeats the following block while `out.size() > 1 && out.back() == '0'` is true. Its one-line body is `out.pop_back();`.
15. `reverse(out.begin(), out.end());`
   Reverses the selected range in place. The second iterator is one position past the range.
16. `return out.empty() ? "0" : out;`
   Ends the function and sends `out.empty() ? "0" : out` back to the caller.

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
- #include <bits/stdc++.h>: Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.
- using namespace std: Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.
- class: Defines a user-made type. Online judges usually create an object of class Solution and call its public method.
- public: Makes the method accessible to the judge outside the class.
- int: A signed whole-number type, commonly 32 bits.
- while: Repeats a block while its condition remains true.
- if / else if / else: Selects one path according to conditions. Only the first true branch in the chain runs.
- return: Ends the current function and optionally sends a value back to the caller.
- reference (&): Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.
- begin / end: Iterators marking the first element and the position just after the final element of a container.
- size: Returns the number of elements in a container.
- empty: Returns true when a container has no elements.
- pop_back / pop_front: Removes the last or first element. The code must ensure the container is not empty first.
- front / back: Accesses the first or last element of a nonempty container.
- reverse: Reverses the order of elements in the selected iterator range.
- ?:: The conditional operator: condition ? value_if_true : value_if_false.
- &&: Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.
- ||: Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.
- ++ / --: Increases/decreases a numeric variable by one.
- += / -= / *= / /=: Updates a variable using its old value, such as x += y meaning x = x + y.
- %: Remainder operator. a % b gives the remainder after integer division by b.

for/while repeat work while their condition allows it; if chooses a branch.
size() is the current element count, and valid indices end at size()-1.
push_back/pop_back use the end of a vector or string. A stack exposes top;
a queue exposes front and back. Empty containers must not be read or popped.
auto infers a type; structured bindings unpack pairs; a lambda captures context
for a local helper. ++/-- change a counter by one. == compares; = assigns.
long long widens arithmetic where differences or totals can exceed int.

5. DRY RUN
Shared contract trace: For 11 + 1, the right column gives 0 with carry 1; the next gives 0 with carry 1; the final carry gives 1. Reverse the collected 001 to get 100.
For this file, apply the method in section 3 to those same inputs and compare its
intermediate state with the preferred method. The expected output is identical.

6. WHY THE ALGORITHM IS CORRECT
The produced suffix is correct; carry is the unprocessed contribution to the next column.
Append in constant amortized time and reverse once after all columns.

7. COMPLEXITY
Time: O(L). Space: O(L) result.
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
