#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        auto vowel=[](char c){return string("aeiouAEIOU").find(c)!=string::npos;}; int l=0,r=(int)s.size()-1; while(l<r){if(!vowel(s[l])){++l;continue;} if(!vowel(s[r])){--r;continue;} swap(s[l++],s[r--]);} return s;
    }
};
