# Revision Notes

## One-line trigger

Create the same reliable key for every member of an anagram group.

## State or invariant to remember

Words in the same group share the same canonical sorted-character key.

## Optimal approach

**Canonical keys reference**

- Time: `O(w L log L + w log w)`
- Extra space: `O(w L)`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Mapping Anagrams
Maintain: Words in the same group share the same canonical sorted-character key.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
