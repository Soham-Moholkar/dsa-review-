#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int best=0;for(int i=0;i<(int)s.size();++i){int cnt[26]={},highest=0;for(int j=i;j<(int)s.size();++j){highest=max(highest,++cnt[s[j]-'A']);if(j-i+1-highest<=k)best=max(best,j-i+1);}}return best;
    }
};
