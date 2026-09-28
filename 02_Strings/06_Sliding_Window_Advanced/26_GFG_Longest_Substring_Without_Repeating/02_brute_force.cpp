#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best=0;for(int i=0;i<(int)s.size();++i){set<char> seen;for(int j=i;j<(int)s.size();++j){if(!seen.insert(s[j]).second)break;best=max(best,j-i+1);}}return best;
    }
};
