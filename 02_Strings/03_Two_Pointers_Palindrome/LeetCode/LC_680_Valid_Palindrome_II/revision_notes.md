# Revision Notes

## One-line trigger

Branch only at the first mismatch and test the two meaningful remaining ranges.

## State or invariant to remember

After the first mismatch, only one of the two skipped ranges may be a palindrome.

## Optimal approach

**Two pointers reference**

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
Pattern: Two Pointers Palindrome
Maintain: After the first mismatch, only one of the two skipped ranges may be a palindrome.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
