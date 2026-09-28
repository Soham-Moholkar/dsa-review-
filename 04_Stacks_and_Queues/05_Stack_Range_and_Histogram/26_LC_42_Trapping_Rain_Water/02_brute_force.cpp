#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int total=0;for(int i=0;i<(int)height.size();++i){int left=0,right=0;for(int j=0;j<=i;++j)left=max(left,height[j]);for(int j=i;j<(int)height.size();++j)right=max(right,height[j]);total+=min(left,right)-height[i];}return total;
    }
};
