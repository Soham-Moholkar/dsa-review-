#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> lo,hi;int left=0,best=0;for(int right=0;right<(int)nums.size();++right){while(!lo.empty()&&nums[lo.back()]>=nums[right])lo.pop_back();while(!hi.empty()&&nums[hi.back()]<=nums[right])hi.pop_back();lo.push_back(right);hi.push_back(right);while((long long)nums[hi.front()]-nums[lo.front()]>limit){if(lo.front()==left)lo.pop_front();if(hi.front()==left)hi.pop_front();++left;}best=max(best,right-left+1);}return best;
    }
};
