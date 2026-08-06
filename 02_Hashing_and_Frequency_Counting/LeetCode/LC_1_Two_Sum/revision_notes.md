# Revision Notes

## One-line trigger

The required complement should map to the index where it was previously seen.

## State or invariant to remember

mp stores value-to-index mappings only for elements before i.

## Optimal approach

**One-pass hashmap**

- Time: `O(n) average`
- Extra space: `O(n)`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Hashing and Frequency Counting
Maintain: mp stores value-to-index mappings only for elements before i.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
