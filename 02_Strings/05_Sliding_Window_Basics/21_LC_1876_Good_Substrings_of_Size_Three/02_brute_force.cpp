#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans=0;for(int i=0;i+3<=(int)s.size();++i){set<char> unique(s.begin()+i,s.begin()+i+3);ans+=unique.size()==3;}return ans;
    }
};
