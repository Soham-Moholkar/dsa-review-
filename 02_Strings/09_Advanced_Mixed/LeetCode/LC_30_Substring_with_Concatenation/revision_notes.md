# Revision Notes

## One-line trigger

Slide in word-sized steps and treat each starting offset as an independent window stream.

## State or invariant to remember

The map counts word multiplicities inside one aligned, word-sized window.

## Optimal approach

**Word-sized windows reference**

- Time: `O(nw) expected`
- Extra space: `O(w + result)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Advanced Mixed
Maintain: The map counts word multiplicities inside one aligned, word-sized window.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
