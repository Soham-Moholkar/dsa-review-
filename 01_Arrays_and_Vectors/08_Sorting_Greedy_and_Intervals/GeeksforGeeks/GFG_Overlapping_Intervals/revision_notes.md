# Revision Notes

## One-line trigger

Sorting by start places possible overlaps next to each other.

## State or invariant to remember

answer contains fully merged intervals, and only its last interval can overlap the current one.

## Optimal approach

**Sorted one-pass interval merge**

- Time: `O(n log n)`
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
Maintain: answer contains fully merged intervals, and only its last interval can overlap the current one.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
