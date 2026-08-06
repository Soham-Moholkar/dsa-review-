# Revision Notes

## One-line trigger

A running streak resets whenever the required value is broken.

## State or invariant to remember

currentCount is the streak ending at i; maximumCount is the best streak seen anywhere.

## Optimal approach

**Single scan streak state**

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
Pattern: Linear Traversal and In-Place Manipulation
Maintain: currentCount is the streak ending at i; maximumCount is the best streak seen anywhere.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
