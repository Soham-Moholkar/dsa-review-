#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseQueue(queue<int>& q) {
        function<void()> reverse=[&](){if(q.empty())return;int x=q.front();q.pop();reverse();q.push(x);};reverse();
    }
};
