# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. Store the earliest occurrence of a prefix, not the latest.
2. A normal positive-only sliding window is unsafe when negative numbers are allowed.
3. Use firstIndex[0] = -1 for subarrays beginning at index 0.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Use cumulative history so a subarray or range can be derived from earlier prefix information.
