#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insertAtBottom(stack<int>& st, int value) {
        vector<int> saved;while(!st.empty()){saved.push_back(st.top());st.pop();}st.push(value);for(int i=(int)saved.size()-1;i>=0;--i)st.push(saved[i]);
    }
};
