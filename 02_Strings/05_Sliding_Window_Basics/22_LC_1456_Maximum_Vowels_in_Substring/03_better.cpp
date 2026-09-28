#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> prefix(s.size()+1);for(int i=0;i<(int)s.size();++i)prefix[i+1]=prefix[i]+(string("aeiou").find(s[i])!=string::npos);int ans=0;for(int i=k;i<(int)prefix.size();++i)ans=max(ans,prefix[i]-prefix[i-k]);return ans;
    }
};
