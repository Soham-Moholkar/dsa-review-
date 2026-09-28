# Revision Notes

## One-line trigger

Build the prefix table and reuse matched information instead of restarting after a mismatch.

## State or invariant to remember

The prefix table stores the longest proper border of each processed prefix.

## Optimal approach

**Lps/prefix table reference**

- Time: `O(n + m)`
- Extra space: `O(m) plus result`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Pattern Matching
Maintain: The prefix table stores the longest proper border of each processed prefix.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
