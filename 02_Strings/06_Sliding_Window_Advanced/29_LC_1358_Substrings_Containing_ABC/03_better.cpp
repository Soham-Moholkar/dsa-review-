#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3]={},left=0,ans=0;for(int right=0;right<(int)s.size();++right){++cnt[s[right]-'a'];while(cnt[0]&&cnt[1]&&cnt[2])--cnt[s[left++]-'a'];ans+=left;}return ans;
    }
};
