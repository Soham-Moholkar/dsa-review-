# Test Cases

## 1. Core case

```text
[1, 2, 3, 4, 5, 6, 7], k=3 -> [5, 6, 7, 1, 2, 3, 4]
```

## 2. Core case

```text
[-1, -100, 3, 99], k=2 -> [3, 99, -1, -100]
```

## 3. Core case

```text
[1], k=10 -> [1]
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
