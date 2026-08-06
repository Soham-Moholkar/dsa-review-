# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. When all values are negative, total-minimum becomes 0, which represents an empty subarray and is invalid.
2. The circular candidate excludes the minimum-sum middle range.
3. Do not allow more than n elements in a circular subarray.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Maintain the best value ending at the current index and decide whether to extend or restart.
