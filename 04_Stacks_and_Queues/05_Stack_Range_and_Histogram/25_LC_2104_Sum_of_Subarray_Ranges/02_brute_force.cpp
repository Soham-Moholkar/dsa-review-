#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;for(int i=0;i<(int)nums.size();++i){int lo=INT_MAX,hi=INT_MIN;for(int j=i;j<(int)nums.size();++j){lo=min(lo,nums[j]);hi=max(hi,nums[j]);sum+=(long long)hi-lo;}}return sum;
    }
};
