# Revision Notes

## One-line trigger

Track the strongest candidate while positions leave the window.

## State or invariant to remember

Deque values decrease from front to back and indices stay inside the window.

## Optimal approach

**Monotonic deque reference**

- Time: `O(n)`
- Extra space: `O(k) plus result`

## Mental checklist

1. What state is updated when the next item arrives?
2. Which explicit comparison makes the baseline slower or use more storage?
3. Why does the invariant still hold after an item is processed or removed?
4. Which duplicate, empty, overflow, or boundary case breaks a careless solution?
5. Can you recode the answer without opening `04_optimal_solution.cpp`?

## Memory trigger

```text
Pattern: Deque and Monotonic Queue
Maintain: Deque values decrease from front to back and indices stay inside the window.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
