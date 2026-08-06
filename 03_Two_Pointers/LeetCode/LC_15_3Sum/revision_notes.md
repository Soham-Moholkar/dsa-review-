# Revision Notes

## One-line trigger

After sorting, fixing one value reduces the remaining search to a two-pointer pair sum.

## State or invariant to remember

For each fixed i, left and right search the only remaining range and duplicates are skipped.

## Optimal approach

**Sort, fix one value, and use two pointers**

- Time: `O(n^2)`
- Extra space: `O(1) excluding answer`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Two Pointers
Maintain: For each fixed i, left and right search the only remaining range and duplicates are skipped.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
