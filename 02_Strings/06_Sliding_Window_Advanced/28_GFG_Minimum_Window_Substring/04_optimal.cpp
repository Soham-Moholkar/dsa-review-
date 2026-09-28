#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty())return "";int need[256]={};for(unsigned char c:t)++need[c];int missing=t.size(),left=0,start=0,best=INT_MAX;for(int right=0;right<(int)s.size();++right){unsigned char c=s[right];if(need[c]-- >0)--missing;while(missing==0){if(right-left+1<best){start=left;best=right-left+1;}unsigned char out=s[left++];if(++need[out]>0)++missing;}}return best==INT_MAX?"":s.substr(start,best);
    }
};
