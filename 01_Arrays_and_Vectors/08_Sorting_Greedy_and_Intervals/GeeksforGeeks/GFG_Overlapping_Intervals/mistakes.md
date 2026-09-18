# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. Sort before comparing only with the last merged interval.
2. Touching intervals are usually treated as overlapping when currentStart <= previousEnd.
3. Update the end with max, not blindly with currentEnd.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Sort related values or intervals together, then make a locally correct scan or greedy decision.
