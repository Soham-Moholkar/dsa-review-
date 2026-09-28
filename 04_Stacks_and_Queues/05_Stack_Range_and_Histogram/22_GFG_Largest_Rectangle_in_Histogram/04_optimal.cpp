#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> st;int best=0,n=heights.size();for(int i=0;i<=n;++i){int h=i==n?0:heights[i];while(!st.empty()&&(i==n||heights[st.back()]>=h)){int height=heights[st.back()];st.pop_back();int left=st.empty()?-1:st.back();best=max(best,height*(i-left-1));}st.push_back(i);}return best;
    }
};
