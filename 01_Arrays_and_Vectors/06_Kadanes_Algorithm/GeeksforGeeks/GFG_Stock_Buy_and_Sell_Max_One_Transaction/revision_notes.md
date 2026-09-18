# Revision Notes

## One-line trigger

For each selling day, only the smallest earlier buying price matters.

## State or invariant to remember

minimumPrice is the cheapest value before or at i; answer is the best valid profit so far.

## Optimal approach

**Minimum price seen so far**

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
Pattern: Kadane's Algorithm
Maintain: minimumPrice is the cheapest value before or at i; answer is the best valid profit so far.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
