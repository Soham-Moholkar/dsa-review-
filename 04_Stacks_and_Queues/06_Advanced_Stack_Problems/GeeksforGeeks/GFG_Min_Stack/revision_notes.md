# Revision Notes

## One-line trigger

Design an API that reports a changing minimum alongside ordinary stack operations.

## State or invariant to remember

The saved minimum equals the smallest value in the current stack.

## Optimal approach

**Aggregate state reference**

- Time: `O(1) per operation`
- Extra space: `O(n)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Advanced Stack Problems
Maintain: The saved minimum equals the smallest value in the current stack.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
