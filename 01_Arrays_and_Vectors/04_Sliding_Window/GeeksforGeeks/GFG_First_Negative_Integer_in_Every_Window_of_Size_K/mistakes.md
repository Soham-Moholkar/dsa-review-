# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. Store indexes rather than only values so expired elements can be removed.
2. Remove expired indexes before reading the front.
3. Output 0 when the deque has no valid negative index.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Maintain one contiguous range and update it by adding an incoming element and removing outgoing elements.
