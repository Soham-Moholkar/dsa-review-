# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. Using chained equality such as nums[i] == nums[i+1] == 1 does not work in C++.
2. Reading nums[i + 1] at the final index causes out-of-bounds access.
3. Resetting maximumCount instead of currentCount erases the best answer.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Maintain the required information while visiting each element, or modify the array in place with carefully controlled indexes.
