#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> val{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};int ans=0;for(int i=0;i<(int)s.size();++i){int v=val[s[i]];ans+=(i+1<(int)s.size()&&v<val[s[i+1]])?-v:v;}return ans;
    }
};
