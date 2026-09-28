#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size(),fresh=0;queue<pair<int,int>> q;for(int i=0;i<rows;++i)for(int j=0;j<cols;++j){if(grid[i][j]==2)q.push({i,j});else if(grid[i][j]==1)++fresh;}int time=0,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};while(!q.empty()&&fresh){int batch=q.size();while(batch--){auto [x,y]=q.front();q.pop();for(int z=0;z<4;++z){int nx=x+dx[z],ny=y+dy[z];if(nx>=0&&nx<rows&&ny>=0&&ny<cols&&grid[nx][ny]==1){grid[nx][ny]=2;--fresh;q.push({nx,ny});}}}++time;}return fresh?-1:time;
    }
};
