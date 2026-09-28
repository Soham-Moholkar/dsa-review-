#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lastEvents(vector<int>& events, int capacity) {
        deque<int> q;for(int x:events){if(capacity==0)continue;if((int)q.size()==capacity)q.pop_front();q.push_back(x);}return vector<int>(q.begin(),q.end());
    }
};
