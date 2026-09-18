# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. Use floating-point division when returning the average.
2. Track maximum sum first because k is constant.
3. Initialising maximum to 0 fails when all window sums are negative.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Maintain one contiguous range and update it by adding an incoming element and removing outgoing elements.
