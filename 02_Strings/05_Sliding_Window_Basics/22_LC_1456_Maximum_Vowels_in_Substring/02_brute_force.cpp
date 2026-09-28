#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;for(int i=0;i+k<=(int)s.size();++i){int count=0;for(int j=i;j<i+k;++j)count+=string("aeiou").find(s[j])!=string::npos;ans=max(ans,count);}return ans;
    }
};
