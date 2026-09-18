# Revision Notes

## One-line trigger

Each index splits the array into a left sum and a right sum.

## State or invariant to remember

leftSum is the sum before i; totalSum after subtraction is the sum after i.

## Optimal approach

**Total sum and running left sum**

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
Pattern: Prefix Sum and Prefix Sum with Hashmap
Maintain: leftSum is the sum before i; totalSum after subtraction is the sum after i.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
