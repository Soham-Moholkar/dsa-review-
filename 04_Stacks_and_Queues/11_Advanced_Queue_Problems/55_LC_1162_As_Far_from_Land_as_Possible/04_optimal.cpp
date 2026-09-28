#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(),dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};queue<pair<int,int>> q;for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(grid[i][j]==1)q.push({i,j});if(q.empty()||(int)q.size()==n*n)return -1;int distance=-1;while(!q.empty()){int batch=q.size();++distance;while(batch--){auto [x,y]=q.front();q.pop();for(int z=0;z<4;++z){int nx=x+dx[z],ny=y+dy[z];if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]==0){grid[nx][ny]=1;q.push({nx,ny});}}}}return distance;
    }
};
