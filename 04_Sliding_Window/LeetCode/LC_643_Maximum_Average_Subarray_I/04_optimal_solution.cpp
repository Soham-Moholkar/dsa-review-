#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long windowSum = 0;
        for(int i = 0; i < k; i++) {
            windowSum = windowSum + nums[i];
        }
        long long maximumSum = windowSum;
        for(int i = k; i < nums.size(); i++) {
            windowSum = windowSum + nums[i] - nums[i - k];
            maximumSum = max(maximumSum, windowSum);
        }
        return (double)maximumSum / k;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Fixed sliding window.
*/
