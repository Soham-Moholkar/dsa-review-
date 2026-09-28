#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white=0,best=k;for(int i=0;i<(int)blocks.size();++i){white+=blocks[i]=='W';if(i>=k)white-=blocks[i-k]=='W';if(i>=k-1)best=min(best,white);}return best;
    }
};
