# Revision Notes

## One-line trigger

Value x maps to index x-1, whose sign can mark presence.

## State or invariant to remember

A negative value at index i marks that i+1 appeared.

## Optimal approach

**Sign marking**

- Time: `O(n)`
- Extra space: `O(1) extra`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Index Placement and Cyclic Sort
Maintain: A negative value at index i marks that i+1 appeared.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
