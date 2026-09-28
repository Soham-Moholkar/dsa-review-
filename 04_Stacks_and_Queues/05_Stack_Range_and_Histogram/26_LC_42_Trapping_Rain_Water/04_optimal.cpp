#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> st;int water=0;for(int i=0;i<(int)height.size();++i){while(!st.empty()&&height[i]>height[st.back()]){int bottom=st.back();st.pop_back();if(st.empty())break;int width=i-st.back()-1;int depth=min(height[i],height[st.back()])-height[bottom];water+=width*depth;}st.push_back(i);}return water;
    }
};
