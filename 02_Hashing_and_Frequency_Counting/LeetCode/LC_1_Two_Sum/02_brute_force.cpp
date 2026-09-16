#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(1LL * nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Compare every pair.
*/
