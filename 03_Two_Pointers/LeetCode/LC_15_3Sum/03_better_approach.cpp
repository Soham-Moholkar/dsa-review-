#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> uniqueTriplets;
        for(int i = 0; i < nums.size(); i++) {
            unordered_set<int> seen;
            for(int j = i + 1; j < nums.size(); j++) {
                int required = -nums[i] - nums[j];
                if(seen.find(required) != seen.end()) {
                    vector<int> triplet = {nums[i], nums[j], required};
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet);
                }
                seen.insert(nums[j]);
            }
        }
        return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
    }
};

/*
Time Complexity: O(n^2 log n) expected
Extra Space: O(n) excluding answers
Approach: Fix two values and use a hash set.
*/
