# Revision Notes

## One-line trigger

With positive values, expanding increases sum and shrinking decreases it monotonically.

## State or invariant to remember

The current window is the candidate range ending at right; all shorter valid prefixes are tested by shrinking.

## Optimal approach

**Variable sliding window**

- Time: `O(n)`
- Extra space: `O(1)`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Sliding Window
Maintain: The current window is the candidate range ending at right; all shorter valid prefixes are tested by shrinking.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
