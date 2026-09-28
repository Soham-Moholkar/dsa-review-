# 02 — Strings

Status: **completed reference curriculum; learner attempts unattempted**

This is a 63-problem curriculum with 27 first-class GeeksforGeeks problems and 36 LeetCode problems. The first-attempt file is yours and remains untouched; brute-force, better, and optimal C++ references and study notes are available for each problem. Read them after an honest attempt.

The [GFG practice index](GFG_PRACTICE.md) lists 27 complete problem folders. Each of the nine stages now includes two additional GFG exercises. Existing problem IDs and learner records are preserved; new module IDs 46–63 are grouped under their prerequisite stages. Read in stage order rather than numeric ID order.

## Learning order

String basics and traversal → Frequency counting and hashing → Two pointers and palindromes → Mappings and anagrams → Fixed sliding-window basics → Variable sliding windows → Parsing and conversion → Pattern matching → Advanced mixed string problems

Dynamic-programming string problems and primarily stack-based string problems are deliberately excluded. They belong in their later textbook modules.

The rotation exercise introduces circular comparisons in stage 03; return to its KMP reference after stage 08. Center expansion is the core palindrome lesson; the Manacher reference is an optional advanced extension.

Inside pattern matching, the intended order is direct matching → periodicity/prefix ideas → KMP → Rabin–Karp-style rolling hash.

## Ordered problem list

| Module ID | Stage | Platform | Problem | Difficulty | Folder |
|---:|---|---|---|---|---|
| 1 | Basics | LeetCode | Reverse String | Easy | [LC_344_Reverse_String](01_Basics/LeetCode/LC_344_Reverse_String/) |
| 2 | Basics | LeetCode | To Lower Case | Easy | [LC_709_To_Lower_Case](01_Basics/LeetCode/LC_709_To_Lower_Case/) |
| 3 | Basics | LeetCode | Length of Last Word | Easy | [LC_58_Length_of_Last_Word](01_Basics/LeetCode/LC_58_Length_of_Last_Word/) |
| 4 | Basics | LeetCode | Merge Strings Alternately | Easy | [LC_1768_Merge_Strings_Alternately](01_Basics/LeetCode/LC_1768_Merge_Strings_Alternately/) |
| 5 | Basics | LeetCode | Reverse Words in a String | Medium | [LC_151_Reverse_Words_in_a_String](01_Basics/LeetCode/LC_151_Reverse_Words_in_a_String/) |
| 46 | Basics | GeeksforGeeks | Remove Spaces | Easy | [GFG_Remove_Spaces](01_Basics/GeeksforGeeks/GFG_Remove_Spaces/) |
| 47 | Basics | GeeksforGeeks | Longest Common Prefix of Strings | Easy | [GFG_Longest_Common_Prefix](01_Basics/GeeksforGeeks/GFG_Longest_Common_Prefix/) |
| 6 | Frequency Counting | LeetCode | First Unique Character in a String | Easy | [LC_387_First_Unique_Character](02_Frequency_Counting/LeetCode/LC_387_First_Unique_Character/) |
| 7 | Frequency Counting | LeetCode | Ransom Note | Easy | [LC_383_Ransom_Note](02_Frequency_Counting/LeetCode/LC_383_Ransom_Note/) |
| 8 | Frequency Counting | LeetCode | Check if All Characters Have Equal Number of Occurrences | Easy | [LC_1941_Check_Equal_Occurrences](02_Frequency_Counting/LeetCode/LC_1941_Check_Equal_Occurrences/) |
| 9 | Frequency Counting | LeetCode | Maximum Number of Balloons | Easy | [LC_1189_Maximum_Number_of_Balloons](02_Frequency_Counting/LeetCode/LC_1189_Maximum_Number_of_Balloons/) |
| 10 | Frequency Counting | LeetCode | Sort Characters by Frequency | Medium | [LC_451_Sort_Characters_by_Frequency](02_Frequency_Counting/LeetCode/LC_451_Sort_Characters_by_Frequency/) |
| 48 | Frequency Counting | GeeksforGeeks | Pangram Checking | Easy | [GFG_Pangram_Checking](02_Frequency_Counting/GeeksforGeeks/GFG_Pangram_Checking/) |
| 49 | Frequency Counting | GeeksforGeeks | String Duplicates Removal | Easy | [GFG_String_Duplicates_Removal](02_Frequency_Counting/GeeksforGeeks/GFG_String_Duplicates_Removal/) |
| 11 | Two Pointers Palindrome | GeeksforGeeks | Valid Palindrome | Easy | [GFG_Valid_Palindrome](03_Two_Pointers_Palindrome/GeeksforGeeks/GFG_Valid_Palindrome/) |
| 12 | Two Pointers Palindrome | LeetCode | Valid Palindrome II | Easy | [LC_680_Valid_Palindrome_II](03_Two_Pointers_Palindrome/LeetCode/LC_680_Valid_Palindrome_II/) |
| 13 | Two Pointers Palindrome | LeetCode | Find First Palindromic String in the Array | Easy | [LC_2108_First_Palindromic_String](03_Two_Pointers_Palindrome/LeetCode/LC_2108_First_Palindromic_String/) |
| 14 | Two Pointers Palindrome | LeetCode | Reverse Vowels of a String | Easy | [LC_345_Reverse_Vowels](03_Two_Pointers_Palindrome/LeetCode/LC_345_Reverse_Vowels/) |
| 15 | Two Pointers Palindrome | LeetCode | Reverse Only Letters | Easy | [LC_917_Reverse_Only_Letters](03_Two_Pointers_Palindrome/LeetCode/LC_917_Reverse_Only_Letters/) |
| 50 | Two Pointers Palindrome | GeeksforGeeks | String Rotation Check | Medium | [GFG_String_Rotation_Check](03_Two_Pointers_Palindrome/GeeksforGeeks/GFG_String_Rotation_Check/) |
| 51 | Two Pointers Palindrome | GeeksforGeeks | Longest Palindrome in String | Medium | [GFG_Longest_Palindromic_Substring](03_Two_Pointers_Palindrome/GeeksforGeeks/GFG_Longest_Palindromic_Substring/) |
| 16 | Mapping Anagrams | GeeksforGeeks | Valid Anagram | Easy | [GFG_Valid_Anagram](04_Mapping_Anagrams/GeeksforGeeks/GFG_Valid_Anagram/) |
| 17 | Mapping Anagrams | GeeksforGeeks | Isomorphic Strings | Easy | [GFG_Isomorphic_Strings](04_Mapping_Anagrams/GeeksforGeeks/GFG_Isomorphic_Strings/) |
| 18 | Mapping Anagrams | LeetCode | Word Pattern | Easy | [LC_290_Word_Pattern](04_Mapping_Anagrams/LeetCode/LC_290_Word_Pattern/) |
| 19 | Mapping Anagrams | GeeksforGeeks | Group Anagrams | Medium | [GFG_Group_Anagrams](04_Mapping_Anagrams/GeeksforGeeks/GFG_Group_Anagrams/) |
| 20 | Mapping Anagrams | LeetCode | Determine if Two Strings Are Close | Medium | [LC_1657_Close_Strings](04_Mapping_Anagrams/LeetCode/LC_1657_Close_Strings/) |
| 52 | Mapping Anagrams | GeeksforGeeks | Uncommon Characters | Easy | [GFG_Uncommon_Characters](04_Mapping_Anagrams/GeeksforGeeks/GFG_Uncommon_Characters/) |
| 53 | Mapping Anagrams | GeeksforGeeks | Make Anagram with Removals | Easy | [GFG_Make_Anagram_with_Removals](04_Mapping_Anagrams/GeeksforGeeks/GFG_Make_Anagram_with_Removals/) |
| 21 | Sliding Window Basics | LeetCode | Substrings of Size Three with Distinct Characters | Easy | [LC_1876_Good_Substrings_of_Size_Three](05_Sliding_Window_Basics/LeetCode/LC_1876_Good_Substrings_of_Size_Three/) |
| 22 | Sliding Window Basics | LeetCode | Maximum Number of Vowels in a Substring of Given Length | Medium | [LC_1456_Maximum_Vowels_in_Substring](05_Sliding_Window_Basics/LeetCode/LC_1456_Maximum_Vowels_in_Substring/) |
| 23 | Sliding Window Basics | LeetCode | Minimum Recolors to Get K Consecutive Black Blocks | Easy | [LC_2379_Minimum_Recolors](05_Sliding_Window_Basics/LeetCode/LC_2379_Minimum_Recolors/) |
| 24 | Sliding Window Basics | LeetCode | Permutation in String | Medium | [LC_567_Permutation_in_String](05_Sliding_Window_Basics/LeetCode/LC_567_Permutation_in_String/) |
| 25 | Sliding Window Basics | LeetCode | Find All Anagrams in a String | Medium | [LC_438_Find_All_Anagrams](05_Sliding_Window_Basics/LeetCode/LC_438_Find_All_Anagrams/) |
| 54 | Sliding Window Basics | GeeksforGeeks | Count Occurrences of Anagrams | Medium | [GFG_Count_Anagram_Occurrences](05_Sliding_Window_Basics/GeeksforGeeks/GFG_Count_Anagram_Occurrences/) |
| 55 | Sliding Window Basics | GeeksforGeeks | Substrings of Length K with K-1 Distinct Characters | Medium | [GFG_K_Length_K_Minus_One_Distinct](05_Sliding_Window_Basics/GeeksforGeeks/GFG_K_Length_K_Minus_One_Distinct/) |
| 26 | Sliding Window Advanced | GeeksforGeeks | Longest Substring Without Repeating Characters | Medium | [GFG_Longest_Substring_Without_Repeating](06_Sliding_Window_Advanced/GeeksforGeeks/GFG_Longest_Substring_Without_Repeating/) |
| 27 | Sliding Window Advanced | LeetCode | Longest Repeating Character Replacement | Medium | [LC_424_Longest_Repeating_Character_Replacement](06_Sliding_Window_Advanced/LeetCode/LC_424_Longest_Repeating_Character_Replacement/) |
| 28 | Sliding Window Advanced | GeeksforGeeks | Minimum Window Substring | Hard | [GFG_Minimum_Window_Substring](06_Sliding_Window_Advanced/GeeksforGeeks/GFG_Minimum_Window_Substring/) |
| 29 | Sliding Window Advanced | LeetCode | Number of Substrings Containing All Three Characters | Medium | [LC_1358_Substrings_Containing_ABC](06_Sliding_Window_Advanced/LeetCode/LC_1358_Substrings_Containing_ABC/) |
| 30 | Sliding Window Advanced | LeetCode | Maximize the Confusion of an Exam | Medium | [LC_2024_Maximize_Exam_Confusion](06_Sliding_Window_Advanced/LeetCode/LC_2024_Maximize_Exam_Confusion/) |
| 56 | Sliding Window Advanced | GeeksforGeeks | Longest Substring with K Uniques | Medium | [GFG_Longest_K_Unique_Substring](06_Sliding_Window_Advanced/GeeksforGeeks/GFG_Longest_K_Unique_Substring/) |
| 57 | Sliding Window Advanced | GeeksforGeeks | Smallest Distinct Window | Medium | [GFG_Smallest_Distinct_Window](06_Sliding_Window_Advanced/GeeksforGeeks/GFG_Smallest_Distinct_Window/) |
| 31 | Parsing Conversion | GeeksforGeeks | Roman to Integer | Easy | [GFG_Roman_to_Integer](07_Parsing_Conversion/GeeksforGeeks/GFG_Roman_to_Integer/) |
| 32 | Parsing Conversion | LeetCode | String to Integer (atoi) | Medium | [LC_8_String_to_Integer_Atoi](07_Parsing_Conversion/LeetCode/LC_8_String_to_Integer_Atoi/) |
| 33 | Parsing Conversion | GeeksforGeeks | Integer to Roman | Medium | [GFG_Integer_to_Roman](07_Parsing_Conversion/GeeksforGeeks/GFG_Integer_to_Roman/) |
| 34 | Parsing Conversion | LeetCode | Add Strings | Easy | [LC_415_Add_Strings](07_Parsing_Conversion/LeetCode/LC_415_Add_Strings/) |
| 35 | Parsing Conversion | LeetCode | Multiply Strings | Medium | [LC_43_Multiply_Strings](07_Parsing_Conversion/LeetCode/LC_43_Multiply_Strings/) |
| 58 | Parsing Conversion | GeeksforGeeks | Add Binary Strings | Easy | [GFG_Add_Binary_Strings](07_Parsing_Conversion/GeeksforGeeks/GFG_Add_Binary_Strings/) |
| 59 | Parsing Conversion | GeeksforGeeks | Sum Numbers in a String | Easy | [GFG_Sum_Numbers_in_String](07_Parsing_Conversion/GeeksforGeeks/GFG_Sum_Numbers_in_String/) |
| 36 | Pattern Matching | LeetCode | Find the Index of the First Occurrence in a String | Easy | [LC_28_First_Occurrence](08_Pattern_Matching/LeetCode/LC_28_First_Occurrence/) |
| 37 | Pattern Matching | LeetCode | Repeated Substring Pattern | Easy | [LC_459_Repeated_Substring_Pattern](08_Pattern_Matching/LeetCode/LC_459_Repeated_Substring_Pattern/) |
| 38 | Pattern Matching | GeeksforGeeks | Search Pattern (KMP Algorithm) | Medium | [GFG_Search_Pattern_KMP](08_Pattern_Matching/GeeksforGeeks/GFG_Search_Pattern_KMP/) |
| 39 | Pattern Matching | LeetCode | Longest Happy Prefix | Hard | [LC_1392_Longest_Happy_Prefix](08_Pattern_Matching/LeetCode/LC_1392_Longest_Happy_Prefix/) |
| 40 | Pattern Matching | LeetCode | Repeated DNA Sequences | Medium | [LC_187_Repeated_DNA_Sequences](08_Pattern_Matching/LeetCode/LC_187_Repeated_DNA_Sequences/) |
| 60 | Pattern Matching | GeeksforGeeks | Search Pattern (Rabin-Karp Algorithm) | Medium | [GFG_Rabin_Karp_Search](08_Pattern_Matching/GeeksforGeeks/GFG_Rabin_Karp_Search/) |
| 61 | Pattern Matching | GeeksforGeeks | Minimum Characters to Add for Palindrome | Medium | [GFG_Min_Chars_for_Palindrome](08_Pattern_Matching/GeeksforGeeks/GFG_Min_Chars_for_Palindrome/) |
| 41 | Advanced Mixed | LeetCode | Repeated String Match | Medium | [LC_686_Repeated_String_Match](09_Advanced_Mixed/LeetCode/LC_686_Repeated_String_Match/) |
| 42 | Advanced Mixed | LeetCode | Substring with Concatenation of All Words | Hard | [LC_30_Substring_with_Concatenation](09_Advanced_Mixed/LeetCode/LC_30_Substring_with_Concatenation/) |
| 43 | Advanced Mixed | LeetCode | Find and Replace Pattern | Medium | [LC_890_Find_and_Replace_Pattern](09_Advanced_Mixed/LeetCode/LC_890_Find_and_Replace_Pattern/) |
| 44 | Advanced Mixed | LeetCode | Partition Labels | Medium | [LC_763_Partition_Labels](09_Advanced_Mixed/LeetCode/LC_763_Partition_Labels/) |
| 45 | Advanced Mixed | LeetCode | Zigzag Conversion | Medium | [LC_6_Zigzag_Conversion](09_Advanced_Mixed/LeetCode/LC_6_Zigzag_Conversion/) |
| 62 | Advanced Mixed | GeeksforGeeks | Run Length Encoding | Easy | [GFG_Run_Length_Encoding](09_Advanced_Mixed/GeeksforGeeks/GFG_Run_Length_Encoding/) |
| 63 | Advanced Mixed | GeeksforGeeks | Look and Say Pattern | Medium | [GFG_Look_and_Say](09_Advanced_Mixed/GeeksforGeeks/GFG_Look_and_Say/) |

## Reference policy

`Reference solution available` is checked in the progress tracker for all 63 entries. The remaining personal-progress columns are untouched. Each problem has three C++ files, a [study explanation](01_Basics/LeetCode/LC_344_Reverse_String/solution.md), and blank personal revision notes. Some simple exercises have the same efficient method in two slots where a different intermediate approach would be artificial.
