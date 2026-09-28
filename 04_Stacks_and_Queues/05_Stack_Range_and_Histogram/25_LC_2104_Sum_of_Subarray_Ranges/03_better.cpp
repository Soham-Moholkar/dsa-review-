#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        auto contribution=[&](bool maximum){int n=nums.size();vector<int> left(n),right(n),st;for(int i=0;i<n;++i){while(!st.empty()&&(maximum?nums[st.back()]<=nums[i]:nums[st.back()]>=nums[i]))st.pop_back();left[i]=st.empty()?-1:st.back();st.push_back(i);}st.clear();for(int i=n-1;i>=0;--i){while(!st.empty()&&(maximum?nums[st.back()]<nums[i]:nums[st.back()]>nums[i]))st.pop_back();right[i]=st.empty()?n:st.back();st.push_back(i);}long long ans=0;for(int i=0;i<n;++i)ans+=(long long)nums[i]*(i-left[i])*(right[i]-i);return ans;};return contribution(true)-contribution(false);
    }
};
