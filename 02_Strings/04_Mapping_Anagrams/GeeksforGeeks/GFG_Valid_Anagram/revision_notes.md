# Revision Notes

## One-line trigger

Use character multiplicity, not membership alone, to decide whether two strings are rearrangements.

## State or invariant to remember

Equal-length anagrams have the same multiplicity for every character.

## Optimal approach

**Frequency equality reference**

- Time: `O(n log n)`
- Extra space: `O(n)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Mapping Anagrams
Maintain: Equal-length anagrams have the same multiplicity for every character.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
