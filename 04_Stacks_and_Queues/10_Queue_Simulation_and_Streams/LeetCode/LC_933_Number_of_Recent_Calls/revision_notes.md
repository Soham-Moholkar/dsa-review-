# Revision Notes

## One-line trigger

Keep only arrivals inside a moving time interval.

## State or invariant to remember

Every queued timestamp is inside the inclusive recent-call interval.

## Optimal approach

**Time window reference**

- Time: `O(1) amortized per ping`
- Extra space: `O(window)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Queue Simulation and Streams
Maintain: Every queued timestamp is inside the inclusive recent-call interval.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
