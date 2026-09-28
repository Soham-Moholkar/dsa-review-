#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseFirstK(queue<int>& q, int k) {
        stack<int> st;int n=q.size();for(int i=0;i<k;++i){st.push(q.front());q.pop();}while(!st.empty()){q.push(st.top());st.pop();}for(int i=0;i<n-k;++i){q.push(q.front());q.pop();}
    }
};
