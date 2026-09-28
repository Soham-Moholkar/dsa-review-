#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;int cols=matrix[0].size(),best=0;vector<int> height(cols);for(auto& row:matrix){for(int j=0;j<cols;++j)height[j]=row[j]=='1'?height[j]+1:0;vector<int> st;for(int j=0;j<=cols;++j){int h=j==cols?0:height[j];while(!st.empty()&&(j==cols||height[st.back()]>=h)){int x=height[st.back()];st.pop_back();best=max(best,x*(j-(st.empty()?-1:st.back())-1));}st.push_back(j);}}return best;
    }
};
