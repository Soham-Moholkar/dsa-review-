#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int need[26]={};for(char c:s1)++need[c-'a'];for(int i=0;i+s1.size()<=s2.size();++i){int have[26]={};for(int j=0;j<(int)s1.size();++j)++have[s2[i+j]-'a'];if(equal(begin(need),end(need),begin(have)))return true;}return false;
    }
};
