"""Reviewed GFG practice additions. Local contracts and independently specified cases.

These extend the accepted curricula without changing their original module IDs.
References are original teaching implementations, not copied platform editorials.
"""
S = '02_Strings'
Q = '04_Stacks_and_Queues'
ITEMS = []


def a(name, time, space, explanation, code):
    return dict(name=name, time=time, space=space, explanation=explanation, code=code)


def p(module, stage, slug, title, url_slug, signature, goal, contract, invariant, trace, cases, approaches, difficulty='Medium', prerequisites='Earlier exercises in this stage', starter=None, design=None):
    index = (46 if module == S else 56) + sum(x['module'] == module for x in ITEMS)
    ITEMS.append(dict(module=module, stage=stage, slug='GFG_'+slug, title=title,
        url='https://www.geeksforgeeks.org/problems/'+url_slug+'/1', signature=signature,
        goal=goal, contract=contract, invariant=invariant, trace=trace, cases=cases,
        approaches=approaches, difficulty=difficulty, prerequisites=prerequisites,
        index=index, global_index=181+len(ITEMS), starter=starter, design=design))

p(S,1,'Remove_Spaces','Remove Spaces','remove-spaces0128','string removeSpaces(string s)',
  'Practise stable filtering and compare erasing with compacting a string.',
  'Remove literal ASCII spaces; preserve every other character in order. Empty input is a local extension.',
  'The written prefix contains exactly the non-space characters already read.',
  'For "a b c", the read positions 0, 2, 4 contribute a, b, c. The write position advances only three times; resizing produces "abc".',
  [(['a b c'],'abc'),(['   '],''),(['x'],'x'),([' a  b '],'ab')],[
  a('Erase each space','O(n²)','O(1) auxiliary','Erasing shifts the remaining suffix; keep the same index after an erase.',r'''for (size_t i = 0; i < s.size();) {
    if (s[i] == ' ') s.erase(i, 1);
    else ++i;
}
return s;'''),
  a('Build a filtered output','O(n)','O(n) result','Append each eligible character to a separate string.',r'''string out;
for (char c : s) if (c != ' ') out += c;
return out;'''),
  a('Compact with a write position','O(n)','O(1) auxiliary','Read each character once, place kept characters in the prefix, then shrink.',r'''size_t write = 0;
for (char c : s) if (c != ' ') s[write++] = c;
s.resize(write);
return s;''')],difficulty='Easy')

p(S,1,'Longest_Common_Prefix','Longest Common Prefix of Strings','longest-common-prefix-in-an-array5129','string longestCommonPrefix(vector<string>& arr)',
  'Compare horizontal and vertical traversal across multiple strings.',
  'Return the common prefix; return an empty string when none exists. Some older drivers display -1 for an empty result.',
  'Every accepted prefix position agrees across all strings.',
  'For ["flower","flow","flight"], columns f and l match. Column 2 contains o, o, i, so the answer is "fl".',
  [([['flower','flow','flight']],'fl'),([['dog','racecar','car']],''),([['solo']],'solo'),([['','abc']],'')],[
  a('Shorten candidate prefixes','O(w L²)','O(L)','Try shorter copies of the first string until each other string starts with it.',r'''if (arr.empty()) return "";
for (int len = arr[0].size(); len >= 0; --len) {
    string candidate = arr[0].substr(0, len);
    bool ok = true;
    for (const string& s : arr) if (s.compare(0, len, candidate) != 0) ok = false;
    if (ok) return candidate;
}
return "";'''),
  a('Sort a copy and compare extremes','O(w L log w)','O(w L)','The first and last sorted strings bound all other strings lexicographically.',r'''if (arr.empty()) return "";
auto words = arr;
sort(words.begin(), words.end());
size_t i = 0;
while (i < words.front().size() && i < words.back().size() && words.front()[i] == words.back()[i]) ++i;
return words.front().substr(0, i);'''),
  a('Compare columns','O(w L)','O(L) result','Stop at the first missing or unequal character in any string.',r'''if (arr.empty()) return "";
for (size_t i = 0; i < arr[0].size(); ++i) {
    for (const string& s : arr) {
        if (i == s.size() || s[i] != arr[0][i]) return arr[0].substr(0, i);
    }
}
return arr[0];''')],difficulty='Easy')

p(S,2,'Pangram_Checking','Pangram Checking','pangram-checking-1587115620','bool checkPangram(string s)',
  'Distinguish character presence from multiplicity and handle case consistently.',
  'Check whether all 26 English letters occur, ignoring ASCII case and nonletters.',
  'Each seen bit means that its letter has appeared at least once.',
  'In the alphabet followed by extra a characters, all 26 flags are true; repeats do not change coverage. Removing z leaves exactly one flag false.',
  [(['The quick brown fox jumps over the lazy dog'],True),(['abcdefghijklmnopqrstuvwxy'],False),(['ABCDEFGHIJKLMNOPQRSTUVWXYZ'],True)],[
  a('Search for every letter','O(26n)','O(1)','For each letter, scan the full input and compare after lowercasing.',r'''for (char letter = 'a'; letter <= 'z'; ++letter) {
    bool found = false;
    for (unsigned char c : s) if (tolower(c) == letter) found = true;
    if (!found) return false;
}
return true;'''),
  a('Collect letters in a set','O(n log 26)','O(26)','Insert normalized letters into an ordered set and inspect its size.',r'''set<char> letters;
for (unsigned char c : s) {
    char lower = tolower(c);
    if (lower >= 'a' && lower <= 'z') letters.insert(lower);
}
return letters.size() == 26;'''),
  a('Fixed presence table','O(n)','O(26) = O(1)','A fixed alphabet needs only 26 flags; duplicate letters leave flags unchanged.',r'''bool seen[26] = {};
for (unsigned char c : s) {
    char lower = tolower(c);
    if (lower >= 'a' && lower <= 'z') seen[lower - 'a'] = true;
}
for (bool present : seen) if (!present) return false;
return true;''')],difficulty='Easy')

p(S,2,'String_Duplicates_Removal','String Duplicates Removal','remove-all-duplicates-from-a-given-string4321','string removeDuplicates(string s)',
  'Keep the first occurrence while preserving case and arrival order.',
  'Return each distinct byte once, in first-appearance order; uppercase and lowercase differ.',
  'The result contains the first occurrence of every character in the processed prefix.',
  'For "banana", retain b, a, n; the later a, n, a were already seen. The result is "ban".',
  [(['banana'],'ban'),(['aaaa'],'a'),(['AaA'],'Aa'),(['abc'],'abc')],[
  a('Search the output','O(n²)','O(A) result','Check the accumulated output before appending the next character.',r'''string out;
for (char c : s) if (out.find(c) == string::npos) out += c;
return out;'''),
  a('Ordered membership set','O(n log A)','O(A)','Use a set for membership but append to a string to preserve first-seen order.',r'''set<char> seen;
string out;
for (char c : s) if (seen.insert(c).second) out += c;
return out;'''),
  a('Byte presence table','O(n)','O(256) plus result','Index by unsigned char so every byte gives a valid nonnegative table index.',r'''bool seen[256] = {};
string out;
for (unsigned char c : s) if (!seen[c]) { seen[c] = true; out += char(c); }
return out;''')],difficulty='Easy')

p(S,3,'String_Rotation_Check','String Rotation Check','check-if-strings-are-rotations-of-each-other-or-not-1587115620','bool areRotations(string s1, string s2)',
  'Connect circular positions to substring matching and revisit after the pattern-matching stage.',
  'Equal-length strings are rotations when one cyclic shift matches the other. Two empty strings return true locally.',
  'A length-n rotation is a length-n substring of the doubled source.',
  'For "abcd" and "cdab", the doubled source is "abcdabcd". Matching from position 2 consumes c,d,a,b; unequal lengths are rejected first.',
  [(['abcd','cdab'],True),(['abcd','acbd'],False),(['aaaa','aaaa'],True),(['ab','a'],False)],[
  a('Compare every cyclic shift','O(n²)','O(1)','Try every start position and compare characters with wraparound.',r'''if (s1.size() != s2.size()) return false;
int n = s1.size();
if (n == 0) return true;
for (int start = 0; start < n; ++start) {
    bool ok = true;
    for (int j = 0; j < n; ++j) if (s1[(start + j) % n] != s2[j]) { ok = false; break; }
    if (ok) return true;
}
return false;'''),
  a('Search the doubled string','O(n²) worst case','O(n)','Use library substring search; do not claim a guaranteed linear std::string::find.',r'''return s1.size() == s2.size() && (s1 + s1).find(s2) != string::npos;'''),
  a('KMP over doubled source','O(n)','O(n)','Build the target prefix table, then scan two source copies without materializing them. Study this file after stage 08.',r'''if (s1.size() != s2.size()) return false;
int n = s1.size();
if (n == 0) return true;
vector<int> pi(n);
for (int i = 1, j = 0; i < n; ++i) {
    while (j && s2[i] != s2[j]) j = pi[j - 1];
    if (s2[i] == s2[j]) ++j;
    pi[i] = j;
}
for (int i = 0, j = 0; i < 2 * n; ++i) {
    char c = s1[i % n];
    while (j && c != s2[j]) j = pi[j - 1];
    if (c == s2[j]) ++j;
    if (j == n) return true;
}
return false;''')])

p(S,3,'Longest_Palindromic_Substring','Longest Palindrome in String','longest-palindrome-in-a-string3411','string longestPalindrome(string s)',
  'Expand around centers; compare a constant-space solution with a linear-time extension.',
  'Return the longest contiguous palindrome, choosing the earliest start on a length tie. Empty input returns an empty string.',
  'A radius describes only matching pairs around one center; the best answer retains the earliest maximum.',
  'In "cbbd", the gap between the two b characters expands to "bb". Its neighbors c and d differ, so the even radius stops at length 2. Odd centers give length 1.',
  [(['babad'],'bab'),(['cbbd'],'bb'),(['aaaa'],'aaaa'),(['abc'],'a'),([''],'')],[
  a('Enumerate and check every interval','O(n³)','O(n) result','Try intervals by increasing start and keep only strictly longer palindromes.',r'''int start = 0, length = 0, n = s.size();
for (int l = 0; l < n; ++l) for (int r = l; r < n; ++r) {
    bool ok = true;
    for (int a = l, b = r; a < b; ++a, --b) if (s[a] != s[b]) ok = false;
    if (ok && r - l + 1 > length) { start = l; length = r - l + 1; }
}
return s.substr(start, length);'''),
  a('Expand odd and even centers','O(n²)','O(1) auxiliary plus result','Every palindrome has a character center or a gap center; expand each while pairs match.',r'''int start = 0, length = 0, n = s.size();
for (int center = 0; center < n; ++center) for (int even = 0; even < 2; ++even) {
    int l = center, r = center + even;
    while (l >= 0 && r < n && s[l] == s[r]) {
        int size = r - l + 1;
        if (size > length || (size == length && l < start)) { start = l; length = size; }
        --l; ++r;
    }
}
return s.substr(start, length);'''),
  a('Manacher radius reuse (advanced extension)','O(n)','O(n)','Track the palindrome reaching farthest right. Mirror a center inside it, cap the copied radius at its boundary, and compare only new pairs. Odd and even radii avoid separator assumptions. Each successful expansion beyond the boundary advances it, giving linear total work.',r'''int n = s.size(), start = 0, length = 0;
vector<int> odd(n), even(n);
auto record = [&](int begin, int size) {
    if (size > length || (size == length && begin < start)) { start = begin; length = size; }
};
for (int i = 0, l = 0, r = -1; i < n; ++i) {
    int k = i > r ? 1 : min(odd[l + r - i], r - i + 1);
    while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
    odd[i] = k;
    record(i - k + 1, 2 * k - 1);
    if (i + k - 1 > r) { l = i - k + 1; r = i + k - 1; }
}
for (int i = 0, l = 0, r = -1; i < n; ++i) {
    int k = i > r ? 0 : min(even[l + r - i + 1], r - i + 1);
    while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) ++k;
    even[i] = k;
    record(i - k, 2 * k);
    if (i + k - 1 > r) { l = i - k; r = i + k - 1; }
}
return s.substr(start, length);''')])

p(S,4,'Uncommon_Characters','Uncommon Characters','uncommon-characters4932','string uncommonChars(string s1, string s2)',
  'Separate set membership from multiplicity and produce ordered output.',
  'Lowercase English input. Return sorted characters present in exactly one string, or "-1" when there are none.',
  'A character is output exactly when its two membership flags differ.',
  'For "abca" and "bcd", a belongs only to the first and d only to the second. b and c belong to both. Emit "ad" once each.',
  [(['abca','bcd'],'ad'),(['aa','a'],'-1'),(['z','a'],'az')],[
  a('Search both strings for every letter','O(26(n+m))','O(1) auxiliary','For every lowercase letter, compare whether each string contains it.',r'''string out;
for (char c = 'a'; c <= 'z'; ++c) if ((s1.find(c) != string::npos) != (s2.find(c) != string::npos)) out += c;
return out.empty() ? "-1" : out;'''),
  a('Symmetric difference of sets','O((n+m) log 26)','O(26)','Build ordered sets and use symmetric difference to retain membership in exactly one.',r'''set<char> x(s1.begin(), s1.end()), y(s2.begin(), s2.end());
string out;
set_symmetric_difference(x.begin(), x.end(), y.begin(), y.end(), back_inserter(out));
return out.empty() ? "-1" : out;'''),
  a('Two presence tables','O(n+m+26)','O(26)','Scan both strings once and emit differing flags in alphabet order.',r'''bool x[26] = {}, y[26] = {};
for (char c : s1) x[c - 'a'] = true;
for (char c : s2) y[c - 'a'] = true;
string out;
for (int i = 0; i < 26; ++i) if (x[i] != y[i]) out += char('a' + i);
return out.empty() ? "-1" : out;''')],difficulty='Easy')

p(S,4,'Make_Anagram_with_Removals','Make Anagram with Removals','anagram-of-string','int remAnagram(string s1, string s2)',
  'Model unmatched character multiplicities as the minimum required deletions.',
  'Lowercase strings; deletion from either string costs one. Return the minimum total deletions.',
  'For each letter, only the absolute difference between its counts must be deleted.',
  'For "aab" and "abb", a has counts 2 and 1, b has counts 1 and 2. Delete one a and one b: total 2.',
  [(['aab','abb'],2),(['abc','abc'],0),(['a','z'],2),(['','abc'],3)],[
  a('Match and consume occurrences','O(nm)','O(m)','Mark each matching occurrence in the second string; unmatched characters on either side are deletions.',r'''vector<bool> used(s2.size());
int matches = 0;
for (char c : s1) for (size_t j = 0; j < s2.size(); ++j) if (!used[j] && c == s2[j]) { used[j] = true; ++matches; break; }
return s1.size() + s2.size() - 2 * matches;'''),
  a('Sort and merge','O(n log n + m log m)','O(log n + log m)','Sorted equal letters match; advance the smaller unmatched letter and count its deletion.',r'''sort(s1.begin(), s1.end()); sort(s2.begin(), s2.end());
size_t i = 0, j = 0; int removed = 0;
while (i < s1.size() && j < s2.size()) {
    if (s1[i] == s2[j]) { ++i; ++j; }
    else if (s1[i] < s2[j]) { ++i; ++removed; }
    else { ++j; ++removed; }
}
return removed + s1.size() - i + s2.size() - j;'''),
  a('Signed frequency difference','O(n+m)','O(26)','Increment for the first string, decrement for the second, and sum absolute imbalances.',r'''int counts[26] = {};
for (char c : s1) ++counts[c - 'a'];
for (char c : s2) --counts[c - 'a'];
int answer = 0;
for (int count : counts) answer += abs(count);
return answer;''')],difficulty='Easy')

p(S,5,'Count_Anagram_Occurrences','Count Occurrences of Anagrams','count-occurences-of-anagrams5839','int search(string pat, string txt)',
  'Revisit fixed windows with GFG argument order and a count result instead of a list of indices.',
  'Lowercase strings, nonempty pattern; count overlapping windows whose letters form an anagram of pat. Arguments are pattern then text.',
  'The live frequency table covers exactly the current pattern-length window.',
  'For pat="ab", txt="abab", windows ab, ba, ab all have one a and one b, so overlapping matches give 3.',
  [(['ab','abab'],3),(['abc','ab'],0),(['aa','aaaa'],3),(['a','bbbb'],0)],[
  a('Sort each window','O(n m log m)','O(m)','Sort the pattern once and compare it with a sorted copy of every length-m window.',r'''int m = pat.size(), answer = 0; sort(pat.begin(), pat.end());
for (int i = 0; i + m <= (int)txt.size(); ++i) {
    string window = txt.substr(i, m); sort(window.begin(), window.end());
    answer += window == pat;
}
return answer;'''),
  a('Count each window afresh','O(n(m+26))','O(26)','Compare frequency arrays rather than sorting; overlapping windows still repeat counting work.',r'''array<int,26> target{};
for (char c : pat) ++target[c - 'a'];
int m = pat.size(), answer = 0;
for (int i = 0; i + m <= (int)txt.size(); ++i) {
    array<int,26> count{};
    for (int j = i; j < i + m; ++j) ++count[txt[j] - 'a'];
    answer += count == target;
}
return answer;'''),
  a('Slide the frequency table','O(26n+m) = O(n+m)','O(26)','Add the incoming character and remove the outgoing character before checking equality.',r'''array<int,26> target{}, count{};
for (char c : pat) ++target[c - 'a'];
int m = pat.size(), answer = 0;
for (int r = 0; r < (int)txt.size(); ++r) {
    ++count[txt[r] - 'a'];
    if (r >= m) --count[txt[r - m] - 'a'];
    if (r + 1 >= m && count == target) ++answer;
}
return answer;''')])

p(S,5,'K_Length_K_Minus_One_Distinct','Substrings of Length K with K-1 Distinct Characters','substrings-of-length-k-with-k-1-distinct-elements','int substrCount(string s, int k)',
  'Update a distinct-character count precisely when a frequency crosses zero.',
  'Lowercase input; count length-k substrings with exactly k-1 distinct characters. k outside 1..n returns zero locally.',
  'Distinct equals the number of positive frequencies in the current window.',
  'For "aabac", k=3, windows aab and aba each have two distinct letters; bac has three. Answer 2.',
  [(['aabac',3],2),(['aaaa',2],3),(['abc',1],0),(['abc',4],0)],[
  a('Build a set for each window','O(nk log 26)','O(26)','Recompute membership for every window and test its cardinality.',r'''if (k <= 0) return 0;
int answer = 0;
for (int i = 0; i + k <= (int)s.size(); ++i) {
    set<char> letters(s.begin() + i, s.begin() + i + k);
    answer += (int)letters.size() == k - 1;
}
return answer;'''),
  a('Slide counts and recount active letters','O(26n)','O(26)','Reuse character counts, then inspect the 26 counts for every complete window.',r'''if (k <= 0) return 0;
int freq[26] = {}, answer = 0;
for (int r = 0; r < (int)s.size(); ++r) {
    ++freq[s[r] - 'a'];
    if (r >= k) --freq[s[r-k] - 'a'];
    int distinct = 0; for (int x : freq) distinct += x > 0;
    if (r + 1 >= k && distinct == k - 1) ++answer;
}
return answer;'''),
  a('Maintain zero-crossing count','O(n)','O(26)','A 0-to-1 count adds a distinct letter and a 1-to-0 count removes one.',r'''if (k <= 0) return 0;
int freq[26] = {}, distinct = 0, answer = 0;
for (int r = 0; r < (int)s.size(); ++r) {
    if (freq[s[r] - 'a']++ == 0) ++distinct;
    if (r >= k && --freq[s[r-k] - 'a'] == 0) --distinct;
    if (r + 1 >= k && distinct == k - 1) ++answer;
}
return answer;''')])

p(S,6,'Longest_K_Unique_Substring','Longest Substring with K Uniques','longest-k-unique-characters-substring0853','int longestKSubstr(string s, int k)',
  'Distinguish exactly-k acceptance from at-most-k window maintenance.',
  'Lowercase input; return the longest nonempty substring length with exactly k distinct letters, or -1 if none exists.',
  'After shrinking, the live window has at most k distinct letters; record it only at exactly k.',
  'For "aabac", k=2, the window grows through "aaba" with two letters. Adding c makes three; removing left characters eventually restores a,c. Best length remains 4.',
  [(['aabac',2],4),(['aaaa',2],-1),(['aaaa',1],4),(['abc',0],-1)],[
  a('Enumerate intervals and rebuild sets','O(n³)','O(26)','For each interval, count its distinct characters from scratch.',r'''int answer = -1;
for (int l = 0; l < (int)s.size(); ++l) for (int r = l; r < (int)s.size(); ++r) {
    set<char> letters(s.begin() + l, s.begin() + r + 1);
    if ((int)letters.size() == k) answer = max(answer, r-l+1);
}
return answer;'''),
  a('Extend each left boundary','O(n²)','O(26)','Maintain counts while extending one start, then restart for the next start.',r'''int answer = -1;
for (int l = 0; l < (int)s.size(); ++l) {
    int freq[26] = {}, distinct = 0;
    for (int r = l; r < (int)s.size(); ++r) {
        if (freq[s[r]-'a']++ == 0) ++distinct;
        if (distinct == k) answer = max(answer, r-l+1);
        if (distinct > k) break;
    }
}
return answer;'''),
  a('Variable sliding window','O(n)','O(26)','Move the left edge only when distinct exceeds k. Each character enters and leaves at most once.',r'''if (k <= 0) return -1;
int freq[26] = {}, distinct = 0, left = 0, answer = -1;
for (int right = 0; right < (int)s.size(); ++right) {
    if (freq[s[right]-'a']++ == 0) ++distinct;
    while (distinct > k) if (--freq[s[left++]-'a'] == 0) --distinct;
    if (distinct == k) answer = max(answer, right-left+1);
}
return answer;''')])

p(S,6,'Smallest_Distinct_Window','Smallest Distinct Window','smallest-distant-window3132','int findSubString(string s)',
  'Derive a window requirement from the input itself and minimize a valid range.',
  'Return the shortest substring length containing every distinct byte present in s. Empty input returns zero.',
  'A window is complete exactly when its distinct count equals the whole-string distinct count.',
  'For "aabcbcdbca", four letters are required. The suffix "dbca" contains all four in length 4; no length-3 window can contain four distinct letters.',
  [(['aabcbcdbca'],4),(['aaaa'],1),(['abc'],3),([''],0)],[
  a('Rebuild each interval membership','O(n³)','O(256)','Enumerate intervals and test each set against the full required set.',r'''set<char> required(s.begin(), s.end()); int best = s.size();
for (int l = 0; l < (int)s.size(); ++l) for (int r = l; r < (int)s.size(); ++r) {
    set<char> current(s.begin()+l, s.begin()+r+1);
    if (current == required) best = min(best, r-l+1);
}
return best;'''),
  a('Extend from every start','O(n²)','O(256)','For each left endpoint, stop at its first complete window.',r'''set<char> required(s.begin(), s.end()); int best = s.size();
for (int l = 0; l < (int)s.size(); ++l) {
    set<char> current;
    for (int r = l; r < (int)s.size(); ++r) {
        current.insert(s[r]);
        if (current.size() == required.size()) { best = min(best, r-l+1); break; }
    }
}
return best;'''),
  a('Shrink complete windows','O(n)','O(256)','Count required letters, then shrink each complete window while recording lengths.',r'''if (s.empty()) return 0;
bool seen[256] = {}; int required = 0;
for (unsigned char c : s) if (!seen[c]) { seen[c] = true; ++required; }
int freq[256] = {}, have = 0, left = 0, best = s.size();
for (int right = 0; right < (int)s.size(); ++right) {
    if (freq[(unsigned char)s[right]]++ == 0) ++have;
    while (have == required) {
        best = min(best, right-left+1);
        if (--freq[(unsigned char)s[left++]] == 0) --have;
    }
}
return best;''')])

binary_core = r'''int i = a.size()-1, j = b.size()-1, carry = 0;
string out;
while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0) sum += a[i--] - '0';
    if (j >= 0) sum += b[j--] - '0';
    out += char('0' + sum % 2); carry = sum / 2;
}
while (out.size() > 1 && out.back() == '0') out.pop_back();
reverse(out.begin(), out.end());
return out.empty() ? "0" : out;'''
p(S,7,'Add_Binary_Strings','Add Binary Strings','add-binary-strings3805','string addBinary(string a, string b)',
  'Generalize decimal carry arithmetic to base two without converting the entire number.',
  'Inputs are nonempty binary strings, possibly with leading zeroes. Return canonical binary output with no leading zeroes except "0".',
  'The produced suffix is correct; carry is the unprocessed contribution to the next column.',
  'For 11 + 1, the right column gives 0 with carry 1; the next gives 0 with carry 1; the final carry gives 1. Reverse the collected 001 to get 100.',
  [(['11','1'],'100'),(['000','0'],'0'),(['1010','1011'],'10101'),(['1','1111'],'10000')],[
  a('Prepend each computed bit','O(L²)','O(L)','Simulate columns but insert each new bit at the front, shifting the accumulated result.',r'''int i = a.size()-1, j = b.size()-1, carry = 0;
string out;
while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0) sum += a[i--]-'0';
    if (j >= 0) sum += b[j--]-'0';
    out.insert(out.begin(), char('0'+sum%2)); carry = sum/2;
}
size_t first = out.find_first_not_of('0');
return first == string::npos ? "0" : out.substr(first);'''),
  a('Append reversed bits','O(L)','O(L) result','Append in constant amortized time and reverse once after all columns.',binary_core),
  a('Same linear carry method; no distinct third algorithm','O(L)','O(L) result','The intermediate method already meets the output-size lower bound. Keep this slot for format consistency.',binary_core)],difficulty='Easy')

sum_core = r'''int answer = 0, current = 0;
for (char c : s) {
    if (c >= '0' && c <= '9') current = 10 * current + c - '0';
    else { answer += current; current = 0; }
}
return answer + current;'''
p(S,7,'Sum_Numbers_in_String','Sum Numbers in a String','sum-of-numbers-in-string-1587115621','int findSum(string s)',
  'Recognize digit runs, flush parsing state at delimiters, and handle a trailing number.',
  'Alphanumeric input. Sum maximal decimal digit runs; the platform bounds the sum at 100000. No sign syntax is used.',
  'Answer contains completed runs; current contains only the unfinished decimal run.',
  'For "12a003b4", reading a commits 12, b commits 3, and the final flush commits 4. Total 19.',
  [(['12a003b4'],19),(['abc'],0),(['0007'],7),(['1a2b3'],6)],[
  a('Collect and parse digit-run strings','O(n)','O(n)','Store completed runs, then convert and sum them. Leading zeros are discarded during conversion.',r'''vector<string> runs; string current;
for (char c : s) {
    if (c >= '0' && c <= '9') current += c;
    else if (!current.empty()) { runs.push_back(current); current.clear(); }
}
if (!current.empty()) runs.push_back(current);
int answer = 0;
for (const string& run : runs) { int value = 0; for (char c : run) value = value*10+c-'0'; answer += value; }
return answer;'''),
  a('Streaming decimal accumulator','O(n)','O(1)','Keep one current number and commit it when a nondigit arrives.',sum_core),
  a('Same constant-state parser; no distinct third algorithm','O(n)','O(1)','The streaming parser already inspects each character once with constant state.',sum_core)],difficulty='Easy')

p(S,8,'Rabin_Karp_Search','Search Pattern (Rabin-Karp Algorithm)','search-pattern-rabin-karp-algorithm--141631','vector<int> search(string pat, string txt)',
  'Compare hashing as a candidate filter with deterministic prefix matching.',
  'Nonempty pattern. Return all ONE-BASED starting positions, including overlaps; no match returns an empty vector.',
  'A hash match is only a candidate; exact character comparison decides whether it is a real match.',
  'For pat="aa", txt="aaaa", windows starting at zero-based 0,1,2 match. The returned positions are [1,2,3], with overlaps retained.',
  [(['aa','aaaa'],[1,2,3]),(['ab','zabxab'],[2,5]),(['abc','ab'],[]),(['x','aaa'],[])],[
  a('Direct matching at every start','O(nm)','O(1) auxiliary plus output','Compare each candidate text window directly with the pattern.',r'''vector<int> out; int m = pat.size();
for (int i = 0; i + m <= (int)txt.size(); ++i) if (txt.compare(i, m, pat) == 0) out.push_back(i+1);
return out;'''),
  a('Rolling hash with collision verification','O(n+m+cm), O(nm) worst case','O(1) auxiliary plus output','Roll a base-257 hash modulo a prime. Verify all c hash candidates directly; collisions cannot create false matches.',r'''vector<int> out;
int n = txt.size(), m = pat.size();
if (m > n) return out;
const long long mod = 1000000007, base = 257;
long long power = 1, target = 0, window = 0;
for (int i = 0; i < m; ++i) {
    if (i) power = power * base % mod;
    target = (target * base + (unsigned char)pat[i] + 1) % mod;
    window = (window * base + (unsigned char)txt[i] + 1) % mod;
}
for (int i = 0; i + m <= n; ++i) {
    if (window == target && txt.compare(i, m, pat) == 0) out.push_back(i+1);
    if (i + m < n) {
        window = (window - ((unsigned char)txt[i]+1)*power % mod + mod) % mod;
        window = (window * base + (unsigned char)txt[i+m] + 1) % mod;
    }
}
return out;'''),
  a('KMP: guaranteed linear comparison','O(n+m)','O(m) plus output','For a guaranteed bound, reuse the pattern border lengths after mismatch and after each full match.',r'''int m = pat.size(); vector<int> pi(m), out;
for (int i = 1, j = 0; i < m; ++i) {
    while (j && pat[i] != pat[j]) j = pi[j-1];
    if (pat[i] == pat[j]) ++j;
    pi[i] = j;
}
for (int i = 0, j = 0; i < (int)txt.size(); ++i) {
    while (j && txt[i] != pat[j]) j = pi[j-1];
    if (txt[i] == pat[j]) ++j;
    if (j == m) { out.push_back(i-m+2); j = pi[j-1]; }
}
return out;''')])

prefix_pal_brute = r'''int n = s.size();
for (int length = n; length >= 0; --length) {
    bool ok = true;
    for (int l = 0, r = length-1; l < r; ++l, --r) if (s[l] != s[r]) { ok = false; break; }
    if (ok) return n-length;
}
return n;'''
p(S,8,'Min_Chars_for_Palindrome','Minimum Characters to Add for Palindrome','minimum-characters-to-be-added-at-front-to-make-string-palindrome','int minChar(string s)',
  'Use a border computation to recognize the longest palindromic prefix.',
  'Only additions at the FRONT are permitted. Return their minimum count; empty input returns zero.',
  'The final border length of source + separator + reverse(source) is its longest palindromic prefix length.',
  'For "aacecaaa", the prefix "aacecaa" is palindromic, length 7. One trailing a lies outside it, so one leading a completes the palindrome.',
  [(['aacecaaa'],1),(['abcd'],3),(['aba'],0),([''],0)],[
  a('Test decreasing prefix lengths','O(n²)','O(1)','Find the longest palindromic prefix by comparing mirrored pairs.',prefix_pal_brute),
  a('Same low-memory baseline; no artificial intermediate','O(n²)','O(1)','This preserves the useful constant-space alternative before introducing the prefix table.',prefix_pal_brute),
  a('Prefix function with an out-of-alphabet separator','O(n)','O(n)','Encode bytes as integers and use -1 as the separator so input punctuation cannot collide with it.',r'''vector<int> text;
for (unsigned char c : s) text.push_back(c);
text.push_back(-1);
for (auto it = s.rbegin(); it != s.rend(); ++it) text.push_back((unsigned char)*it);
vector<int> pi(text.size());
for (int i = 1, j = 0; i < (int)text.size(); ++i) {
    while (j && text[i] != text[j]) j = pi[j-1];
    if (text[i] == text[j]) ++j;
    pi[i] = j;
}
return s.size()-pi.back();''')])

rle_core = r'''string out;
for (int i = 0; i < (int)s.size();) {
    int j = i+1;
    while (j < (int)s.size() && s[j] == s[i]) ++j;
    out += s[i]; out += to_string(j-i); i = j;
}
return out;'''
p(S,9,'Run_Length_Encoding','Run Length Encoding','run-length-encoding','string encode(string s)',
  'Keep consecutive runs separate even when the same symbol appears again later.',
  'Encode every consecutive character run as character followed by its decimal count, including count 1. This study adapter uses Solution::encode.',
  'Every completed run has been emitted once; the next unread index begins a new run.',
  'For "aaabbcaa", runs are aaa, bb, c, aa. Their encodings a3, b2, c1, a2 concatenate to "a3b2c1a2".',
  [(['aaabbcaa'],'a3b2c1a2'),(['abc'],'a1b1c1'),(['aaaaaaaaaaaa'],'a12'),([''],'')],[
  a('Store runs before formatting','O(n)','O(n)','Collect character/count pairs first, then serialize them into an output string.',r'''vector<pair<char,int>> runs;
for (char c : s) {
    if (runs.empty() || runs.back().first != c) runs.push_back({c,1});
    else ++runs.back().second;
}
string out;
for (auto [c, count] : runs) { out += c; out += to_string(count); }
return out;'''),
  a('Serialize each run immediately','O(n)','O(n) result; O(1) auxiliary','Advance a run endpoint and write the run as soon as it is complete.',rle_core),
  a('Same linear run scan; no distinct third algorithm','O(n)','O(n) result; O(1) auxiliary','Every input character and output character must be visited; the run scan meets that bound.',rle_core)],difficulty='Easy')

look_step = r'''string next;
for (int i = 0; i < (int)current.size();) {
    int j = i+1;
    while (j < (int)current.size() && current[j] == current[i]) ++j;
    next += to_string(j-i); next += current[i]; i = j;
}'''
look_core = r'''string current = "1";
for (int row = 1; row < n; ++row) {
'''+look_step+r'''
    current = move(next);
}
return current;'''
p(S,9,'Look_and_Say','Look and Say Pattern','decode-the-pattern1138','string countAndSay(int n)',
  'Build one representation from another while keeping source and destination separate.',
  'n >= 1. The first row is "1"; every later row describes counts then digits of consecutive runs in the previous row.',
  'Current is the complete previous row, and next describes only its fully consumed runs.',
  'Rows 1 through 5 are "1", "11", "21", "1211", "111221". In row 4, one 1, one 2, two 1s produce row 5.',
  [([1],'1'),([4],'1211'),([5],'111221'),([6],'312211')],[
  a('Retain every generated row','O(T)','O(T)','Save every row for easy inspection; T is the total number of characters generated across rows.',r'''vector<string> rows{"1"};
for (int row = 1; row < n; ++row) {
    string current = rows.back();
'''+look_step+r'''
    rows.push_back(next);
}
return rows.back();'''),
  a('Keep only consecutive rows','O(T)','O(L)','Replace the current row after the next row is complete; L is the largest row length.',look_core),
  a('Same rolling-row simulation; no distinct third algorithm','O(T)','O(L)','Avoid inventing a closed-form shortcut; reading and constructing all intermediate rows is the documented method.',look_core)])

two_starter = '''class twoStacks {
public:
    twoStacks() {}
    void push1(int x) {}
    void push2(int x) {}
    int pop1() {}
    int pop2() {}
};'''
two_test = 'S x; if(x.pop1()!=-1||x.pop2()!=-1)return false; x.push1(10);x.push2(20);x.push1(30);x.push2(40);if(x.pop1()!=30||x.pop2()!=40||x.pop1()!=10||x.pop2()!=20)return false;return x.pop1()==-1&&x.pop2()==-1;'
p(Q,1,'Two_Stacks_in_Array','Two Stacks in Array','implement-two-stacks-in-an-array','class twoStacks',
  'Manage two independent LIFO boundaries in shared storage.',
  'Public methods: push1, push2, pop1, pop2; empty pop returns -1. Local fixed-array references support at most 100000 total live elements. Values are nonnegative; test operations respect capacity.',
  'The first stack grows from the left, the second from the right, and their occupied ranges never overlap.',
  'Push1(10), push2(20), push1(30) leaves stack1=[10,30] and stack2=[20]. Pop1 returns 30; pop2 returns 20; neither operation changes the other stack.',
  [(['push1 10','push2 20','pop1','pop2'],[10,20]),(['pop1','pop2'],[-1,-1]),(['push2 7','push2 9','pop2'],[9])],[
  a('Contiguous sections with shifting','O(n) stack1 push/pop; O(1) amortized stack2 push/pop','O(n)','The split marks the first stack end; inserting there shifts stack2 without changing its order.',r'''class twoStacks {
    vector<int> data; int split = 0;
public:
    void push1(int x) { data.insert(data.begin()+split, x); ++split; }
    void push2(int x) { data.push_back(x); }
    int pop1() { if (split == 0) return -1; int value = data[split-1]; data.erase(data.begin()+--split); return value; }
    int pop2() { if ((int)data.size() == split) return -1; int value = data.back(); data.pop_back(); return value; }
};'''),
  a('Reserve independent halves','O(1) operations; O(C) initialization','O(2C)','Give each stack C positions. This satisfies the documented bound but wastes the unused half when only one stack grows.',r'''class twoStacks {
    static constexpr int C = 100000;
    vector<int> data; int one = 0, two = C;
public:
    twoStacks() : data(2*C) {}
    void push1(int x) { data[one++] = x; }
    void push2(int x) { data[two++] = x; }
    int pop1() { return one == 0 ? -1 : data[--one]; }
    int pop2() { return two == C ? -1 : data[--two]; }
};'''),
  a('Share free space between opposing tops','O(1) operations; O(C) initialization','O(C)','With a total-live-elements bound C, grow inward from opposite ends to share every free slot.',r'''class twoStacks {
    static constexpr int C = 100000;
    vector<int> data; int left = 0, right = C-1;
public:
    twoStacks() : data(C) {}
    void push1(int x) { if (left > right) throw overflow_error("full"); data[left++] = x; }
    void push2(int x) { if (left > right) throw overflow_error("full"); data[right--] = x; }
    int pop1() { return left == 0 ? -1 : data[--left]; }
    int pop2() { return right == C-1 ? -1 : data[++right]; }
};''')],difficulty='Easy',starter=two_starter,design=two_test)

p(Q,2,'Stack_Permutations','Validate Stack Operations','stack-permutations','bool isStackPermutation(vector<int>& a, vector<int>& b)',
  'Compare recursive search through operation choices with a forced-pop stack simulation.',
  'Equal-length arrays of distinct values give push and required pop order. This local adapter returns bool and omits redundant n. Revisit Validate Stack Sequences using the GFG contract.',
  'The explicit stack holds pushed values not yet consumed by the requested pop prefix.',
  'For a=[1,2,3], b=[2,1,3], push 1 and 2, pop 2 and 1, then push and pop 3. For b=[3,1,2], 2 blocks access to 1 after popping 3.',
  [([[1,2,3],[2,1,3]],True),([[1,2,3],[3,1,2]],False),([[1],[1]],True)],[
  a('Explore legal push/pop sequences','O(4^n n) upper bound','O(n²) copied states','Recursively try pushing the next input and popping only a matching top. This exponential teaching baseline is for small examples.',r'''if (a.size() != b.size()) return false;
int n = a.size();
function<bool(int,int,vector<int>)> visit = [&](int i, int j, vector<int> st) {
    if (j == n) return true;
    if (!st.empty() && st.back() == b[j]) {
        auto next = st; next.pop_back();
        if (visit(i, j+1, next)) return true;
    }
    if (i < n) { st.push_back(a[i]); if (visit(i+1, j, st)) return true; }
    return false;
};
return visit(0,0,{});'''),
  a('Greedy std::stack simulation','O(n)','O(n)','Push in order, then consume every requested pop currently available at the top.',r'''if (a.size() != b.size()) return false;
stack<int> st; size_t j = 0;
for (int value : a) {
    st.push(value);
    while (!st.empty() && j < b.size() && st.top() == b[j]) { st.pop(); ++j; }
}
return j == b.size();'''),
  a('Same linear simulation with vector storage','O(n)','O(n)','A vector back is another LIFO implementation; the algorithm and asymptotic bound are the same.',r'''if (a.size() != b.size()) return false;
vector<int> st; size_t j = 0;
for (int value : a) {
    st.push_back(value);
    while (!st.empty() && j < b.size() && st.back() == b[j]) { st.pop_back(); ++j; }
}
return j == b.size();''')])

infix_core = r'''auto precedence = [](char c) { return c == '^' ? 3 : (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : 0; };
string out; stack<char> operators;
for (unsigned char c : s) {
    if (isalnum(c)) out += char(c);
    else if (c == '(') operators.push(c);
    else if (c == ')') {
        while (!operators.empty() && operators.top() != '(') { out += operators.top(); operators.pop(); }
        operators.pop();
    } else {
        while (!operators.empty() && operators.top() != '(' &&
               (precedence(operators.top()) > precedence(c) ||
                (precedence(operators.top()) == precedence(c) && c != '^'))) {
            out += operators.top(); operators.pop();
        }
        operators.push(c);
    }
}
while (!operators.empty()) { out += operators.top(); operators.pop(); }
return out;'''
p(Q,3,'Infix_to_Postfix','Infix to Postfix','infix-to-postfix-1587115620','string infixToPostfix(string s)',
  'Distinguish precedence, associativity, and parenthesis scope when converting representations.',
  'Valid expressions with single alphanumeric operands and binary + - * / ^, with optional parentheses and no spaces. ^ is right-associative; the other operators are left-associative.',
  'Output operands are already in evaluation order; pending operators wait until their right operand is complete.',
  'For a^b^c, the second ^ stays above the first. Draining produces abc^^, which means a^(b^c). For a-b-c, the first - is emitted before pushing the second, producing ab-c-.',
  [(['a+b*c'],'abc*+'),(['(a+b)*c'],'ab+c*'),(['a^b^c'],'abc^^'),(['a-b-c'],'ab-c-'),(['x'],'x')],[
  a('Recursive expression splitting','O(n²)','O(n²) conservative copied-output bound','At depth zero, split at the lowest-precedence operator. Choose the rightmost equal-precedence operator for left associativity, but the leftmost ^ for right associativity. Strip an enclosing pair only when it wraps the entire interval.',r'''auto prec = [](char c) { return c == '^' ? 3 : (c == '*' || c == '/') ? 2 : 1; };
function<string(int,int)> convert = [&](int l, int r) -> string {
    if (l == r) return string(1,s[l]);
    int depth = 0, split = -1, best = 4;
    for (int i = l; i <= r; ++i) {
        char c = s[i];
        if (c == '(') ++depth;
        else if (c == ')') --depth;
        else if (depth == 0 && !isalnum((unsigned char)c)) {
            int p = prec(c);
            if (p < best || (p == best && c != '^')) { best = p; split = i; }
        }
    }
    if (split == -1) return convert(l+1,r-1);
    return convert(l,split-1) + convert(split+1,r) + s[split];
};
return convert(0,(int)s.size()-1);'''),
  a('Operator-stack conversion','O(n)','O(n)','Drain only stronger operators, or equal operators when the incoming operator associates left. Parentheses limit draining.',infix_core),
  a('Same linear operator-stack method','O(n)','O(n)','Every operator is pushed and popped once; no separate faster third method is needed.',infix_core)])

p(Q,3,'Minimum_Bracket_Reversals','Minimum Bracket Reversals to Balance','count-the-reversals0401','int countRev(string s)',
  'Distinguish reversal cost from insertion cost and reason about unavoidable repairs.',
  'Input uses only { and }. Reverse one brace per operation. Return minimum reversals, or -1 for odd length.',
  'After repairing an unmatched closing brace, the processed prefix is balanced or has spare openings.',
  'For "}}{{", the first closing brace must reverse, the second closes it, and the final two openings need one reversal. Total 2. Odd length can never balance.',
  [(['}}{{'],2),(['{}'],0),(['{{{'],-1),(['}}}}'],2),(['}{'],2)],[
  a('Enumerate orientation choices','O(2^n n)','O(n) recursion','Try keeping or flipping every brace; reject choices with negative prefix balance or nonzero final balance. Use only small teaching cases.',r'''int n = s.size(); if (n%2) return -1;
int best = n+1;
function<void(int,int,int)> visit = [&](int i, int balance, int cost) {
    if (balance < 0 || cost >= best) return;
    if (i == n) { if (balance == 0) best = cost; return; }
    int delta = s[i] == '{' ? 1 : -1;
    visit(i+1,balance+delta,cost);
    visit(i+1,balance-delta,cost+1);
};
visit(0,0,0); return best;'''),
  a('Cancel matched pairs with a stack','O(n)','O(n)','Cancel {} pairs. The remaining closings and openings each need ceiling(count/2) flips.',r'''if (s.size()%2) return -1;
stack<char> st;
for (char c : s) {
    if (c == '}' && !st.empty() && st.top() == '{') st.pop();
    else st.push(c);
}
int opening = 0, closing = 0;
while (!st.empty()) { if (st.top() == '{') ++opening; else ++closing; st.pop(); }
return (opening+1)/2 + (closing+1)/2;'''),
  a('Repair balance while scanning','O(n)','O(1)','A closing brace with zero balance is forced to reverse. After scanning, reverse half of the remaining openings.',r'''if (s.size()%2) return -1;
int balance = 0, flips = 0;
for (char c : s) {
    if (c == '{') ++balance;
    else if (balance > 0) --balance;
    else { ++flips; ++balance; }
}
return flips + balance/2;''')])

p(Q,4,'Next_Greater_Frequency','Next Element with Greater Frequency','next-element-with-greater-frequency--170637','vector<int> nextFreqGreater(vector<int>& arr)',
  'Apply the monotonic framework to a derived key instead of comparing raw values.',
  'For each position return the nearest value to its right whose total-array frequency is strictly greater; use -1 if none.',
  'Stack candidates have strictly decreasing frequency from bottom to top when scanning right to left.',
  'For [1,1,2,3,2,1], frequencies are 1:3, 2:2, 3:1. The 3 resolves to the following 2; each 2 resolves to the final 1. Answer [-1,-1,1,2,1,-1].',
  [([[1,1,2,3,2,1]],[-1,-1,1,2,1,-1]),([[4,4,4]],[-1,-1,-1]),([[1,2,3]],[-1,-1,-1])],[
  a('Recount frequencies during each search','O(n³)','O(n) result','For each candidate pair, count both values directly in the full array.',r'''vector<int> out(arr.size(),-1);
for (int i = 0; i < (int)arr.size(); ++i) for (int j = i+1; j < (int)arr.size(); ++j) {
    if (count(arr.begin(),arr.end(),arr[j]) > count(arr.begin(),arr.end(),arr[i])) { out[i] = arr[j]; break; }
}
return out;'''),
  a('Precount then scan to the right','O(n²) expected','O(n)','Build frequencies once, then search directly for every position.',r'''unordered_map<int,int> freq; for (int value : arr) ++freq[value];
vector<int> out(arr.size(),-1);
for (int i = 0; i < (int)arr.size(); ++i) for (int j = i+1; j < (int)arr.size(); ++j) {
    if (freq[arr[j]] > freq[arr[i]]) { out[i] = arr[j]; break; }
}
return out;'''),
  a('Monotonic stack on frequencies','O(n) expected','O(n)','Pop values with no greater frequency: the closer current value dominates them for future positions to its left.',r'''unordered_map<int,int> freq; for (int value : arr) ++freq[value];
vector<int> out(arr.size(),-1); stack<int> candidates;
for (int i = (int)arr.size()-1; i >= 0; --i) {
    while (!candidates.empty() && freq[candidates.top()] <= freq[arr[i]]) candidates.pop();
    if (!candidates.empty()) out[i] = candidates.top();
    candidates.push(arr[i]);
}
return out;''')])

p(Q,5,'Max_of_Min_Every_Window','Max of Min for Every Window Size','maximum-of-minimum-for-every-window-size3453','vector<int> maxOfMins(vector<int>& arr)',
  'Use smaller-element boundaries to aggregate answers for all window sizes.',
  'Return n values: result[k-1] is the largest minimum among all contiguous windows of size k. Negative values are supported.',
  'Each value contributes to the largest span in which no strictly smaller value blocks it; shorter answers inherit larger-span candidates.',
  'For [2,1,3], size-1 minima are 2,1,3 so best=3; size-2 minima are 1,1 so best=1; size-3 minimum is 1. Answer [3,1,1].',
  [([[2,1,3]],[3,1,1]),([[2,2]],[2,2]),([[-2,-1,-3]],[-1,-2,-3]),([[7]],[7])],[
  a('Scan every window for every size','O(n³)','O(n) result','Enumerate window sizes and starts, then scan each window for its minimum.',r'''int n = arr.size(); vector<int> out(n,INT_MIN);
for (int k = 1; k <= n; ++k) for (int start = 0; start+k <= n; ++start) {
    int value = *min_element(arr.begin()+start,arr.begin()+start+k);
    out[k-1] = max(out[k-1],value);
}
return out;'''),
  a('Run one monotonic deque per size','O(n²)','O(n)','For each size, maintain a deque of increasing candidates; this computes all minima in one pass per size.',r'''int n = arr.size(); vector<int> out(n,INT_MIN);
for (int k = 1; k <= n; ++k) {
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && dq.front() <= i-k) dq.pop_front();
        while (!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();
        dq.push_back(i);
        if (i+1 >= k) out[k-1] = max(out[k-1],arr[dq.front()]);
    }
}
return out;'''),
  a('Smaller boundaries plus downward propagation','O(n)','O(n)','Find previous and next strictly smaller indices, assign each value to its maximum span, then propagate from larger lengths to smaller lengths. Equal heights can share a span because we maximize rather than count contributions.',r'''int n = arr.size(); vector<int> left(n,-1), right(n,n), st, out(n,INT_MIN);
for (int i = 0; i < n; ++i) {
    while (!st.empty() && arr[st.back()] >= arr[i]) st.pop_back();
    if (!st.empty()) left[i] = st.back(); st.push_back(i);
}
st.clear();
for (int i = n-1; i >= 0; --i) {
    while (!st.empty() && arr[st.back()] >= arr[i]) st.pop_back();
    if (!st.empty()) right[i] = st.back(); st.push_back(i);
}
for (int i = 0; i < n; ++i) { int length = right[i]-left[i]-1; out[length-1] = max(out[length-1],arr[i]); }
for (int i = n-2; i >= 0; --i) out[i] = max(out[i],out[i+1]);
return out;''')],difficulty='Hard')

celebrity_verify = r'''for (int i = 0; i < n; ++i) if (i != candidate && (mat[candidate][i] || !mat[i][candidate])) return -1;
return candidate;'''
p(Q,6,'Celebrity_Problem','Celebrity Problem','the-celebrity-problem','int celebrity(vector<vector<int>>& mat)',
  'Recognize pairwise candidate elimination and the need for a final verification pass.',
  'Square binary knows matrix. A celebrity knows nobody else and is known by everyone else. Ignore the diagonal. Return zero-based index or -1.',
  'Every eliminated person has a concrete witness proving they cannot be the celebrity.',
  'If 0 knows 1, discard 0. If 1 does not know 2, discard 2. Candidate 1 still must pass both its row and column checks.',
  [([[[0,1,0],[0,0,0],[0,1,0]]],1),([[[0,1],[1,0]]],-1),([[[1]]],0),([[[0,0],[0,0]]],-1)],[
  a('Verify every person','O(n²)','O(1)','Test all row and column conditions for each candidate.',r'''int n = mat.size();
for (int candidate = 0; candidate < n; ++candidate) {
    bool valid = true;
    for (int i = 0; i < n; ++i) if (i != candidate && (mat[candidate][i] || !mat[i][candidate])) valid = false;
    if (valid) return candidate;
}
return -1;'''),
  a('Pairwise elimination with a stack','O(n)','O(n)','Pop two people; one knows-relation always eliminates at least one. Verify the survivor.',r'''int n = mat.size(); if (!n) return -1;
stack<int> people; for (int i = 0; i < n; ++i) people.push(i);
while (people.size() > 1) { int a = people.top(); people.pop(); int b = people.top(); people.pop(); people.push(mat[a][b] ? b : a); }
int candidate = people.top();
'''+celebrity_verify),
  a('Carry one elimination candidate','O(n)','O(1)','The same pairwise elimination needs only a current candidate and the next person.',r'''int n = mat.size(); if (!n) return -1;
int candidate = 0;
for (int i = 1; i < n; ++i) if (mat[candidate][i]) candidate = i;
'''+celebrity_verify)])

p(Q,7,'Generate_Binary_Numbers','Generate Binary Numbers','generate-binary-numbers-1587115620','vector<string> generate(int n)',
  'See how FIFO expansion generates states in increasing length and numeric order.',
  'Return binary representations of decimal integers 1 through n. Zero returns an empty vector locally.',
  'The queue removes shorter binary strings before longer ones, and 0-children before 1-children.',
  'Starting with queue [1], emit 1 and enqueue 10,11. Emit 10 and enqueue 100,101. The first four outputs are 1,10,11,100.',
  [([4],['1','10','11','100']),([1],['1']),([0],[])],[
  a('Convert each integer separately','O(T)','O(T) output','Repeatedly extract binary digits and reverse each number. T is the total emitted bit count, Theta(n log(n+1)).',r'''vector<string> out;
for (int value = 1; value <= n; ++value) {
    int x = value; string bits;
    while (x) { bits += char('0'+x%2); x /= 2; }
    reverse(bits.begin(),bits.end()); out.push_back(bits);
}
return out;'''),
  a('Reuse earlier representations','O(T)','O(T) output','The representation of i is that of floor(i/2), followed by its low bit; output storage also holds parent states.',r'''vector<string> out;
for (int i = 1; i <= n; ++i) out.push_back((i == 1 ? string() : out[i/2-1]) + char('0'+i%2));
return out;'''),
  a('FIFO state expansion','O(T)','O(T) queue and output','Pop a prefix and enqueue its two extensions. Avoid generating children after the final output. This is the queue-focused method, not an asymptotic improvement over conversion.',r'''vector<string> out; if (n <= 0) return out;
queue<string> pending; pending.push("1");
while ((int)out.size() < n) {
    string current = pending.front(); pending.pop(); out.push_back(current);
    if ((int)out.size() < n) { pending.push(current+'0'); pending.push(current+'1'); }
}
return out;''')],difficulty='Easy')

p(Q,8,'Circular_Tour','Gas Station (Circular Tour)','circular-tour-1587115620','int startStation(vector<int>& gas, vector<int>& cost)',
  'Compare a circular journey simulation with eliminating impossible starting positions.',
  'Equal-length nonempty nonnegative arrays. Start with an empty tank, collect gas[i], and pay cost[i] to reach the next station. Return the first feasible zero-based start, or -1. This adapter uses the modern two-array contract.',
  'When a candidate segment runs out of fuel, every start inside that segment is also ruled out.',
  'For gas=[1,2,3], cost=[2,2,1], start 0 immediately fails. Start 1 has tank 0, then 2, then 1 after wraparound, so it completes the tour.',
  [([[1,2,3],[2,2,1]],1),([[1,1],[2,2]],-1),([[2],[2]],0),([[2,2],[1,1]],0)],[
  a('Simulate every circular start','O(n²)','O(1)','Try each start and use modulo indexing to visit exactly n stations.',r'''int n = gas.size();
for (int start = 0; start < n; ++start) {
    long long tank = 0; bool ok = true;
    for (int step = 0; step < n; ++step) {
        int i = (start+step)%n; tank += (long long)gas[i]-cost[i];
        if (tank < 0) { ok = false; break; }
    }
    if (ok) return start;
}
return -1;'''),
  a('Store prefix balances','O(n)','O(n)','A start after the first strict minimum prefix never drops below its initial balance; a negative total rejects all starts.',r'''int n = gas.size(); if (!n) return -1;
vector<long long> prefix(n+1);
for (int i = 0; i < n; ++i) prefix[i+1] = prefix[i]+(long long)gas[i]-cost[i];
if (prefix[n] < 0) return -1;
int start = 0;
for (int i = 1; i < n; ++i) if (prefix[i] < prefix[start]) start = i;
return start;'''),
  a('Eliminate failed candidate segments','O(n)','O(1)','Accumulate a total and a candidate tank; reset the candidate only when its tank turns negative. This optimization no longer needs a queue.',r'''if (gas.empty()) return -1;
long long total = 0, tank = 0; int start = 0;
for (int i = 0; i < (int)gas.size(); ++i) {
    long long delta = (long long)gas[i]-cost[i]; total += delta; tank += delta;
    if (tank < 0) { start = i+1; tank = 0; }
}
return total < 0 ? -1 : start;''')])

p(Q,9,'Count_Distinct_Window','Count Distinct Elements in Every Window','count-distinct-elements-in-every-window/1'.removesuffix('/1'),'vector<int> countDistinct(vector<int>& arr, int k)',
  'Revisit the Arrays/Vectors window problem using explicit FIFO expiration and a frequency map.',
  'Return distinct-value counts for every contiguous length-k window. Invalid k returns an empty result locally.',
  'The queue stores exactly the active arrivals, while each map count equals its multiplicity in that queue.',
  'For [1,2,1,3], k=3, the first queue contains 1,2,1: two distinct values. Evict one 1 and append 3; the remaining 1 still counts, yielding three distinct values.',
  [([[1,2,1,3],3],[2,3]),([[4,4,4],2],[1,1]),([[1,2,3],1],[1,1,1]),([[1],2],[])],[
  a('Rebuild each window set','O(nk log k)','O(k) plus output','Insert each window into a fresh ordered set and report its size.',r'''vector<int> out; if (k <= 0) return out;
for (int i = 0; i+k <= (int)arr.size(); ++i) {
    set<int> values(arr.begin()+i,arr.begin()+i+k); out.push_back(values.size());
}
return out;'''),
  a('Ordered frequency map','O(n log k)','O(k) plus output','Add and remove window endpoints and erase keys only when their frequency reaches zero.',r'''vector<int> out; if (k <= 0) return out;
map<int,int> freq;
for (int i = 0; i < (int)arr.size(); ++i) {
    ++freq[arr[i]];
    if (i >= k && --freq[arr[i-k]] == 0) freq.erase(arr[i-k]);
    if (i+1 >= k) out.push_back(freq.size());
}
return out;'''),
  a('FIFO arrivals with a hash frequency map','O(n) expected','O(k) plus output','An explicit queue supplies the expired value, which also works when input arrives as a stream.',r'''vector<int> out; if (k <= 0) return out;
queue<int> arrivals; unordered_map<int,int> freq;
for (int value : arr) {
    arrivals.push(value); ++freq[value];
    if ((int)arrivals.size() > k) {
        int old = arrivals.front(); arrivals.pop();
        if (--freq[old] == 0) freq.erase(old);
    }
    if ((int)arrivals.size() == k) out.push_back(freq.size());
}
return out;''')],difficulty='Easy')

lru_starter = '''class LRUCache {
public:
    LRUCache(int capacity) {}
    int get(int key) {}
    void put(int key, int value) {}
};'''
lru_test = 'S x(2);x.put(1,10);x.put(2,20);if(x.get(1)!=10)return false;x.put(3,30);if(x.get(2)!=-1)return false;x.put(1,11);x.put(4,40);if(x.get(3)!=-1||x.get(1)!=11||x.get(4)!=40)return false;S zero(0);zero.put(1,2);return zero.get(1)==-1;'
lru_map = r'''class LRUCache {
    int capacity;
    list<pair<int,int>> order;
    MAP<int,list<pair<int,int>>::iterator> locations;
public:
    LRUCache(int cap) : capacity(cap) {}
    int get(int key) {
        auto it = locations.find(key);
        if (it == locations.end()) return -1;
        order.splice(order.begin(),order,it->second);
        return it->second->second;
    }
    void put(int key, int value) {
        if (capacity <= 0) return;
        auto it = locations.find(key);
        if (it != locations.end()) {
            it->second->second = value;
            order.splice(order.begin(),order,it->second);
            return;
        }
        if ((int)order.size() == capacity) { locations.erase(order.back().first); order.pop_back(); }
        order.push_front({key,value}); locations[key] = order.begin();
    }
};'''
p(Q,10,'LRU_Cache','LRU Cache','lru-cache','class LRUCache',
  'Distinguish arrival order from access recency and combine keyed lookup with eviction order.',
  'get(key) returns the stored value or -1 and refreshes recency on hits. put refreshes updated keys. Evict the least recently used key when full. Capacity zero is a local extension. std::list supplies stable iterators; no manual node prerequisite.',
  'The list front is most recently used, the back least recently used, and each map iterator points to its unique live list node.',
  'With capacity 2: put(1,10), put(2,20), get(1) makes key 1 newest. put(3,30) evicts key 2. A read miss changes no recency.',
  [(['capacity 2','put 1 10','put 2 20','get 1','put 3 30','get 2'],[10,-1]),(['capacity 1','put 1 1','put 1 2','get 1'],[2]),(['capacity 0','put 1 1','get 1'],[-1])],[
  a('Scan and move in a vector','O(C) per operation','O(C)','Store most recent first. Search linearly, erase the found pair, and reinsert it at the front.',r'''class LRUCache {
    int capacity; vector<pair<int,int>> order;
public:
    LRUCache(int cap) : capacity(cap) {}
    int get(int key) {
        for (int i = 0; i < (int)order.size(); ++i) if (order[i].first == key) {
            auto entry = order[i]; order.erase(order.begin()+i); order.insert(order.begin(),entry); return entry.second;
        }
        return -1;
    }
    void put(int key, int value) {
        if (capacity <= 0) return;
        for (int i = 0; i < (int)order.size(); ++i) if (order[i].first == key) { order.erase(order.begin()+i); break; }
        order.insert(order.begin(),{key,value});
        if ((int)order.size() > capacity) order.pop_back();
    }
};'''),
  a('Ordered map plus recency list','O(log C) per operation','O(C)','A tree map locates stable list iterators; splice moves a node without invalidating its iterator.',lru_map.replace('MAP<','map<')),
  a('Hash map plus recency list','O(1) expected per operation','O(C)','Hash lookup locates a node, splice refreshes it, and back eviction removes the least recent key. Expected time assumes ordinary hash behavior.',lru_map.replace('MAP<','unordered_map<'))],difficulty='Hard',starter=lru_starter,design=lru_test)

p(Q,11,'Nearest_One_Distance','Distance of Nearest Cell Having 1','distance-of-nearest-cell-having-1-1587115620','vector<vector<int>> nearest(vector<vector<int>>& grid)',
  'Process multiple initial sources in one FIFO wave and mark states when enqueued.',
  'Rectangular nonempty binary matrix. Return shortest four-direction distance to any 1. If no source exists, this local extension returns -1 at every cell.',
  'Each enqueued cell has its shortest distance because FIFO processes every smaller distance first.',
  'For [[0,0,1],[0,0,0]], begin with (0,2) at distance 0. Its neighbors receive 1, then the next wave receives 2. Result [[2,1,0],[3,2,1]].',
  [([[[0,0,1],[0,0,0]]],[[2,1,0],[3,2,1]]),([[[1]]],[[0]]),([[[0,0]]],[[-1,-1]]),([[[1,0,1]]],[[0,1,0]])],[
  a('Compare every cell with every source','O((rc)²)','O(rc) result','With no obstacles, Manhattan distance equals shortest four-direction distance. Scan all ones for each cell.',r'''int rows = grid.size(), cols = grid[0].size(); vector<vector<int>> out(rows,vector<int>(cols,-1));
for (int r = 0; r < rows; ++r) for (int c = 0; c < cols; ++c) {
    int best = INT_MAX;
    for (int x = 0; x < rows; ++x) for (int y = 0; y < cols; ++y) if (grid[x][y]) best = min(best,abs(r-x)+abs(c-y));
    if (best != INT_MAX) out[r][c] = best;
}
return out;'''),
  a('Separate BFS from each cell','O((rc)²)','O(rc)','Start one queue search per cell and stop at its first one. This teaches FIFO shortest distance before sharing the searches.',r'''int rows = grid.size(), cols = grid[0].size(); vector<vector<int>> out(rows,vector<int>(cols,-1));
int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
for (int r = 0; r < rows; ++r) for (int c = 0; c < cols; ++c) {
    vector<vector<int>> distance(rows,vector<int>(cols,-1));
    queue<pair<int,int>> pending; pending.push({r,c}); distance[r][c] = 0;
    while (!pending.empty()) {
        auto [x,y] = pending.front(); pending.pop();
        if (grid[x][y]) { out[r][c] = distance[x][y]; break; }
        for (int d = 0; d < 4; ++d) {
            int nx = x+dr[d], ny = y+dc[d];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && distance[nx][ny] == -1) {
                distance[nx][ny] = distance[x][y]+1; pending.push({nx,ny});
            }
        }
    }
}
return out;'''),
  a('One multi-source BFS','O(rc)','O(rc)','Enqueue every source at distance zero. Mark a neighbor as soon as it enters the queue so it cannot be enqueued again.',r'''int rows = grid.size(), cols = grid[0].size(); vector<vector<int>> out(rows,vector<int>(cols,-1));
queue<pair<int,int>> pending;
for (int r = 0; r < rows; ++r) for (int c = 0; c < cols; ++c) if (grid[r][c]) { out[r][c] = 0; pending.push({r,c}); }
int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
while (!pending.empty()) {
    auto [r,c] = pending.front(); pending.pop();
    for (int d = 0; d < 4; ++d) {
        int nr = r+dr[d], nc = c+dc[d];
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && out[nr][nc] == -1) {
            out[nr][nc] = out[r][c]+1; pending.push({nr,nc});
        }
    }
}
return out;''')],prerequisites='Queue operations; rectangular matrix bounds; FIFO distance layers')

assert len(ITEMS) == 30
assert sum(x['module'] == S for x in ITEMS) == 18
assert sum(x['module'] == Q for x in ITEMS) == 12
assert len({x['url'] for x in ITEMS}) == 30
