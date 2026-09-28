#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;int left=0,best=0;for(int right=0;right<(int)s.size();++right){while(seen.count(s[right]))seen.erase(s[left++]);seen.insert(s[right]);best=max(best,right-left+1);}return best;
    }
};
