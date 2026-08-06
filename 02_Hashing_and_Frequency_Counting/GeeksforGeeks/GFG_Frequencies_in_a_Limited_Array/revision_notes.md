# Revision Notes

## One-line trigger

Values lie in a known range, so array indexes can encode counts.

## State or invariant to remember

After encoding, arr[i] contains its original remainder plus N times the frequency of value i + 1.

## Optimal approach

**Encode counts inside the input array**

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
Pattern: Hashing and Frequency Counting
Maintain: After encoding, arr[i] contains its original remainder plus N times the frequency of value i + 1.
```

## Revision status

| Revision | Date | Coded without help? | Time taken | Mistake remembered? | Notes |
|---|---|---|---|---|---|
| First solve |  |  |  |  |  |
| 2-day revision |  |  |  |  |  |
| 1-week revision |  |  |  |  |  |
| 1-month revision |  |  |  |  |  |
