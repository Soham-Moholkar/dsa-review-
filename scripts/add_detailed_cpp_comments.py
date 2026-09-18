#!/usr/bin/env python3
"""Generate a beginner-friendly explanatory appendix for every reference C++ file.

The appendix is deliberately placed after the code so the implementation stays
clean enough to copy into a judge while the explanation remains beside it.
"""

from __future__ import annotations

import json
from pathlib import Path
import re


ROOT = Path(__file__).resolve().parents[1]


TYPE_EXPLANATIONS = {
    "int": "returns one signed integer",
    "long long": "returns a signed integer with a wider range than int",
    "bool": "returns either true or false",
    "double": "returns a decimal (floating-point) number",
    "void": "does not return a value; the answer is written into an input object",
    "pair<int, int>": "returns two integers grouped together in one pair",
    "vector<int>": "returns a dynamic array of integers",
    "vector<long long>": "returns a dynamic array of wide integers",
    "vector<vector<int>>": "returns a dynamic array whose elements are integer vectors",
}


PARAMETER_EXPLANATIONS = {
    "vector<int>": "a dynamic array of integers",
    "vector<long long>": "a dynamic array of wide integers",
    "vector<vector<int>>": "a two-dimensional dynamic integer matrix",
    "int": "one signed integer value",
    "long long": "one wide signed integer value",
    "double": "one decimal value",
    "bool": "one true/false value",
}


GLOSSARY = {
    "#include <bits/stdc++.h>": "Loads the common C++ standard-library facilities used by competitive-programming code. It is supported by GCC/Clang environments but is not an ISO-standard header.",
    "using namespace std": "Lets the file write vector, sort, cout, and other standard-library names without the std:: prefix.",
    "class": "Defines a user-made type. Online judges usually create an object of class Solution and call its public method.",
    "public": "Makes the method accessible to the judge outside the class.",
    "int": "A signed whole-number type, commonly 32 bits.",
    "long long": "A wider signed whole-number type, commonly 64 bits; it is used when an int may be too small.",
    "double": "A floating-point type used for decimal results.",
    "bool": "A type with only two values: true and false.",
    "void": "Means the function returns no value. Any answer must be produced through mutation or another side effect.",
    "true / false": "The two boolean values.",
    "vector": "A resizable array from the standard library. vector<int> stores integers; vector<vector<int>> represents a matrix.",
    "pair": "Stores two values together. first names the first value and second names the second value.",
    "set": "Stores unique values in sorted order, usually with O(log n) insert and lookup.",
    "unordered_set": "Stores unique values in a hash table, with expected O(1) insert and lookup.",
    "map": "Stores key-value pairs in sorted-key order, usually with O(log n) operations.",
    "unordered_map": "Stores key-value pairs in a hash table, with expected O(1) operations.",
    "deque": "A double-ended queue that can efficiently add or remove elements at both ends.",
    "function": "A standard-library wrapper able to store a callable object such as a recursive lambda.",
    "auto": "Asks the compiler to infer the variable's type from the value on the right.",
    "for": "Starts a loop. A traditional for-loop has initialization, continuation condition, and update parts.",
    "range-based for": "Visits every element of a container directly, without manually writing an index.",
    "while": "Repeats a block while its condition remains true.",
    "do ... while": "Runs the block once before checking whether it should repeat.",
    "if / else if / else": "Selects one path according to conditions. Only the first true branch in the chain runs.",
    "return": "Ends the current function and optionally sends a value back to the caller.",
    "break": "Immediately exits the nearest loop.",
    "continue": "Skips the remainder of the current loop iteration and begins the next one.",
    "const": "Promises that the named value will not be changed through that declaration.",
    "reference (&)": "Makes a parameter or loop variable refer to the original object instead of copying it. Changes can therefore affect the caller/container.",
    "raw array ([])": "In a function parameter, this is passed as a pointer to the first element; the separate length tells the code how many elements are valid.",
    "begin / end": "Iterators marking the first element and the position just after the final element of a container.",
    "size": "Returns the number of elements in a container.",
    "empty": "Returns true when a container has no elements.",
    "push_back": "Adds one element to the end of a vector or deque.",
    "pop_back / pop_front": "Removes the last or first element. The code must ensure the container is not empty first.",
    "front / back": "Accesses the first or last element of a nonempty container.",
    "insert": "Adds an element to a container. A set ignores a value already present.",
    "erase": "Removes an element or position from a container.",
    "find": "Searches for a value/key. A failed standard-container search returns end(). For vectors, the algorithm form find(begin, end, value) performs a linear scan.",
    "sort": "Rearranges a range into ascending order by default. This changes the container.",
    "reverse": "Reverses the order of elements in the selected iterator range.",
    "swap": "Exchanges two stored values.",
    "min / max": "Returns the smaller/larger of the supplied values.",
    "min_element / max_element": "Returns an iterator pointing to the smallest/largest element in a range.",
    "lower_bound": "On a sorted range, returns the first position whose value is not smaller than the target.",
    "upper_bound": "On a sorted range, returns the first position whose value is greater than the target.",
    "binary_search": "Checks whether a target exists in a sorted range.",
    "next_permutation": "Changes a range to its next lexicographically greater ordering and wraps to the smallest ordering after the greatest one.",
    "INT_MIN / INT_MAX": "The smallest/largest value representable by int.",
    "LLONG_MIN": "The smallest value representable by long long.",
    "DBL_MAX": "A very large representable double value; -DBL_MAX is useful as an initial smallest value.",
    "static_cast / C-style cast": "Explicitly converts a value to another type. Converting before arithmetic can prevent int overflow or integer division.",
    "lambda ([&])": "Creates an unnamed function. [&] captures surrounding local variables by reference, so the lambda can read and modify them.",
    "recursion": "A function calls itself on a smaller remaining choice. It needs a stopping condition to avoid infinite calls.",
    "?:": "The conditional operator: condition ? value_if_true : value_if_false.",
    "&&": "Logical AND; both conditions must be true. Evaluation stops as soon as one part is false.",
    "||": "Logical OR; at least one condition must be true. Evaluation stops as soon as one part is true.",
    "!": "Logical NOT; reverses true and false.",
    "++ / --": "Increases/decreases a numeric variable by one.",
    "+= / -= / *= / /=": "Updates a variable using its old value, such as x += y meaning x = x + y.",
    "%": "Remainder operator. a % b gives the remainder after integer division by b.",
    "^": "Bitwise XOR. Equal bits cancel; x ^ x is 0 and x ^ 0 is x.",
    "1LL": "A long long literal. Multiplying by 1LL promotes later arithmetic so it is performed with a wider integer type.",
    "iterator subtraction": "Subtracting two random-access iterators gives the zero-based distance between their positions.",
}


VARIABLE_PURPOSES = {
    "arr": "the input integer array used by the GFG-style function",
    "nums": "the input integer array used by the LeetCode-style function",
    "a": "the input array of packet sizes or values for this problem",
    "A": "the raw input array used by the window function",
    "matrix": "the input two-dimensional matrix; this function may read or update its cells",
    "mat": "the input two-dimensional matrix used by the GFG-style function",
    "height": "the input wall heights",
    "prices": "the stock price on each day, in chronological order",
    "fruits": "the fruit type at every consecutive tree position",
    "numbers": "the sorted input numbers in the LC 167 function",
    "intervals": "the working collection of intervals",
    "newInterval": "the interval that must be inserted and possibly expanded by overlaps",
    "key": "the target value searched for in the array",
    "m": "the number of packets that must be selected",
    "i": "the main zero-based loop index; it usually marks the element currently being processed",
    "j": "a second index, often used to compare another element or mark the next write position",
    "k": "the problem-supplied limit, window size, rotation count, or target parameter described by the signature",
    "n": "the number of elements currently considered",
    "N": "the array length supplied by the GFG function contract",
    "P": "the upper bound on original values in the limited-frequency problem",
    "row": "the current matrix row index",
    "column": "the current matrix column index",
    "r": "a short row index used while traversing a matrix",
    "c": "a short column index used while traversing a matrix",
    "rows": "the number of matrix rows",
    "columns": "the number of matrix columns",
    "left": "the left boundary or left pointer of the active search/window",
    "right": "the right boundary or right pointer of the active search/window",
    "low": "the beginning of the still-unknown region in a three-way partition or search",
    "mid": "the middle position in binary search, or the scanning pointer in Dutch National Flag",
    "high": "the end of the still-unknown region",
    "top": "the first unprocessed matrix row",
    "bottom": "the last unprocessed matrix row",
    "start": "the first index of a candidate subarray/window",
    "end": "the final index or iterator boundary of a candidate range",
    "index": "a computed zero-based position in an array/vector",
    "answer": "the best or complete result found so far",
    "result": "the result container/value being built for return",
    "sum": "the running sum of the elements currently being examined",
    "windowSum": "the sum of exactly the elements in the current sliding window",
    "totalSum": "the sum of the entire input, later compared with a partial sum",
    "leftSum": "the sum strictly to the left of the current index",
    "rightSum": "the sum strictly to the right of the current index",
    "prefixSum": "the cumulative sum from index 0 through the current position",
    "prefixXor": "the cumulative XOR from index 0 through the current position",
    "currentXor": "the XOR of the candidate subarray currently being enumerated",
    "prefix": "an array/container of cumulative values from the start",
    "suffix": "an array/container of cumulative values from the end",
    "frequency": "counts how many times each value/key occurs in the relevant range",
    "firstIndex": "stores the earliest index at which each prefix state occurred",
    "seen": "stores values or prefix states already visited",
    "values": "stores the distinct values needed for quick membership checks",
    "types": "stores the distinct fruit types in the current candidate range",
    "count": "a running occurrence/vote count",
    "currentCount": "the length/count of the streak currently ending at this position",
    "maximumCount": "the greatest valid streak/count found so far",
    "zeroes": "the number of zero values inside the current window",
    "ones": "the number of one values counted so far",
    "twos": "the number of two values counted so far",
    "length": "the length of the candidate sequence/subarray currently examined",
    "currentLength": "the length of the consecutive sequence currently being extended",
    "maximumLength": "the longest valid sequence length found so far",
    "currentValue": "the sequence value currently being checked or extended",
    "value": "the current element/value taken from the input or a candidate range",
    "required": "the complementary prefix/value needed to form the requested answer",
    "remaining": "the complement still needed to reach the target",
    "target": "the value or sum the problem asks the algorithm to find",
    "x": "the target/threshold value supplied by the problem",
    "outgoing": "the element leaving a sliding window",
    "windowStart": "the first valid index of the current fixed-size window",
    "pointer": "an index into a stored list that advances without moving backwards",
    "largestValue": "the largest distinct value seen so far",
    "secondLargest": "the second-largest distinct value seen so far",
    "minimumValue": "the smallest value found in the relevant range",
    "maximumValue": "the largest value found in the relevant range",
    "candidate": "the current possible majority value",
    "found": "records whether a requested value was discovered",
    "isLargest": "records whether the current candidate survived every comparison",
    "first": "the first matching boundary/index, or a flag describing the first row",
    "last": "the last matching boundary/index or saved last value",
    "position": "an iterator/index returned by a standard search operation",
    "leftOkay": "whether the current value satisfies the left-neighbour peak condition",
    "rightOkay": "whether the current value satisfies the right-neighbour peak condition",
    "currentSum": "the best sum of a subarray ending at the current element",
    "maximumSum": "the greatest valid sum found so far",
    "minimumSum": "the smallest subarray sum found so far",
    "currentMaximum": "the best maximum-sum state ending at the current element",
    "currentMinimum": "the best minimum-sum state ending at the current element",
    "maximumEnding": "the largest product of a subarray ending at the current element",
    "minimumEnding": "the smallest product ending here; a later negative value may turn it into the largest",
    "product": "the product of the candidate subarray currently being enumerated",
    "prefixProduct": "a running product scanned from the left",
    "suffixProduct": "a running product scanned from the right",
    "minimumPrice": "the cheapest stock price seen before or on the current day",
    "maximumProfit": "the greatest legal one-transaction profit found so far",
    "buy": "the candidate buying-day index",
    "sell": "the candidate selling-day index, always after buy",
    "suffixMaximum": "the best/largest value from each index through the end",
    "water": "the total trapped-water units accumulated so far",
    "leftMaximum": "the highest wall seen from the left",
    "rightMaximum": "the highest wall seen from the right",
    "smallerHeight": "the shorter boundary that limits the current container area",
    "area": "the container area produced by the current pair of boundaries",
    "uniqueTriplets": "an ordered set used to remove repeated 3Sum triplets",
    "triplet": "one candidate group of three values",
    "uniqueValues": "a temporary vector containing one copy of each sorted value",
    "number": "a working copy of the number whose digits are being counted",
    "digits": "the number of decimal digits found in the working number",
    "step": "the current simulation or repeated-operation count",
    "lastValue": "the final element saved before other values shift right",
    "newIndex": "the destination index after applying the rotation",
    "temp": "temporary storage used while swapping two values manually",
    "direction": "which of the four matrix movement directions is active",
    "directionRow": "row changes for right, down, left, and up movement",
    "directionColumn": "column changes for right, down, left, and up movement",
    "directions": "paired row/column changes for the four matrix directions",
    "nextRow": "the row index of the next proposed matrix cell",
    "nextColumn": "the column index of the next proposed matrix cell",
    "visited": "marks matrix cells already added to the spiral result",
    "firstRowZero": "remembers whether the original first row contained a zero",
    "firstColumnZero": "remembers whether the original first column contained a zero",
    "zeroRow": "marks rows that must become zero",
    "zeroColumn": "marks columns that must become zero",
    "firstRow": "remembers whether the original first row contained a one",
    "firstColumn": "remembers whether the original first column contained a one",
    "markRow": "marks rows that must become one",
    "markColumn": "marks columns that must become one",
    "negativeIndexes": "stores indices of negative values that may still be the first negative in a window",
    "rightPrefix": "the prefix-array position found by binary search for the required sum",
    "best": "the best valid boundary/index found during the current search",
    "pivot": "the special split position: a rotation minimum or next-permutation increase point",
    "successor": "the smallest suitable value to swap with the next-permutation pivot",
    "original": "an unchanged copy used for comparison or to prevent newly written markers from affecting the scan",
    "current": "the current candidate arrangement/value being processed",
    "permutations": "all generated unique arrangements in lexicographic order",
    "currentStart": "the starting point of the interval currently being merged",
    "currentEnd": "the ending point of the interval currently being merged",
    "changed": "records whether one merge occurred and another pass is required",
    "minimumDifference": "the smallest maximum-minus-minimum range found for m packets",
    "chosen": "the packet values currently selected by recursive subset generation",
    "repeating": "the value detected more than once",
    "missing": "the value absent from the required range",
    "slow": "Floyd's pointer that advances one link at a time",
    "fast": "Floyd's pointer that advances two links at a time during cycle detection",
    "mp": "a hash map from a previously seen value to its index",
}


def section(text: str, heading: str, next_heading: str | None = None) -> str:
    start_marker = f"## {heading}\n\n"
    if start_marker not in text:
        return ""
    value = text.split(start_marker, 1)[1]
    if next_heading:
        value = value.split(f"\n## {next_heading}", 1)[0]
    else:
        value = value.split("\n## ", 1)[0]
    return " ".join(line.strip() for line in value.strip().splitlines() if line.strip())


def split_signature(signature: str) -> tuple[str, str, list[str]]:
    head, params_text = signature.split("(", 1)
    return_type, method = head.rsplit(" ", 1)
    params = [p.strip() for p in params_text.rstrip(")").split(",") if p.strip()]
    return return_type.strip(), method.strip(), params


def explain_parameter(param: str) -> str:
    raw = param.strip()
    name_match = re.search(r"([A-Za-z_]\w*)\s*(?:\[\])?$", raw)
    name = name_match.group(1) if name_match else "parameter"
    is_raw_array = "[]" in raw
    by_reference = "&" in raw
    base = raw.replace("&", "").replace("[]", "")
    base = re.sub(rf"\b{re.escape(name)}\b\s*$", "", base).strip()
    meaning = PARAMETER_EXPLANATIONS.get(base, f"a value of type {base}")
    details = [f"`{name}` is {meaning}"]
    if by_reference:
        details.append("`&` passes the original object without copying it, so mutations remain visible to the caller")
    elif base.startswith("vector"):
        details.append("it is passed by value, so this function receives a copy")
    if is_raw_array:
        details.append("`[]` is a raw-array parameter and a separate length limits valid access")
    return "; ".join(details) + "."


def clean_code_for_walkthrough(code: str) -> list[str]:
    body = re.sub(r"/\*.*?\*/", "", code, flags=re.S)
    result = []
    for raw in body.splitlines():
        line = raw.strip()
        if not line or line in {"{", "}", "};"} or line.startswith("//"):
            continue
        if "//" in line:
            line = line.split("//", 1)[0].rstrip()
        result.append(line)
    return result


def parenthesized_part(line: str) -> tuple[str, str]:
    """Return the first balanced (...) content and the text following it."""
    start = line.find("(")
    if start == -1:
        return "", ""
    depth = 0
    for index in range(start, len(line)):
        if line[index] == "(":
            depth += 1
        elif line[index] == ")":
            depth -= 1
            if depth == 0:
                return line[start + 1:index], line[index + 1:].strip()
    return line[start + 1:], ""


def explain_line(line: str) -> str:
    plain = line.rstrip(";")
    if line.startswith("#include"):
        return "Loads the standard-library declarations used later in the file."
    if line.startswith("using namespace"):
        return "Allows standard-library names to be written without the `std::` prefix."
    if line.startswith("class Solution"):
        return "Defines the class name expected by the online judge."
    if line == "public:":
        return "Makes the following method callable by the judge."
    if re.match(r"(?:[\w:<>,&\[\] ]+)\s+\w+\([^;]*\)\s*\{?$", line) and not line.startswith(("if", "for", "while", "switch")):
        return "Defines the judge-facing function and lists the inputs it receives."
    if re.match(r"function<.*?>\s+\w+\s*=\s*\[&\]", line):
        name = re.search(r">\s+(\w+)\s*=", line).group(1)
        return f"Creates a callable named `{name}`. `[&]` lets it use surrounding local variables by reference, which is needed for the recursive search."
    if line.startswith("for(") or line.startswith("for ("):
        inner, trailing = parenthesized_part(line)
        if ":" in inner and ";" not in inner:
            message = f"Starts a range-based loop. `{inner}` means: take each element from the container in turn and run the block."
            return message + (f" Its one-line body is `{trailing}`." if trailing and trailing != "{" else "")
        parts = [p.strip() for p in inner.split(";")]
        if len(parts) == 3:
            message = f"Starts a loop: first `{parts[0]}`; keep repeating while `{parts[1]}` is true; after each iteration perform `{parts[2]}`."
            return message + (f" Its one-line body is `{trailing}`." if trailing and trailing != "{" else "")
        return "Starts a counted loop over the required range."
    if line.startswith("while(") or line.startswith("while ("):
        condition, trailing = parenthesized_part(line)
        message = f"Repeats the following block while `{condition}` is true."
        return message + (f" Its one-line body is `{trailing}`." if trailing and trailing != "{" else "")
    if line.startswith("do"):
        return "Starts a do-while loop, so its body runs at least once."
    if line.startswith("if(") or line.startswith("if ("):
        condition, trailing = parenthesized_part(line)
        message = f"Runs the next block only when `{condition}` is true."
        return message + (f" The one-line action is `{trailing}`." if trailing and trailing != "{" else "")
    if line.startswith("else if"):
        condition, trailing = parenthesized_part(line)
        message = f"If earlier branches failed, runs this block when `{condition}` is true."
        return message + (f" The one-line action is `{trailing}`." if trailing and trailing != "{" else "")
    if line.startswith("else"):
        return "Handles the remaining case after the preceding condition(s) were false."
    if line.startswith("return"):
        value = plain[len("return"):].strip()
        return f"Ends the function and sends `{value}` back to the caller." if value else "Ends the function."
    if line == "break;":
        return "Stops the nearest loop immediately because no more iterations are needed."
    if line == "continue;":
        return "Skips the rest of this iteration and starts the next one."
    if "sort(" in line:
        return "Sorts the selected range in ascending order, changing the container so ordered reasoning becomes possible."
    if "reverse(" in line:
        return "Reverses the selected range in place. The second iterator is one position past the range."
    if "swap(" in line:
        return "Exchanges the two selected values without needing a manual temporary variable."
    if ".push_back(" in line:
        return "Appends the computed value to the end of the result/container."
    if ".pop_front(" in line:
        return "Removes the oldest element from the front of the deque after it becomes irrelevant."
    if ".pop_back(" in line:
        return "Removes the last element from the container."
    if ".erase(" in line:
        return "Removes the selected key/element so the container represents only currently relevant data."
    if ".insert(" in line:
        return "Stores this value in the set/map so later iterations can find it."
    if "next_permutation(" in line:
        return "Uses the standard algorithm to replace the sequence with its next lexicographic permutation."
    if re.fullmatch(r"solve\s*\(\s*0\s*\)\s*;", line):
        return "Starts the recursive search at index 0, before any input element has been considered."
    if re.match(r"solve\s*\(", line):
        return "Recursively calls the local `solve` function with the next index, exploring the next include/exclude decision."
    if re.search(r"\b(?:int|long long|double|bool|auto|vector<.*?>|set<.*?>|map<.*?>|unordered_set<.*?>|unordered_map<.*?>|deque<.*?>|pair<.*?>)\s+\w+", line):
        match = re.search(r"\b([A-Za-z_]\w*)\s*(?:=|\(|\{|;|$)", plain)
        name = match.group(1) if match else "the variable"
        if "=" in plain:
            rhs = plain.split("=", 1)[1].strip()
            return f"Creates `{name}` and initializes it from `{rhs}`. This gives the algorithm its starting state."
        return f"Declares `{name}` so it can store state used by the algorithm."
    if re.search(r"(?:\+\+|--)(?:;|$)", line) or re.match(r"(?:\+\+|--)\w+", plain):
        return "Moves the relevant counter or pointer by one position."
    if re.search(r"(?:\+=|-=|\*=|/=)", line):
        return "Updates the stored state using its previous value and the expression on the right."
    if "=" in plain and "==" not in plain and "!=" not in plain and ">=" not in plain and "<=" not in plain:
        left, right = plain.split("=", 1)
        return f"Updates `{left.strip()}` to `{right.strip()}` for the next step of the algorithm."
    return "Performs this operation to maintain the state described in the algorithm walkthrough."


def glossary_keys(code: str) -> list[str]:
    tests = [
        ("#include <bits/stdc++.h>", "#include <bits/stdc++.h>" in code),
        ("using namespace std", "using namespace std" in code),
        ("class", re.search(r"\bclass\b", code)),
        ("public", "public:" in code),
        ("int", re.search(r"\bint\b", code)),
        ("long long", "long long" in code),
        ("double", re.search(r"\bdouble\b", code)),
        ("bool", re.search(r"\bbool\b", code)),
        ("void", re.search(r"\bvoid\b", code)),
        ("true / false", re.search(r"\b(?:true|false)\b", code)),
        ("vector", "vector<" in code),
        ("pair", "pair<" in code),
        ("set", re.search(r"\bset<", code)),
        ("unordered_set", "unordered_set<" in code),
        ("map", re.search(r"\bmap<", code)),
        ("unordered_map", "unordered_map<" in code),
        ("deque", "deque<" in code),
        ("function", "function<" in code),
        ("auto", re.search(r"\bauto\b", code)),
        ("for", re.search(r"\bfor\s*\(", code)),
        ("range-based for", re.search(r"for\s*\([^;]+:[^;]+\)", code)),
        ("while", re.search(r"\bwhile\s*\(", code)),
        ("do ... while", re.search(r"\bdo\s*\{", code)),
        ("if / else if / else", re.search(r"\bif\s*\(", code)),
        ("return", re.search(r"\breturn\b", code)),
        ("break", re.search(r"\bbreak\s*;", code)),
        ("continue", re.search(r"\bcontinue\s*;", code)),
        ("const", re.search(r"\bconst\b", code)),
        ("reference (&)", "&" in code),
        ("raw array ([]) ", "[]" in code),
        ("begin / end", ".begin()" in code or ".end()" in code),
        ("size", ".size()" in code),
        ("empty", ".empty()" in code),
        ("push_back", ".push_back(" in code),
        ("pop_back / pop_front", ".pop_" in code),
        ("front / back", ".front()" in code or ".back()" in code),
        ("insert", ".insert(" in code),
        ("erase", ".erase(" in code),
        ("find", "find(" in code),
        ("sort", "sort(" in code),
        ("reverse", "reverse(" in code),
        ("swap", "swap(" in code),
        ("min / max", re.search(r"\b(?:min|max)\(", code)),
        ("min_element / max_element", "_element(" in code),
        ("lower_bound", "lower_bound(" in code),
        ("upper_bound", "upper_bound(" in code),
        ("binary_search", "binary_search(" in code),
        ("next_permutation", "next_permutation(" in code),
        ("INT_MIN / INT_MAX", "INT_MIN" in code or "INT_MAX" in code),
        ("LLONG_MIN", "LLONG_MIN" in code),
        ("DBL_MAX", "DBL_MAX" in code),
        ("static_cast / C-style cast", "static_cast" in code or re.search(r"\([A-Za-z ]+\)\w", code)),
        ("lambda ([&])", "[&]" in code),
        ("recursion", "function<" in code),
        ("?:", "?" in code and ":" in code),
        ("&&", "&&" in code),
        ("||", "||" in code),
        ("!", re.search(r"!(?!=)", code)),
        ("++ / --", "++" in code or "--" in code),
        ("+= / -= / *= / /=", re.search(r"[+\-*/]=", code)),
        ("%", "%" in code),
        ("^", "^" in code),
        ("1LL", "1LL" in code),
        ("iterator subtraction", re.search(r"\.begin\(\)", code) and re.search(r"-\s*\w+\.begin\(\)", code)),
    ]
    result = []
    for key, present in tests:
        key = key.strip()
        if present and key in GLOSSARY and key not in result:
            result.append(key)
    return result


def variable_guide(code: str, signature: str) -> list[str]:
    """Return purposes for parameters and local state, in first-use order."""
    _, method, params = split_signature(signature)
    names: list[str] = []
    for param in params:
        match = re.search(r"([A-Za-z_]\w*)\s*(?:\[\])?$", param)
        if match:
            names.append(match.group(1))

    code_without_comments = re.sub(r"/\*.*?\*/", "", code, flags=re.S)
    declaration = re.compile(
        r"\b(?:int|long long|double|bool|auto|vector<[^;]+?>|set<[^;]+?>|"
        r"unordered_set<[^;]+?>|map<[^;]+?>|unordered_map<[^;]+?>|"
        r"deque<[^;]+?>|pair<[^;]+?>)\s+([A-Za-z_]\w*)"
    )
    for match in declaration.finditer(code_without_comments):
        name = match.group(1)
        if name != method and name not in names:
            names.append(name)

    # Pick up additional variables from declarations such as
    # `int top = 0, bottom = n - 1, left = 0, right = m - 1;`.
    for line in code_without_comments.splitlines():
        match = re.match(r"\s*(?:int|long long|double|bool)\s+(.+?);", line)
        if not match:
            continue
        for part in match.group(1).split(","):
            name_match = re.match(r"\s*([A-Za-z_]\w*)", part)
            if name_match:
                name = name_match.group(1)
                if name != method and name not in names:
                    names.append(name)

    result = []
    for name in names:
        purpose = VARIABLE_PURPOSES.get(
            name,
            "a value/container whose exact updates are shown in the numbered walkthrough below",
        )
        result.append(f"- `{name}`: {purpose}.")
    return result


def strip_old_appendix(code: str) -> str:
    marker = "/*\nDETAILED BEGINNER EXPLANATION"
    if marker in code:
        return code.split(marker, 1)[0].rstrip() + "\n"
    # Most original files ended with a short /* Time Complexity ... */ block.
    code = re.sub(
        r"\n/\*\n(?:Time Complexity:|Approach:).*?\*/\s*$",
        "\n",
        code,
        flags=re.S,
    )
    code = re.sub(
        r"\n/\*\nTime Complexity:.*?\*/\s*$",
        "\n",
        code,
        flags=re.S,
    )
    return code.rstrip() + "\n"


def referenced_parameter_names(signature: str) -> list[str]:
    """Return only parameters passed by non-const reference or as raw arrays."""
    _, _, params = split_signature(signature)
    names = []
    for param in params:
        if "&" not in param and "[]" not in param:
            continue
        if re.search(r"\bconst\b", param):
            continue
        match = re.search(r"([A-Za-z_]\w*)\s*(?:\[\])?$", param)
        if match:
            names.append(match.group(1))
    return names


def mutates_input(code: str, signature: str, return_type: str) -> bool:
    """Conservatively detect writes to parameters, not unrelated local containers."""
    names = referenced_parameter_names(signature)
    if not names:
        return False
    # In this repository the judge-facing void methods communicate their result
    # by changing the input object.
    if return_type == "void":
        return True
    for name in names:
        escaped = re.escape(name)
        patterns = (
            rf"\b{escaped}\s*=",                         # nums = answer
            rf"\b{escaped}\s*\[[^\]]+\]\s*(?:[+\-*/%]?=|\+\+|--)",
            rf"(?:\+\+|--)\s*{escaped}\s*\[",          # ++arr[i]
            rf"\b(?:sort|reverse)\s*\(\s*{escaped}\.",
            rf"\bswap\s*\([^;]*\b{escaped}\s*\[",
            rf"\b{escaped}\.(?:assign|clear|erase|insert|push_back|pop_back|resize)\s*\(",
        )
        if any(re.search(pattern, code) for pattern in patterns):
            return True
    return False


def approach_specific_reasoning(level: int, approach: dict, optimal_trace: str,
                                optimal_correctness: str, optimal_invariant: str) -> tuple[str, str, str]:
    """Avoid presenting the optimal proof as if it described another implementation."""
    name = approach["name"]
    if level == 4:
        return optimal_trace, optimal_correctness, optimal_invariant
    if level == 2:
        proof = (
            f'This file uses the exhaustive "{name}" strategy. The numbered walkthrough '
            "shows the complete candidate search performed by this implementation. Because "
            "every candidate allowed by the loops is examined before the answer is returned, "
            "a valid candidate cannot be skipped; the return/update condition keeps exactly "
            "the result required by the problem."
        )
        invariant = (
            "All candidates before the current loop position have been examined according to "
            "the code's condition, and the stored result reflects those candidates."
        )
    else:
        proof = (
            f'This file uses the intermediate "{name}" strategy. Each operation in the numbered '
            "walkthrough preserves the information needed for the answer while arranging or "
            "storing it in a form that is easier to query. After every input element or required "
            "position has been processed, the final return/update condition selects the requested result."
        )
        invariant = (
            "After each completed iteration, the auxiliary or rearranged state represents every "
            "input item processed so far without discarding information needed for the answer."
        )
    trace = (
        f'Trace this exact file using the first example in `testcases.md`. It applies the "{name}" '
        "approach, so follow the numbered executable statements above and record each listed "
        "variable after it changes. Do not reuse the optimal implementation's saved variables: "
        "this file may enumerate candidates, sort values, or build auxiliary state instead."
    )
    return trace, proof, invariant


def appendix(path: Path, code: str, metadata: dict, explanation_doc: str, readme: str) -> str:
    level = int(path.name[:2])
    approach = metadata["approaches"][level - 2]
    return_type, method, params = split_signature(metadata["signature"])
    thinking = section(explanation_doc, "How to think about it", "Worked trace")
    problem_summary = section(readme, "Problem summary", "Classification")
    problem_summary = problem_summary.replace(
        "This is a study summary, not a verbatim copy of the platform statement. Confirm the current platform signature and constraints before submission.",
        "",
    ).strip()
    optimal_trace = section(explanation_doc, "Worked trace", "Why this works")
    optimal_correctness = section(explanation_doc, "Why this works", "Approaches to compare")
    trace, correctness, invariant = approach_specific_reasoning(
        level, approach, optimal_trace, optimal_correctness, metadata["invariant"]
    )
    input_contract = section(explanation_doc, "Input and result", "How to think about it")
    if "```" in input_contract:
        input_contract = input_contract.split("```", 2)[-1].strip()
    lines = clean_code_for_walkthrough(code)
    walk = [f"{i}. `{line}`\n   {explain_line(line)}" for i, line in enumerate(lines, 1)]
    terms = glossary_keys(code)
    glossary = [f"- {key}: {GLOSSARY[key]}" for key in terms]
    variables = variable_guide(code, metadata["signature"])
    mutates = "Yes" if mutates_input(code, metadata["signature"], return_type) else "No deliberate input mutation, apart from any mutation explicitly visible in the walkthrough"
    parameter_text = "\n".join(f"- {explain_parameter(p)}" for p in params)
    return_meaning = TYPE_EXPLANATIONS.get(return_type, f"returns a value of type {return_type}")
    return f'''/*
DETAILED BEGINNER EXPLANATION
=============================

1. WHAT THIS FILE SOLVES
------------------------
Problem: {metadata['title']}
Platform: {metadata['platform']}
Pattern: {metadata['pattern']}

Problem goal:
{problem_summary or metadata['recognition_cue']}

Core insight for this problem family:
{thinking}

This particular file uses the "{approach['name']}" approach.
It is the {['brute-force baseline', 'intermediate comparison', 'preferred/optimal reference'][level - 2]} stored in this problem folder.

2. FUNCTION SIGNATURE, PART BY PART
-----------------------------------
`{metadata['signature']}`

- `{return_type}` means this function {return_meaning}.
- `{method}` is the function name the online judge calls.
{parameter_text}
- Mutates an input object: {mutates}.

Contract/preconditions recorded for this repository:
{input_contract or 'Use the constraints and conventions stated in the problem README and metadata.'}

3. ALGORITHM IN SIMPLE STEPS
----------------------------
Approach name: {approach['name']}

This file implements exactly the approach named above. {['It deliberately uses a direct baseline so you can see the complete search before optimizing it.', 'It demonstrates an intermediate method or a different time/space trade-off.', 'It is the preferred implementation under the stated input contract.'][level - 2]}

Important variables and what they mean:

{chr(10).join(variables)}

Read the executable code in this order:

{chr(10).join(walk)}

4. C++ KEYWORDS, TYPES, STL CALLS, AND SYMBOLS USED
---------------------------------------------------
{chr(10).join(glossary)}

General syntax reminders:
- Parentheses `()` hold function arguments or conditions.
- Braces `{{}}` group statements into a class, function, loop, or condition block.
- Square brackets `[]` index a vector/array from zero; valid indices are 0 through size-1.
- A semicolon `;` ends a C++ statement.
- `==` compares values; `=` assigns a new value. Confusing them is a common bug.
- `<`, `>`, `<=`, and `>=` compare values.

5. DRY RUN
----------
{trace}

When tracing by hand, write the important variables after every iteration. Do not jump directly to the final answer.

6. WHY THE ALGORITHM IS CORRECT
-------------------------------
{correctness}

The key invariant (a fact that remains true after every useful iteration) is:
{invariant}

7. COMPLEXITY
-------------
- Time complexity: {approach['time']}.
- Extra-space complexity: {approach['space']}.
- `n` normally means the number of array elements. For matrix problems, use rows and columns as described in the approach.
- Required output storage is excluded only when the complexity text explicitly says so.

8. EDGE CASES TO CHECK
----------------------
- The smallest input allowed by the contract.
- Repeated values and an answer at the first or last valid position.
- Already sorted/reversed input when ordering matters.
- All-negative values, zeroes, or a missing answer when the problem permits them.
- Values near integer limits when the code adds, subtracts, multiplies, or forms a complement.
- For in-place code, remember that the input may look different after the call.

9. COMMON MISTAKES
------------------
- Using `=` when a comparison needs `==`.
- Reading index `size()` even though the final valid index is `size() - 1`.
- Moving a pointer/counter in the wrong branch or forgetting to move it, causing an infinite loop.
- Returning the right value with the wrong index base (zero-based versus one-based).
- Copying this approach to inputs that do not satisfy its sortedness, positivity, range, or matrix-shape assumptions.
- Ignoring overflow: promote before arithmetic when the implementation uses `long long` or `1LL`.

10. HOW TO STUDY THIS SOLUTION
------------------------------
1. Hide the code and state the main idea in one sentence.
2. Explain every variable without using its name as the explanation.
3. Perform the dry run and state the invariant after each iteration.
4. Re-code the method from memory.
5. Compare it with the other numbered approaches in this folder and explain the time/space trade-off.

Comments are ignored by the C++ compiler, so this appendix changes documentation only, not program behaviour.
*/
'''


def main() -> None:
    changed = 0
    for metadata_path in sorted(ROOT.glob("*/*/*/metadata.json")):
        folder = metadata_path.parent
        metadata = json.loads(metadata_path.read_text())
        explanation_doc = (folder / "solution.md").read_text()
        readme = (folder / "README.md").read_text()
        for path in sorted(folder.glob("0[234]_*.cpp")):
            original = path.read_text()
            clean = strip_old_appendix(original)
            updated = clean.rstrip() + "\n\n" + appendix(path, clean, metadata, explanation_doc, readme)
            if updated != original:
                path.write_text(updated)
                changed += 1
    print(f"Added detailed explanatory appendices to {changed} C++ reference files.")


if __name__ == "__main__":
    main()
