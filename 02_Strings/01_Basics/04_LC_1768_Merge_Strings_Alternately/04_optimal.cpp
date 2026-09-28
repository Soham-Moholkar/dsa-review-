#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string out; int i=0; while(i<(int)word1.size()||i<(int)word2.size()){if(i<(int)word1.size()) out+=word1[i]; if(i<(int)word2.size()) out+=word2[i]; ++i;} return out;
    }
};
