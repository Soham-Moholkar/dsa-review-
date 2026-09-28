#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0,r=(int)s.size()-1; while(l<r){if(!isalpha((unsigned char)s[l])){++l;continue;} if(!isalpha((unsigned char)s[r])){--r;continue;} swap(s[l++],s[r--]);} return s;
    }
};
