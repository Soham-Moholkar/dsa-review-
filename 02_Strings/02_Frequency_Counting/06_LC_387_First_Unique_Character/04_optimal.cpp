#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[256]={}; for(unsigned char c:s) ++cnt[c]; for(int i=0;i<(int)s.size();++i) if(cnt[(unsigned char)s[i]]==1) return i; return -1;
    }
};
