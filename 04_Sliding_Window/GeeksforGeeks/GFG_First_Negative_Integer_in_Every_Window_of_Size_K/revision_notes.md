# Revision Notes

## One-line trigger

The answer depends on the earliest still-valid negative index.

## State or invariant to remember

The deque stores negative indexes in increasing order and only from the current window.

## Optimal approach

**Deque of negative indexes**

- Time: `O(n)`
- Extra space: `O(k)`

## Mental checklist

1. What information must be maintained while moving through the array?
2. Why is the brute-force method slower?
3. Which assumption makes the optimal movement valid?
4. Which boundary, duplicate, overflow, or empty-input case can break the code?
5. Can the solution be recoded without viewing `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Sliding Window
Maintain: The deque stores negative indexes in increasing order and only from the current window.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
