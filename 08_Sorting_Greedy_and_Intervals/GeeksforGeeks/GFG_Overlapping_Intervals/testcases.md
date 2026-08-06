# Test Cases

## 1. Core case

```text
[[1,3],[2,4],[6,8],[9,10]] -> [[1,4],[6,8],[9,10]]
```

## 2. Core case

```text
[[1,4],[4,5]] -> [[1,5]]
```

## 3. Core case

```text
[] -> []
```

## Edge-case checklist

Before submitting, test the cases that apply:

- Empty input, when the platform allows it
- One element
- Two elements
- All values equal
- Already sorted or already valid input
- Reverse-sorted input
- All-negative values or zeroes, when permitted
- Duplicate values
- Answer at the first index
- Answer at the final index
- No valid answer
- Maximum constraint sizes and possible integer overflow
