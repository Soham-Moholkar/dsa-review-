#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseStack(stack<int>& st) {
        function<void(int)> bottom=[&](int x){if(st.empty()){st.push(x);return;}int t=st.top();st.pop();bottom(x);st.push(t);};function<void()> reverse=[&](){if(st.empty())return;int t=st.top();st.pop();reverse();bottom(t);};reverse();
    }
};
