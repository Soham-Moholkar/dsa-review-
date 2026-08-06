# Mistake Analysis

## Original-attempt status

No exact prior attempt was available, so no mistake has been invented or attributed to you.

## Common mistakes for this problem

1. Initialising the maximum to 0 fails when all values are negative.
2. Writing arr[i] = largestValue updates the array in the wrong direction.
3. Using i <= arr.size() accesses one index beyond the array.

## Your exact mistake log

After solving, record:

- **Incorrect line or condition:**
- **Why it looked reasonable:**
- **Counterexample that breaks it:**
- **Corrected rule:**
- **How to recognize this mistake next time:**

## Pattern-level reminder

Maintain the required information while visiting each element, or modify the array in place with carefully controlled indexes.
