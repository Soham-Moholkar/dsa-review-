# Revision Notes

## One-line trigger

Revisit the Arrays/Vectors exercise with a position-aware FIFO candidate structure.

## State or invariant to remember

The deque holds unexpired positions of negative values.

## Optimal approach

**Deque of candidate indices reference**

- Time: `O(n)`
- Extra space: `O(k) plus result`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Deque and Monotonic Queue
Maintain: The deque holds unexpired positions of negative values.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
