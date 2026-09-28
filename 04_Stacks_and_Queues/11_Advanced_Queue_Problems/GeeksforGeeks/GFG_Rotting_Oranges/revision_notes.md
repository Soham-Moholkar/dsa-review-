# Revision Notes

## One-line trigger

Process simultaneous arrivals by rounds from several starting points.

## State or invariant to remember

Each cell enters the queue when it first becomes rotten.

## Optimal approach

**Multi-source queue reference**

- Time: `O(rows × columns)`
- Extra space: `O(rows × columns)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Advanced Queue Problems
Maintain: Each cell enters the queue when it first becomes rotten.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
