# Revision Notes

## One-line trigger

The best circular range equals total sum minus the minimum middle subarray.

## State or invariant to remember

Normal Kadane covers non-wrapping ranges; total-minimum covers wrapping ranges.

## Optimal approach

**Maximum Kadane plus total minus minimum Kadane**

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
Pattern: Kadane's Algorithm
Maintain: Normal Kadane covers non-wrapping ranges; total-minimum covers wrapping ranges.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
