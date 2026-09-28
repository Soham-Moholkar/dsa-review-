#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;vector<string> rows(numRows);for(int i=0;i<(int)s.size();++i){int period=2*numRows-2,x=i%period;int row=min(x,period-x);rows[row]+=s[i];}string out;for(auto& row:rows)out+=row;return out;
    }
};
