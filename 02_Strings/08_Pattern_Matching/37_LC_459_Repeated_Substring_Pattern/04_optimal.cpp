#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();vector<int> pi(n);for(int i=1;i<n;++i){int j=pi[i-1];while(j&&s[i]!=s[j])j=pi[j-1];if(s[i]==s[j])++j;pi[i]=j;}int period=n-pi.back();return pi.back()>0&&n%period==0;
    }
};
