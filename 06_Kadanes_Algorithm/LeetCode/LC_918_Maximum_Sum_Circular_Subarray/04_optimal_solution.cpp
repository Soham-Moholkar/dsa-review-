#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = nums[0];
        int currentMaximum = nums[0];
        int maximumSum = nums[0];
        int currentMinimum = nums[0];
        int minimumSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            totalSum = totalSum + nums[i];
            currentMaximum = max(nums[i], currentMaximum + nums[i]);
            maximumSum = max(maximumSum, currentMaximum);
            currentMinimum = min(nums[i], currentMinimum + nums[i]);
            minimumSum = min(minimumSum, currentMinimum);
        }
        if(maximumSum < 0) {
            return maximumSum;
        }
        return max(maximumSum, totalSum - minimumSum);
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Maximum and minimum Kadane.
*/
