# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. Returning immediately on equality finds an arbitrary occurrence, not a boundary.
2. For the first occurrence, continue left; for the last, continue right.
3. upper_bound points one position after the last occurrence.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Use a monotonic condition to discard half of the remaining search space.
