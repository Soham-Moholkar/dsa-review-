# Test Cases

## 1. Core case

```text
[[1,2,3],[4,5,6],[7,8,9]] -> [1,2,3,6,9,8,7,4,5]
```

## 2. Core case

```text
[[1,2,3,4]] -> [1,2,3,4]
```

## 3. Core case

```text
[[1],[2]] -> [1,2]
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
