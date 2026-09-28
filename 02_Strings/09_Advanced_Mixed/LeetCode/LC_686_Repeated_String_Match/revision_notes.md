# Revision Notes

## One-line trigger

Prove how many repeats are sufficient to test when the match may cross a repetition boundary.

## State or invariant to remember

The built string contains exactly the current number of copies of a.

## Optimal approach

**Repeated construction reference**

- Time: `O((n + m)m) worst case`
- Extra space: `O(n + m)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Advanced Mixed
Maintain: The built string contains exactly the current number of copies of a.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
