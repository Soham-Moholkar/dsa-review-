#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[256]={}; for(unsigned char c:magazine) ++cnt[c]; for(unsigned char c:ransomNote) if(--cnt[c]<0) return false; return true;
    }
};
