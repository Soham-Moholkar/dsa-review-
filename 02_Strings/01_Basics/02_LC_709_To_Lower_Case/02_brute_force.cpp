#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        string out=s;for(int i=0;i<(int)out.size();++i)if(out[i]>='A'&&out[i]<='Z')out[i]+=32;return out;
    }
};
