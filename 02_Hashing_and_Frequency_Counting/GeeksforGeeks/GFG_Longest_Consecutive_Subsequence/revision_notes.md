# Revision Notes

## One-line trigger

Order in the input is irrelevant; fast existence checks are more useful than positions.

## State or invariant to remember

A sequence is expanded only from a value whose predecessor is absent.

## Optimal approach

**Hash set and sequence starts**

- Time: `O(n) average`
- Extra space: `O(n)`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Hashing and Frequency Counting
Maintain: A sequence is expanded only from a value whose predecessor is absent.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
