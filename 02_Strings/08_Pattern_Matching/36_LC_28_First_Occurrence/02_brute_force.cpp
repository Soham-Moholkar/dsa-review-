#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i+needle.size()<=haystack.size();++i)if(haystack.compare(i,needle.size(),needle)==0)return i;return -1;
    }
};
