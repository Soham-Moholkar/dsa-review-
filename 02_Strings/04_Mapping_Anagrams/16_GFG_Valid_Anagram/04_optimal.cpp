#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[256]={}; if(s.size()!=t.size()) return false; for(unsigned char c:s) ++cnt[c]; for(unsigned char c:t) if(--cnt[c]<0) return false; return true;
    }
};
