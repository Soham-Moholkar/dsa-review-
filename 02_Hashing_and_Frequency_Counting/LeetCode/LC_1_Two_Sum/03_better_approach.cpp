#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];
            if(mp.find(remaining) != mp.end() && mp[remaining] != i) {
                return {i, mp[remaining]};
            }
        }
        return {-1, -1};
    }
};

/*
Time Complexity: O(n) average
Extra Space: O(n)
Approach: Two-pass hashmap.
*/
