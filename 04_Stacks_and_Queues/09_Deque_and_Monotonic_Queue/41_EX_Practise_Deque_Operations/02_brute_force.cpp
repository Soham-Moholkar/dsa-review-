#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> applyDequeOperations(vector<string>& commands) {
        deque<int> dq;for(auto& command:commands){istringstream in(command);string op;int x;in>>op;if(op=="push_front"){in>>x;dq.push_front(x);}else if(op=="push_back"){in>>x;dq.push_back(x);}else if(op=="pop_front"&&!dq.empty())dq.pop_front();else if(op=="pop_back"&&!dq.empty())dq.pop_back();}return vector<int>(dq.begin(),dq.end());
    }
};
