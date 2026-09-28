#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char,int> f;for(char c:s)++f[c];int n=f.begin()->second;for(auto [c,count]:f)if(count!=n)return false;return true;
    }
};
