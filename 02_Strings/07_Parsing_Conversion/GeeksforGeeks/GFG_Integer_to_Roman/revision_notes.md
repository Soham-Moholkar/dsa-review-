# Revision Notes

## One-line trigger

Choose the largest legal symbol repeatedly, including subtractive pairs as first-class entries.

## State or invariant to remember

After each symbol is chosen, num is the unrepresented remainder.

## Optimal approach

**Greedy representation reference**

- Time: `O(output length)`
- Extra space: `O(output length)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Parsing Conversion
Maintain: After each symbol is chosen, num is the unrepresented remainder.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
