#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int repeat=(b.size()+a.size()-1)/a.size();string built;for(int i=0;i<repeat;++i)built+=a;if(built.find(b)!=string::npos)return repeat;built+=a;return built.find(b)!=string::npos?repeat+1:-1;
    }
};
