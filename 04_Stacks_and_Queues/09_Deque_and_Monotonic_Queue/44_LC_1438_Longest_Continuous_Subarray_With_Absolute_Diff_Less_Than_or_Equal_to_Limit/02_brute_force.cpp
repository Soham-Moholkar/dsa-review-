#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int best=0;for(int i=0;i<(int)nums.size();++i){int lo=INT_MAX,hi=INT_MIN;for(int j=i;j<(int)nums.size();++j){lo=min(lo,nums[j]);hi=max(hi,nums[j]);if((long long)hi-lo<=limit)best=max(best,j-i+1);}}return best;
    }
};
