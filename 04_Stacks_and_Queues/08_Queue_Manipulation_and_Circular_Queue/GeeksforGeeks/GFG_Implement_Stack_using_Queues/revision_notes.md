# Revision Notes

## One-line trigger

Compare where the work happens when implementing an opposite adapter.

## State or invariant to remember

Rotating after a push makes the newest element the next queue front.

## Optimal approach

**Lifo from fifo reference**

- Time: `O(n) push, O(1) pop/top`
- Extra space: `O(n)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Queue Manipulation and Circular Queue
Maintain: Rotating after a push makes the newest element the next queue front.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
