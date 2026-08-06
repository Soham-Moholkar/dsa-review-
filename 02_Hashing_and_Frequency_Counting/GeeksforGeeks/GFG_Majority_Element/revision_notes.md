# Revision Notes

## One-line trigger

One value may dominate all others, but the candidate must be verified when existence is not guaranteed.

## State or invariant to remember

Boyer-Moore count represents the candidate’s net votes against different values.

## Optimal approach

**Boyer-Moore plus verification**

- Time: `O(n)`
- Extra space: `O(1)`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Hashing and Frequency Counting
Maintain: Boyer-Moore count represents the candidate’s net votes against different values.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
