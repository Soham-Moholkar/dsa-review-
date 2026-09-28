#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;int need[26]={},have[26]={};for(char c:s1)++need[c-'a'];for(int i=0;i<(int)s2.size();++i){++have[s2[i]-'a'];if(i>=(int)s1.size())--have[s2[i-s1.size()]-'a'];if(i+1>=(int)s1.size()&&equal(begin(need),end(need),begin(have)))return true;}return false;
    }
};
