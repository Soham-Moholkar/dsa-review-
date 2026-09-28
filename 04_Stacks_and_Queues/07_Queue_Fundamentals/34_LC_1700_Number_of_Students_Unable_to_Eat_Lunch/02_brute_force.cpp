#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;for(int x:students)q.push(x);int i=0,rotations=0;while(!q.empty()&&rotations<(int)q.size()){int x=q.front();q.pop();if(x==sandwiches[i]){++i;rotations=0;}else{q.push(x);++rotations;}}return q.size();
    }
};
