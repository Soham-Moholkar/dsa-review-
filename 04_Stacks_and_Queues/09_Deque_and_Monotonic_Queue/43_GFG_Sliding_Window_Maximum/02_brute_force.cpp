#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;for(int i=0;i+k<=(int)nums.size();++i)out.push_back(*max_element(nums.begin()+i,nums.begin()+i+k));return out;
    }
};
