# Revision Notes

## One-line trigger

If prefixXor ^ oldPrefix = k, then oldPrefix = prefixXor ^ k.

## State or invariant to remember

frequency stores how many times every earlier prefix XOR has occurred.

## Optimal approach

**Hashmap of prefix XOR frequencies**

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
Maintain: frequency stores how many times every earlier prefix XOR has occurred.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
