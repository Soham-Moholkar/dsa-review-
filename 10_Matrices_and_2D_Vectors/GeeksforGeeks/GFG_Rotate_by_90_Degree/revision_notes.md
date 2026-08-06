# Revision Notes

## One-line trigger

Anti-clockwise rotation equals transpose followed by reversing each column.

## State or invariant to remember

Transpose swaps row/column roles; column reversal places each value at its rotated row.

## Optimal approach

**In-place transpose and column reversal**

- Time: `O(n^2)`
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
Maintain: Transpose swaps row/column roles; column reversal places each value at its rotated row.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
