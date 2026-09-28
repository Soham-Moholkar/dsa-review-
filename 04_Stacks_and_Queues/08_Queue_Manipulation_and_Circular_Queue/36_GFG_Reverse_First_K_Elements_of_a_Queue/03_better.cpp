#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseFirstK(queue<int>& q, int k) {
        deque<int> d;while(!q.empty()){d.push_back(q.front());q.pop();}for(int i=k-1;i>=0;--i)q.push(d[i]);for(int i=k;i<(int)d.size();++i)q.push(d[i]);
    }
};
