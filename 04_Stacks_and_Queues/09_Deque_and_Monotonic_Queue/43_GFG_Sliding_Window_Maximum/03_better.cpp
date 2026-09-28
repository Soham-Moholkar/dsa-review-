#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;multiset<int> window;for(int i=0;i<(int)nums.size();++i){window.insert(nums[i]);if(i>=k)window.erase(window.find(nums[i-k]));if(i>=k-1)out.push_back(*window.rbegin());}return out;
    }
};
