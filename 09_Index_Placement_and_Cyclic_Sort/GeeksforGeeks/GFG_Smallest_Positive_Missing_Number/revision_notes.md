# Revision Notes

## One-line trigger

Only values 1 through n can affect the first missing positive answer.

## State or invariant to remember

After cyclic placement, value x should be at index x-1 whenever it is present and valid.

## Optimal approach

**Cyclic placement**

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
Pattern: Index Placement and Cyclic Sort
Maintain: After cyclic placement, value x should be at index x-1 whenever it is present and valid.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
