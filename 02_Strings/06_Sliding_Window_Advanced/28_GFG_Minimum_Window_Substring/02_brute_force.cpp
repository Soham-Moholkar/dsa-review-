#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string best="";for(int i=0;i<(int)s.size();++i)for(int j=i;j<(int)s.size();++j){string part=s.substr(i,j-i+1);int cnt[256]={};for(unsigned char c:part)++cnt[c];bool ok=true;for(unsigned char c:t)if(--cnt[c]<0){ok=false;break;}if(ok&&(best.empty()||part.size()<best.size()))best=part;}return best;
    }
};
