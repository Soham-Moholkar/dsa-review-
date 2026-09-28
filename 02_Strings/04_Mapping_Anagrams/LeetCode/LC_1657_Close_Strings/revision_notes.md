# Revision Notes

## One-line trigger

Separate which characters exist from how often the existing characters occur.

## State or invariant to remember

The two strings use the same characters and the same multiset of frequencies.

## Optimal approach

**Character sets reference**

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
Pattern: Mapping Anagrams
Maintain: The two strings use the same characters and the same multiset of frequencies.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
