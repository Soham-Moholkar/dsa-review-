#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<long long, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            long long remaining = 1LL * target - nums[i];
            if(mp.find(remaining) != mp.end()) {
                return {mp[remaining], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

/*
Time Complexity: O(n) average
Extra Space: O(n)
Approach: One-pass hashmap.
*/
