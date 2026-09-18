# 02 — Strings

Status: **current learning module**

This is an intentionally unsolved, 45-problem curriculum. The first-attempt file is yours; the brute-force, better, and optimal files are locked placeholders until you have made and recorded an honest attempt.

## Learning order

String basics and traversal → Frequency counting and hashing → Two pointers and palindromes → Mappings and anagrams → Fixed sliding-window basics → Variable sliding windows → Parsing and conversion → Pattern matching → Advanced mixed string problems

Dynamic-programming string problems and primarily stack-based string problems are deliberately excluded. They belong in their later textbook modules.

Inside pattern matching, the intended order is direct matching → periodicity/prefix ideas → KMP → Rabin–Karp-style rolling hash.

## Ordered problem list

| # | Stage | Problem | Difficulty | Folder |
|---:|---|---|---|---|
| 1 | Basics | Reverse String | Easy | [`01_LC_344_Reverse_String`](01_Basics/01_LC_344_Reverse_String/) |
| 2 | Basics | To Lower Case | Easy | [`02_LC_709_To_Lower_Case`](01_Basics/02_LC_709_To_Lower_Case/) |
| 3 | Basics | Length of Last Word | Easy | [`03_LC_58_Length_of_Last_Word`](01_Basics/03_LC_58_Length_of_Last_Word/) |
| 4 | Basics | Merge Strings Alternately | Easy | [`04_LC_1768_Merge_Strings_Alternately`](01_Basics/04_LC_1768_Merge_Strings_Alternately/) |
| 5 | Basics | Reverse Words in a String | Medium | [`05_LC_151_Reverse_Words_in_a_String`](01_Basics/05_LC_151_Reverse_Words_in_a_String/) |
| 6 | Frequency Counting | First Unique Character in a String | Easy | [`06_LC_387_First_Unique_Character`](02_Frequency_Counting/06_LC_387_First_Unique_Character/) |
| 7 | Frequency Counting | Ransom Note | Easy | [`07_LC_383_Ransom_Note`](02_Frequency_Counting/07_LC_383_Ransom_Note/) |
| 8 | Frequency Counting | Check if All Characters Have Equal Number of Occurrences | Easy | [`08_LC_1941_Check_Equal_Occurrences`](02_Frequency_Counting/08_LC_1941_Check_Equal_Occurrences/) |
| 9 | Frequency Counting | Maximum Number of Balloons | Easy | [`09_LC_1189_Maximum_Number_of_Balloons`](02_Frequency_Counting/09_LC_1189_Maximum_Number_of_Balloons/) |
| 10 | Frequency Counting | Sort Characters by Frequency | Medium | [`10_LC_451_Sort_Characters_by_Frequency`](02_Frequency_Counting/10_LC_451_Sort_Characters_by_Frequency/) |
| 11 | Two Pointers Palindrome | Valid Palindrome | Easy | [`11_LC_125_Valid_Palindrome`](03_Two_Pointers_Palindrome/11_LC_125_Valid_Palindrome/) |
| 12 | Two Pointers Palindrome | Valid Palindrome II | Easy | [`12_LC_680_Valid_Palindrome_II`](03_Two_Pointers_Palindrome/12_LC_680_Valid_Palindrome_II/) |
| 13 | Two Pointers Palindrome | Find First Palindromic String in the Array | Easy | [`13_LC_2108_First_Palindromic_String`](03_Two_Pointers_Palindrome/13_LC_2108_First_Palindromic_String/) |
| 14 | Two Pointers Palindrome | Reverse Vowels of a String | Easy | [`14_LC_345_Reverse_Vowels`](03_Two_Pointers_Palindrome/14_LC_345_Reverse_Vowels/) |
| 15 | Two Pointers Palindrome | Reverse Only Letters | Easy | [`15_LC_917_Reverse_Only_Letters`](03_Two_Pointers_Palindrome/15_LC_917_Reverse_Only_Letters/) |
| 16 | Mapping Anagrams | Valid Anagram | Easy | [`16_LC_242_Valid_Anagram`](04_Mapping_Anagrams/16_LC_242_Valid_Anagram/) |
| 17 | Mapping Anagrams | Isomorphic Strings | Easy | [`17_LC_205_Isomorphic_Strings`](04_Mapping_Anagrams/17_LC_205_Isomorphic_Strings/) |
| 18 | Mapping Anagrams | Word Pattern | Easy | [`18_LC_290_Word_Pattern`](04_Mapping_Anagrams/18_LC_290_Word_Pattern/) |
| 19 | Mapping Anagrams | Group Anagrams | Medium | [`19_LC_49_Group_Anagrams`](04_Mapping_Anagrams/19_LC_49_Group_Anagrams/) |
| 20 | Mapping Anagrams | Determine if Two Strings Are Close | Medium | [`20_LC_1657_Close_Strings`](04_Mapping_Anagrams/20_LC_1657_Close_Strings/) |
| 21 | Sliding Window Basics | Substrings of Size Three with Distinct Characters | Easy | [`21_LC_1876_Good_Substrings_of_Size_Three`](05_Sliding_Window_Basics/21_LC_1876_Good_Substrings_of_Size_Three/) |
| 22 | Sliding Window Basics | Maximum Number of Vowels in a Substring of Given Length | Medium | [`22_LC_1456_Maximum_Vowels_in_Substring`](05_Sliding_Window_Basics/22_LC_1456_Maximum_Vowels_in_Substring/) |
| 23 | Sliding Window Basics | Minimum Recolors to Get K Consecutive Black Blocks | Easy | [`23_LC_2379_Minimum_Recolors`](05_Sliding_Window_Basics/23_LC_2379_Minimum_Recolors/) |
| 24 | Sliding Window Basics | Permutation in String | Medium | [`24_LC_567_Permutation_in_String`](05_Sliding_Window_Basics/24_LC_567_Permutation_in_String/) |
| 25 | Sliding Window Basics | Find All Anagrams in a String | Medium | [`25_LC_438_Find_All_Anagrams`](05_Sliding_Window_Basics/25_LC_438_Find_All_Anagrams/) |
| 26 | Sliding Window Advanced | Longest Substring Without Repeating Characters | Medium | [`26_LC_3_Longest_Substring_Without_Repeating`](06_Sliding_Window_Advanced/26_LC_3_Longest_Substring_Without_Repeating/) |
| 27 | Sliding Window Advanced | Longest Repeating Character Replacement | Medium | [`27_LC_424_Longest_Repeating_Character_Replacement`](06_Sliding_Window_Advanced/27_LC_424_Longest_Repeating_Character_Replacement/) |
| 28 | Sliding Window Advanced | Minimum Window Substring | Hard | [`28_LC_76_Minimum_Window_Substring`](06_Sliding_Window_Advanced/28_LC_76_Minimum_Window_Substring/) |
| 29 | Sliding Window Advanced | Number of Substrings Containing All Three Characters | Medium | [`29_LC_1358_Substrings_Containing_ABC`](06_Sliding_Window_Advanced/29_LC_1358_Substrings_Containing_ABC/) |
| 30 | Sliding Window Advanced | Maximize the Confusion of an Exam | Medium | [`30_LC_2024_Maximize_Exam_Confusion`](06_Sliding_Window_Advanced/30_LC_2024_Maximize_Exam_Confusion/) |
| 31 | Parsing Conversion | Roman to Integer | Easy | [`31_LC_13_Roman_to_Integer`](07_Parsing_Conversion/31_LC_13_Roman_to_Integer/) |
| 32 | Parsing Conversion | String to Integer (atoi) | Medium | [`32_LC_8_String_to_Integer_Atoi`](07_Parsing_Conversion/32_LC_8_String_to_Integer_Atoi/) |
| 33 | Parsing Conversion | Integer to Roman | Medium | [`33_LC_12_Integer_to_Roman`](07_Parsing_Conversion/33_LC_12_Integer_to_Roman/) |
| 34 | Parsing Conversion | Add Strings | Easy | [`34_LC_415_Add_Strings`](07_Parsing_Conversion/34_LC_415_Add_Strings/) |
| 35 | Parsing Conversion | Multiply Strings | Medium | [`35_LC_43_Multiply_Strings`](07_Parsing_Conversion/35_LC_43_Multiply_Strings/) |
| 36 | Pattern Matching | Find the Index of the First Occurrence in a String | Easy | [`36_LC_28_First_Occurrence`](08_Pattern_Matching/36_LC_28_First_Occurrence/) |
| 37 | Pattern Matching | Repeated Substring Pattern | Easy | [`37_LC_459_Repeated_Substring_Pattern`](08_Pattern_Matching/37_LC_459_Repeated_Substring_Pattern/) |
| 38 | Pattern Matching | Search Pattern (KMP Algorithm) | Medium | [`38_GFG_Search_Pattern_KMP`](08_Pattern_Matching/38_GFG_Search_Pattern_KMP/) |
| 39 | Pattern Matching | Longest Happy Prefix | Hard | [`39_LC_1392_Longest_Happy_Prefix`](08_Pattern_Matching/39_LC_1392_Longest_Happy_Prefix/) |
| 40 | Pattern Matching | Repeated DNA Sequences | Medium | [`40_LC_187_Repeated_DNA_Sequences`](08_Pattern_Matching/40_LC_187_Repeated_DNA_Sequences/) |
| 41 | Advanced Mixed | Repeated String Match | Medium | [`41_LC_686_Repeated_String_Match`](09_Advanced_Mixed/41_LC_686_Repeated_String_Match/) |
| 42 | Advanced Mixed | Substring with Concatenation of All Words | Hard | [`42_LC_30_Substring_with_Concatenation`](09_Advanced_Mixed/42_LC_30_Substring_with_Concatenation/) |
| 43 | Advanced Mixed | Find and Replace Pattern | Medium | [`43_LC_890_Find_and_Replace_Pattern`](09_Advanced_Mixed/43_LC_890_Find_and_Replace_Pattern/) |
| 44 | Advanced Mixed | Partition Labels | Medium | [`44_LC_763_Partition_Labels`](09_Advanced_Mixed/44_LC_763_Partition_Labels/) |
| 45 | Advanced Mixed | Zigzag Conversion | Medium | [`45_LC_6_Zigzag_Conversion`](09_Advanced_Mixed/45_LC_6_Zigzag_Conversion/) |

## Reference policy

`Reference solution available` remains unchecked in the progress tracker until a genuine reference is added. Empty reference placeholders are not solutions, and they never count as personal completion.
