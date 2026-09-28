#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;int j=0;for(int value:pushed){st.push(value);while(!st.empty()&&j<(int)popped.size()&&st.top()==popped[j]){st.pop();++j;}}return j==(int)popped.size();
    }
};
