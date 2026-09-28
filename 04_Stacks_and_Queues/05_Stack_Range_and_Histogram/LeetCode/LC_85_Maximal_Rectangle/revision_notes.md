# Revision Notes

## One-line trigger

Recognize a familiar histogram inside a two-dimensional input.

## State or invariant to remember

Each row turns vertical runs of ones into histogram heights.

## Optimal approach

**Row histogram reference**

- Time: `O(rows × columns)`
- Extra space: `O(columns)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Stack Range and Histogram
Maintain: Each row turns vertical runs of ones into histogram heights.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
