#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26]={},left=0,best=0;for(int right=0;right<(int)s.size();++right){++count[s[right]-'A'];while(true){int highest=*max_element(begin(count),end(count));if(right-left+1-highest<=k)break;--count[s[left++]-'A'];}best=max(best,right-left+1);}return best;
    }
};
