#!/usr/bin/env python3
"""Create the intentionally-unsolved Strings learning module and its trackers."""

from __future__ import annotations

import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
STRINGS_ROOT = ROOT / "02_Strings"

CATEGORIES = [
    ("01_Basics", "String basics and traversal", "Indexing, character classification, building output, and careful boundary handling."),
    ("02_Frequency_Counting", "Frequency counting and hashing", "Turn characters into counts, compare distributions, and choose an appropriate counting structure."),
    ("03_Two_Pointers_Palindrome", "Two pointers and palindromes", "Move inward safely, normalize only when required, and reason about one permitted mismatch."),
    ("04_Mapping_Anagrams", "Mappings and anagrams", "Maintain one-to-one mappings and use canonical representations without losing multiplicity."),
    ("05_Sliding_Window_Basics", "Fixed sliding-window basics", "Reuse work when a fixed-size substring moves one position."),
    ("06_Sliding_Window_Advanced", "Variable sliding windows", "Grow and shrink a window while maintaining a precise validity condition."),
    ("07_Parsing_Conversion", "Parsing and conversion", "Translate representations, handle signs and overflow, and simulate arithmetic on strings."),
    ("08_Pattern_Matching", "Pattern matching", "Progress from direct comparison to prefix functions and KMP, then Rabin–Karp-style rolling-hash reasoning."),
    ("09_Advanced_Mixed", "Advanced mixed string problems", "Combine earlier tools with grouping, greedy boundaries, modular indexing, or simulation."),
]


def p(category, folder, title, url, difficulty, signature, concepts, prerequisites, goal, tests):
    return {
        "category": category,
        "folder": folder,
        "title": title,
        "url": url,
        "platform": "GeeksforGeeks" if "geeksforgeeks" in url else "LeetCode",
        "difficulty": difficulty,
        "signature": signature,
        "concepts": concepts,
        "prerequisites": prerequisites,
        "goal": goal,
        "tests": tests,
    }


PROBLEMS = [
    p("01_Basics", "01_LC_344_Reverse_String", "Reverse String", "https://leetcode.com/problems/reverse-string/", "Easy", "void reverseString(vector<char>& s)", "Traversal; indexing; in-place updates", "vector<char>; zero-based indexing", "Practise reading and changing characters without creating an unnecessary second answer.", ["['h','e','l','l','o'] -> ['o','l','l','e','h']", "['H','a','n','n','a','h'] -> ['h','a','n','n','a','H']", "['a'] -> ['a']"]),
    p("01_Basics", "02_LC_709_To_Lower_Case", "To Lower Case", "https://leetcode.com/problems/to-lower-case/", "Easy", "string toLowerCase(string s)", "Character traversal; ASCII/library conversion", "char; string; range-based loops", "Learn to transform selected characters while leaving all other characters unchanged.", ["\"Hello\" -> \"hello\"", "\"here\" -> \"here\"", "\"LOVELY\" -> \"lovely\""]),
    p("01_Basics", "03_LC_58_Length_of_Last_Word", "Length of Last Word", "https://leetcode.com/problems/length-of-last-word/", "Easy", "int lengthOfLastWord(string s)", "Reverse traversal; whitespace boundaries", "string::size; indexes", "Handle trailing separators and stop exactly at the previous word boundary.", ["\"Hello World\" -> 5", "\"   fly me   to   the moon  \" -> 4", "\"a\" -> 1"]),
    p("01_Basics", "04_LC_1768_Merge_Strings_Alternately", "Merge Strings Alternately", "https://leetcode.com/problems/merge-strings-alternately/", "Easy", "string mergeAlternately(string word1, string word2)", "Parallel traversal; output construction", "string concatenation; unequal lengths", "Coordinate two indexes and append the remaining suffix safely.", ["\"abc\", \"pqr\" -> \"apbqcr\"", "\"ab\", \"pqrs\" -> \"apbqrs\"", "\"abcd\", \"pq\" -> \"apbqcd\""]),
    p("01_Basics", "05_LC_151_Reverse_Words_in_a_String", "Reverse Words in a String", "https://leetcode.com/problems/reverse-words-in-a-string/", "Medium", "string reverseWords(string s)", "Token boundaries; traversal; normalized output", "basic string traversal; whitespace handling", "Separate word order from character order and normalize repeated spaces.", ["\"the sky is blue\" -> \"blue is sky the\"", "\"  hello world  \" -> \"world hello\"", "\"a good   example\" -> \"example good a\""]),

    p("02_Frequency_Counting", "06_LC_387_First_Unique_Character", "First Unique Character in a String", "https://leetcode.com/problems/first-unique-character-in-a-string/", "Easy", "int firstUniqChar(string s)", "Frequency table; second pass", "arrays or unordered_map; traversal", "Learn why counting first and locating second can be clearer than mixing both jobs.", ["\"leetcode\" -> 0", "\"loveleetcode\" -> 2", "\"aabb\" -> -1"]),
    p("02_Frequency_Counting", "07_LC_383_Ransom_Note", "Ransom Note", "https://leetcode.com/problems/ransom-note/", "Easy", "bool canConstruct(string ransomNote, string magazine)", "Consumable counts; hashing", "frequency arrays; decrementing counts", "Treat each source character as a resource that can be used only as often as it appears.", ["\"a\", \"b\" -> false", "\"aa\", \"ab\" -> false", "\"aa\", \"aab\" -> true"]),
    p("02_Frequency_Counting", "08_LC_1941_Check_Equal_Occurrences", "Check if All Characters Have Equal Number of Occurrences", "https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/", "Easy", "bool areOccurrencesEqual(string s)", "Frequency comparison; ignoring absent keys", "frequency arrays or maps", "Compare only characters that actually occur and avoid treating zero counts as evidence.", ["\"abacbc\" -> true", "\"aaabb\" -> false", "\"zz\" -> true"]),
    p("02_Frequency_Counting", "09_LC_1189_Maximum_Number_of_Balloons", "Maximum Number of Balloons", "https://leetcode.com/problems/maximum-number-of-balloons/", "Easy", "int maxNumberOfBalloons(string text)", "Required multiplicities; limiting frequency", "frequency tables; integer division", "Account for letters that occur twice in the target word and identify the limiting resource.", ["\"nlaebolko\" -> 1", "\"loonbalxballpoon\" -> 2", "\"leetcode\" -> 0"]),
    p("02_Frequency_Counting", "10_LC_451_Sort_Characters_by_Frequency", "Sort Characters by Frequency", "https://leetcode.com/problems/sort-characters-by-frequency/", "Medium", "string frequencySort(string s)", "Counting; ordering by frequency; buckets or sorting", "maps; pairs; custom comparison", "Move from merely counting characters to reconstructing output in frequency order.", ["\"tree\" -> any valid frequency-sorted result", "\"cccaaa\" -> any valid result with grouped equal frequencies", "\"Aabb\" -> any valid frequency-sorted result"]),

    p("03_Two_Pointers_Palindrome", "11_LC_125_Valid_Palindrome", "Valid Palindrome", "https://leetcode.com/problems/valid-palindrome/", "Easy", "bool isPalindrome(string s)", "Two pointers; character filtering; case normalization", "isalnum/tolower or equivalent checks", "Coordinate two pointers while skipping irrelevant characters independently.", ["\"A man, a plan, a canal: Panama\" -> true", "\"race a car\" -> false", "\" \" -> true"]),
    p("03_Two_Pointers_Palindrome", "12_LC_680_Valid_Palindrome_II", "Valid Palindrome II", "https://leetcode.com/problems/valid-palindrome-ii/", "Easy", "bool validPalindrome(string s)", "Two pointers; one allowed deletion", "palindrome range checking", "Branch only at the first mismatch and test the two meaningful remaining ranges.", ["\"aba\" -> true", "\"abca\" -> true", "\"abc\" -> false"]),
    p("03_Two_Pointers_Palindrome", "13_LC_2108_First_Palindromic_String", "Find First Palindromic String in the Array", "https://leetcode.com/problems/find-first-palindromic-string-in-the-array/", "Easy", "string firstPalindrome(vector<string>& words)", "Reusable palindrome check; ordered search", "vector<string>; helper functions", "Write a small reusable predicate and respect the input order when returning the first match.", ["[\"abc\",\"car\",\"ada\",\"racecar\",\"cool\"] -> \"ada\"", "[\"notapalindrome\",\"racecar\"] -> \"racecar\"", "[\"def\",\"ghi\"] -> \"\""]),
    p("03_Two_Pointers_Palindrome", "14_LC_345_Reverse_Vowels", "Reverse Vowels of a String", "https://leetcode.com/problems/reverse-vowels-of-a-string/", "Easy", "string reverseVowels(string s)", "Two pointers; membership checks; selective swaps", "character sets; swap", "Skip non-target characters from both ends and swap only members of the selected set.", ["\"IceCreAm\" -> \"AceCreIm\"", "\"leetcode\" -> \"leotcede\"", "\"rhythm\" -> \"rhythm\""]),
    p("03_Two_Pointers_Palindrome", "15_LC_917_Reverse_Only_Letters", "Reverse Only Letters", "https://leetcode.com/problems/reverse-only-letters/", "Easy", "string reverseOnlyLetters(string s)", "Two pointers; classification; selective swaps", "isalpha; boundary checks", "Preserve fixed punctuation positions while reversing only eligible characters.", ["\"ab-cd\" -> \"dc-ba\"", "\"a-bC-dEf-ghIj\" -> \"j-Ih-gfE-dCba\"", "\"Test1ng-Leet=code-Q!\" -> \"Qedo1ct-eeLg=ntse-T!\""]),

    p("04_Mapping_Anagrams", "16_LC_242_Valid_Anagram", "Valid Anagram", "https://leetcode.com/problems/valid-anagram/", "Easy", "bool isAnagram(string s, string t)", "Frequency equality; anagram invariants", "frequency counting; length checks", "Use character multiplicity, not membership alone, to decide whether two strings are rearrangements.", ["\"anagram\", \"nagaram\" -> true", "\"rat\", \"car\" -> false", "\"aacc\", \"ccac\" -> false"]),
    p("04_Mapping_Anagrams", "17_LC_205_Isomorphic_Strings", "Isomorphic Strings", "https://leetcode.com/problems/isomorphic-strings/", "Easy", "bool isIsomorphic(string s, string t)", "Bidirectional mapping; consistency", "hash maps or fixed arrays", "Enforce a one-to-one mapping in both directions rather than checking only one direction.", ["\"egg\", \"add\" -> true", "\"foo\", \"bar\" -> false", "\"badc\", \"baba\" -> false"]),
    p("04_Mapping_Anagrams", "18_LC_290_Word_Pattern", "Word Pattern", "https://leetcode.com/problems/word-pattern/", "Easy", "bool wordPattern(string pattern, string s)", "Tokenization; bidirectional mapping", "string streams or manual word parsing; maps", "Apply the same one-to-one mapping idea across different element types: characters and whole words.", ["\"abba\", \"dog cat cat dog\" -> true", "\"abba\", \"dog cat cat fish\" -> false", "\"aaaa\", \"dog cat cat dog\" -> false"]),
    p("04_Mapping_Anagrams", "19_LC_49_Group_Anagrams", "Group Anagrams", "https://leetcode.com/problems/group-anagrams/", "Medium", "vector<vector<string>> groupAnagrams(vector<string>& strs)", "Canonical keys; hash-map grouping", "anagram frequency/sorting; map values as vectors", "Create the same reliable key for every member of an anagram group.", ["[\"eat\",\"tea\",\"tan\",\"ate\",\"nat\",\"bat\"] -> groups by anagram", "[\"\"] -> [[\"\"]]", "[\"a\"] -> [[\"a\"]]"]),
    p("04_Mapping_Anagrams", "20_LC_1657_Close_Strings", "Determine if Two Strings Are Close", "https://leetcode.com/problems/determine-if-two-strings-are-close/", "Medium", "bool closeStrings(string word1, string word2)", "Character sets; multiset of frequencies", "frequency arrays; sorting small arrays", "Separate which characters exist from how often the existing characters occur.", ["\"abc\", \"bca\" -> true", "\"a\", \"aa\" -> false", "\"cabbba\", \"abbccc\" -> true"]),

    p("05_Sliding_Window_Basics", "21_LC_1876_Good_Substrings_of_Size_Three", "Substrings of Size Three with Distinct Characters", "https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/", "Easy", "int countGoodSubstrings(string s)", "Fixed window; tiny frequency state", "frequency counting; substring boundaries", "Recognize when a fixed window is small enough for direct checks and when maintained counts are clearer.", ["\"xyzzaz\" -> 1", "\"aababcabc\" -> 4", "\"ab\" -> 0"]),
    p("05_Sliding_Window_Basics", "22_LC_1456_Maximum_Vowels_in_Substring", "Maximum Number of Vowels in a Substring of Given Length", "https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/", "Medium", "int maxVowels(string s, int k)", "Fixed window; add incoming/remove outgoing", "vowel membership; running counts", "Update one window statistic in constant time as the window slides.", ["\"abciiidef\", 3 -> 3", "\"aeiou\", 2 -> 2", "\"leetcode\", 3 -> 2"]),
    p("05_Sliding_Window_Basics", "23_LC_2379_Minimum_Recolors", "Minimum Recolors to Get K Consecutive Black Blocks", "https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/", "Easy", "int minimumRecolors(string blocks, int k)", "Fixed window; minimize a count", "running counts; min", "Interpret the cost of a candidate substring as the count of characters that must change.", ["\"WBBWWBBWBW\", 7 -> 3", "\"WBWBBBW\", 2 -> 0", "\"WW\", 1 -> 1"]),
    p("05_Sliding_Window_Basics", "24_LC_567_Permutation_in_String", "Permutation in String", "https://leetcode.com/problems/permutation-in-string/", "Medium", "bool checkInclusion(string s1, string s2)", "Fixed window; frequency equality", "valid anagram; two frequency tables", "Turn an anagram question into a fixed-length substring scan.", ["\"ab\", \"eidbaooo\" -> true", "\"ab\", \"eidboaoo\" -> false", "\"adc\", \"dcda\" -> true"]),
    p("05_Sliding_Window_Basics", "25_LC_438_Find_All_Anagrams", "Find All Anagrams in a String", "https://leetcode.com/problems/find-all-anagrams-in-a-string/", "Medium", "vector<int> findAnagrams(string s, string p)", "Fixed window; frequency equality; result indexes", "permutation-in-string pattern; vector output", "Extend existence checking into reporting every valid starting position.", ["\"cbaebabacd\", \"abc\" -> [0,6]", "\"abab\", \"ab\" -> [0,1,2]", "\"a\", \"aa\" -> []"]),

    p("06_Sliding_Window_Advanced", "26_LC_3_Longest_Substring_Without_Repeating", "Longest Substring Without Repeating Characters", "https://leetcode.com/problems/longest-substring-without-repeating-characters/", "Medium", "int lengthOfLongestSubstring(string s)", "Variable window; last seen/frequency state", "two pointers; hash maps", "Shrink or jump the left boundary without losing the invariant that the current window has unique characters.", ["\"abcabcbb\" -> 3", "\"bbbbb\" -> 1", "\"pwwkew\" -> 3"]),
    p("06_Sliding_Window_Advanced", "27_LC_424_Longest_Repeating_Character_Replacement", "Longest Repeating Character Replacement", "https://leetcode.com/problems/longest-repeating-character-replacement/", "Medium", "int characterReplacement(string s, int k)", "Variable window; dominant frequency; replacement budget", "frequency arrays; window length", "Express validity as window length minus its most frequent character count.", ["\"ABAB\", 2 -> 4", "\"AABABBA\", 1 -> 4", "\"AAAA\", 0 -> 4"]),
    p("06_Sliding_Window_Advanced", "28_LC_76_Minimum_Window_Substring", "Minimum Window Substring", "https://leetcode.com/problems/minimum-window-substring/", "Hard", "string minWindow(string s, string t)", "Variable window; required multiplicities; minimum valid range", "frequency maps; grow/shrink windows", "Track when all required counts are satisfied, then remove unnecessary characters from the left.", ["\"ADOBECODEBANC\", \"ABC\" -> \"BANC\"", "\"a\", \"a\" -> \"a\"", "\"a\", \"aa\" -> \"\""]),
    p("06_Sliding_Window_Advanced", "29_LC_1358_Substrings_Containing_ABC", "Number of Substrings Containing All Three Characters", "https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/", "Medium", "int numberOfSubstrings(string s)", "Variable window; count all valid extensions", "frequency counts; combinational window counting", "Count many valid substrings at once after the smallest required window becomes valid.", ["\"abcabc\" -> 10", "\"aaacb\" -> 3", "\"abc\" -> 1"]),
    p("06_Sliding_Window_Advanced", "30_LC_2024_Maximize_Exam_Confusion", "Maximize the Confusion of an Exam", "https://leetcode.com/problems/maximize-the-confusion-of-an-exam/", "Medium", "int maxConsecutiveAnswers(string answerKey, int k)", "Variable window; bounded flips; symmetric cases", "replacement-window reasoning", "Model a binary alphabet and decide whether one generic invariant or two passes is clearer.", ["\"TTFF\", 2 -> 4", "\"TFFT\", 1 -> 3", "\"TTFTTFTT\", 1 -> 5"]),

    p("07_Parsing_Conversion", "31_LC_13_Roman_to_Integer", "Roman to Integer", "https://leetcode.com/problems/roman-to-integer/", "Easy", "int romanToInt(string s)", "Symbol mapping; local parsing rule", "maps or switch; traversal", "Recognize when a smaller symbol before a larger one changes the operation from addition to subtraction.", ["\"III\" -> 3", "\"LVIII\" -> 58", "\"MCMXCIV\" -> 1994"]),
    p("07_Parsing_Conversion", "32_LC_8_String_to_Integer_Atoi", "String to Integer (atoi)", "https://leetcode.com/problems/string-to-integer-atoi/", "Medium", "int myAtoi(string s)", "Parsing states; sign; overflow clamping", "digit conversion; integer limits", "Process whitespace, optional sign, digits, and overflow in the exact required order.", ["\"42\" -> 42", "\"   -042\" -> -42", "\"1337c0d3\" -> 1337", "\"-91283472332\" -> INT_MIN"]),
    p("07_Parsing_Conversion", "33_LC_12_Integer_to_Roman", "Integer to Roman", "https://leetcode.com/problems/integer-to-roman/", "Medium", "string intToRoman(int num)", "Greedy representation; ordered symbol table", "integer division/remainder; output building", "Choose the largest legal symbol repeatedly, including subtractive pairs as first-class entries.", ["3749 -> \"MMMDCCXLIX\"", "58 -> \"LVIII\"", "1994 -> \"MCMXCIV\""]),
    p("07_Parsing_Conversion", "34_LC_415_Add_Strings", "Add Strings", "https://leetcode.com/problems/add-strings/", "Easy", "string addStrings(string num1, string num2)", "Digit simulation; carry; reverse traversal", "character-to-digit conversion; output reversal", "Simulate column addition without converting the entire inputs to built-in numeric types.", ["\"11\", \"123\" -> \"134\"", "\"456\", \"77\" -> \"533\"", "\"0\", \"0\" -> \"0\""]),
    p("07_Parsing_Conversion", "35_LC_43_Multiply_Strings", "Multiply Strings", "https://leetcode.com/problems/multiply-strings/", "Medium", "string multiply(string num1, string num2)", "Digit simulation; positional accumulation; carries", "add-strings idea; vectors; place values", "Translate grade-school multiplication into indexed accumulation while handling leading zeroes.", ["\"2\", \"3\" -> \"6\"", "\"123\", \"456\" -> \"56088\"", "\"0\", \"999\" -> \"0\""]),

    p("08_Pattern_Matching", "36_LC_28_First_Occurrence", "Find the Index of the First Occurrence in a String", "https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/", "Easy", "int strStr(string haystack, string needle)", "Naive pattern matching; alignment boundaries", "nested traversal; substring length", "Start with direct alignment checking and make every boundary explicit before using advanced algorithms.", ["\"sadbutsad\", \"sad\" -> 0", "\"leetcode\", \"leeto\" -> -1", "\"aaa\", \"aaaa\" -> -1"]),
    p("08_Pattern_Matching", "37_LC_459_Repeated_Substring_Pattern", "Repeated Substring Pattern", "https://leetcode.com/problems/repeated-substring-pattern/", "Easy", "bool repeatedSubstringPattern(string s)", "Periodicity; divisors; prefix-function motivation", "substring comparison; factors of length", "Connect repeated structure with valid period lengths before studying prefix functions.", ["\"abab\" -> true", "\"aba\" -> false", "\"abcabcabcabc\" -> true"]),
    p("08_Pattern_Matching", "38_GFG_Search_Pattern_KMP", "Search Pattern (KMP Algorithm)", "https://www.geeksforgeeks.org/problems/search-pattern0205/1", "Medium", "vector<int> search(string &pat, string &txt)", "LPS/prefix table; KMP fallback", "naive matching; prefix/suffix definitions", "Build the prefix table and reuse matched information instead of restarting after a mismatch.", ["txt=\"abcab\", pat=\"ab\" -> [0,3] (confirm platform index convention)", "txt=\"aaaaa\", pat=\"aa\" -> overlapping matches", "pattern longer than text -> []"]),
    p("08_Pattern_Matching", "39_LC_1392_Longest_Happy_Prefix", "Longest Happy Prefix", "https://leetcode.com/problems/longest-happy-prefix/", "Hard", "string longestPrefix(string s)", "Prefix function; proper prefix/suffix", "KMP LPS construction", "Understand what the final prefix-function value means even when no separate text search is performed.", ["\"level\" -> \"l\"", "\"ababab\" -> \"abab\"", "\"leetcodeleet\" -> \"leet\""]),
    p("08_Pattern_Matching", "40_LC_187_Repeated_DNA_Sequences", "Repeated DNA Sequences", "https://leetcode.com/problems/repeated-dna-sequences/", "Medium", "vector<string> findRepeatedDnaSequences(string s)", "Rabin–Karp-style rolling hash; fixed-length patterns; collision awareness", "fixed windows; hashing; sets", "Use a rolling representation for repeated fixed-length substrings and reason about verification/collisions.", ["\"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT\" -> [\"AAAAACCCCC\",\"CCCCCAAAAA\"]", "\"AAAAAAAAAAAAA\" -> [\"AAAAAAAAAA\"]", "length below 10 -> []"]),

    p("09_Advanced_Mixed", "41_LC_686_Repeated_String_Match", "Repeated String Match", "https://leetcode.com/problems/repeated-string-match/", "Medium", "int repeatedStringMatch(string a, string b)", "Repeated construction; boundary-spanning match; optional rolling hash", "pattern matching; length bounds", "Prove how many repeats are sufficient to test when the match may cross a repetition boundary.", ["\"abcd\", \"cdabcdab\" -> 3", "\"a\", \"aa\" -> 2", "\"abc\", \"wxyz\" -> -1"]),
    p("09_Advanced_Mixed", "42_LC_30_Substring_with_Concatenation", "Substring with Concatenation of All Words", "https://leetcode.com/problems/substring-with-concatenation-of-all-words/", "Hard", "vector<int> findSubstring(string s, vector<string>& words)", "Word-sized windows; frequency maps; multiple offsets", "sliding windows; hashing; equal word lengths", "Slide in word-sized steps and treat each starting offset as an independent window stream.", ["\"barfoothefoobarman\", [\"foo\",\"bar\"] -> [0,9]", "\"wordgoodgoodgoodbestword\", [\"word\",\"good\",\"best\",\"word\"] -> []", "\"barfoofoobarthefoobarman\", [\"bar\",\"foo\",\"the\"] -> [6,9,12]"]),
    p("09_Advanced_Mixed", "43_LC_890_Find_and_Replace_Pattern", "Find and Replace Pattern", "https://leetcode.com/problems/find-and-replace-pattern/", "Medium", "vector<string> findAndReplacePattern(vector<string>& words, string pattern)", "Canonical mapping; repeated structure", "isomorphic strings; vectors", "Reuse bidirectional/canonical mapping across a list of candidate words.", ["[\"abc\",\"deq\",\"mee\",\"aqq\",\"dkd\",\"ccc\"], \"abb\" -> [\"mee\",\"aqq\"]", "[\"a\",\"b\",\"c\"], \"a\" -> all words", "[\"aa\",\"ab\"], \"cc\" -> [\"aa\"]"]),
    p("09_Advanced_Mixed", "44_LC_763_Partition_Labels", "Partition Labels", "https://leetcode.com/problems/partition-labels/", "Medium", "vector<int> partitionLabels(string s)", "Last occurrence; greedy boundary expansion", "frequency/index tables; traversal", "Expand a partition boundary whenever a character inside it must appear later.", ["\"ababcbacadefegdehijhklij\" -> [9,7,8]", "\"eccbbbbdec\" -> [10]", "\"abc\" -> [1,1,1]"]),
    p("09_Advanced_Mixed", "45_LC_6_Zigzag_Conversion", "Zigzag Conversion", "https://leetcode.com/problems/zigzag-conversion/", "Medium", "string convert(string s, int numRows)", "Simulation; direction changes; row aggregation", "vectors of strings; boundary cases", "Model the row movement cleanly and handle the single-row case before simulating.", ["\"PAYPALISHIRING\", 3 -> \"PAHNAPLSIIGYIR\"", "\"PAYPALISHIRING\", 4 -> \"PINALSIGYAHRPI\"", "\"A\", 1 -> \"A\""]),
]


def starter(problem):
    return f'''#include <bits/stdc++.h>
using namespace std;

class Solution {{
public:
    {problem["signature"]} {{
        // LEARNER STARTER — write your own first attempt here.
        // Do not copy a reference solution into this file.
    }}
}};
'''


def reference_placeholder(level):
    return f'''/*
REFERENCE SLOT INTENTIONALLY EMPTY — {level.upper()}

Write and save 01_original_attempt.cpp before asking to unlock this layer.
When this file is eventually completed, preserve the original attempt exactly.
*/
'''


def problem_readme(problem, number):
    concepts = "\n".join(f"- {item.strip()}" for item in problem["concepts"].split(";"))
    prerequisites = "\n".join(f"- {item.strip()}" for item in problem["prerequisites"].split(";"))
    return f'''# {number:02d}. {problem["title"]}

| Field | Value |
|---|---|
| Platform | {problem["platform"]} |
| Difficulty | {problem["difficulty"]} |
| Problem link | [Open the live problem]({problem["url"]}) |
| Starter signature | `{problem["signature"]}` |
| Reference solution available | No — intentionally locked |

## What you are meant to learn

{problem["goal"]}

## Concepts required

{concepts}

## Prerequisites

{prerequisites}

## Attempt protocol

1. Read the live platform statement and constraints.
2. Add two of your own edge cases to `test_cases.txt`.
3. Write only your first honest solution in `01_original_attempt.cpp`.
4. Record compiler errors, wrong assumptions, and failed cases in `mistakes.md`.
5. Mark the progress tracker truthfully before requesting a hint or reference layer.

The README intentionally explains the learning target, not the algorithm.
'''


def mistakes_template(problem):
    return f'''# Mistakes — {problem["title"]}

Complete this after your first attempt. Do not pre-fill a mistake you have not made.

## My initial assumption

-

## Failing test case

```text

```

## Root cause

- [ ] Syntax/API misunderstanding
- [ ] Boundary or empty-input case
- [ ] Incorrect invariant/logic
- [ ] Time complexity too high
- [ ] Space complexity too high
- [ ] Overflow or character-conversion issue
- [ ] Misread platform contract

## Correction in my own words

-
'''


def tests_file(problem):
    rows = "\n".join(f"{i}. {case}" for i, case in enumerate(problem["tests"], 1))
    next_number = len(problem["tests"]) + 1
    return f'''# Starter test cases for {problem["title"]}
# Confirm exact formatting and constraints on the live platform.

{rows}

# Add at least two of your own before coding:
{next_number}. [add your own case]
{next_number + 1}. [add your own case]
'''


def build_module():
    if len(PROBLEMS) != 45:
        raise ValueError(f"Expected exactly 45 problems, found {len(PROBLEMS)}")
    manifest = []
    rows = []
    for category, title, description in CATEGORIES:
        category_root = STRINGS_ROOT / category
        category_root.mkdir(parents=True, exist_ok=True)
        category_problems = [item for item in PROBLEMS if item["category"] == category]
        category_lines = "\n".join(
            f'{i}. [{item["title"]}]({item["folder"]}/) — {item["difficulty"]}'
            for i, item in enumerate(category_problems, 1)
        )
        (category_root / "README.md").write_text(
            f"# {title}\n\n{description}\n\nWork through these in order:\n\n{category_lines}\n"
        )
    for number, problem in enumerate(PROBLEMS, 1):
        folder = STRINGS_ROOT / problem["category"] / problem["folder"]
        folder.mkdir(parents=True, exist_ok=True)
        files = {
            "README.md": problem_readme(problem, number),
            "01_original_attempt.cpp": starter(problem),
            "02_brute_force.cpp": reference_placeholder("brute force"),
            "03_better.cpp": reference_placeholder("better"),
            "04_optimal.cpp": reference_placeholder("optimal"),
            "mistakes.md": mistakes_template(problem),
            "test_cases.txt": tests_file(problem),
        }
        for name, content in files.items():
            (folder / name).write_text(content)
        rel = folder.relative_to(ROOT).as_posix()
        manifest.append({**problem, "index": number, "folder": rel})
        rows.append(
            f'| {number} | {problem["category"].split("_", 1)[1].replace("_", " ")} | '
            f'{problem["title"]} | {problem["difficulty"]} | [`{problem["folder"]}`]({problem["category"]}/{problem["folder"]}/) |'
        )
    learning_order = " → ".join(title for _, title, _ in CATEGORIES)
    module_readme = f'''# 02 — Strings

Status: **current learning module**

This is an intentionally unsolved, 45-problem curriculum. The first-attempt file is yours; the brute-force, better, and optimal files are locked placeholders until you have made and recorded an honest attempt.

## Learning order

{learning_order}

Dynamic-programming string problems and primarily stack-based string problems are deliberately excluded. They belong in their later textbook modules.

Inside pattern matching, the intended order is direct matching → periodicity/prefix ideas → KMP → Rabin–Karp-style rolling hash.

## Ordered problem list

| # | Stage | Problem | Difficulty | Folder |
|---:|---|---|---|---|
{chr(10).join(rows)}

## Reference policy

`Reference solution available` remains unchecked in the progress tracker until a genuine reference is added. Empty reference placeholders are not solutions, and they never count as personal completion.
'''
    (STRINGS_ROOT / "README.md").write_text(module_readme)
    (STRINGS_ROOT / "problem_manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")
    return manifest


def build_progress_tracker(strings_manifest):
    arrays = json.loads((ROOT / "repository_manifest.json").read_text())
    header = '''# DSA Progress Tracker

Reference availability and personal progress are intentionally separate. A checked reference column means study material exists; it does **not** mean the problem was attempted or solved by you.

Use exactly one outcome after an attempt: independently, with a hint, or after needing the full solution. Revision columns should be checked only after actually re-coding/reviewing on that schedule.

| # | Module / pattern | Problem | Reference available | Attempted by me | Solved independently | Solved with hint | Needed full solution | 2-day revision | 1-week revision | 1-month revision |
|---:|---|---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
'''
    rows = []
    for item in arrays:
        rows.append(
            f'| {item["index"]} | 01 Arrays & Vectors / {item["pattern"]} | {item["title"]} | '
            '[x] | [ ] | [ ] | [ ] | [ ] | [ ] | [ ] | [ ] |'
        )
    for item in strings_manifest:
        stage = item["category"].split("_", 1)[1].replace("_", " ")
        rows.append(
            f'| {80 + item["index"]} | 02 Strings / {stage} | {item["title"]} | '
            '[ ] | [ ] | [ ] | [ ] | [ ] | [ ] | [ ] | [ ] |'
        )
    (ROOT / "PROGRESS_TRACKER.md").write_text(header + "\n".join(rows) + "\n")


def main():
    strings_manifest = build_module()
    build_progress_tracker(strings_manifest)
    print(f"Prepared {len(strings_manifest)} intentionally-unsolved String problems.")


if __name__ == "__main__":
    main()
