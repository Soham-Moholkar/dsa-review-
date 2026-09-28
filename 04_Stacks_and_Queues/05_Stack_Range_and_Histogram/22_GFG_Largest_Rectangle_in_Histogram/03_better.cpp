#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),best=0;vector<int> left(n),right(n),st;for(int i=0;i<n;++i){while(!st.empty()&&heights[st.back()]>=heights[i])st.pop_back();left[i]=st.empty()?-1:st.back();st.push_back(i);}st.clear();for(int i=n-1;i>=0;--i){while(!st.empty()&&heights[st.back()]>=heights[i])st.pop_back();right[i]=st.empty()?n:st.back();st.push_back(i);}for(int i=0;i<n;++i)best=max(best,heights[i]*(right[i]-left[i]-1));return best;
    }
};
