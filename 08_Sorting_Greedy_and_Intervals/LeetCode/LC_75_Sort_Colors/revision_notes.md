# Revision Notes

## One-line trigger

Three categories map to a three-way partition.

## State or invariant to remember

0s are before low, 1s before mid, unknowns between mid and high, and 2s after high.

## Optimal approach

**Dutch National Flag**

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
Pattern: Sorting, Greedy Decisions, and Intervals
Maintain: 0s are before low, 1s before mid, unknowns between mid and high, and 2s after high.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
