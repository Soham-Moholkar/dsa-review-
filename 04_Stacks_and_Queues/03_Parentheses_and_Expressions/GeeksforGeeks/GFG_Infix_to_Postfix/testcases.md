# Test cases — Infix to Postfix

Valid expressions with single alphanumeric operands and binary + - * / ^, with optional parentheses and no spaces. ^ is right-associative; the other operators are left-associative.

| Arguments / operations | Expected |
|---|---|
| `["a+b*c"]` | `"abc*+"` |
| `["(a+b)*c"]` | `"ab+c*"` |
| `["a^b^c"]` | `"abc^^"` |
| `["a-b-c"]` | `"ab-c-"` |
| `["x"]` | `"x"` |

## My cases before coding

1. [add your own case]
2. [add your own case]
