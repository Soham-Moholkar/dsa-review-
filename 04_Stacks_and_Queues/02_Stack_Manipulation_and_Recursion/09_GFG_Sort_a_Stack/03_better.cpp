#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortStack(stack<int>& st) {
        function<void(int)> insert=[&](int x){if(st.empty()||st.top()<=x){st.push(x);return;}int y=st.top();st.pop();insert(x);st.push(y);};function<void()> sortRec=[&](){if(st.empty())return;int x=st.top();st.pop();sortRec();insert(x);};sortRec();
    }
};
