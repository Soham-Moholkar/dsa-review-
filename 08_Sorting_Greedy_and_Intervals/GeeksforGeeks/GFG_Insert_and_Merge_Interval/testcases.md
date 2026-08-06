# Test Cases

## 1. Core case

```text
[[1,3],[6,9]], [2,5] -> [[1,5],[6,9]]
```

## 2. Core case

```text
[[1,2],[3,5],[6,7],[8,10],[12,16]], [4,8] -> [[1,2],[3,10],[12,16]]
```

## 3. Core case

```text
[] + [5,7] -> [[5,7]]
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
