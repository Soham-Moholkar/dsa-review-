# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. Store frequencies, not just existence.
2. Negative values make a basic sliding window unreliable.
3. frequency[0] = 1 handles a valid prefix from index 0.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Use cumulative history so a subarray or range can be derived from earlier prefix information.
