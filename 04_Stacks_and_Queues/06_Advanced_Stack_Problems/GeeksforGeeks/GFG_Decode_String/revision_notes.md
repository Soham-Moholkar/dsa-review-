# Revision Notes

## One-line trigger

Track nested repetition and restore the enclosing parse context.

## State or invariant to remember

Each closed bracket restores its previous prefix and repeats its inner block.

## Optimal approach

**Nested frames reference**

- Time: `O(decoded length)`
- Extra space: `O(decoded length + nesting)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Advanced Stack Problems
Maintain: Each closed bracket restores its previous prefix and repeats its inner block.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
