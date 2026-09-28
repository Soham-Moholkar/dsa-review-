#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=k;for(int i=0;i+k<=(int)blocks.size();++i){int whites=0;for(int j=i;j<i+k;++j)whites+=blocks[j]=='W';ans=min(ans,whites);}return ans;
    }
};
