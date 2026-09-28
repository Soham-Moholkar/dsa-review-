# Revision Notes

## One-line trigger

Extend existence checking into reporting every valid starting position.

## State or invariant to remember

Every reported starting index has the same character multiplicities as p.

## Optimal approach

**Fixed window reference**

- Time: `O(n + m)`
- Extra space: `O(1) plus result`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Sliding Window Basics
Maintain: Every reported starting index has the same character multiplicities as p.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
