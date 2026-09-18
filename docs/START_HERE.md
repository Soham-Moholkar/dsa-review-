# Use this repo to learn, not just collect solutions

Choose one pattern and stay with it until its basic idea makes sense. A useful session is one careful problem, one explanation in your own words, and one short revision of an earlier problem.

## A session, step by step

1. Open [the index](../INDEX.md), choose a problem, and read its summary and input contract.
2. Try it yourself in `01_original_attempt.cpp`. Keep your exact first attempt even if it fails.
3. If stuck, read only the recognition cue. Next read the brute-force reference. Open `solution.md` when you want the full worked explanation.
4. Trace a small input on paper. For each variable, explain what it stores and when it changes.
5. Implement again from memory. Log a concrete failing input and the rule you learned in `mistakes.md`.
6. Revisit after two days, one week, and one month. Fill your own revision table; reference availability is not personal mastery.

## Run a solution locally

Install **Python 3.9+** and **GCC with C++17** (the references use GCC's `bits/stdc++.h`). From the repository root:

```bash
python3 scripts/validate_structure.py
python3 scripts/test_solutions.py --problem LC_1_Two_Sum --sanitize
python3 scripts/test_solutions.py --pattern 04 --sanitize
python3 scripts/test_solutions.py --sanitize
```

On Windows, run these in WSL with Python and g++ installed, or use an equivalent GCC environment. Select another compatible compiler using `--compiler` or the `CXX` environment variable. The sanitizer option uses UndefinedBehaviorSanitizer and checked libstdc++ indexing; it is not an AddressSanitizer run.

The runner tests all three references, not your preserved original attempt. To test your own implementation without losing your first attempt, copy the repository to a temporary practice folder and replace one reference there, or submit your code to the platform judge. Each reference is a judge-style `class Solution`; compile it with a driver rather than expecting a built-in `main()`.

### Tiny driver example

Save this as `practice.cpp` in the repository root (it is ignored by Git):

```cpp
#include "01_Arrays_and_Vectors/02_Hashing_and_Frequency_Counting/LeetCode/LC_1_Two_Sum/04_optimal_solution.cpp"
int main() {
    std::vector<int> nums{2, 7, 11, 15};
    auto answer = Solution().twoSum(nums, 9);
    std::cout << answer[0] << ' ' << answer[1] << '\n';
}
```

```bash
g++ -std=c++17 practice.cpp -o practice
./practice
```

For your attempt, change the include to your own file containing `class Solution`. Do not include several files with that same class name in one driver. The test runner isolates references in separate namespaces.

## Which pattern should I try?

| Question cue | First idea | Important condition |
|---|---|---|
| Best value or consecutive streak | Linear scan | Define the saved state |
| Have I seen this before? | Set / map | Store existence, count, or index deliberately |
| Sorted pair or keeping a valid prefix | Two pointers | Pointer moves must safely discard work |
| Contiguous block of fixed length | Sliding window | Add incoming, subtract outgoing |
| Shortest positive-sum block | Variable window | Negative values invalidate simple shrinking |
| Signed subarray sum / count | Prefix sum + map | Seed the empty prefix |
| Largest contiguous sum | Kadane | Start from a real element for all-negative inputs |
| Sorted location or a boundary | Binary search | State what remains possible |
| Ranges that overlap | Sort and merge | Decide whether touching endpoints overlap |
| Values confined to 1..n | Index placement / marking | Validate ranges before indexing |
| Row and column conditions | Matrix traversal / markers | Do not let new markers contaminate old data |

## Five questions before calling a solution correct

1. What exactly does it return: value, index, boolean, count, or mutated prefix?
2. What remains true after each loop iteration?
3. Why does every discarded choice fail to improve the answer?
4. Which small input would expose an off-by-one, duplicate, or all-negative bug?
5. How do time and extra space grow, including sorting, recursion, and output?

See [contract differences](CONTRACTS.md) before submitting and [verification details](../VALIDATION_REPORT.md) for what was actually checked.
