#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int best=INT_MAX;for(int i=0;i<(int)nums.size();++i){long long sum=0;for(int j=i;j<(int)nums.size();++j){sum+=nums[j];if(sum>=k)best=min(best,j-i+1);}}return best==INT_MAX?-1:best;
    }
};
