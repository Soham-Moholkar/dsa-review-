# Revision Notes

## One-line trigger

Four boundaries shrink after completing each direction.

## State or invariant to remember

All cells outside top,bottom,left,right have already been emitted exactly once.

## Optimal approach

**Four shrinking boundaries**

- Time: `O(rows × columns)`
- Extra space: `O(1) excluding answer`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Matrices and Two-Dimensional Vectors
Maintain: All cells outside top,bottom,left,right have already been emitted exactly once.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
