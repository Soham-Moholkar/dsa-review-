# Revision Notes

## One-line trigger

Every answer reuses the cumulative result immediately before it.

## State or invariant to remember

After processing i, nums[i] equals the prefix sum through i.

## Optimal approach

**Modify the input in place**

- Time: `O(n)`
- Extra space: `O(1) extra`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Prefix Sum and Prefix Sum with Hashmap
Maintain: After processing i, nums[i] equals the prefix sum through i.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
