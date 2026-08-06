# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. Failing to require a distinct value lets a duplicate maximum become the answer.
2. Updating largest before preserving its old value loses the second-largest candidate.
3. Initialising both answers to 0 breaks negative-only arrays.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Maintain the required information while visiting each element, or modify the array in place with carefully controlled indexes.
