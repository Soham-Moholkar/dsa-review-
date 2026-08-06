#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto position = lower_bound(nums.begin(), nums.end(), target);
        if(position != nums.end() && *position == target) {
            return position - nums.begin();
        }
        return -1;
    }
};

/*
Time Complexity: O(log n)
Extra Space: O(1)
Approach: lower_bound.
*/
