# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. Swapping when nums[i] == 0 moves zeroes toward the front.
2. Incrementing j for every element rather than every non-zero value breaks the write boundary.
3. Using an unstable method may change the order of non-zero values.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Maintain the required information while visiting each element, or modify the array in place with carefully controlled indexes.
