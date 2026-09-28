#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;int left=0,best=0;for(int right=0;right<(int)nums.size();++right){window.insert(nums[right]);while((long long)*window.rbegin()-*window.begin()>limit){window.erase(window.find(nums[left++]));}best=max(best,right-left+1);}return best;
    }
};
