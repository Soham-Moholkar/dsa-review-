#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        vector<int> prefix(blocks.size()+1);for(int i=0;i<(int)blocks.size();++i)prefix[i+1]=prefix[i]+(blocks[i]=='W');int best=k;for(int i=k;i<(int)prefix.size();++i)best=min(best,prefix[i]-prefix[i-k]);return best;
    }
};
