#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1||numRows>=(int)s.size())return s;vector<string> rows(numRows);int row=0,step=1;for(char c:s){rows[row]+=c;if(row==0)step=1;else if(row==numRows-1)step=-1;row+=step;}string out;for(auto& part:rows)out+=part;return out;
    }
};
