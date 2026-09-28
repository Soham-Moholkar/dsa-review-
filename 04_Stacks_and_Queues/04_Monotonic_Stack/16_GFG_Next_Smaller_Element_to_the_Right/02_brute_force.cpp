#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmaller(vector<int>& nums) {
        vector<int> out(nums.size(),-1);for(int i=0;i<nums.size();++i)for(int j=i+1;j<nums.size();++j)if(nums[j]<nums[i]){out[i]=nums[j];break;}return out;
    }
};
