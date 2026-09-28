#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows=maze.size(),cols=maze[0].size(),dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};queue<pair<int,int>> q;q.push({entrance[0],entrance[1]});maze[entrance[0]][entrance[1]]='+';int steps=0;while(!q.empty()){int batch=q.size();while(batch--){auto [x,y]=q.front();q.pop();if(steps&&(x==0||x==rows-1||y==0||y==cols-1))return steps;for(int z=0;z<4;++z){int nx=x+dx[z],ny=y+dy[z];if(nx>=0&&nx<rows&&ny>=0&&ny<cols&&maze[nx][ny]=='.'){maze[nx][ny]='+';q.push({nx,ny});}}}++steps;}return -1;
    }
};
