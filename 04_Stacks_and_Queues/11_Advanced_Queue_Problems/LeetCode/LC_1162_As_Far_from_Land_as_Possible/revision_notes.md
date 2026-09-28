# Revision Notes

## One-line trigger

Start from all sources and recognize the final distance layer.

## State or invariant to remember

Each land-origin BFS layer gives the shortest distance of its newly reached sea cells.

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
Maintain: Each land-origin BFS layer gives the shortest distance of its newly reached sea cells.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
