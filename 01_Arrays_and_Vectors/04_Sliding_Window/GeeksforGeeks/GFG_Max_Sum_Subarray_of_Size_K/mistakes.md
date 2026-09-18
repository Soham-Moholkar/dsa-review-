# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. The outgoing index is i - K.
2. Initialise the answer from the first complete window, not 0, because sums may be negative.
3. A fixed-size window must never shrink to a different length.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Maintain one contiguous range and update it by adding an incoming element and removing outgoing elements.
