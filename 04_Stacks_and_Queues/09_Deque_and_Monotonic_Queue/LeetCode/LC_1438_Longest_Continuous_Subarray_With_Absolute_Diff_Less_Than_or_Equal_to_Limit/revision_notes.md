# Revision Notes

## One-line trigger

Maintain both extremes as a variable window changes.

## State or invariant to remember

Two deques track the current minimum and maximum of the live window.

## Optimal approach

**Two monotonic deques reference**

- Time: `O(n)`
- Extra space: `O(n)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Deque and Monotonic Queue
Maintain: Two deques track the current minimum and maximum of the live window.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
