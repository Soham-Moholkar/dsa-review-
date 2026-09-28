#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string s) {
        int count[256]={};string out;for(int i=0;i<(int)s.size();++i){++count[(unsigned char)s[i]];char first='#';for(int j=0;j<=i;++j)if(count[(unsigned char)s[j]]==1){first=s[j];break;}out+=first;}return out;
    }
};
