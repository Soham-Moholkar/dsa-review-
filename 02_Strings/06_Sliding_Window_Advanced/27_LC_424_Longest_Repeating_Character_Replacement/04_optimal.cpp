#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26]={},left=0,best=0,top=0;for(int right=0;right<(int)s.size();++right){top=max(top,++cnt[s[right]-'A']);while(right-left+1-top>k)--cnt[s[left++]-'A'];best=max(best,right-left+1);}return best;
    }
};
