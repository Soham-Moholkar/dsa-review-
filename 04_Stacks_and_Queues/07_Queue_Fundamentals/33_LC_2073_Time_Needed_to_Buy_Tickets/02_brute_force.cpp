#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;for(int i=0;i<(int)tickets.size();++i)q.push({i,tickets[i]});int time=0;while(!q.empty()){auto [index,count]=q.front();q.pop();++time;if(--count==0){if(index==k)return time;}else q.push({index,count});}return time;
    }
};
