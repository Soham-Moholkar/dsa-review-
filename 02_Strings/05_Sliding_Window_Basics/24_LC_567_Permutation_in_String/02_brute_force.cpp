#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());for(int i=0;i+s1.size()<=s2.size();++i){string part=s2.substr(i,s1.size());sort(part.begin(),part.end());if(part==s1)return true;}return false;
    }
};
