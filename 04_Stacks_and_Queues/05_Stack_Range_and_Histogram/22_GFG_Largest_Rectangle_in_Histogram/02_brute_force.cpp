#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int best=0;for(int i=0;i<(int)heights.size();++i){int lowest=INT_MAX;for(int j=i;j<(int)heights.size();++j){lowest=min(lowest,heights[j]);best=max(best,lowest*(j-i+1));}}return best;
    }
};
