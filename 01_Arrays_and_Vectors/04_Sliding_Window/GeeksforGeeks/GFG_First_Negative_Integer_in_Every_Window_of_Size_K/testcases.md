# Test Cases

## 1. Core case

```text
[-8,2,3,-6,10], K=2 -> [-8,0,-6,-6]
```

## 2. Core case

```text
[1,2,3], K=2 -> [0,0]
```

## 3. Core case

```text
[-1], K=1 -> [-1]
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
