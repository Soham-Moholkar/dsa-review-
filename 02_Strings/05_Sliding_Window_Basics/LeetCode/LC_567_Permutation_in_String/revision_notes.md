# Revision Notes

## One-line trigger

Turn an anagram question into a fixed-length substring scan.

## State or invariant to remember

The frequency table describes exactly one window of s1.size() characters.

## Optimal approach

**Fixed window reference**

- Time: `O(n + m)`
- Extra space: `O(1)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Sliding Window Basics
Maintain: The frequency table describes exactly one window of s1.size() characters.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
