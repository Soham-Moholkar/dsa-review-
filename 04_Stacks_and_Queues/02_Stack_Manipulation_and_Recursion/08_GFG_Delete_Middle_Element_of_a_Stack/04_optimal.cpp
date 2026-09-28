#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void deleteMiddle(stack<int>& st) {
        int depth=(int)st.size()-1-((int)st.size()-1)/2;function<void(int)> remove=[&](int d){if(d==0){st.pop();return;}int x=st.top();st.pop();remove(d-1);st.push(x);};if(!st.empty())remove(depth);
    }
};
