# Revision Notes

## One-line trigger

Equal prefix sums imply that the values between them sum to zero.

## State or invariant to remember

seen contains every prefix sum before the current position, including 0 before the array starts.

## Optimal approach

**Prefix sum hash set**

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
Pattern: Prefix Sum and Prefix Sum with Hashmap
Maintain: seen contains every prefix sum before the current position, including 0 before the array starts.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
