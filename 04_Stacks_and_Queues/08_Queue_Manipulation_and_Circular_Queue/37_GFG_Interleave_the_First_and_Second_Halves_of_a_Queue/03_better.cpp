#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void interleaveQueue(queue<int>& q) {
        vector<int> v;while(!q.empty()){v.push_back(q.front());q.pop();}int middle=v.size()/2;for(int i=0;i<middle;++i){q.push(v[i]);q.push(v[i+middle]);}
    }
};
