#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size(),fresh=0;queue<tuple<int,int,int>> q;for(int i=0;i<rows;++i)for(int j=0;j<cols;++j){if(grid[i][j]==2)q.push({i,j,0});else if(grid[i][j]==1)++fresh;}int time=0,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};while(!q.empty()){auto [x,y,t]=q.front();q.pop();for(int z=0;z<4;++z){int a=x+dx[z],b=y+dy[z];if(a>=0&&a<rows&&b>=0&&b<cols&&grid[a][b]==1){grid[a][b]=2;--fresh;time=t+1;q.push({a,b,t+1});}}}return fresh?-1:time;
    }
};
