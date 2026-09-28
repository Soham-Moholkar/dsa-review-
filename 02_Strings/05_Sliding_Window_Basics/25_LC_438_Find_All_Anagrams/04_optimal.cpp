#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> out;if(p.size()>s.size())return out;int want[26]={},have[26]={};for(char c:p)++want[c-'a'];for(int i=0;i<(int)s.size();++i){++have[s[i]-'a'];if(i>=(int)p.size())--have[s[i-p.size()]-'a'];if(i+1>=(int)p.size()&&equal(begin(want),end(want),begin(have)))out.push_back(i+1-p.size());}return out;
    }
};
