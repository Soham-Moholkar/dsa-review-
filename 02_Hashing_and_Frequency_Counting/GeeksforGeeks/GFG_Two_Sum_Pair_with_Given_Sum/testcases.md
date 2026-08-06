# Test Cases

## 1. Core case

```text
[1, 4, 45, 6, 10, 8], target=16 -> true
```

## 2. Core case

```text
[1, 2, 4], target=8 -> false
```

## 3. Core case

```text
[3, 3], target=6 -> true
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
