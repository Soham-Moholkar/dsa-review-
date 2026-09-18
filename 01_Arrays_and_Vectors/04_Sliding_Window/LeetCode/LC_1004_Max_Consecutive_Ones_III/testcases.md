# Test Cases

## 1. Core case

```text
[1,1,1,0,0,0,1,1,1,1,0], k=2 -> 6
```

## 2. Core case

```text
[0,0,1,1], k=0 -> 2
```

## 3. Core case

```text
[1,1], k=1 -> 2
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
