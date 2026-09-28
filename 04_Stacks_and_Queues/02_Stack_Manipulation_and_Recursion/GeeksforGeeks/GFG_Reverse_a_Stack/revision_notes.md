# Revision Notes

## One-line trigger

Compare an explicit second stack with recursive call frames and account for extra space.

## State or invariant to remember

Reinsertion under the remaining stack reverses the removed suffix.

## Optimal approach

**Auxiliary stack reference**

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
Maintain: Reinsertion under the remaining stack reverses the removed suffix.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
