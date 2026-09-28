#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[256]={}; for(unsigned char c:s) ++cnt[c]; int expected=0; for(int x:cnt) if(x){if(expected && x!=expected) return false; expected=x;} return true;
    }
};
