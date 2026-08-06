# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. The sell index must occur after the buy index.
2. Return 0 when no profitable transaction exists.
3. Update profit using the previous minimum before or along with updating the minimum.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Maintain the best value ending at the current index and decide whether to extend or restart.
