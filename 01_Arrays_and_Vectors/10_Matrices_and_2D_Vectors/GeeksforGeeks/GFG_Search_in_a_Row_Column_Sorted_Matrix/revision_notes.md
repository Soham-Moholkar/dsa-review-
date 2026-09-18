# Revision Notes

## One-line trigger

From the top-right corner, one comparison eliminates a full row or column.

## State or invariant to remember

The remaining candidate rectangle lies below and left of the current position.

## Optimal approach

**Top-right staircase search**

- Time: `O(r+c)`
- Extra space: `O(1)`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Matrices and Two-Dimensional Vectors
Maintain: The remaining candidate rectangle lies below and left of the current position.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
