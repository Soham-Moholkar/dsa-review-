#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(),best=-1;for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(grid[i][j]==0){int distance=INT_MAX;for(int x=0;x<n;++x)for(int y=0;y<n;++y)if(grid[x][y]==1)distance=min(distance,abs(i-x)+abs(j-y));if(distance!=INT_MAX)best=max(best,distance);}return best;
    }
};
