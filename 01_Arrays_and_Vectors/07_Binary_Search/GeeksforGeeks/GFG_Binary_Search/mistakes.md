# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. Binary search requires sorted input.
2. Use left <= right so a one-element range is checked.
3. Use left + (right-left)/2 to avoid overflow.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Use a monotonic condition to discard half of the remaining search space.
