# Revision Notes

## One-line trigger

Model a binary alphabet and decide whether one generic invariant or two passes is clearer.

## State or invariant to remember

The current window needs at most k changes to become all one chosen character.

## Optimal approach

**Variable window reference**

- Time: `O(n)`
- Extra space: `O(1)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Sliding Window Advanced
Maintain: The current window needs at most k changes to become all one chosen character.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
