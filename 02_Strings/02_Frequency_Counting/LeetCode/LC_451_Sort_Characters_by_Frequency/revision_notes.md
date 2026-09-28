# Revision Notes

## One-line trigger

Move from merely counting characters to reconstructing output in frequency order.

## State or invariant to remember

The output is assembled from characters in nonincreasing frequency order.

## Optimal approach

**Counting reference**

- Time: `O(n + A log A)`
- Extra space: `O(A + n)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Frequency Counting
Maintain: The output is assembled from characters in nonincreasing frequency order.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
