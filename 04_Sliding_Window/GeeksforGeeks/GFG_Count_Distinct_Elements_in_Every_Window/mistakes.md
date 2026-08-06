# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. A zero-frequency key must be erased before using map size as the distinct count.
2. Remove arr[i-k], not arr[i-k+1].
3. Build the first complete window before sliding.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Maintain one contiguous range and update it by adding an incoming element and removing outgoing elements.
