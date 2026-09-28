#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size(),answer=n+1;vector<long long> sum(n+1);for(int i=0;i<n;++i)sum[i+1]=sum[i]+nums[i];deque<int> dq;for(int i=0;i<=n;++i){while(!dq.empty()&&sum[i]-sum[dq.front()]>=k){answer=min(answer,i-dq.front());dq.pop_front();}while(!dq.empty()&&sum[i]<=sum[dq.back()])dq.pop_back();dq.push_back(i);}return answer==n+1?-1:answer;
    }
};
