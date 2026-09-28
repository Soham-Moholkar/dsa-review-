#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];fill(begin(last),end(last),-1);int left=0,best=0;for(int right=0;right<(int)s.size();++right){left=max(left,last[(unsigned char)s[right]]+1);last[(unsigned char)s[right]]=right;best=max(best,right-left+1);}return best;
    }
};
