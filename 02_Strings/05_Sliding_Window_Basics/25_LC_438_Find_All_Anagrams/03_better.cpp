#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> out;int need[26]={};for(char c:p)++need[c-'a'];for(int i=0;i+p.size()<=s.size();++i){int have[26]={};for(int j=0;j<(int)p.size();++j)++have[s[i+j]-'a'];if(equal(begin(need),end(need),begin(have)))out.push_back(i);}return out;
    }
};
