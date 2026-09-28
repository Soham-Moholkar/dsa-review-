#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        for(int i=0;i<(int)s.size();++i){int count=0;for(char c:s)count+=c==s[i];if(count==1)return i;}return -1;
    }
};
