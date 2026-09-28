#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void interleaveQueue(queue<int>& q) {
        int n=q.size();queue<int> first;for(int i=0;i<n/2;++i){first.push(q.front());q.pop();}queue<int> out;while(!first.empty()){out.push(first.front());first.pop();out.push(q.front());q.pop();}q=move(out);
    }
};
