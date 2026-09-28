# Revision Notes

## One-line trigger

Decide how to preserve order while placing values in a stack, and count hidden recursion space.

## State or invariant to remember

The recursively sorted remainder stays sorted as each item is inserted.

## Optimal approach

**Recursion reference**

- Time: `O(n²)`
- Extra space: `O(n) recursion`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Stack Manipulation and Recursion
Maintain: The recursively sorted remainder stays sorted as each item is inserted.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
