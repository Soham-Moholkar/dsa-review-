#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        auto pal=[](string a){string b=a;reverse(b.begin(),b.end());return a==b;};if(pal(s))return true;for(int i=0;i<(int)s.size();++i)if(pal(s.substr(0,i)+s.substr(i+1)))return true;return false;
    }
};
