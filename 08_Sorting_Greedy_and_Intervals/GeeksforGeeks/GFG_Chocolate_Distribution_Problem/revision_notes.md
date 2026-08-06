# Revision Notes

## One-line trigger

After sorting, an optimal chosen group appears as a contiguous window of size m.

## State or invariant to remember

Each scanned sorted window represents a candidate group with smallest and largest at its ends.

## Optimal approach

**Sorted fixed-size greedy window**

- Time: `O(n log n)`
- Extra space: `O(log n)`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Sorting, Greedy Decisions, and Intervals
Maintain: Each scanned sorted window represents a candidate group with smallest and largest at its ends.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
