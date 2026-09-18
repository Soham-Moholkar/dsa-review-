# Revision Notes

## One-line trigger

Scan intervals before, overlapping with, and after the new interval.

## State or invariant to remember

The new interval grows to cover every overlap before it is appended.

## Optimal approach

**Linear insertion and merge**

- Time: `O(n)`
- Extra space: `O(n) answer`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Sorting, Greedy Decisions, and Intervals
Maintain: The new interval grows to cover every overlap before it is appended.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
