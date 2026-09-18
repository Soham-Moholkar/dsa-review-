# Revision Notes

## One-line trigger

The input is sorted and one comparison can discard half the range.

## State or invariant to remember

answer is a known matching index or -1; any earlier undiscovered occurrence remains inside left through right.

## Optimal approach

**Manual iterative binary search**

- Time: `O(log n)`
- Extra space: `O(1)`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Binary Search
Maintain: answer is a known matching index or -1; any earlier undiscovered occurrence remains inside left through right.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
