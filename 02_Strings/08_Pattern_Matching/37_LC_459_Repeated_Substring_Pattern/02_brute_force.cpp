#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int width=1;width*2<=s.size();++width){if(s.size()%width)continue;bool ok=true;for(int i=width;i<(int)s.size();++i)if(s[i]!=s[i%width]){ok=false;break;}if(ok)return true;}return false;
    }
};
