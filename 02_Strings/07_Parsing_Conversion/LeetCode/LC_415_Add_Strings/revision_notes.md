# Revision Notes

## One-line trigger

Simulate column addition without converting the entire inputs to built-in numeric types.

## State or invariant to remember

Every produced digit equals the column sum modulo ten; carry moves left.

## Optimal approach

**Digit simulation reference**

- Time: `O(max(n,m))`
- Extra space: `O(max(n,m))`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Parsing Conversion
Maintain: Every produced digit equals the column sum modulo ten; carry moves left.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
